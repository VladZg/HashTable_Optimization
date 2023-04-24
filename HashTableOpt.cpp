#include "./Config.h"
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <time.h>
#include "./Libs/List/Include/List.h"
#include "./Include/HashFunctions.h"
#include "./Include/HashTable.h"

#define N_LOOPS 200

static void PrepareData();
static void ShowGraphs();

int main()
{
    // PrepareData();

    FILE* input_file = fopen("./Data/input_text_parsed.txt", "r");
    assert(input_file);

    HashTable hash_table = {};

    int n_words = 0;
    fscanf(input_file, "%d", &n_words);
    assert(n_words <= HASH_TABLE_MAX_CAPACITY);
    int hash_table_size = n_words / HASH_TABLE_LIST_SIZE;
    fgetc(input_file);

    // List list = {};
    // ListCtor(&list);
    // char* str = (char*) calloc(HASH_MAX_STRLEN, sizeof(char));
    // sprintf(str, "%s", "aboba");
    // // printf("%s\n", str);
    // ListPushBack(&list, str);
    // int flag = FindInList(&list, str);
    // printf("%d\n", flag);
    // ListDtor(&list);

    HashTableCtor(&hash_table, hash_table_size, MyHash);
    FillHashTable(&hash_table, input_file, n_words);

    clock_t start, end;
    start = clock();

    for (int loop = 0; loop < N_LOOPS; loop++)
    {
        fscanf(input_file, "%d", &n_words);
        fgetc(input_file);

        int counter = 0;

        for (int word_i = 0; word_i < n_words; word_i++)
        {
            char* str = (char*) calloc(HASH_MAX_STRLEN, sizeof(char));
            assert(str);

            fscanf(input_file, "%s ", str);

            int flag = FindInHashTable(str, &hash_table);
            if (flag) counter++;

            free(str);
        }

        // printf("%d\n", counter);

        fseek(input_file, 0, SEEK_SET);
    }

    end = clock();
    double seconds = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%lf seconds\n", seconds);

    HashTableDtor(&hash_table);
    fclose(input_file);

    return 1;
}

static void PrepareData()
{
    system("cd ./Data; make; cd ../");
}
