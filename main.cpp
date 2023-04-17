#include "./Include/Config.h"
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include "./Libs/List/Include/List.h"
#include "./Include/HashFunctions.h"
#include "./Include/HashTable.h"

int main()
{
    system("cd ./Data; make; cd ../");

    FILE* input_file = fopen("./Data/input_text_parsed.txt", "r");
    assert(input_file);

    int n_words = 0;
    fscanf(input_file, "%d", &n_words);
    fgetc(input_file);

    int hash_table_size = n_words / HASH_TABLE_LIST_SIZE;
    // fprintf(stderr, "%d\n", hash_table_size);

    FILE* output_file = fopen("./Graphs/data.csv", "w");
    assert(output_file);

    HashTable hash_table = {};

    HashFunc hash_functions_set[N_HASH_FUNCTIONS] = {HashConst, HashLen, HashFirstSymb, HashSum, HashRol, HashRol, MyHash};
    // const char hash_functions_names[N_HASH_FUNCTIONS][10] = {"const", "length", "ascii", "sum"};
    HashFunctions hash_functions = {N_HASH_FUNCTIONS, hash_functions_set};
    // hash_functions.func_names = hash_functions_names;

    for (int hash_func_i = 0; hash_func_i < N_HASH_FUNCTIONS; hash_func_i++)
    {
        HashTableCtor(&hash_table, hash_table_size);
        FillHashTable(&hash_table, input_file, n_words, hash_functions.funcs[hash_func_i]);
        // HashTableDump(hash_table);

        // fprintf(output_file, "%s,", hash_functions.func_names[hash_func_i]);

        for (int list_i = 0; list_i < hash_table.size; list_i++)
            fprintf(output_file, "%ld,", hash_table.lists[list_i].size);

        fprintf(output_file, "\n");

        HashTableDtor(&hash_table);
        fseek(input_file, 0, SEEK_SET);
    }

    fclose(input_file);
    fclose(output_file);

    // int a = HashRol("aboba");
    // printf("%d\n", a);

    system("cd ./Graphs; make; cd ../");

    return 1;
}
