#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include "./Config.h"
#include <stdlib.h>

typedef int (*HashFunction)(const char* string);

#define N_HASH_FUNCTIONS 4

int HashConst    (const char* string);
int HashLen      (const char* string);
int HashFirstSymb(const char* string);
int HashSum      (const char* string);

// int HashConst(const char* string)
// {
//     return CONSTANT_HASH;
// }


#endif
