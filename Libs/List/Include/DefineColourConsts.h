#ifndef DEFINECOLOURCONSTS_H
#define DEFINECOLOURCONSTS_H

#undef KNRM
#undef KRED
#undef KGRN
#undef KYEL
#undef KBLU
#undef KMAG
#undef KCYN
#undef KWHT

#ifdef NLOGGING

    #define KNRM  "\x1B[0m"
    #define KRED  "\x1B[31m"
    #define KGRN  "\x1B[32m"
    #define KYEL  "\x1B[33m"
    #define KBLU  "\x1B[34m"
    #define KMAG  "\x1B[35m"
    #define KCYN  "\x1B[36m"
    #define KWHT  "\x1B[37m"

#else

    #define KNRM  ""
    #define KRED  ""
    #define KGRN  ""
    #define KYEL  ""
    #define KBLU  ""
    #define KMAG  ""
    #define KCYN  ""
    #define KWHT  ""

#endif

#endif
