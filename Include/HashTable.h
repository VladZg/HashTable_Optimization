#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "./Config.h"
#include <stdlib.h>
#include "../Libs/List/Include/List.h"

enum HashTableConsts
{
    HASH_TABLE_SIZE = 100,
    HASH_MAX_STRLEN = 255,
};

struct HashTable
{
    size_t size;
    List*  lists;
};

int HashTableCtor(HashTable* hash_table);
int HashTableDtor(HashTable* hash_table);
int HashTableDump(HashTable hash_table);
int FillHashTable(HashTable* hash_table, FILE* source, int n_elems, int (*HashFuction)(const char*));

#endif
