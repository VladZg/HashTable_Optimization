#ifndef LIST_H
#define LIST_H

#include "./Config.h"
#include <cstdio>
#include <stdbool.h>
#include <immintrin.h>
#include "./Constants.h"

struct ListElem
{
    Value_t value;
    size_t  next;
    size_t  prev;
};

struct List
{
    ListElem* data;

    size_t  head_index;
    size_t  tail_index;

    size_t  size;
    size_t  capacity;
    size_t  free;

    bool    is_linear;

    int     status;

    // size_t InsertAfter(size_t phys_index, Value_t value);
};

int ListCtor (List* list);
int ListDtor (List* list);

int ListVerify     (List* list);
int ListFullVerify (List* list);
int ListTextDump   (List* list, FILE* file = stdout);
int ListGraphDump  (List* list, size_t* DumpAmnt, const char* head_text);

size_t ListFindElemIndexByLogIndex (List* list, size_t log_index );

size_t ListNext (List* list, size_t phys_index);
size_t ListPrev (List* list, size_t phys_index);

size_t  ListHead (List* list);
size_t  ListTail (List* list);

size_t  ListInsertAfter  (List* list, size_t phys_index, Value_t value);
size_t  ListInsertBefore (List* list, size_t phys_index, Value_t value);
Value_t ListErase        (List* list, size_t phys_index);

Value_t ListPopBack   (List* list);
int     ListPushBack  (List* list, Value_t value);
Value_t ListPopFront  (List* list);
int     ListPushFront (List* list, Value_t value);

int ListLinearize (List* list);

int ListClear  (List* list);
int ListResize (List* list, int resize_mode);

int ListPrint (List* list);

int FindInList(const List* list, Value_t value);
int FindInList_avx2(const List* list, __m256i value);


#endif
