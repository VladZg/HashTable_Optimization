#include "./Config.h"
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <time.h>
#include <immintrin.h>
#include "./Libs/List/Include/List.h"
#include "./Include/HashFunctions.h"
#include "./Include/HashTable.h"

#define N_LOOPS 1000
#define N_WORDS 10000

// #define NO_AVX
#define AVX2

#ifdef NO_AVX
    #define FILLING_WORDS_FILENAME "./Data/filling_words.txt"
    #define SEARCHING_WORDS_FILENAME "./Data/searching_words.txt"
#else
    #define FILLING_WORDS_FILENAME "./Data/filling_words_bin.bin"
    #define SEARCHING_WORDS_FILENAME "./Data/searching_words_bin.bin"
#endif

static void PrepareData();
static int  FillWordsBufFromFile(FILE* source, char** buf, int n_words);
static int  WordsBufDtor(char** buf, int n_words);
static inline void RunSearchLoop(HashTable hash_table, char** searching_words, int n_searching_words);
static inline void RunSearchLoop_avx2(HashTable hash_table, __m256i* searching_words, int n_searching_words);

inline void printf_m256i_bytes(__m256i a)
{
    char* arr = (char*)(&a);
    for (int i = 0; i < sizeof(__m256i); i++) printf("%02X ", arr[i]);
    printf("\n");
}

inline void printf_m256i_chars(__m256i a)
{
    char* arr = (char*)(&a);
    for (int i = 0; i < sizeof(__m256i); i++) printf("%c ", arr[i]);
    printf("\n");
}

#define GetTime(cmds)                                                       \
{                                                                           \
    clock_t timer_start = clock();                                          \
    cmds                                                                    \
    clock_t timer_end = clock();                                            \
    double seconds = ((double) (timer_end - timer_start)) / CLOCKS_PER_SEC; \
    printf("%lf seconds\n", seconds);                                       \
}

int main()
{
    // PrepareData();

    FILE* filling_words_file = fopen(FILLING_WORDS_FILENAME, "r");
    assert(filling_words_file);

    FILE* searching_words_file = fopen(SEARCHING_WORDS_FILENAME, "r");
    assert(searching_words_file);

    HashTable hash_table = {};

    int n_filling_words = N_WORDS;
    assert(n_filling_words <= HASH_TABLE_MAX_CAPACITY);
    int n_searching_words = N_WORDS;

    // int hash_table_size = 100;
    // int hash_table_size = 1000; // кринж размер
    int hash_table_size =  6673; // list_avg_size~1.5, простое число (теорема)

    HashTableCtor(&hash_table, hash_table_size, GnuHash_asm);

#ifdef NO_AVX
    FillHashTable(&hash_table, filling_words_file, n_filling_words);

    char* searching_words[n_searching_words] = {};
    FillWordsBufFromFile(searching_words_file, searching_words, n_searching_words);

    GetTime(
    for (int loop = 0; loop < N_LOOPS; loop++)
        RunSearchLoop(hash_table, searching_words, n_searching_words);
    )

    WordsBufDtor(searching_words, n_searching_words);

#else
    size_t avx_word_size = sizeof(__m256i);

    __m256i filling_words_avx2 [n_filling_words] = {};
    fread(filling_words_avx2, avx_word_size, n_filling_words, filling_words_file);

    __m256i* searching_words_avx2 = (__m256i*) aligned_alloc(avx_word_size, n_searching_words*avx_word_size);
    fread(searching_words_avx2, avx_word_size, n_searching_words, searching_words_file);

    FillHashTable_alligned(&hash_table, filling_words_avx2, n_filling_words);
    // HashTableDump(hash_table);

    GetTime(
    for (int loop = 0; loop < N_LOOPS; loop++)
        RunSearchLoop_avx2(hash_table, searching_words_avx2, n_searching_words);
    )

    free(searching_words_avx2);

#endif
    fclose(filling_words_file);
    fclose(searching_words_file);

    HashTableDtor(&hash_table);

    // test of GnuHash:
    // const char str[][10] = {"bdff", "asf", "dsgs", "adfsf", "dskfjn", "dksj", "dsfjn", "afsb"};
    // for (int i = 0; i < 8; i++)
    // {
    //     printf("result: %d, %d\n", GnuHash_asm(str[i]), GnuHash(str[i]));
    // }

    return 1;
}

static void PrepareData()
{
    system("cd ./Data; make; cd ../");
}

static int FillWordsBufFromFile(FILE* source, char** buf, int n_words)
{
    for (int word_i = 0; word_i < n_words; word_i++)
    {
        char* str = (char*) calloc(HASH_MAX_STRLEN, sizeof(char));
        fscanf(source, "%s ", str);
        buf[word_i] = str;
        // fprintf(stdout, "%s ", searching_words[word_i]);
    }

    return 1;
}

static int WordsBufDtor(char** buf, int n_words)
{
    for (int word_i = 0; word_i < n_words; word_i++)
        free(buf[word_i]);

    return 1;
}

static inline void RunSearchLoop(HashTable hash_table, char** searching_words, int n_searching_words)
{
    int counter = 0;

    for (int word_i = 0; word_i < n_searching_words; word_i++)
    {
        int flag = FindInHashTable(searching_words[word_i], hash_table);
        counter += flag;
    }

    // printf("%d times!!!\n", counter);
}

static inline void RunSearchLoop_avx2(HashTable hash_table, __m256i* searching_words, int n_searching_words)
{
    // int counter = 0;

    for (int word_i = 0; word_i < n_searching_words; word_i++)
    {
        __m256i word = _mm256_load_si256(searching_words + word_i);
        int flag = FindInHashTable_avx2(word, hash_table);
        // counter += flag;
    }

    // printf("%d times!!!\n", counter);
}
