#ifndef HASH_FUNCTIONS_CPP
#define HASH_FUNCTIONS_CPP

#include "./Config.h"
#include <stdlib.h>

int HashConst    (const char* string);
int HashLen      (const char* string);
int HashFirstSymb(const char* string);
int HashSum      (const char* string);

// int HashConst(const char* string)
// {
//     return CONSTANT_HASH;
// }


#endif
