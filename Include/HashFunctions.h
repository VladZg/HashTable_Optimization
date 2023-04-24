#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include "../Config.h"
#include <stdlib.h>

typedef int (*HashFunc)(const char* value);

#define N_HASH_FUNCTIONS 7

struct HashFunctions
{
    size_t      n_funcs;
    HashFunc*   funcs;
    // const char**  func_names;
};

int HashConst    (const char* value);
int HashLen      (const char* value);
int HashFirstSymb(const char* value);
int HashSum      (const char* value);
int HashRol      (const char* value);
int HashRor      (const char* value);
int MyHash       (const char* value);

#endif
