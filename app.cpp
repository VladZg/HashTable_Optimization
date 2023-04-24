#include "./Config.h"
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include "./Libs/List/Include/List.h"
#include "./Include/HashFunctions.h"
#include "./Include/HashTable.h"

static void PrepareData();
static void ShowGraphs();

int main()
{
    // PrepareData();

    FILE* input_file = fopen("./Data/input_text_parsed.txt", "r");
    assert(input_file);

    FILE* output_file = fopen("./Graphs/data.csv", "w");
    assert(output_file);

    HashTable hash_table = {};

    HashFunc hash_functions_set[N_HASH_FUNCTIONS] = {HashConst, HashLen, HashFirstSymb, HashSum, HashRol, HashRor, MyHash};
    // const char hash_functions_names[N_HASH_FUNCTIONS][10] = {"const", "length", "ascii", "sum", "rol", "ror", "myhash"};
    HashFunctions hash_functions = {N_HASH_FUNCTIONS, hash_functions_set};
    // hash_functions.func_names = hash_functions_names;

    int n_words = 0;
    fscanf(input_file, "%d", &n_words);
    assert(n_words <= HASH_TABLE_MAX_CAPACITY);
    int hash_table_size = n_words / HASH_TABLE_LIST_SIZE;
    fgetc(input_file);

    for (int hash_func_i = 0; hash_func_i < N_HASH_FUNCTIONS; hash_func_i++)
    {
        fscanf(input_file, "%d", &n_words);
        fgetc(input_file);

        HashTableCtor(&hash_table, hash_table_size, hash_functions.funcs[hash_func_i]);
        FillHashTable(&hash_table, input_file, n_words);
        // HashTableDump(hash_table);

        // fprintf(output_file, "%7s, ", hash_functions_names[hash_func_i]);

        for (int list_i = 0; list_i < hash_table.size; list_i++)
            fprintf(output_file, "%ld, ", hash_table.lists[list_i].size);
        fseek(output_file, -2, SEEK_CUR);
        fprintf(output_file, "\n");

        HashTableDtor(&hash_table);
    }

    fclose(output_file);

    // List list = {};
    // ListCtor(&list);
    // char* str = (char*) calloc(HASH_MAX_STRLEN, sizeof(char));
    // sprintf(str, "%s", "aboba");
    // // printf("%s\n", str);
    // ListPushBack(&list, str);
    // int flag = FindInList(&list, str);
    // printf("%d\n", flag);
    // ListDtor(&list);

//     fscanf(input_file, "%d", &n_words);
//     fgetc(input_file);
//     HashTableCtor(&hash_table, hash_table_size, hash_functions.funcs[6]);
//     FillHashTable(&hash_table, input_file, n_words);
//
//     for (int loop = 0; loop < 1; loop++)
//     {
//         fscanf(input_file, "%d", &n_words);
//         fgetc(input_file);
//
//         int counter = 0;
//
//         for (int word_i = 0; word_i < n_words; word_i++)
//         {
//             char* str = (char*) calloc(HASH_MAX_STRLEN, sizeof(char));
//             assert(str);
//
//             fscanf(input_file, "%s ", str);
//
//             int flag = FindInHashTable(str, &hash_table);
//             if (flag) counter++;
//
//             free(str);
//         }
//
//         printf("%d\n", counter);
//
//         fseek(input_file, 0, SEEK_SET);
//     }
//
//     HashTableDtor(&hash_table);
    fclose(input_file);

    ShowGraphs();

    return 1;
}

static void PrepareData()
{
    system("cd ./Data; make; cd ../");
}

static void ShowGraphs()
{
    system("cd ./Graphs; make; cd ../");
}
