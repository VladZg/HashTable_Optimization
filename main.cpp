#include "./Include/Config.h"
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include "./Libs/List/Include/List.h"
#include "./Include/HashTable.h"
#include "./Include/HashFunctions.h"

int main()
{
    system("cd ./Data; make; cd ../");

    FILE* input_file = fopen("./Data/input_text_parsed.txt", "r");
    FILE* output_file = fopen("./Graphs/data.csv", "w");

    HashTable hash_table = {};

    HashFunc hash_functions_set[N_HASH_FUNCTIONS] = {HashConst, HashLen, HashFirstSymb, HashSum};
    // const char hash_functions_names[N_HASH_FUNCTIONS][10] = {"const", "length", "ascii", "sum"};
    HashFunctions hash_functions = {N_HASH_FUNCTIONS, hash_functions_set};
    // hash_functions.func_names = hash_functions_names;

    int n_words = 0;
    fscanf(input_file, "%d", &n_words);
    fgetc(input_file);

    for (int hash_func_i = 0; hash_func_i < N_HASH_FUNCTIONS; hash_func_i++)
    {
        HashTableCtor(&hash_table);
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

    return 1;
}
