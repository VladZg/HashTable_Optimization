#include "../Include/Config.h"
#include <stdlib.h>
#include "../Include/Consts.h"
#include "../Include/ListDefault.h"

int main()
{
    ListElem* elem1 = ListCtor(1);
    ListElem* elem2 = ListElemInsert(elem1, 2);
    ListElem* elem3 = ListElemInsert(elem1, 1.5);
    ListPrint(elem1);

    return 1;
}
