#include<stdio.h>
#define PRINT(age) printf("%s = %d\n",#age,age)


int main()
{
    int age =10;
    PRINT(age);
}
/*

# Stringizing Operator (#)

## Definition

The # operator is called the Stringizing Operator. It converts a macro argument into a string literal during preprocessing.

It does not evaluate the expression; it simply converts the argument text into a string.

---

## Syntax

C

#define PRINT(x) printf("%s = %d\n", #x, x)

---

## Example

C

#include <stdio.h>

#define PRINT(x) printf("%s = %d\n", #x, x)

int main()
{
    int age = 25;

    PRINT(age);

    return 0;
}

### Preprocessor Expansion

C

printf("%s = %d\n", "age", age);

### Output

age = 25

---

## Uses

- Logging
- Debugging
- Assertion Macros
- Unit Testing Frameworks

---

## Important Points

- Works only inside macros.
- Executed during preprocessing.
- Converts argument text into a string literal.
- Does not evaluate expressions.

Example

C

SHOW(2+3)

becomes

C

printf("%s","2+3");

Output

2+3

---

## Interview Definition

The # operator converts a macro argument into a string literal during preprocessing.

*/