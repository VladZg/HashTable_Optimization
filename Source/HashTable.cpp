#ifndef HASH_TABLE_CPP
#define HASH_TABLE_CPP

#include "../Config.h"
#include <cassert>
#include <cstring>
#include "../Include/HashFunctions.h"
#include "../Include/HashTable.h"

static void HashTableVerify(HashTable* hash_table)
{
    assert(hash_table);
    assert(hash_table->hash_function);
}

int HashTableCtor(HashTable* hash_table, size_t init_size, int (*hash_function)(const char*))
{
    assert(hash_table);
    assert(hash_function);

    hash_table->n_words = 0;
    hash_table->size = init_size;
    hash_table->hash_function = hash_function;
    hash_table->lists = (List*) calloc(init_size, sizeof(List));
    assert(hash_table->lists);

    List* lists = hash_table->lists;
    for (int list_i = 0; list_i < init_size; list_i++)
        ListCtor(lists + list_i);

    return 1;
}

int HashTableDtor(HashTable* hash_table)
{
    HashTableVerify(hash_table);

    List* lists = hash_table->lists;
    for (int list_i = 0; list_i < hash_table->size; list_i++)
        ListDtor(lists + list_i);

    free(hash_table->lists);
    hash_table->lists = nullptr;
    hash_table->size = 0;
    hash_table->n_words = 0;
    hash_table->hash_function = nullptr;
    hash_table = nullptr;

    return 1;
}

int HashTableDump(HashTable hash_table)
{
    printf("HashTableDump:\n"
           "{\n"             );

    for (size_t list_i = 0; list_i < hash_table.size; list_i++)
    {
        printf("    [%2ld]: ", list_i);

        ListPrint(hash_table.lists + list_i);
    }

    printf("}\n\n");

    return 1;
}

int FillHashTable(HashTable* hash_table, FILE* source, int n_elems)
{
    HashTableVerify(hash_table);
    assert(source);

    for (int elem_i = 0; elem_i < n_elems; elem_i++)
    {
        char* str = (char*) calloc(HASH_MAX_STRLEN, sizeof(char));
        assert(str);

        if (!fscanf(source, "%s", str))
        {
            free(str);
            return 0;
        }

        int hash = hash_table->hash_function(str) % hash_table->size;
        ListPushBack(hash_table->lists + hash, str);
    }

    return 1;
}

// int GetHashTableGraphData(HashFunctions* hash_functions, HashTable* hash_table, FILE* file)
// {
//     for (int hash_func_i = 0; hash_func_i < hash_functions->n_funcs; hash_func_i++)
//     {
//         fprintf(file, "%s,", hash_functions->func_names[hash_func_i]);
//
//         int list_i_size = hash_table->lists[hash_func_i].size;
//         for (int list_i = 0; list_i < hash_table
//     }
//
//     return 1;
// }

int FindInHashTable(const char* value, HashTable* hash_table)
{
    HashTableVerify(hash_table);
    assert(value);
    assert(hash_table->size);

    int hash = hash_table->hash_function(value) % hash_table->size;
    List list = hash_table->lists[hash];

    return FindInList(&list, value);
}

#endif
