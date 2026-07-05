/*
ifndef is completely opposite of ifdef
ifndef means if not defined then compile this code
ifndef is basically include guards 


#ifndef

Definition:
Checks whether a macro is not defined. If the macro does not exist, the enclosed code is included during preprocessing.

Common Uses:

⭐ Include Guards (most common) 
Default configuration values
Library configuration
Embedded system defaults
Linux kernel fallback definitions
*/
#include <stdio.h>

int main()
{


    printf("inside main\n");
#ifndef DEBUG
    #define DEBUG
    printf("inside ifndef \n");
#endif

    return 0;
}