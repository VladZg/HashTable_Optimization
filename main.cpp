#include "./Include/Config.h"
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include "./Include/HashFunctions.h"

int main()
{
    FILE* input_file = fopen("./Data/input_text.txt", "r");
    FILE* output_file = fopen("./Graphs/data.csv", "w");

    fprintf(output_file, "const, length, first, sum\n");

    for (int word_i = 0; word_i < 10; word_i++)
    {
        char string[20] = {};
        fscanf(input_file, "%s", string);

        fprintf(output_file, "%2d   , %2d    , %2d   , %2d\n", HashConst(string)    ,
                                                              HashLen(string)      ,
                                                              HashFirstSymb(string),
                                                              HashSum(string)      );
    }

    fclose(input_file);
    fclose(output_file);

    return 1;
}
