#include "./Include/Config.h"
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include "./Libs/List/Include/List.h"
#include "./Include/HashTable.h"
#include "./Include/HashFunctions.h"

int main()
{
    FILE* input_file = fopen("./Data/input_text.txt", "r");
    FILE* output_file = fopen("./Graphs/data.csv", "w");

    fprintf(output_file, "const, length, first, sum\n");

    HashTable hash_table = {};

    HashFunction HashFunctions[N_HASH_FUNCTIONS] = {HashConst, HashLen, HashFirstSymb, HashSum};

    for (int hash_func_i = 0; hash_func_i < N_HASH_FUNCTIONS; hash_func_i++)
    {
        HashTableCtor(&hash_table);
        FillHashTable(&hash_table, input_file, 10, HashFunctions[hash_func_i]);
        // HashTableDump(hash_table);
        HashTableDtor(&hash_table);
        fseek(input_file, 0, SEEK_SET);
    }

    fclose(input_file);
    fclose(output_file);

    return 1;
}
