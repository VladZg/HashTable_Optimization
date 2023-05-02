#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include "../Config.h"
#include <stdlib.h>
#include <immintrin.h>

typedef int (*HashFunc)(const char* value);

#define N_HASH_FUNCTIONS 7

// struct HashFunctions
// {
//     size_t      n_funcs;
//     HashFunc*   funcs;
//     // const char**  func_names;
// };

int ConstHash    (const char* value);
int LenHash      (const char* value);
int FirstSymbHash(const char* value);
int SumHash      (const char* value);
int RolHash      (const char* value);
int RorHash      (const char* value);
int MyHash       (const char* value);
int GnuHash      (const char* value);
// int Crc32Hash    (const char* value);

int GnuHash_asm  (const char* value);
int GnuHash_avx2 (__m256i value);

extern "C" inline int Crc32Hash_asm(const char* value);

#endif
