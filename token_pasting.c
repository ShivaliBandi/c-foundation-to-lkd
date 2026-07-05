#include<stdio.h>
#define VAR(x) int var##x=x;
int main()
{
    VAR(10);
    VAR(20);
    VAR(30);
    printf("var10=%d\n",var10);
    printf("var20=%d\n",var20);
    return 0;
}


/*
# Token Pasting Operator (##)

## Definition

The ## operator is called the Token Pasting Operator. It joins two tokens together to form a single valid C token during preprocessing.

---

## Syntax

C

#define MERGE(a,b) a##b

---

## Example 1

C

#include <stdio.h>

#define MERGE(a,b) a##b

int main()
{
    int num1 = 100;

    printf("%d", MERGE(num,1));

    return 0;
}

### Expansion

C

printf("%d", num1);

Output

100

---

## Example 2

C

#define CREATE(x) int var##x = x;

CREATE(10)

Expansion

C

int var10 = 10;

---

## Uses

- Generate variable names
- Generate function names
- Generic APIs
- Register access macros
- Linux Kernel macros

---

## Important Points

- Works only inside macros.
- Executed during preprocessing.
- Both sides must form a valid C token.
- Frequently used in generic macro programming.

---

## Interview Definition

The ## operator joins two macro arguments into a single token during preprocessing.

*/