#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#define CONSTANT_HASH 17

#include "../Include/Config.h"
#include <stdlib.h>
#include <cstring>
#include "../Include/HashFunctions.h"

int HashConst(const char* string)
{
    return CONSTANT_HASH % HASH_TABLE_SIZE;
}

int HashLen(const char* string)
{
    return (int)strlen(string) % HASH_TABLE_SIZE;
}

int HashFirstSymb(const char* string)
{
    return (int)string[0] % HASH_TABLE_SIZE;
}

int HashSum(const char* string)
{
    int hash = 0;
    size_t len = strlen(string);

    for (size_t symbol_i = 0; symbol_i < len; symbol_i++)
        hash+=string[symbol_i];

    return hash % HASH_TABLE_SIZE;
}

#endif
