#include "../Include/Config.h"
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include "../Include/Constants.h"
#include "../Include/DefineColourConsts.h"
#include "../Include/Assert.h"
#include "../Include/List.h"

//DSL
#define DATA      list->data
#define STATUS    list->status
#define TAIL_IND  list->tail_index
#define HEAD_IND  list->head_index
#define SIZE      list->size
#define CAPACITY  list->capacity
#define FREE      list->free
#define IS_LINEAR list->is_linear

#ifdef NDEBUG
#undef  ASSERT
#define ASSERT( condition ) {}
#endif

#define PrintError( msg )                           \
                                                    \
    fprintf(stderr, KYEL "\"%s\"" KNRM ": %s\n",    \
            __PRETTY_FUNCTION__, msg);              \

#define ListVerify_                                 \
                                                    \
    if(ListVerify(list) != LIST_IS_OK_STATUS)       \
    {                                               \
        PrintError("List is damaged\n");            \
        return 0;                                   \
    }

#define ListVerifyStatus_                           \
                                                    \
    int status = ListVerify(list);                  \
                                                    \
    if (status != LIST_IS_OK_STATUS)                \
    {                                               \
        PrintError("List is damaged");              \
        return status;                              \
    }

#define PhysIndexVerify_                                \
                                                        \
    if (((phys_index == 0) && (phys_index != HEAD_IND)) \
          || (phys_index > CAPACITY))                   \
    {                                                   \
        PrintError("Wrong index")                       \
        return 0;                                       \
    }

int ListCtor(List* list)
{
    ASSERT(list != nullptr);

    SIZE      = 0;
    CAPACITY  = LIST_MIN_CAPACITY;

    HEAD_IND  = 0;
    TAIL_IND  = 0;
    FREE      = 1;

    IS_LINEAR = true;

    DATA = (ListElem*) calloc(CAPACITY + 1, sizeof(ListElem));
    ASSERT(DATA != nullptr);

    DATA[0] = {(Value_t) LIST_ELEM_POISONED_VALUE, 0, 0};

    for (int index = 1; index <= CAPACITY; index++)
    {
        DATA[index] =
        {
            (Value_t) LIST_ELEM_POISONED_VALUE,
            DATA[index].next = index + 1,
            DATA[index].prev = LIST_ELEM_FREE,
        };
    }

    DATA[CAPACITY].next = 0;

    ListVerifyStatus_

    return LIST_IS_OK_STATUS;
}

static void ListValueDtor(const char* value) {ASSERT(value); free((void*)value);}
static void ListValueDtor(int         value) {}
static void ListValueDtor(float       value) {}
static void ListValueDtor(char        value) {}
static void ListValueDtor(double      value) {}

int ListDtor(List* list)
{
    ListVerifyStatus_

    int size = list->size;
    for (int elem_i = 1; elem_i <= size; elem_i++, (list->size)--)
    {
        // fprintf(stderr, "%s", list->data[elem_i].value);
        ListValueDtor(list->data[elem_i].value);
        list->data[elem_i].value = nullptr;
    }

    free(DATA);
    DATA = nullptr;

    STATUS = LIST_IS_DESTRUCTED_STATUS;
    CAPACITY = LIST_DEAD_CAPACITY;
    FREE = LIST_DEAD_FREE;
    SIZE = LIST_DEAD_SIZE;
    HEAD_IND = LIST_DEAD_HEAD_IND;
    TAIL_IND = LIST_DEAD_HEAD_IND;

    return LIST_IS_DESTRUCTED_STATUS;
}

int ListVerify(List* list)
{
    int list_status = LIST_IS_OK_STATUS;

    if (list == nullptr)
    {
        list_status = LIST_IS_NULL_STATUS;
        PrintError("List is null");
    }

    if (DATA == nullptr)
    {
        list_status = LIST_DATA_IS_NULL_STATUS;
        PrintError("List data is null");
    }

    if (STATUS == LIST_IS_DESTRUCTED_STATUS)
    {
        list_status = LIST_IS_DESTRUCTED_STATUS;
        PrintError("List is destructed");
    }

    if (SIZE > CAPACITY)
    {
        list_status = LIST_OVERFLOW_STATUS;
        PrintError("List size > capacity");
    }

    if (HEAD_IND > CAPACITY)
    {
        list_status = HEAD_IND_WRONG_STATUS;
        PrintError("List head index > capacity");
    }

    if (TAIL_IND > CAPACITY)
    {
        list_status = TAIL_IND_WRONG_STATUS;
        PrintError("List tail index < capactiy");
    }

    if (FREE > CAPACITY)
    {
        list_status = LIST_FREE_WRONG_STATUS;
        PrintError("List free index > capacity");
    }

    if (IS_LINEAR > 1)
    {
        list_status = LIST_IS_LINEAR_WRONG_STATUS;
        PrintError("List linear status is wrong");
    }

    STATUS = list_status;

    if (list_status != LIST_IS_OK_STATUS)
        return list_status;

    return LIST_IS_OK_STATUS;
}

int ListFullVerify (List* list)
{
    int list_status = ListVerify(list);

    if (list_status == LIST_IS_OK_STATUS)
        return list_status;

    if (DATA[HEAD_IND].prev != 0)
    {
        list_status = LIST_HEAD_IS_WRONG_STATUS;
        PrintError("List head element is wrong");
    }

    if (DATA[TAIL_IND].next != 0)
    {
        list_status = LIST_TAIL_IS_WRONG_STATUS;
        PrintError("List tail element is wrong");
    }

    if (SIZE >= 1)
    {
        size_t index = HEAD_IND;

        while (DATA[index].next != 0)
        {
            if ((index != HEAD_IND) && (index != TAIL_IND))
            {
                if (DATA[DATA[index].next].prev != index)
                {
                    PrintError("List is damaged");
                    list_status = LIST_IS_SOMEWHERE_WRONG_STATUS;
                }
            }

            index = DATA[index].next;
        }
    }

    STATUS = list_status;

    return list_status;
}

static int IsListEmpty(List* list)
{
    ListVerifyStatus_

    if (SIZE)
        return LIST_IS_OK_STATUS;

    return LIST_IS_EMPTY_STATUS;
}

static void PrintListElemValue(FILE* file, int value)
{
    ASSERT(file != nullptr);

    fprintf(file, "%d", value);
}

static void PrintListElemValue(FILE* file, char value)
{
    ASSERT(file != nullptr);

    fprintf(file, "%c", value);
}

static void PrintListElemValue(FILE* file, double value)
{
    ASSERT(file != nullptr);

    fprintf(file, "%lf", value);
}

static void PrintListElemValue(FILE* file, const char* value)
{
    ASSERT(file != nullptr);

    fprintf(file, "%s", value);
}

static void PrintListElemValue(FILE* file, float value)
{
    ASSERT(file != nullptr);

    fprintf(file, "%f", value);
}

int ListTextDump(List* list, FILE* file)
{
    ListVerifyStatus_

    ASSERT(file != nullptr);

    if (file != stdout)
    {
        #include "../Include/UndefColourConsts.h"
    }

    fprintf(file, KYEL "  %s:\n\n" KNRM, __PRETTY_FUNCTION__);

    fprintf(file, KBLU "\tsize      " KNRM "= %ld\n"
                  KBLU "\tcapacity  " KNRM "= %ld\n"
                  KBLU "\tis_linear " KNRM "= %d \n"
                  KBLU "\thead_ind  " KNRM "= %ld\n"
                  KBLU "\ttail_ind  " KNRM "= %ld\n"
                  KBLU "\tfree      " KNRM "= %ld\n\n", SIZE, CAPACITY, IS_LINEAR, HEAD_IND, TAIL_IND, FREE);

    fprintf(file, KBLU "\tdata = " KNRM "{\n");

    for (size_t index = 1; index <= CAPACITY; index++)
    {
        fprintf(file, "\t\t[" KCYN "%02ld" KNRM "]: ", index);

        if (DATA[index].value != (Value_t) LIST_ELEM_POISONED_VALUE)
            PrintListElemValue(file, DATA[index].value);

        else fprintf(file, "NULL (" KMAG "POISON" KNRM ")");

        fprintf(file, "\n");
    }

    fprintf(file, "\t}\n");

    fprintf(file, KBLU "\n\tnext " KNRM "= {\n");

    for (size_t index = 1; index <= CAPACITY; index++)
    {
        fprintf(file, "\t\t[" KCYN "%02ld" KNRM "]: ", index);

        fprintf(file, "%ld\n", DATA[index].next);
    }

    fprintf(file, "\t}\n");

    fprintf(file, KBLU "\n\tprev " KNRM "= {\n");

    for (size_t index = 1; index <= CAPACITY; index++)
    {
        fprintf(file, "\t\t[" KCYN "%02ld" KNRM "]: ", index);

        if (DATA[index].prev != LIST_ELEM_FREE)
            fprintf(file, "%ld\n", DATA[index].prev);

        else fprintf(file, "%X (" KMAG "POISON" KNRM ")\n", LIST_ELEM_FREE);
    }

    fprintf(file, "\t}\n\n");

    if (file != stdout)
    {
        #include "../Include/DefineColourConsts.h"
    }

    return 1;
}

static const char* PickColour(List* list, size_t phys_index)
{
    if ((phys_index == TAIL_IND) && (phys_index == HEAD_IND))
        return "pink";

    if (phys_index == TAIL_IND)
        return "lightblue";

    if (phys_index = HEAD_IND)
        return "lightgreen";

    if (DATA[phys_index].value)
        return "lightgrey";

    return "yellow";
}

int ListGraphDump(List* list, size_t* DumpAmnt, const char* head_text)
{
    ListVerifyStatus_

    (*DumpAmnt)++;

    // if (IsListEmpty(list) == LIST_IS_EMPTY_STATUS)
    // {
    //     PrintError("List is empty");
    //     return LIST_IS_EMPTY_STATUS;
    // }

    FILE* file_dot = fopen("./ListDump/TextForGraphDump", "w");

    fprintf(file_dot, "digraph G{\n"
                      "    rankdir = LR;\n"
                      "    node[ colour = black, shape = rectangle, fontsize = 12 ];\n"
                      "    edge[ colour = black ];\n");

//     fprintf(file_dot, "    index0 [ label = \" 0 \" ];\n");
//     fprintf(file_dot, "    node0 [ style = filled, fillcolor = pink ];\n");
//     fprintf(file_dot, "    index0 -> node0 [ color = white ];\n");
//
//     for (size_t phys_index = 1; phys_index <= CAPACITY; phys_index++)
//     {
//         fprintf(file_dot, "    node%ld [ shape = record, style = filled, label = \" value:\\n", phys_index);
//         PrintListElemValue(file_dot, DATA[phys_index].value);
//         fprintf(file_dot, "| <prev> prev:\\n%ld | <next> next:\\n%ld \"];\n", (DATA[phys_index].prev == LIST_ELEM_FREE ? -1 : DATA[phys_index].prev), DATA[phys_index].next);
//         fprintf(file_dot, "    index%ld [ label = \" %ld \" ];\n", phys_index, phys_index);
//         fprintf(file_dot, "    index%ld -> node%ld [ color = white ];\n", phys_index, phys_index);
//     }
//
//     fprintf(file_dot, "    { rank = same; ");
//
//     for (size_t phys_index = 0; phys_index <= CAPACITY; phys_index++)
//         fprintf(file_dot, "index%ld; ", phys_index);
//
//     fprintf(file_dot, " };\n");
//
//     fprintf(file_dot, "    head [style = filled, color = lightgreen];\n");
//     fprintf(file_dot, "    tail [style = filled, color = lightblue];\n");
//     fprintf(file_dot, "    free [style = filled, color = yellow];\n");
//
//     fprintf(file_dot, "    { rankdir = same; head; tail; free; };\n");
//
//     fprintf(file_dot, "    head -> node%ld;\n", HEAD_IND);
//     fprintf(file_dot, "    tail -> node%ld\n", TAIL_IND);
//     fprintf(file_dot, "    free -> node%ld;\n", FREE);


    fprintf(file_dot, "    node0 [ style = filled, color = lightgrey ];\n");
    fprintf(file_dot, "    index0 [ label = \" 0 \" ];\n");
    fprintf(file_dot, "    { rank = same; node0; index0 };\n");

    for (size_t phys_index = 1; phys_index <= CAPACITY; phys_index++)
    {
        fprintf(file_dot, "    node%ld [shape = record, style = filled, fillcolor = %s, label = \" value:\\n", phys_index, PickColour(list, phys_index));
        PrintListElemValue(file_dot, DATA[phys_index].value);
        fprintf(file_dot, " | <prev> prev:\\n%ld | <next> next:\\n%ld \"];\n", (DATA[phys_index].prev == LIST_ELEM_FREE ? -1 : DATA[phys_index].prev), DATA[phys_index].next);
        fprintf(file_dot, "    index%ld [ label = \" %ld \" ];\n", phys_index, phys_index);
        fprintf(file_dot, "    { rank = same; index%ld; node%ld };\n", phys_index, phys_index);
    }

    for (size_t phys_index = 0; phys_index < CAPACITY; phys_index++)
    {
        fprintf(file_dot, "    index%ld -> index%ld [color = white];\n", phys_index, phys_index + 1);
    }

    // fprintf(file_dot, "    index%ld [ label = \" %ld \" ];\n", phys_index, phys_index);
    // fprintf(file_dot, "    { rank = same; index%ld; node%ld };\n", phys_index, phys_index);

    fprintf(file_dot, "    head [style = filled, color = lightgreen];\n");
    fprintf(file_dot, "    tail [style = filled, color = lightblue];\n");
    fprintf(file_dot, "    free [style = filled, color = yellow];\n");

    for (size_t phys_index = 1; phys_index <= CAPACITY; phys_index++)
    {
        if (DATA[phys_index].next != 0)
            fprintf(file_dot, "    node%ld: <next> -> node%ld: <next>;\n", phys_index, DATA[phys_index].next);

        if ((DATA[phys_index].prev != LIST_ELEM_FREE) && (DATA[phys_index].prev != 0))
            fprintf(file_dot, "    node%ld: <prev> -> node%ld: <prev> [arrowtail = back];\n", DATA[phys_index].prev, phys_index);
    }

    fprintf(file_dot, "    index%ld -> head;\n", HEAD_IND);
    fprintf(file_dot, "    index%ld -> tail;\n", TAIL_IND);
    fprintf(file_dot, "    index%ld -> free;\n", FREE);

    fprintf(file_dot, "    { rank = same; node%ld; head };\n", HEAD_IND);
    fprintf(file_dot, "    { rank = same; node%ld; tail };\n", TAIL_IND);
    fprintf(file_dot, "    { rank = same; node%ld; free };\n", FREE);


//     size_t phys_index = ListHead(list);
//     size_t log_index = 0;
//     fprintf(file_dot, "    node0 [style = filled, color = lightblue, colour = black, shape = record, label = \" <phys_index> phys_index:\\n%d | <log_index> log_index:\\n%ld | value:\\n%d | <prev> prev:\\n%d | <next> next:\\n%d }\"];\n", 0, log_index++, 0, 0, 0);
//     fprintf(file_dot, "    node%ld [shape = record, label = \" <phys_index> phys_index:\\n%ld | <log_index> log_index:\\n%ld | value:\\n", phys_index, phys_index, log_index++);
//     PrintListElemValue(file_dot, DATA[phys_index].value);
//     fprintf(file_dot, " | <prev> prev:\\n%ld | <next> next:\\n%ld \"];\n", DATA[phys_index].prev, DATA[phys_index].next);
//
//     while ((phys_index = ListNext(list, phys_index)) != 0)
//     {
//         fprintf(file_dot, "    node%ld [shape = record, label = \" <phys_index> phys_index:\\n%ld | <log_index> log_index:\\n%ld | value:\\n", phys_index, phys_index, log_index++);
//         PrintListElemValue(file_dot, DATA[phys_index].value);
//         fprintf(file_dot, " | <prev> prev:\\n%ld | <next> next:\\n%ld \"];\n", DATA[phys_index].prev, DATA[phys_index].next);
//     }
//
//     phys_index = ListHead(list);
//     // fprintf(file_dot, "    node0: <next> -> node%ld: <next>;\n", phys_index);
//     fprintf(file_dot, "    node%ld: <prev> -> node0: <prev>;\n", phys_index);
//     fprintf(file_dot, "    node%ld: <next> -> node%ld: <next>;\n", phys_index, DATA[phys_index].next);
//     fprintf(file_dot, "    node%ld: <prev> -> node%ld: <prev>;\n", DATA[phys_index].next, phys_index);
//
//     // for (size_t index = 1; index <= CAPACITY; index++)
//     while ((phys_index = ListNext(list, phys_index)) != 0)
//     {
//         // if (list->data[index].next != 0)
//             fprintf(file_dot, "    node%ld: <next> -> node%ld: <next>;\n", phys_index, DATA[phys_index].next);
//
//         // if ((DATA[index].prev != LIST_ELEM_FREE) && (DATA[index].prev != 0))
//             fprintf(file_dot, "    node%ld: <prev> -> node%ld: <prev>;\n", DATA[phys_index].next, phys_index);
//     }
//
// //     for (size_t index = 0; index <= CAPACITY; index++)
// //     {
// //         // if (list->data[index].next != 0)
// //             fprintf(file_dot, "    node%ld: <next> -> node%ld: <next>;\n", index, DATA[index].next);
// //
// //         // if ((DATA[index].prev != LIST_ELEM_FREE) && (DATA[index].prev != 0))
// //             fprintf(file_dot, "    node%ld: <prev> -> node%ld: <prev>;\n", DATA[index].prev, index);
// //     }

    fprintf(file_dot, "}\n");

    fclose(file_dot);

    char* dump_comand = (char*) calloc(100, sizeof(char));
    sprintf(dump_comand, "dot ./ListDump/TextForGraphDump -Tsvg -o ./ListDump/GraphDumpImages/GraphDump%ld.svg", *DumpAmnt);
    system(dump_comand);
    free(dump_comand);

    FILE* file_html = NULL;

    if (*DumpAmnt != 1)
        file_html = fopen("./ListDump/FullDump.html", "a");

    else
        file_html = fopen("./ListDump/FullDump.html", "w+");

    fseek(file_html, 0, SEEK_SET);

    fprintf(file_html, "<pre>\n");
    fprintf(file_html, "    <h1> ListFullDump: %s </h1>\n", head_text);

    // #include "./UndefColourConsts.h"
    ListTextDump(list, file_html);
    // #include "./DefineColourConsts.h"

    fprintf(file_html,  "    \n"
                        "        <img src = \"./GraphDumpImages/GraphDump%ld.svg\">\n"
                        "    <hr>\n"
                        "<!-- ------------------------------------------------------------ -->\n", *DumpAmnt);

    fprintf(file_html, "</pre>\n\n");

    fclose(file_html);

    return LIST_IS_OK_STATUS;
}

size_t ListFindElemIndexByLogIndex(List* list, size_t log_index) //C-r-I-n-G-e
{
    ListVerify_

    if ((log_index == 0) || (log_index > SIZE))
    {
        PrintError("Wrong index");
        return 0;
    }

    if (IS_LINEAR)
        return HEAD_IND + log_index - 1;

    size_t phys_index = HEAD_IND;
    int    elem_i_index = 1;

    while (elem_i_index++ < log_index)
        phys_index = DATA[phys_index].next;

    return phys_index;
}

size_t ListNext(List* list, size_t phys_index)
{
    ListVerify_
    PhysIndexVerify_

    return DATA[phys_index].next;
}

size_t ListPrev(List* list, size_t phys_index)
{
    ListVerify_
    PhysIndexVerify_

    return DATA[phys_index].prev;
}

size_t ListHead(List* list)
{
    ListVerify_

    return HEAD_IND;
}

size_t ListTail(List* list)
{
    ListVerify_

    return TAIL_IND;
}

size_t ListInsertAfter(List* list, size_t phys_index, Value_t value)
{
    ListVerify_

    if ((phys_index > CAPACITY) ||
        ((DATA[phys_index].prev == LIST_ELEM_FREE) && ((SIZE > 0) || (phys_index != HEAD_IND))))
    {
        PrintError("Wrong index");
        return 0;
    }

    if (FREE == 0)
    {
        if (ListResize(list, INCREASE_LIST_CAPACITY_MODE) != LIST_IS_OK_STATUS)
            return 0;
    }

    size_t new_elem_index = FREE;
    FREE = DATA[FREE].next;

    // fprintf(stdout, "Dump before insert:\n");
    // ListTextDump(list);

    if ((phys_index == HEAD_IND) && (phys_index == TAIL_IND) && (SIZE == 0))
    {
        DATA[new_elem_index]= {value, 0, 0};

        TAIL_IND = new_elem_index;
        HEAD_IND = new_elem_index;
    }

    else if (phys_index == TAIL_IND)
    {
        if (new_elem_index != TAIL_IND + 1)
            IS_LINEAR = false;

        DATA[TAIL_IND].next = new_elem_index;
        DATA[new_elem_index] = {value, 0, TAIL_IND};

        TAIL_IND = new_elem_index;
    }

    else
    {
        IS_LINEAR = false;

        if (phys_index != 0)
        {
            DATA[new_elem_index] = {value, DATA[phys_index].next, phys_index};
            DATA[DATA[phys_index].next].prev = new_elem_index;
            DATA[phys_index].next = new_elem_index;
        }

        else
        {
            DATA[new_elem_index] = {value, HEAD_IND, 0};
            DATA[HEAD_IND].prev = new_elem_index;
            HEAD_IND = new_elem_index;
        }
    }

    SIZE++;

    // fprintf(stdout, "Dump after insert:\n");
    // ListTextDump(list);

    ListVerify_

    return new_elem_index;
}
//
// size_t List::InsertAfter(size_t phys_index, Value_t value)
// {
//     ListVerify_
//
//     if ((phys_index > this->capacity) ||
//         ((data[phys_index].prev == LIST_ELEM_FREE) && ((size > 0) || (phys_index != HEAD_IND))))
//     {
//         PrintError("Wrong index");
//         return 0;
//     }
//
//     if (FREE == 0)
//     {
//         if (ListResize(list, INCREASE_LIST_CAPACITY_MODE) != LIST_IS_OK_STATUS)
//             return 0;
//     }
//
//     size_t new_elem_index = FREE;
//     FREE = DATA[FREE].next;
//
//     // fprintf(stdout, "Dump before insert:\n");
//     // ListTextDump(list);
//
//     if ((phys_index == HEAD_IND) && (phys_index == TAIL_IND) && (SIZE == 0))
//     {
//         DATA[new_elem_index]= {value, 0, 0};
//
//         TAIL_IND = new_elem_index;
//         HEAD_IND = new_elem_index;
//     }
//
//     else if (phys_index == TAIL_IND)
//     {
//         if (new_elem_index != TAIL_IND + 1)
//             IS_LINEAR = false;
//
//         DATA[TAIL_IND].next = new_elem_index;
//         DATA[new_elem_index] = {value, 0, TAIL_IND};
//
//         TAIL_IND = new_elem_index;
//     }
//
//     else
//     {
//         IS_LINEAR = false;
//
//         if (phys_index != 0)
//         {
//             DATA[new_elem_index] = {value, DATA[phys_index].next, phys_index};
//             DATA[DATA[phys_index].next].prev = new_elem_index;
//             DATA[phys_index].next = new_elem_index;
//         }
//
//         else
//         {
//             DATA[new_elem_index] = {value, HEAD_IND, 0};
//             DATA[HEAD_IND].prev = new_elem_index;
//             HEAD_IND = new_elem_index;
//         }
//     }
//
//     SIZE++;
//
//     // fprintf(stdout, "Dump after insert:\n");
//     // ListTextDump(list);
//
//     ListVerify_
//
//     return new_elem_index;
// }

size_t ListInsertBefore(List* list, size_t phys_index, Value_t value)
{
    ListVerify_

    if ((phys_index == 0) || (phys_index > CAPACITY) ||
        ((DATA[phys_index].prev == LIST_ELEM_FREE) && ((SIZE > 0) || (phys_index == HEAD_IND))))
    {
        PrintError("Wrong index");
        return 0;
    }

    if ((HEAD_IND == TAIL_IND) && (SIZE == 0))
        return ListInsertAfter(list, phys_index, value);

    if (FREE == 0)
    {
        if (ListResize(list, INCREASE_LIST_CAPACITY_MODE) != LIST_IS_OK_STATUS)
            return 0;
    }

    IS_LINEAR = false;

    if (phys_index == HEAD_IND)
    {
        size_t new_elem_index = FREE;
        FREE = DATA[FREE].next;

        DATA[HEAD_IND].prev = new_elem_index;
        DATA[new_elem_index] = {value, HEAD_IND, 0};

        HEAD_IND = new_elem_index;

        SIZE++;

        return new_elem_index;
    }

    else
        return ListInsertAfter(list, DATA[phys_index].prev, value);
}

Value_t ListErase(List* list, size_t phys_index)
{
    ListVerify_
    PhysIndexVerify_

    if (DATA[phys_index].prev == LIST_ELEM_FREE)
    {
        PrintError("Wrong index");
        return (Value_t) LIST_ELEM_POISONED_VALUE;;
    }

    if (SIZE == 0)
    {
        PrintError("List is empty, can't delete element");
        return (Value_t) LIST_ELEM_POISONED_VALUE;
    }

    Value_t deleted_value = DATA[phys_index].value;

    if ((phys_index == HEAD_IND) && (phys_index == TAIL_IND))
    {
        DATA[phys_index] = {(Value_t) LIST_ELEM_POISONED_VALUE, FREE, LIST_ELEM_FREE};

        HEAD_IND = 0;
        TAIL_IND = 0;
        FREE = phys_index;
    }

    else if (phys_index == HEAD_IND)
    {
        size_t new_head_ind = DATA[HEAD_IND].next;

        DATA[new_head_ind].prev  = 0;
        DATA[HEAD_IND] = {(Value_t) LIST_ELEM_POISONED_VALUE, FREE, LIST_ELEM_FREE};

        FREE = HEAD_IND;
        HEAD_IND = new_head_ind;
    }

    else if (phys_index == TAIL_IND)
    {
        size_t new_tail_ind = DATA[TAIL_IND].prev;

        DATA[new_tail_ind].next = 0;
        DATA[TAIL_IND] = {(Value_t) LIST_ELEM_POISONED_VALUE, FREE, LIST_ELEM_FREE};

        FREE = TAIL_IND;
        TAIL_IND = new_tail_ind;
    }

    else
    {
        IS_LINEAR = false;

        DATA[DATA[phys_index].prev].next = DATA[phys_index].next;
        DATA[DATA[phys_index].next].prev = DATA[phys_index].prev;
        DATA[phys_index] = {(Value_t) LIST_ELEM_POISONED_VALUE, FREE, LIST_ELEM_FREE};
        FREE = phys_index;
    }

    SIZE--;

    if ((SIZE <= CAPACITY / 2) && (CAPACITY > LIST_MIN_CAPACITY))
    {
        if (ListResize(list, DECREASE_LIST_CAPACITY_MODE) != LIST_IS_OK_STATUS)
            return (Value_t) LIST_ELEM_POISONED_VALUE;
    }

    return deleted_value;
}

Value_t ListPopBack(List* list)
{
    return ListErase(list, TAIL_IND);
}

int ListPushBack(List* list, Value_t value)
{
    return ListInsertAfter(list, TAIL_IND, value);
}

Value_t ListPopFront(List* list)
{
    return ListErase(list, HEAD_IND);
}

int ListPushFront(List* list, Value_t value)
{
    return ListInsertAfter(list, 0, value);;
}

int ListLinearize(List* list)
{
    ListVerifyStatus_

    if (!IS_LINEAR)
    {
        ListElem* new_data = (ListElem*) calloc(CAPACITY + 1, sizeof(ListElem));
        ASSERT(new_data != nullptr);

        new_data[0] = {(Value_t) LIST_ELEM_POISONED_VALUE, 0, 0};

        FREE = 0;

        size_t data_index = ListHead(list);

        for (size_t new_index = 1; new_index <= CAPACITY; new_index++)
        {
            if (data_index != 0)
                new_data[new_index] = {DATA[data_index].value, (new_index == CAPACITY ? 0 : new_index + 1), new_index - 1};

            else
            {
                if (FREE == 0) FREE = new_index;

                new_data[new_index] = {(Value_t) LIST_ELEM_POISONED_VALUE, (new_index == CAPACITY ? 0 : new_index + 1), LIST_ELEM_FREE};
                data_index = FREE;
            }

            data_index = ListNext(list, data_index);
        }

        for (size_t free_elem_index = FREE; free_elem_index <= CAPACITY; free_elem_index++)
            new_data[free_elem_index].prev = LIST_ELEM_FREE;

        free(DATA);

        DATA = new_data;
        IS_LINEAR = true;
        HEAD_IND = (SIZE == 0 ? 0 : 1);
        TAIL_IND = (SIZE == 0 ? 0 : SIZE);
        DATA[TAIL_IND].next = 0;

        // fprintf(stdout, "Dump after Linearization:\n");
        // ListTextDump(list);
    }

    return LIST_IS_OK_STATUS;
}

int ListClear(List* list)
{
    ListVerifyStatus_

    while (SIZE > 0)
        ListPopBack(list) == (Value_t) LIST_ELEM_POISONED_VALUE;

    return LIST_IS_OK_STATUS;
}

static void FindNullFreeElem(List* list, size_t new_free)
{
    size_t free_elem_index = FREE;

    while (DATA[free_elem_index].next != 0)
        free_elem_index = DATA[free_elem_index].next;

    DATA[free_elem_index].next = new_free;
}

int ListResize(List* list, int resize_mode)
{
    ListVerifyStatus_

    size_t new_capacity = CAPACITY;
    ListElem* new_data = nullptr;
    size_t new_free = FREE;

    if(resize_mode == INCREASE_LIST_CAPACITY_MODE)
    {
        if ((new_capacity *= 2) > LIST_MAX_CAPACITY)
        {
            PrintError("Size can't be more than MAX_CAPACITY");
            return 0;
        }

        new_free = CAPACITY + 1;

        new_data = (ListElem*) realloc(DATA, (new_capacity + 1) * sizeof(ListElem));
        ASSERT(new_data != nullptr);

        if (SIZE != 0)
        {
            size_t elem_index = HEAD_IND;

            while (new_data[elem_index].next != 0)
                elem_index = DATA[elem_index].next;

            if (FREE == 0)
            {
                FREE = new_free;
                new_data[elem_index].next = FREE;
            }

            else FindNullFreeElem(list, new_free);
        }

        // fprintf(stdout, "%ld\n", FREE);

        else FindNullFreeElem(list, new_free);

        for (size_t index = FREE; index <= new_capacity; index++)
            new_data[index] = {(Value_t) LIST_ELEM_POISONED_VALUE, index + 1, LIST_ELEM_FREE};

        new_data[new_capacity].next = 0;

        // for (size_t i = 1; i <= new_capacity; i++)
            // fprintf(stdout, "%ld: %s\n", i, new_data[i].value);
    }

    else if (resize_mode == DECREASE_LIST_CAPACITY_MODE)
    {
        if ((new_capacity /= 2) < LIST_MIN_CAPACITY)
            return LIST_IS_OK_STATUS;

        if ((IS_LINEAR == false) || ((IS_LINEAR == true)  && (TAIL_IND > new_capacity)))
        {
            if (ListLinearize(list) != LIST_IS_OK_STATUS)
                return 0;
        }

        // fprintf(stdout, "Dump while resize:\n");
        // ListTextDump(list);

        FREE = 0;

        for (size_t index = new_capacity; index >= 1; index--)
        {
            if (DATA[index].prev == LIST_ELEM_FREE)
            {
                if (FREE == 0)
                {
                    FREE = index;
                    DATA[index].next = 0;
                }
                else
                {
                    DATA[index].next = FREE;
                    FREE = index;
                }
            }
        }

        DATA[TAIL_IND].next = 0;

        new_data = (ListElem*) realloc(DATA, (new_capacity + 1) * sizeof(ListElem));
        ASSERT(new_data != nullptr);
    }

    else
    {
        PrintError("Wrong resize mode");
        return WRONG_RESIZE_MODE;
    }

    CAPACITY = new_capacity;
    DATA     = new_data;

    // fprintf(stdout, "Dump after resize:\n");
    // ListTextDump(list);

    return ListVerify(list);
}

int ListPrint(List* list)
{
    ListVerifyStatus_

    if (IsListEmpty(list) == LIST_IS_EMPTY_STATUS)
    {
        // PrintError("List is empty");
        fprintf(stdout, "--\n");
        return LIST_IS_EMPTY_STATUS;
    }

    size_t index = ListHead(list);
    fprintf(stdout, "\"");
    PrintListElemValue(stdout, DATA[index].value);
    fprintf(stdout, "\"");

    for (size_t i = 1; i < SIZE; i++)
    {
        index = ListNext(list, index);
        fprintf(stdout, ", \"");
        PrintListElemValue(stdout, DATA[index].value);
        fprintf(stdout, "\"");
    }

    fprintf(stdout, "\n");

    return LIST_IS_OK_STATUS;
}

static int CmpListValue(const char* value1, const char* value2)
{
    ASSERT(value1);
    ASSERT(value2);
    // printf("%s VS %s\n", value1, value2);

    return strcmp(value1, value2);
}

static int CmpListValue(int value1, int value2)
{
    return value1 == value2;
}

static int CmpListValue(float value1, float value2)
{
    return value1 == value2;
}

static int CmpListValue(char value1, char value2)
{
    return value1 == value2;
}

static int CmpListValue(double value1, double value2)
{
    return value1 == value2;
}

int FindInList(List* list, Value_t value)
{
    ListVerifyStatus_

    for (size_t elem_i = 1; elem_i <= list->size; elem_i++)
    {
        // PrintListElemValue(stdout, list->data[elem_i].value);
        // printf("\n");

        if (!CmpListValue(value, list->data[elem_i].value)) return 1;
    }

    return 0;
}
