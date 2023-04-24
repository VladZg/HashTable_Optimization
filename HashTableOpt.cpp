#include "./Config.h"
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <time.h>
#include "./Libs/List/Include/List.h"
#include "./Include/HashFunctions.h"
#include "./Include/HashTable.h"

#define N_LOOPS 100

static void PrepareData();

int main()
{
    // PrepareData();

    FILE* filling_words_file = fopen("./Data/filling_words.txt", "r");
    assert(filling_words_file);

    FILE* searching_words_file = fopen("./Data/searching_words.txt", "r");
    assert(searching_words_file);

    HashTable hash_table = {};

    int n_filling_words = 0;
    fscanf(filling_words_file, "%d", &n_filling_words);
    assert(n_filling_words <= HASH_TABLE_MAX_CAPACITY);
    int hash_table_size = (int) ((float)n_filling_words / HashTableListAvgSize);
    // int hash_table_size =  100; // кринж размер
    // int hash_table_size =  6673; //простое число (теорема)
    fgetc(filling_words_file);

    // printf("%d\n", hash_table_size);

    int n_searching_words = 0;
    fscanf(searching_words_file, "%d", &n_searching_words);
    fgetc(searching_words_file);

    char* searching_words[n_searching_words] = {};
    for (int word_i = 0; word_i < n_searching_words; word_i++)
    {
        char* str = (char*) calloc(HASH_MAX_STRLEN, sizeof(char));
        fscanf(searching_words_file, "%s ", str);
        searching_words[word_i] = str;
        // fprintf(stdout, "%s ", searching_words[word_i]);
    }

    HashTableCtor(&hash_table, hash_table_size, MyHash);
    FillHashTable(&hash_table, filling_words_file, n_filling_words);

    fclose(filling_words_file);
    fclose(searching_words_file);

    clock_t start, end;
    start = clock();

    for (int loop = 0; loop < N_LOOPS; loop++)
    {
        int counter = 0;

        for (int word_i = 0; word_i < n_searching_words; word_i++)
        {
            // fprintf(stdout, "%s ", searching_words[word_i]);
            int flag = FindInHashTable(searching_words[word_i], &hash_table);
            if (flag) counter++;
        }

        // printf("%d\n", counter);
    }

    end = clock();
    double seconds = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%lf seconds\n", seconds);

    for (int word_i = 0; word_i < n_searching_words; word_i++)
        free(searching_words[word_i]);

    HashTableDtor(&hash_table);

    return 1;
}

static void PrepareData()
{
    system("cd ./Data; make; cd ../");
}
