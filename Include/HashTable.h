#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "./Config.h"
#include <stdlib.h>
#include "../Libs/List/Include/List.h"
#include "./HashFunctions.h"

enum HashTableConsts
{
    // HASH_TABLE_SIZE      = 100,
    HASH_MAX_STRLEN      = 255,
    HASH_TABLE_LIST_SIZE = 2  ,
};

struct HashTable
{
    size_t size;
    List*  lists;
};

int HashTableCtor(HashTable* hash_table, size_t init_size);
int HashTableDtor(HashTable* hash_table);
int HashTableDump(HashTable hash_table);
int FillHashTable(HashTable* hash_table, FILE* source, int n_elems, int (*HashFuction)(const char*));
int IsElemInHashTable(const char* value, int hash, HashTable* hash_table);

#endif
