/*
Topic: defined() Operator
Definition

defined() is a preprocessor operator that checks whether a macro has been defined.

It is used only inside #if and #elif expressions.
defined() is a preprocessor operator used within #if and #elif expressions to test whether a macro is defined.
It enables complex compile-time conditions using logical operators such as &&, ||, and !.
*/

#include<stdio.h>

#define DEBUG

int main()
{
#if defined(DEBUG)//approach 1
    printf("Debug Build\n");
#endif


#if defined DEBUG //approach 2

   printf("Debug Build\n");

#endif


#if defined(DEBUG) && defined(__linux__)

printf("Linux Debug Build\n");

#endif

//compile if linux or macbook
#if defined(__linux__) || defined(__APPLE__)

printf("POSIX System");

#endif


#if !defined(DEBUG)

printf("Release Build");

#endif


#if defined(CONFIG_SMP) && defined(CONFIG_X86)
/*
Compile this code only if:

SMP support exists
x86 architecture exists
*/


#if defined(__GNUC__) && (__GNUC__ >= 13)
/*
Compile this code only for GCC 13 or newer.
*/


#if defined(_WIN32)

...

#elif defined(__linux__)

...

#elif defined(__APPLE__)

...

#endif
/*

One codebase.

Three operating systems.
cross-platform
*/




    return 0;

}