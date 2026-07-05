//#ifdef checks whether a macro has been defined. If it exists, the enclosed code is included; otherwise, it is removed during preprocessing.
#include<stdio.h>
#define DEBUG
/*
where its used
1)debug in build envoirname and we can skip it in production 
2) platform code specific code->__LINUX__ and __WIN32
Debug builds (DEBUG)
Platform-specific code (__linux__, _WIN32)
Feature flags (ENABLE_SSL)
Linux kernel configuration (CONFIG_SMP, CONFIG_X86)
Embedded hardware support
Unit testing
*/
int main()
{
    #ifdef DEBUG
    printf("inside ifdef \n");
    #endif
    printf("outside ifdef\n");

    return 0;
}