#include "../Include/ListDefault.h"
#include <stdlib.h>
#include <cstdio>
#include "../Include/Consts.h"

ListElem* ListElemCtor(Value_t value)
{
    ListElem* root = (ListElem*) calloc(1, sizeof(ListElem));

    *root = {value, NULL, NULL};

    return root;
}

void ListElemDtor(ListElem* root)
{
    free(root);
    root = NULL;
}

ListElem* ListElemInsert(ListElem* elem, Value_t value)
{
    ListElem* temp = (ListElem*) calloc(1, sizeof(ListElem));
    ListElem* p = elem->next;

    elem->next = temp;
    *temp = {value, p, elem};

    if (p != NULL)
        p->prev = temp;

    return temp;
}

Value_t ListElemErase(ListElem* elem)
{
    ListElem* next = elem->next;
    ListElem* prev = elem->prev;

    if (prev != NULL)
        prev->next = elem->next;

    if (next != NULL)
        next->prev = elem->prev;

    Value_t deleted_value = elem->value;

    free(elem);
    elem = nullptr;

    return deleted_value;
}

void ListPrint(ListElem* elem)
{
    ListElem *cur = elem;

    do
    {
        printf("%lf ", cur->value);
        cur = cur->next;
    }

    while (cur != NULL);

    printf("\n");
}
