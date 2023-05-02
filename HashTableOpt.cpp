#include "./Config.h"
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <time.h>
#include "./Libs/List/Include/List.h"
#include "./Include/HashFunctions.h"
#include "./Include/HashTable.h"

#define N_LOOPS 1000
#define N_WORDS 10000

static void PrepareData();
static int  FillWordsBufFromFile(FILE* source, char** buf, int n_words);
static int  WordsBufDtor(char** buf, int n_words);
static inline void RunSearchLoop(HashTable hash_table, char** searching_words, int n_searching_words);

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

    FILE* filling_words_file = fopen("./Data/filling_words.txt", "r");
    assert(filling_words_file);

    FILE* searching_words_file = fopen("./Data/searching_words.txt", "r");
    assert(searching_words_file);

    HashTable hash_table = {};

    int n_filling_words = N_WORDS;
    assert(n_filling_words <= HASH_TABLE_MAX_CAPACITY);

    // int hash_table_size = 100;
    // int hash_table_size = 1000; // кринж размер
    int hash_table_size =  6673; // list_avg_size~1.5, простое число (теорема)

    HashTableCtor(&hash_table, hash_table_size, GnuHash_asm);
    FillHashTable(&hash_table, filling_words_file, n_filling_words);
    fclose(filling_words_file);

    int n_searching_words = N_WORDS;
    char* searching_words[n_searching_words] = {};
    FillWordsBufFromFile(searching_words_file, searching_words, n_searching_words);
    fclose(searching_words_file);

    GetTime(
    for (int loop = 0; loop < N_LOOPS; loop++)
        RunSearchLoop(hash_table, searching_words, n_searching_words);
    )

    WordsBufDtor(searching_words, n_searching_words);
    HashTableDtor(&hash_table);

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
    for (int word_i = 0; word_i < n_searching_words; word_i++)
        int flag = FindInHashTable(searching_words[word_i], hash_table);
}
