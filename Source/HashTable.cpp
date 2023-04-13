#ifndef HASH_TABLE_CPP
#define HASH_TABLE_CPP

#include "../Include/Config.h"
#include <cassert>
#include "../Include/HashTable.h"

int HashTableCtor(HashTable* hash_table)
{
    assert(hash_table);

    hash_table->size = HASH_TABLE_SIZE;
    hash_table->lists = (List*) calloc(HASH_TABLE_SIZE, sizeof(List));
    assert(hash_table->lists);

    List* lists = hash_table->lists;
    for (int list_i = 0; list_i < HASH_TABLE_SIZE; list_i++)
        ListCtor(lists + list_i);

    return 1;
}

int HashTableDtor(HashTable* hash_table)
{
    assert(hash_table);

    List* lists = hash_table->lists;
    for (int list_i = 0; list_i < HASH_TABLE_SIZE; list_i++)
        ListDtor(lists + list_i);

    free(hash_table->lists);
    hash_table->lists = nullptr;
    hash_table->size = 0;
    // *hash_table = nullptr;

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

int FillHashTable(HashTable* hash_table, FILE* source, int n_elems, int (*HashFuction)(const char*))
{
    for (int elem_i = 0; elem_i < n_elems; elem_i++)
    {
        char* str = (char*) calloc(HASH_MAX_STRLEN, sizeof(char));
        fscanf(source, "%s", str);
        if (!str)
        {
            free(str);
            return 0;
        }

        // fprintf(stderr, "%s\n", str);

        int list_i = HashFuction(str);

        ListPushBack(hash_table->lists + list_i, str);
        // ListPrint(hash_table->lists + list_i);
    }

    return 1;
}

#endif
