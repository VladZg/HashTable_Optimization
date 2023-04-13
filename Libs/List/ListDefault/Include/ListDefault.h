#include "./Config.h"
#include <stdlib.h>
#include "./Consts.h"

struct ListElem
{
    Value_t   value;
    ListElem* next;
    ListElem* prev;
};

ListElem* ListCtor       (Value_t value);
int       ListDtor       (ListElem* elem);
ListElem* ListElemInsert (ListElem* elem, Value_t value);
Value_t   ListElemErase  (ListElem* elem);
void      ListPrint      (ListElem* elem);
