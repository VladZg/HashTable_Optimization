#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "../Config.h"
#include <stdlib.h>
#include "../Libs/List/Include/List.h"
#include "./HashFunctions.h"

enum HashTableConsts
{
    // HASH_TABLE_SIZE      = 100,
    HASH_MAX_STRLEN      = 20 ,
    HASH_TABLE_LIST_SIZE = 2  ,
    HASH_TABLE_MAX_CAPACITY = 10000,
};

const float HashTableListAvgSize = 1.5;

struct HashTable
{
    size_t n_words;
    size_t size;
    List*  lists;
    int (*hash_function)(const char*);
};

int HashTableCtor(HashTable* hash_table, size_t init_size, int (*hash_function)(const char*));
int HashTableDtor(HashTable* hash_table);
int HashTableDump(const HashTable hash_table);
int FillHashTable(HashTable* hash_table, FILE* source, int n_elems);
int FindInHashTable(const char* value, HashTable hash_table);

#endif
