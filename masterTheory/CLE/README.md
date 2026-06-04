# CLE-Style C Code Analysis Practice — 200 Multiple-Choice Questions

> Original practice set inspired by the public C++ Institute / OpenEDG **CLE – C Certified Entry-Level Programmer** objectives and the **C Essentials 1** syllabus. This is not an official exam dump and does not reproduce real exam items.

## How to use

- Read the code first.
- Choose exactly one alternative unless the question explicitly says otherwise.
- Assume C11 in a hosted implementation.
- Unless the question is testing undefined/implementation-defined behavior, assume a typical platform with 32-bit `int`, 8-bit `char`, ASCII-compatible character codes, and successful dynamic allocation when checked.
- Do not run the code first; train mental execution.

## Coverage map

- **Block 1 – Basic Concepts:** 20 questions
- **Block 2 – Data Types, Evaluations, and Basic I/O:** 25 questions
- **Block 3 – Arithmetic, Logical, and Bitwise Operators:** 30 questions
- **Block 4 – Flow Control: Decision-Making Statements:** 25 questions
- **Block 5 – Flow Control: Loops:** 30 questions
- **Block 6 – Arrays, Pointers, and Memory Management:** 36 questions
- **Block 7 – String Manipulation:** 20 questions
- **Block 8 – The Basics of Functions:** 14 questions

---


## Block 1 – Basic Concepts

### Question 001 — Successful compilation and execution

```c
#include <stdio.h>

int main(void)
{
    printf("C");
    puts("LE");
    return 0;
}
```

What is the correct interpretation?

A. It prints `C LE` with a space.
B. It prints `C` and then stops before `LE`.
C. It fails because `printf` and `puts` cannot be used together.
D. It prints `CLE` followed by a newline.

### Question 002 — Role of return from main

```c
#include <stdio.h>

int main(void)
{
    puts("done");
    return 7;
}
```

What is the correct interpretation?

A. The program cannot compile because `main` must return 0.
B. The program prints `done7`.
C. The program prints `done`; the value `7` is returned to the operating environment.
D. The program prints `7` only.

### Question 003 — String literal escaping

```c
#include <stdio.h>

int main(void)
{
    printf("A\\nB");
    return 0;
}
```

What is the correct interpretation?

A. It prints the four visible characters `A\nB`.
B. It fails because `\n` is not valid inside a string.
C. It prints `A` only.
D. It prints `A`, then a newline, then `B`.

### Question 004 — Character literal vs integer value

```c
#include <stdio.h>

int main(void)
{
    printf("%d", 'A' == 65);
    return 0;
}
```

What is the correct interpretation?

A. It prints `65`.
B. It prints `A`.
C. It prints `1` on ASCII-compatible systems.
D. It is always undefined behavior.

### Question 005 — Octal literal detail

```c
#include <stdio.h>

int main(void)
{
    int x = 010;
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `8`.
B. It prints `010`.
C. It fails because leading zeroes are not allowed.
D. It prints `10`.

### Question 006 — Hexadecimal literal detail

```c
#include <stdio.h>

int main(void)
{
    int x = 0x10 + 10;
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `26`.
B. It fails because hexadecimal cannot be added to decimal.
C. It prints `0x1010`.
D. It prints `20`.

### Question 007 — Scientific notation literal

```c
#include <stdio.h>

int main(void)
{
    double x = 1.5e2;
    printf("%.0f", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `1.5e2`.
B. It prints `150`.
C. It prints `15`.
D. It fails because `e` notation is only for strings.

### Question 008 — Comments are ignored

```c
#include <stdio.h>

int main(void)
{
    int x = 3;
    /* x = x + 100; */
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `103`.
B. It fails because comments cannot contain semicolons.
C. It prints `3`.
D. It prints nothing.

### Question 009 — Line comment boundary

```c
#include <stdio.h>

int main(void)
{
    int x = 1; // x = 5;
    x = x + 2;
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `1`.
B. It prints `5`.
C. It prints `3`.
D. It fails because `//` is not a C comment.

### Question 010 — puts appends newline

```c
#include <stdio.h>

int main(void)
{
    puts("A");
    puts("B");
    return 0;
}
```

What is the correct interpretation?

A. It prints `A\nB` literally.
B. It fails because `puts` needs a format specifier.
C. It prints `AB` on one line.
D. It prints `A` and `B` on separate lines.

### Question 011 — printf does not append newline automatically

```c
#include <stdio.h>

int main(void)
{
    printf("A");
    printf("B");
    return 0;
}
```

What is the correct interpretation?

A. It prints `A B`.
B. It prints `AB`.
C. It prints nothing because there is no newline.
D. It prints `A` and `B` on separate lines.

### Question 012 — Missing header symptom

```c
int main(void)
{
    printf("Hello");
    return 0;
}
```

What is the correct interpretation?

A. The code is valid only if `main` returns `void`.
B. The code is guaranteed to compile without warnings in modern C.
C. The best correction is to include `<stdlib.h>` because `printf` allocates memory.
D. The best correction is to include `<stdio.h>` because `printf` is declared there.

### Question 013 — Semantics vs syntax

```c
#include <stdio.h>

int main(void)
{
    int x = 10 / 2;
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. The code is valid only in C++.
B. The code is syntactically invalid because `/` cannot be used with integers.
C. The code is syntactically valid and semantically calculates an integer division.
D. The code is semantically invalid because `printf` cannot print integers.

### Question 014 — Binary numeral reasoning

```c
#include <stdio.h>

int main(void)
{
    int x = 8 + 4 + 1;
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `841`.
B. It fails because binary arithmetic needs a binary literal.
C. It represents binary `1011` in decimal and prints `11`.
D. It represents binary `1101` in decimal and prints `13`.

### Question 015 — Main signature

```c
#include <stdio.h>

int main(void)
{
    return 0;
}
```

What is the correct interpretation?

A. This is a standard valid form of `main` for a program with no command-line parameters.
B. This function cannot be the program entry point.
C. This always prints `0`.
D. This must be written as `void main()` in C.

### Question 016 — Portability detail

```c
#include <stdio.h>

int main(void)
{
    printf("%zu", sizeof(int));
    return 0;
}
```

What is the correct interpretation?

A. It fails because `sizeof` cannot be applied to a type.
B. It always prints `4` by the C standard.
C. It prints the address of `int`.
D. It prints the size of `int` in bytes, which may vary by implementation.

### Question 017 — Integer literal type context

```c
#include <stdio.h>

int main(void)
{
    long x = 1000L;
    printf("%ld", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `1000L`.
B. It converts `1000L` into a string.
C. It fails because suffixes are not part of C literals.
D. It prints `1000`; the `L` suffix asks for a long integer literal.

### Question 018 — Escape sequence newline

```c
#include <stdio.h>

int main(void)
{
    printf("X\nY");
    return 0;
}
```

What is the correct interpretation?

A. It prints `XnY`.
B. It fails because newline escapes work only in `puts`.
C. It prints `X` and `Y` on separate lines.
D. It prints `X\nY`.

### Question 019 — Preprocessor include role

```c
#include <stdio.h>

int main(void)
{
    puts("ok");
    return 0;
}
```

What is the correct interpretation?

A. The include changes `main` into a library function.
B. The include allocates memory for `puts`.
C. The include executes `stdio.h` as a separate program.
D. The include makes declarations such as `puts` available before compilation proper.

### Question 020 — Lexis detail

```c
#include <stdio.h>

int main(void)
{
    int score = 10;
    printf("%d", score);
    return 0;
}
```

What is the correct interpretation?

A. `int`, `score`, `=`, `10`, and `;` are lexical elements/tokens used to form the statement.
B. `score` is not part of the program lexis because it is user-defined.
C. `10` is syntax but not a token.
D. Only header names are lexical elements.


## Block 2 – Data Types, Evaluations, and Basic I/O

### Question 021 — Integer division assigned to float

```c
#include <stdio.h>

int main(void)
{
    float x = 5 / 2;
    printf("%.1f", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `2.0`.
B. It prints `3.0`.
C. It fails because an integer expression cannot be assigned to `float`.
D. It prints `2.5`.

### Question 022 — Casting before division

```c
#include <stdio.h>

int main(void)
{
    float x = (float)5 / 2;
    printf("%.1f", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `2.0`.
B. It fails because `(float)` can only cast variables.
C. It prints `3.0`.
D. It prints `2.5`.

### Question 023 — Assignment direction

```c
#include <stdio.h>

int main(void)
{
    int a = 2;
    int b = 9;
    a = b;
    printf("%d %d", a, b);
    return 0;
}
```

What is the correct interpretation?

A. It prints `9 9`.
B. It swaps the variables and prints `9 2`.
C. It prints `2 2`.
D. It prints `2 9`.

### Question 024 — Constant modification

```c
#include <stdio.h>

int main(void)
{
    const int limit = 5;
    limit = 6;
    printf("%d", limit);
    return 0;
}
```

What is the correct interpretation?

A. It fails to compile because a const-qualified object cannot be assigned to after initialization.
B. It is undefined behavior at runtime only.
C. It prints `6`.
D. It prints `5`.

### Question 025 — Char as small integer

```c
#include <stdio.h>

int main(void)
{
    char c = 'A';
    c = c + 1;
    printf("%c", c);
    return 0;
}
```

What is the correct interpretation?

A. It prints `66`.
B. It prints `A1`.
C. It prints `B` on ASCII-compatible systems.
D. It fails because characters cannot be added to integers.

### Question 026 — Format specifier mismatch idea

```c
#include <stdio.h>

int main(void)
{
    int x = 42;
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. `%f` is required because all numbers become double in printf.
B. No conversion specifier is needed for variables.
C. `%d` is the appropriate conversion specifier for printing a signed int value.
D. `%c` is required for all integer values.

### Question 027 — Width formatting

```c
#include <stdio.h>

int main(void)
{
    printf("[%5d]", 12);
    return 0;
}
```

What is the correct interpretation?

A. It fails because width cannot be used with `%d`.
B. It prints `[12   ]`.
C. It prints `[   12]`.
D. It prints `[12]` with no spaces.

### Question 028 — Precision with float

```c
#include <stdio.h>

int main(void)
{
    printf("%.2f", 3.14159);
    return 0;
}
```

What is the correct interpretation?

A. It prints `3.14159`.
B. It fails because precision is only for strings.
C. It prints `3.14`.
D. It prints `3`.

### Question 029 — scanf address requirement

```c
#include <stdio.h>

int main(void)
{
    int x;
    scanf("%d", &x);
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. `&x` is unnecessary and always wrong with `scanf`.
B. `&x` prints the address of `x`.
C. The `&x` passes the address where `scanf` stores the read integer.
D. `&x` converts `x` to a string.

### Question 030 — scanf with given input

```c
#include <stdio.h>

int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", a + b);
    return 0;
}
```

What is the correct interpretation?

A. If input is `3 4`, it prints `7`.
B. If input is `3 4`, it prints `34`.
C. If input is `3 4`, it prints `3`.
D. It fails because two `%d` specifiers need a comma in the input.

### Question 031 — Float scanf specifier

```c
#include <stdio.h>

int main(void)
{
    float f;
    scanf("%f", &f);
    printf("%.1f", f);
    return 0;
}
```

What is the correct interpretation?

A. For input `2.75`, it prints `2`.
B. For input `2.75`, it prints `2.8` because of rounding to one digit.
C. `%f` is never valid with `scanf`.
D. For input `2.75`, it prints `2.75` exactly.

### Question 032 — Double printf promotion

```c
#include <stdio.h>

int main(void)
{
    float f = 1.25f;
    printf("%.2f", f);
    return 0;
}
```

What is the correct interpretation?

A. It prints `1.25`.
B. It prints the memory address of `f`.
C. It prints `1`.
D. It fails because `printf` needs `%lf` for float.

### Question 033 — Implicit conversion to int

```c
#include <stdio.h>

int main(void)
{
    int x = 3.9;
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `4`.
B. It prints `3`.
C. It prints `3.9`.
D. It fails because floating literals cannot initialize integers.

### Question 034 — Mixed arithmetic conversion

```c
#include <stdio.h>

int main(void)
{
    double x = 3 + 2.0;
    printf("%.1f", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `5`.
B. It fails because int and double cannot be added.
C. It prints `5.0`.
D. It prints `32.0`.

### Question 035 — Unsigned wrap note

```c
#include <stdio.h>

int main(void)
{
    unsigned int x = 0;
    x = x - 1;
    printf("%u", x > 0);
    return 0;
}
```

What is the correct interpretation?

A. It prints `0` because `x` becomes negative.
B. It is undefined behavior because unsigned cannot subtract.
C. It prints `1` because unsigned arithmetic wraps modulo its range.
D. It fails because `%u` cannot print a comparison result.

### Question 036 — Sizeof result type

```c
#include <stdio.h>

int main(void)
{
    int a[3] = {1, 2, 3};
    printf("%zu", sizeof a / sizeof a[0]);
    return 0;
}
```

What is the correct interpretation?

A. It prints the number of bytes in one int.
B. It always prints `12`.
C. It fails because division cannot be used with `sizeof`.
D. It prints the number of elements in the array, `3`.

### Question 037 — Derived data type identification

```c
#include <stdio.h>

int main(void)
{
    int values[4] = {0};
    printf("%d", values[2]);
    return 0;
}
```

What is the correct interpretation?

A. `values` is a primary floating-point type.
B. `values` is an array object, a derived type built from `int`.
C. `values` is a function pointer.
D. `values` is a string literal.

### Question 038 — Long specifier

```c
#include <stdio.h>

int main(void)
{
    long n = 123L;
    printf("%ld", n);
    return 0;
}
```

What is the correct interpretation?

A. It prints `123`.
B. It prints `123L`.
C. It fails because `%ld` is not a valid printf specifier.
D. It prints the address of `n`.

### Question 039 — Remainder operator

```c
#include <stdio.h>

int main(void)
{
    printf("%d", 17 % 5);
    return 0;
}
```

What is the correct interpretation?

A. It prints `3`.
B. It prints `2`.
C. It fails because `%` can only be used in `printf` formats.
D. It prints `3.4`.

### Question 040 — Assignment inside printf argument

```c
#include <stdio.h>

int main(void)
{
    int x = 1;
    printf("%d", x = 5);
    return 0;
}
```

What is the correct interpretation?

A. It prints the address of `x`.
B. It prints `5`.
C. It fails because assignments cannot appear in function arguments.
D. It prints `1`.

### Question 041 — Comma in declaration

```c
#include <stdio.h>

int main(void)
{
    int a = 1, b = 2, c;
    c = a + b;
    printf("%d", c);
    return 0;
}
```

What is the correct interpretation?

A. It prints an uninitialized value.
B. It prints `12`.
C. It prints `3`.
D. It fails because only one variable may be declared per line.

### Question 042 — scanf whitespace

```c
#include <stdio.h>

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", x * y);
    return 0;
}
```

What is the correct interpretation?

A. It fails because `%d %d` accepts only one-line input.
B. With input `6
7`, it prints `6` and ignores `7`.
C. With input `6
7`, it prints `42`.
D. It prints `67`.

### Question 043 — Integer truncation after expression

```c
#include <stdio.h>

int main(void)
{
    int x = 7;
    int y = 2;
    printf("%d", x / y);
    return 0;
}
```

What is the correct interpretation?

A. It fails because `/` requires floating types.
B. It prints `3.5`.
C. It prints `4`.
D. It prints `3`.

### Question 044 — Char printed as integer

```c
#include <stdio.h>

int main(void)
{
    char c = '0';
    printf("%d", c);
    return 0;
}
```

What is the correct interpretation?

A. It fails because `%d` cannot receive a char expression.
B. It prints `0`.
C. It prints `'0'` including quotes.
D. It prints the numeric code of character `'0'`, commonly `48` in ASCII.

### Question 045 — Literal suffix and type

```c
#include <stdio.h>

int main(void)
{
    unsigned int x = 10U;
    printf("%u", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `10U`.
B. It prints `10`; `U` marks the literal as unsigned.
C. It prints a Unicode code point.
D. It fails because uppercase suffixes are not allowed.


## Block 3 – Arithmetic, Logical, and Bitwise Operators

### Question 046 — Precedence: multiplication before addition

```c
#include <stdio.h>

int main(void)
{
    printf("%d", 2 + 3 * 4);
    return 0;
}
```

What is the correct interpretation?

A. It prints `24`.
B. It prints `20`.
C. It fails because precedence must be written with parentheses.
D. It prints `14`.

### Question 047 — Parentheses change precedence

```c
#include <stdio.h>

int main(void)
{
    printf("%d", (2 + 3) * 4);
    return 0;
}
```

What is the correct interpretation?

A. It fails because parentheses cannot group arithmetic.
B. It prints `20`.
C. It prints `9`.
D. It prints `14`.

### Question 048 — Pre-increment value

```c
#include <stdio.h>

int main(void)
{
    int x = 4;
    int y = ++x;
    printf("%d %d", x, y);
    return 0;
}
```

What is the correct interpretation?

A. It prints `5 4`.
B. It prints `4 5`.
C. It prints `5 5`.
D. It has undefined behavior.

### Question 049 — Post-increment value

```c
#include <stdio.h>

int main(void)
{
    int x = 4;
    int y = x++;
    printf("%d %d", x, y);
    return 0;
}
```

What is the correct interpretation?

A. It has undefined behavior.
B. It prints `5 5`.
C. It prints `5 4`.
D. It prints `4 5`.

### Question 050 — Compound assignment

```c
#include <stdio.h>

int main(void)
{
    int x = 10;
    x -= 3;
    x *= 2;
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `7`.
B. It prints `20`.
C. It prints `4`.
D. It prints `14`.

### Question 051 — Logical AND returns 0 or 1

```c
#include <stdio.h>

int main(void)
{
    printf("%d", (5 > 2) && (3 < 1));
    return 0;
}
```

What is the correct interpretation?

A. It fails because comparisons cannot be combined.
B. It prints `1`.
C. It prints `5`.
D. It prints `0`.

### Question 052 — Logical OR

```c
#include <stdio.h>

int main(void)
{
    printf("%d", (0 || 7));
    return 0;
}
```

What is the correct interpretation?

A. It prints `1`.
B. It fails because `||` requires comparisons only.
C. It prints `7`.
D. It prints `0`.

### Question 053 — Logical NOT

```c
#include <stdio.h>

int main(void)
{
    int x = 0;
    printf("%d", !x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `0`.
B. It fails because `!` can only be used with `bool`.
C. It prints `-1`.
D. It prints `1`.

### Question 054 — Bitwise AND

```c
#include <stdio.h>

int main(void)
{
    printf("%d", 6 & 3);
    return 0;
}
```

What is the correct interpretation?

A. It prints `2`.
B. It prints `7`.
C. It prints `18`.
D. It prints `1`.

### Question 055 — Bitwise OR

```c
#include <stdio.h>

int main(void)
{
    printf("%d", 6 | 3);
    return 0;
}
```

What is the correct interpretation?

A. It prints `18`.
B. It prints `2`.
C. It prints `7`.
D. It prints `1`.

### Question 056 — Bitwise XOR

```c
#include <stdio.h>

int main(void)
{
    printf("%d", 6 ^ 3);
    return 0;
}
```

What is the correct interpretation?

A. It prints `5`.
B. It prints `18`.
C. It prints `7`.
D. It prints `2`.

### Question 057 — Left shift positive int

```c
#include <stdio.h>

int main(void)
{
    printf("%d", 3 << 2);
    return 0;
}
```

What is the correct interpretation?

A. It prints `5`.
B. It prints `6`.
C. It prints `12`.
D. It prints `1`.

### Question 058 — Right shift positive int

```c
#include <stdio.h>

int main(void)
{
    printf("%d", 16 >> 2);
    return 0;
}
```

What is the correct interpretation?

A. It prints `8`.
B. It prints `32`.
C. It prints `64`.
D. It prints `4`.

### Question 059 — Short-circuit AND

```c
#include <stdio.h>

int main(void)
{
    int x = 0;
    int y = 5;
    if (x && ++y)
        printf("A");
    printf("%d", y);
    return 0;
}
```

What is the correct interpretation?

A. It prints `6`.
B. It has undefined behavior.
C. It prints `5`.
D. It prints `A6`.

### Question 060 — Short-circuit OR

```c
#include <stdio.h>

int main(void)
{
    int x = 1;
    int y = 5;
    if (x || ++y)
        printf("%d", y);
    return 0;
}
```

What is the correct interpretation?

A. It has undefined behavior.
B. It prints `5`.
C. It prints nothing.
D. It prints `6`.

### Question 061 — Relational chain trap

```c
#include <stdio.h>

int main(void)
{
    printf("%d", 1 < 2 < 1);
    return 0;
}
```

What is the correct interpretation?

A. It prints `0` because `(1 < 2)` becomes `1`, then `1 < 1` is false.
B. It fails because chained comparisons are invalid in C.
C. It is undefined behavior.
D. It prints `1` because it means `1 < 2 && 2 < 1`.

### Question 062 — Equality vs assignment in expression

```c
#include <stdio.h>

int main(void)
{
    int x = 3;
    printf("%d %d", x == 3, x);
    return 0;
}
```

What is the correct interpretation?

A. It changes x to 3 and prints `3 3`.
B. It prints `0 3`.
C. It prints `1 3`.
D. It prints `3 3`.

### Question 063 — Assignment expression value

```c
#include <stdio.h>

int main(void)
{
    int x = 0;
    if (x = 4)
        printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `0`.
B. It prints nothing.
C. It prints `4`.
D. It fails because assignment is not an expression in C.

### Question 064 — Associativity of subtraction

```c
#include <stdio.h>

int main(void)
{
    printf("%d", 20 - 5 - 3);
    return 0;
}
```

What is the correct interpretation?

A. It prints `18`.
B. It prints `12`.
C. It fails because associativity is ambiguous.
D. It prints `-12`.

### Question 065 — Associativity of assignment

```c
#include <stdio.h>

int main(void)
{
    int a, b, c;
    a = b = c = 2;
    printf("%d %d %d", a, b, c);
    return 0;
}
```

What is the correct interpretation?

A. It prints `0 0 2`.
B. It prints `2 2 2`.
C. It fails because chained assignment is invalid.
D. It prints uninitialized values.

### Question 066 — Modifying once safely

```c
#include <stdio.h>

int main(void)
{
    int x = 2;
    x = x + 1;
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. It has undefined behavior.
B. It prints `2`.
C. It prints `3`.
D. It fails because a variable cannot appear on both sides of `=`.

### Question 067 — Undefined behavior: unsequenced modification

```c
#include <stdio.h>

int main(void)
{
    int x = 1;
    printf("%d", x++ + ++x);
    return 0;
}
```

What is the correct interpretation?

A. It must print `5`.
B. It has undefined behavior because `x` is modified more than once without sequencing.
C. It must print `4`.
D. It fails because increment operators cannot be used inside expressions.

### Question 068 — Unary minus precedence

```c
#include <stdio.h>

int main(void)
{
    int x = 3;
    printf("%d", -x * 2);
    return 0;
}
```

What is the correct interpretation?

A. It fails because unary minus cannot be applied to variables.
B. It prints `6`.
C. It prints `-1`.
D. It prints `-6`.

### Question 069 — Ternary conditional

```c
#include <stdio.h>

int main(void)
{
    int x = 4;
    printf("%d", x > 3 ? x : 0);
    return 0;
}
```

What is the correct interpretation?

A. It prints `4`.
B. It fails because C has no conditional operator.
C. It prints `0`.
D. It prints `1`.

### Question 070 — Comma operator

```c
#include <stdio.h>

int main(void)
{
    int x;
    x = (1, 2, 3);
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `2`.
B. It prints `1`.
C. It prints `3`.
D. It fails because commas cannot appear in parentheses.

### Question 071 — Bit mask check

```c
#include <stdio.h>

int main(void)
{
    int flags = 10; /* binary 1010 */
    printf("%d", (flags & 2) != 0);
    return 0;
}
```

What is the correct interpretation?

A. It prints `2` because `!=` is ignored.
B. It prints `0` because 10 is even.
C. It fails because bitwise operators require unsigned variables.
D. It prints `1` because bit 1 is set.

### Question 072 — Bit clearing

```c
#include <stdio.h>

int main(void)
{
    unsigned x = 7; /* 0111 */
    x = x & ~1U;
    printf("%u", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `7`.
B. It has undefined behavior because `~` cannot be used with unsigned.
C. It prints `6`.
D. It prints `0`.

### Question 073 — Rounding via cast

```c
#include <stdio.h>

int main(void)
{
    double x = 4.99;
    printf("%d", (int)x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `4.99`.
B. It fails because double cannot be cast to int.
C. It prints `5`.
D. It prints `4`.

### Question 074 — Arithmetic with remainder and division

```c
#include <stdio.h>

int main(void)
{
    int x = 23;
    printf("%d", (x / 10) + (x % 10));
    return 0;
}
```

What is the correct interpretation?

A. It prints `14`.
B. It prints `23`.
C. It prints `2.3`.
D. It prints `5`.

### Question 075 — Logical vs bitwise AND

```c
#include <stdio.h>

int main(void)
{
    printf("%d %d", 2 && 4, 2 & 4);
    return 0;
}
```

What is the correct interpretation?

A. It prints `1 1`.
B. It prints `1 0`.
C. It prints `0 1`.
D. It prints `2 4`.


## Block 4 – Flow Control: Decision-Making Statements

### Question 076 — Simple if true branch

```c
#include <stdio.h>

int main(void)
{
    int score = 80;
    if (score >= 70)
        printf("pass");
    else
        printf("fail");
    return 0;
}
```

What is the correct interpretation?

A. It prints both.
B. It prints nothing.
C. It prints `fail`.
D. It prints `pass`.

### Question 077 — Dangling else

```c
#include <stdio.h>

int main(void)
{
    int a = 0, b = 1;
    if (a)
        if (b)
            printf("X");
        else
            printf("Y");
    return 0;
}
```

What is the correct interpretation?

A. It prints `Y`.
B. It fails because `else` is ambiguous.
C. It prints nothing.
D. It prints `X`.

### Question 078 — Braces change else pairing

```c
#include <stdio.h>

int main(void)
{
    int a = 0, b = 1;
    if (a) {
        if (b)
            printf("X");
    } else {
        printf("Y");
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `Y`.
B. It prints nothing.
C. It fails because nested ifs require no braces.
D. It prints `X`.

### Question 079 — else if ladder first match

```c
#include <stdio.h>

int main(void)
{
    int x = 12;
    if (x > 0)
        printf("A");
    else if (x > 10)
        printf("B");
    else
        printf("C");
    return 0;
}
```

What is the correct interpretation?

A. It prints `A`.
B. It prints `AB`.
C. It prints `B`.
D. It prints `C`.

### Question 080 — Independent if statements

```c
#include <stdio.h>

int main(void)
{
    int x = 12;
    if (x > 0)
        printf("A");
    if (x > 10)
        printf("B");
    else
        printf("C");
    return 0;
}
```

What is the correct interpretation?

A. It prints `AB`.
B. It prints `A`.
C. It prints `AC`.
D. It prints `B`.

### Question 081 — Switch exact matching

```c
#include <stdio.h>

int main(void)
{
    int x = 2;
    switch (x) {
        case 1: printf("one"); break;
        case 2: printf("two"); break;
        default: printf("other");
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `other`.
B. It prints `one`.
C. It fails because switch works only with char.
D. It prints `two`.

### Question 082 — Switch fall-through

```c
#include <stdio.h>

int main(void)
{
    int x = 1;
    switch (x) {
        case 1: printf("A");
        case 2: printf("B");
        default: printf("C");
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `A` only.
B. It prints `ABC`.
C. It prints `AB`.
D. It prints `C` only.

### Question 083 — Switch default position

```c
#include <stdio.h>

int main(void)
{
    int x = 3;
    switch (x) {
        default: printf("D"); break;
        case 1: printf("A"); break;
        case 2: printf("B"); break;
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `D`.
B. It prints nothing because default must be last.
C. It prints `A`.
D. It prints `B`.

### Question 084 — Switch without default

```c
#include <stdio.h>

int main(void)
{
    int x = 9;
    switch (x) {
        case 1: printf("A"); break;
        case 2: printf("B"); break;
    }
    printf("Z");
    return 0;
}
```

What is the correct interpretation?

A. It prints `BZ`.
B. It fails because default is mandatory.
C. It prints `Z`.
D. It prints `AZ`.

### Question 085 — Nested condition

```c
#include <stdio.h>

int main(void)
{
    int age = 20;
    int has_id = 0;
    if (age >= 18) {
        if (has_id)
            printf("enter");
        else
            printf("wait");
    } else {
        printf("minor");
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints nothing.
B. It prints `minor`.
C. It prints `enter`.
D. It prints `wait`.

### Question 086 — Assignment in condition

```c
#include <stdio.h>

int main(void)
{
    int x = 0;
    if (x = 0)
        printf("A");
    else
        printf("B");
    return 0;
}
```

What is the correct interpretation?

A. It prints `B`.
B. It has undefined behavior.
C. It prints `A`.
D. It fails because assignment cannot be used in a condition.

### Question 087 — Condition nonzero

```c
#include <stdio.h>

int main(void)
{
    int x = -3;
    if (x)
        printf("T");
    else
        printf("F");
    return 0;
}
```

What is the correct interpretation?

A. It prints `F` because only positive values are true.
B. It prints `T` because any nonzero value is true.
C. It fails because conditions need boolean type.
D. It prints `-3`.

### Question 088 — Equality in condition

```c
#include <stdio.h>

int main(void)
{
    int x = 5;
    if (x == 5)
        printf("yes");
    else
        printf("no");
    return 0;
}
```

What is the correct interpretation?

A. It prints `no`.
B. It fails because `==` cannot compare integers.
C. It assigns 5 to x and prints `5`.
D. It prints `yes`.

### Question 089 — Multiple condition with AND

```c
#include <stdio.h>

int main(void)
{
    int x = 6;
    if (x > 0 && x % 2 == 0)
        printf("even positive");
    else
        printf("other");
    return 0;
}
```

What is the correct interpretation?

A. It fails because `%` cannot be used in conditions.
B. It prints both messages.
C. It prints `even positive`.
D. It prints `other`.

### Question 090 — Multiple condition with OR

```c
#include <stdio.h>

int main(void)
{
    int x = -1;
    if (x < 0 || x > 100)
        printf("outside");
    else
        printf("inside");
    return 0;
}
```

What is the correct interpretation?

A. It prints nothing.
B. It prints `outside`.
C. It fails because `||` cannot be used with comparisons.
D. It prints `inside`.

### Question 091 — Switch char expression

```c
#include <stdio.h>

int main(void)
{
    char op = '+';
    switch (op) {
        case '+': printf("add"); break;
        case '-': printf("sub"); break;
    }
    return 0;
}
```

What is the correct interpretation?

A. It fails because switch cannot use char values.
B. It prints `add`.
C. It prints `+`.
D. It prints `sub`.

### Question 092 — Range not valid as case

```c
#include <stdio.h>

int main(void)
{
    int x = 5;
    switch (x) {
        case 1:
            printf("one");
            break;
        case 5:
            printf("five");
            break;
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints nothing.
B. It fails because case labels must be strings.
C. It prints `one`.
D. It prints `five`.

### Question 093 — Unreachable else-if detail

```c
#include <stdio.h>

int main(void)
{
    int x = 25;
    if (x > 10)
        printf("big");
    else if (x > 20)
        printf("huge");
    else
        printf("small");
    return 0;
}
```

What is the correct interpretation?

A. It prints `small`.
B. It prints `huge`.
C. It prints `big`.
D. It prints `bighuge`.

### Question 094 — Correct ordering of conditions

```c
#include <stdio.h>

int main(void)
{
    int x = 25;
    if (x > 20)
        printf("huge");
    else if (x > 10)
        printf("big");
    else
        printf("small");
    return 0;
}
```

What is the correct interpretation?

A. It prints `huge`.
B. It prints `hugebig`.
C. It prints `small`.
D. It prints `big`.

### Question 095 — Conditional operator nested in output

```c
#include <stdio.h>

int main(void)
{
    int x = 0;
    printf("%s", x ? "true" : "false");
    return 0;
}
```

What is the correct interpretation?

A. It prints `true`.
B. It fails because `?:` cannot return strings.
C. It prints `0`.
D. It prints `false`.

### Question 096 — If body without braces

```c
#include <stdio.h>

int main(void)
{
    int x = 0;
    if (x)
        printf("A");
        printf("B");
    return 0;
}
```

What is the correct interpretation?

A. It prints `B`.
B. It prints nothing.
C. It prints `A`.
D. It prints `AB`.

### Question 097 — Else with nearest if

```c
#include <stdio.h>

int main(void)
{
    int a = 1, b = 0;
    if (a)
        if (b)
            printf("X");
        else
            printf("Y");
    return 0;
}
```

What is the correct interpretation?

A. It prints nothing.
B. It fails because the `else` has no matching `if`.
C. It prints `Y`.
D. It prints `X`.

### Question 098 — Switch case constant expression

```c
#include <stdio.h>

int main(void)
{
    int x = 2;
    switch (x) {
        case 1 + 1:
            printf("two");
            break;
        default:
            printf("other");
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `other`.
B. It prints `1 + 1`.
C. It fails because `case` labels cannot contain expressions.
D. It prints `two`.

### Question 099 — Logical NOT in decision

```c
#include <stdio.h>

int main(void)
{
    int ready = 0;
    if (!ready)
        printf("prepare");
    else
        printf("run");
    return 0;
}
```

What is the correct interpretation?

A. It fails because `!` cannot appear inside if.
B. It prints `run`.
C. It prints `prepare`.
D. It prints `0`.

### Question 100 — Default fall-through

```c
#include <stdio.h>

int main(void)
{
    int x = 9;
    switch (x) {
        default: printf("D");
        case 9: printf("N");
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `D`.
B. It prints `DN`.
C. It fails because default cannot appear before case.
D. It prints `N`.


## Block 5 – Flow Control: Loops

### Question 101 — Basic while loop

```c
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i < 3) {
        printf("%d", i);
        i++;
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints nothing.
B. It prints `123`.
C. It prints `012`.
D. It prints `0123`.

### Question 102 — For loop count

```c
#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 3; i++)
        printf("%d", i);
    return 0;
}
```

What is the correct interpretation?

A. It prints `123`.
B. It prints `012`.
C. It is an infinite loop.
D. It prints `1234`.

### Question 103 — Do-while executes once

```c
#include <stdio.h>

int main(void)
{
    int i = 5;
    do {
        printf("%d", i);
        i++;
    } while (i < 3);
    return 0;
}
```

What is the correct interpretation?

A. It prints `5`.
B. It prints nothing.
C. It is an infinite loop.
D. It prints `567`.

### Question 104 — Break exits loop

```c
#include <stdio.h>

int main(void)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (i == 3)
            break;
        printf("%d", i);
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `01234`.
B. It prints `012`.
C. It prints `34`.
D. It prints `0123`.

### Question 105 — Continue skips iteration body

```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 5; i++) {
        if (i == 2)
            continue;
        printf("%d", i);
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `0134`.
B. It stops at 2.
C. It prints `2`.
D. It prints `01234`.

### Question 106 — Loop condition checked first

```c
#include <stdio.h>

int main(void)
{
    int i = 10;
    while (i < 5) {
        printf("X");
        i++;
    }
    printf("Y");
    return 0;
}
```

What is the correct interpretation?

A. It is an infinite loop.
B. It prints `X`.
C. It prints `Y`.
D. It prints `XY`.

### Question 107 — Nested loops

```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            printf("*");
    return 0;
}
```

What is the correct interpretation?

A. It prints 6 stars.
B. It prints 3 stars.
C. It prints 2 stars.
D. It prints 5 stars.

### Question 108 — Nested loop values

```c
#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            printf("%d%d ", i, j);
        }
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `11 22 `.
B. It prints `11 12 21 22 `.
C. It prints `12 21 `.
D. It prints `1 2 1 2 `.

### Question 109 — For loop update timing

```c
#include <stdio.h>

int main(void)
{
    int i;
    for (i = 0; i < 3; i++)
        ;
    printf("%d", i);
    return 0;
}
```

What is the correct interpretation?

A. It is undefined behavior.
B. It prints `3`.
C. It prints `0`.
D. It prints `2`.

### Question 110 — Empty body trap

```c
#include <stdio.h>

int main(void)
{
    int i;
    for (i = 0; i < 3; i++);
    printf("%d", i);
    return 0;
}
```

What is the correct interpretation?

A. It prints `2`.
B. It prints `012`.
C. It prints `0`.
D. It prints `3`.

### Question 111 — Accumulating sum

```c
#include <stdio.h>

int main(void)
{
    int sum = 0;
    for (int i = 1; i <= 4; i++)
        sum += i;
    printf("%d", sum);
    return 0;
}
```

What is the correct interpretation?

A. It prints `1234`.
B. It prints `10`.
C. It prints `4`.
D. It prints `24`.

### Question 112 — Counting down

```c
#include <stdio.h>

int main(void)
{
    int i = 3;
    while (i > 0) {
        printf("%d", i);
        i--;
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `321`.
B. It prints `3` forever.
C. It prints `123`.
D. It prints `210`.

### Question 113 — Infinite loop recognition

```c
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i < 3) {
        printf("%d", i);
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `0` repeatedly because `i` never changes.
B. It prints `012`.
C. It prints nothing.
D. It fails because while requires an update expression.

### Question 114 — Break in nested loop

```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 1)
                break;
            printf("%d%d ", i, j);
        }
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `00 01 10 11 `.
B. It prints `01 11 `.
C. It prints nothing.
D. It prints `00 10 `.

### Question 115 — Continue in nested loop

```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 1)
                continue;
            printf("%d%d ", i, j);
        }
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `01 11 `.
B. It stops at `01`.
C. It prints `00 01 02 10 11 12 `.
D. It prints `00 02 10 12 `.

### Question 116 — Do-while sum

```c
#include <stdio.h>

int main(void)
{
    int i = 1, sum = 0;
    do {
        sum += i;
        i++;
    } while (i <= 3);
    printf("%d", sum);
    return 0;
}
```

What is the correct interpretation?

A. It prints `6`.
B. It prints `0`.
C. It prints `3`.
D. It prints `123`.

### Question 117 — For loop missing init

```c
#include <stdio.h>

int main(void)
{
    int i = 0;
    for (; i < 3; i++)
        printf("%d", i);
    return 0;
}
```

What is the correct interpretation?

A. It is an infinite loop.
B. It prints `012`.
C. It prints `123`.
D. It fails because the initialization expression is mandatory.

### Question 118 — For loop missing update

```c
#include <stdio.h>

int main(void)
{
    int i;
    for (i = 0; i < 3;) {
        printf("%d", i);
        i++;
    }
    return 0;
}
```

What is the correct interpretation?

A. It fails because the update expression is mandatory.
B. It is always an infinite loop.
C. It prints `012`.
D. It prints `000`.

### Question 119 — Loop variable scope

```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 2; i++)
        printf("%d", i);
    /* printf("%d", i); */
    return 0;
}
```

What is the correct interpretation?

A. The loop prints nothing.
B. The loop itself is invalid in C.
C. The commented final `printf` would print `2`.
D. The commented final `printf` would be invalid in C99/C11 because `i` is scoped to the for statement.

### Question 120 — Multiplicative update

```c
#include <stdio.h>

int main(void)
{
    int x = 1;
    for (int i = 0; i < 4; i++)
        x *= 2;
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `32`.
B. It prints `16`.
C. It prints `4`.
D. It prints `8`.

### Question 121 — Loop with modulo filter

```c
#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 5; i++) {
        if (i % 2 == 0)
            printf("%d", i);
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `12345`.
B. It prints `135`.
C. It prints `2` only.
D. It prints `24`.

### Question 122 — Sentinel-like loop

```c
#include <stdio.h>

int main(void)
{
    int x = 16;
    while (x > 1)
        x /= 2;
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `16`.
B. It prints `1`.
C. It prints `2`.
D. It prints `8`.

### Question 123 — Off-by-one

```c
#include <stdio.h>

int main(void)
{
    int count = 0;
    for (int i = 0; i <= 4; i++)
        count++;
    printf("%d", count);
    return 0;
}
```

What is the correct interpretation?

A. It prints `5`.
B. It prints `4`.
C. It prints `0`.
D. It prints `6`.

### Question 124 — Condition after body

```c
#include <stdio.h>

int main(void)
{
    int n = 0;
    do {
        printf("A");
    } while (n);
    return 0;
}
```

What is the correct interpretation?

A. It prints `A` once.
B. It fails because `while` needs braces.
C. It prints nothing.
D. It prints `A` forever.

### Question 125 — Continue with while update placement

```c
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i < 3) {
        i++;
        if (i == 2)
            continue;
        printf("%d", i);
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `1` forever.
B. It prints `123`.
C. It prints `13`.
D. It prints `02`.

### Question 126 — Dangerous continue placement

```c
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i < 3) {
        if (i == 1)
            continue;
        printf("%d", i);
        i++;
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints nothing.
B. It fails because continue is invalid in while.
C. It prints `012`.
D. It prints `0` and then loops forever at `i == 1`.

### Question 127 — Loop with break after print

```c
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (1) {
        printf("%d", i);
        if (i == 2)
            break;
        i++;
    }
    return 0;
}
```

What is the correct interpretation?

A. It is an infinite loop.
B. It prints `012`.
C. It prints `01`.
D. It prints `2` only.

### Question 128 — Double increment

```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 5; i++) {
        printf("%d", i);
        i++;
    }
    return 0;
}
```

What is the correct interpretation?

A. It prints `04`.
B. It prints `135`.
C. It prints `01234`.
D. It prints `024`.

### Question 129 — Counting characters printed

```c
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (++i < 4)
        printf("*");
    return 0;
}
```

What is the correct interpretation?

A. It prints 2 stars.
B. It prints 4 stars.
C. It prints 3 stars.
D. It prints no stars.

### Question 130 — Loop and comma operator

```c
#include <stdio.h>

int main(void)
{
    int i, j;
    for (i = 0, j = 3; i < j; i++, j--)
        printf("%d%d ", i, j);
    return 0;
}
```

What is the correct interpretation?

A. It fails because a for clause cannot contain commas.
B. It prints `03 12 21 `.
C. It prints `03 `.
D. It prints `03 12 `.


## Block 6 – Arrays, Pointers, and Memory Management

### Question 131 — Array indexing

```c
#include <stdio.h>

int main(void)
{
    int a[3] = {10, 20, 30};
    printf("%d", a[1]);
    return 0;
}
```

What is the correct interpretation?

A. It prints `10`.
B. It prints `20`.
C. It prints `30`.
D. It fails because C arrays start at 1.

### Question 132 — Partial initialization

```c
#include <stdio.h>

int main(void)
{
    int a[5] = {1, 2};
    printf("%d %d", a[0], a[4]);
    return 0;
}
```

What is the correct interpretation?

A. It prints `0 0`.
B. It prints `1` and an indeterminate value.
C. It fails because all elements must be initialized.
D. It prints `1 0`.

### Question 133 — Array size from initializer

```c
#include <stdio.h>

int main(void)
{
    int a[] = {4, 5, 6, 7};
    printf("%zu", sizeof a / sizeof a[0]);
    return 0;
}
```

What is the correct interpretation?

A. It prints `4`.
B. It fails because the array size is missing.
C. It prints the address of `a`.
D. It prints `16` on all systems.

### Question 134 — Pointer dereference

```c
#include <stdio.h>

int main(void)
{
    int x = 9;
    int *p = &x;
    printf("%d", *p);
    return 0;
}
```

What is the correct interpretation?

A. It fails because `*p` can only assign.
B. It prints the address of `x`.
C. It prints an indeterminate value.
D. It prints `9`.

### Question 135 — Changing through pointer

```c
#include <stdio.h>

int main(void)
{
    int x = 9;
    int *p = &x;
    *p = 4;
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `9`.
B. It prints `4`.
C. It fails because `*p` is read-only.
D. It prints the pointer value.

### Question 136 — Address operator

```c
#include <stdio.h>

int main(void)
{
    int x = 5;
    int *p = &x;
    printf("%d", p == &x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `0`.
B. It prints `1`.
C. It prints `5`.
D. It fails because addresses cannot be compared for equality.

### Question 137 — Array-to-pointer use

```c
#include <stdio.h>

int main(void)
{
    int a[3] = {2, 4, 6};
    int *p = a;
    printf("%d", *(p + 2));
    return 0;
}
```

What is the correct interpretation?

A. It prints `4`.
B. It prints `2`.
C. It prints `6`.
D. It fails because arrays cannot initialize pointers.

### Question 138 — Pointer arithmetic units

```c
#include <stdio.h>

int main(void)
{
    int a[3] = {10, 20, 30};
    int *p = a;
    p++;
    printf("%d", *p);
    return 0;
}
```

What is the correct interpretation?

A. It prints the byte after the first element.
B. It prints `20`.
C. It prints `10`.
D. It prints `30`.

### Question 139 — Pointers and arrays syntax

```c
#include <stdio.h>

int main(void)
{
    int a[3] = {7, 8, 9};
    printf("%d", 1[a]);
    return 0;
}
```

What is the correct interpretation?

A. It prints `8`.
B. It prints the address of `a[1]`.
C. It fails because `1[a]` is invalid syntax.
D. It prints `7`.

### Question 140 — Two-dimensional indexing

```c
#include <stdio.h>

int main(void)
{
    int m[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("%d", m[1][2]);
    return 0;
}
```

What is the correct interpretation?

A. It prints `6`.
B. It prints `3`.
C. It prints `4`.
D. It prints `5`.

### Question 141 — Multidimensional partial init

```c
#include <stdio.h>

int main(void)
{
    int m[2][2] = {{1}, {2}};
    printf("%d %d", m[0][1], m[1][0]);
    return 0;
}
```

What is the correct interpretation?

A. It prints `0 2`.
B. It prints `1 2`.
C. It fails because nested braces must fill all cells.
D. It prints an indeterminate value and `2`.

### Question 142 — Array sorting pass

```c
#include <stdio.h>

int main(void)
{
    int a[3] = {3, 1, 2};
    for (int i = 0; i < 2; i++) {
        if (a[i] > a[i + 1]) {
            int t = a[i];
            a[i] = a[i + 1];
            a[i + 1] = t;
        }
    }
    printf("%d%d%d", a[0], a[1], a[2]);
    return 0;
}
```

What is the correct interpretation?

A. It prints `312`.
B. It prints `132`.
C. It prints `213`.
D. It prints `123`.

### Question 143 — Pointer difference

```c
#include <stdio.h>

int main(void)
{
    int a[5] = {0};
    int *p = &a[4];
    int *q = &a[1];
    printf("%td", p - q);
    return 0;
}
```

What is the correct interpretation?

A. It prints `3`.
B. It prints the byte difference.
C. It is undefined because pointers in the same array cannot be subtracted.
D. It prints `5`.

### Question 144 — NULL comparison

```c
#include <stdio.h>

int main(void)
{
    int *p = NULL;
    if (p == NULL)
        printf("empty");
    else
        printf("%d", *p);
    return 0;
}
```

What is the correct interpretation?

A. It prints `empty`.
B. It fails because NULL cannot be assigned to pointers.
C. It dereferences NULL and crashes.
D. It prints `0`.

### Question 145 — Dereferencing NULL

```c
#include <stdio.h>

int main(void)
{
    int *p = NULL;
    printf("%d", *p);
    return 0;
}
```

What is the correct interpretation?

A. It has undefined behavior because it dereferences a null pointer.
B. It fails because `printf` cannot print `*p`.
C. It prints `0`.
D. It prints `NULL`.

### Question 146 — sizeof array vs pointer

```c
#include <stdio.h>

int main(void)
{
    int a[10];
    int *p = a;
    printf("%d", sizeof a == sizeof p);
    return 0;
}
```

What is the correct interpretation?

A. It usually prints `0`; an array object size is not the same concept as pointer object size.
B. It always prints `1`.
C. It fails because `sizeof` cannot be applied to pointers.
D. It has undefined behavior.

### Question 147 — Function parameter array decay

```c
#include <stdio.h>

void f(int a[])
{
    printf("%zu", sizeof a);
}

int main(void)
{
    int x[4] = {0};
    f(x);
    return 0;
}
```

What is the correct interpretation?

A. It prints the number of elements.
B. Inside `f`, `a` is adjusted to a pointer parameter, so `sizeof a` is the size of a pointer.
C. Inside `f`, `sizeof a` is always 4 times `sizeof(int)`.
D. The code cannot compile because arrays cannot be parameters.

### Question 148 — Dynamic allocation basic

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = malloc(3 * sizeof *p);
    if (p == NULL)
        return 1;
    p[0] = 4;
    p[1] = 5;
    p[2] = 6;
    printf("%d", p[1]);
    free(p);
    return 0;
}
```

What is the correct interpretation?

A. It leaks memory because `free` is missing.
B. It prints `5`.
C. It prints the address returned by malloc.
D. It fails because malloc memory cannot use `[]`.

### Question 149 — malloc header

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = malloc(sizeof *p);
    if (p) {
        *p = 12;
        printf("%d", *p);
        free(p);
    }
    return 0;
}
```

What is the correct interpretation?

A. `<stdlib.h>` is the correct standard header for `malloc` and `free` declarations.
B. `<stdio.h>` declares `malloc` and `free`.
C. No header is ever needed for `malloc`.
D. `malloc` returns an int in modern C.

### Question 150 — Use after free

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = malloc(sizeof *p);
    if (!p)
        return 1;
    *p = 3;
    free(p);
    printf("%d", *p);
    return 0;
}
```

What is the correct interpretation?

A. It always prints `3` safely.
B. It fails because `free` prints the value.
C. It has undefined behavior because it reads through a pointer after `free`.
D. It prints `0` because free clears memory.

### Question 151 — Freeing NULL

```c
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *p = NULL;
    free(p);
    printf("ok");
    return 0;
}
```

What is the correct interpretation?

A. It prints `ok`; calling `free(NULL)` is safe.
B. It prints nothing because free exits the program.
C. It fails to compile because `free` requires non-NULL.
D. It has undefined behavior because NULL cannot be freed.

### Question 152 — Out-of-bounds access

```c
#include <stdio.h>

int main(void)
{
    int a[3] = {1, 2, 3};
    printf("%d", a[3]);
    return 0;
}
```

What is the correct interpretation?

A. It fails because arrays cannot be indexed with constants.
B. It prints `0`.
C. It has undefined behavior because index 3 is outside the array.
D. It prints the last element, `3`.

### Question 153 — Pointer to pointer

```c
#include <stdio.h>

int main(void)
{
    int x = 5;
    int *p = &x;
    int **pp = &p;
    **pp = 8;
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `5`.
B. It prints `8`.
C. It fails because double pointers cannot point to local variables.
D. It prints the address of `x`.

### Question 154 — Array of pointers

```c
#include <stdio.h>

int main(void)
{
    int a = 1, b = 2;
    int *p[2] = {&a, &b};
    printf("%d", *p[1]);
    return 0;
}
```

What is the correct interpretation?

A. It prints the address of `b`.
B. It prints `2`.
C. It fails because arrays cannot store pointers.
D. It prints `1`.

### Question 155 — Pointer to array element

```c
#include <stdio.h>

int main(void)
{
    int a[3] = {4, 5, 6};
    int *p = &a[1];
    printf("%d", p[1]);
    return 0;
}
```

What is the correct interpretation?

A. It is always undefined because p does not point to the first element.
B. It prints `6`.
C. It prints `4`.
D. It prints `5`.

### Question 156 — Array assignment invalid

```c
#include <stdio.h>

int main(void)
{
    int a[2] = {1, 2};
    int b[2] = {3, 4};
    /* a = b; */
    printf("%d", a[0]);
    return 0;
}
```

What is the correct interpretation?

A. If uncommented, `a = b;` would copy both elements.
B. If uncommented, `a = b;` would swap the arrays.
C. The current program fails because arrays cannot be initialized.
D. If uncommented, `a = b;` would be invalid because array objects are not assignable.

### Question 157 — Copying array elements manually

```c
#include <stdio.h>

int main(void)
{
    int src[3] = {1, 2, 3};
    int dst[3] = {0};
    for (int i = 0; i < 3; i++)
        dst[i] = src[i];
    printf("%d", dst[2]);
    return 0;
}
```

What is the correct interpretation?

A. It prints `2`.
B. It prints `0`.
C. It prints `3`.
D. It fails because arrays cannot be copied element by element.

### Question 158 — Dynamic array indexing

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a = malloc(4 * sizeof *a);
    if (!a)
        return 1;
    for (int i = 0; i < 4; i++)
        a[i] = i * i;
    printf("%d", *(a + 3));
    free(a);
    return 0;
}
```

What is the correct interpretation?

A. It prints `9`.
B. It prints `3`.
C. It prints `6`.
D. It has undefined behavior because dynamic memory cannot use pointer arithmetic.

### Question 159 — Pointer comparison in same array

```c
#include <stdio.h>

int main(void)
{
    int a[3] = {0};
    int *p = &a[0];
    int *q = &a[2];
    printf("%d", p < q);
    return 0;
}
```

What is the correct interpretation?

A. It prints `1` because both pointers point into the same array and p precedes q.
B. It prints the distance between p and q.
C. It always fails because pointers cannot be ordered.
D. It has undefined behavior because pointer comparisons are never allowed.

### Question 160 — Incrementing through array

```c
#include <stdio.h>

int main(void)
{
    int a[4] = {1, 2, 3, 4};
    int *p = a;
    int sum = 0;
    for (int i = 0; i < 4; i++)
        sum += *p++;
    printf("%d", sum);
    return 0;
}
```

What is the correct interpretation?

A. It has undefined behavior because `*p++` is invalid.
B. It prints `1234`.
C. It prints `4`.
D. It prints `10`.

### Question 161 — Precedence of * and ++

```c
#include <stdio.h>

int main(void)
{
    int a[3] = {10, 20, 30};
    int *p = a;
    printf("%d ", *p++);
    printf("%d", *p);
    return 0;
}
```

What is the correct interpretation?

A. It prints `10 10`.
B. It prints `20 30`.
C. It prints `20 20`.
D. It prints `10 20`.

### Question 162 — Increment pointed value

```c
#include <stdio.h>

int main(void)
{
    int a[2] = {5, 6};
    int *p = a;
    (*p)++;
    printf("%d %d", a[0], a[1]);
    return 0;
}
```

What is the correct interpretation?

A. It prints `6 6`.
B. It increments the pointer and prints `5 6`.
C. It prints `5 6`.
D. It prints `5 7`.

### Question 163 — One-past pointer

```c
#include <stdio.h>

int main(void)
{
    int a[3] = {1, 2, 3};
    int *p = a + 3;
    printf("%td", p - a);
    return 0;
}
```

What is the correct interpretation?

A. It has undefined behavior because forming one-past pointer is always invalid.
B. It fails because pointer subtraction returns void.
C. It prints the byte size of the array.
D. It prints `3`.

### Question 164 — Dereferencing one-past pointer

```c
#include <stdio.h>

int main(void)
{
    int a[3] = {1, 2, 3};
    int *p = a + 3;
    printf("%d", *p);
    return 0;
}
```

What is the correct interpretation?

A. It has undefined behavior because the one-past pointer is not dereferenceable.
B. It fails because `a + 3` cannot be formed.
C. It prints `0`.
D. It prints `3`.

### Question 165 — malloc size bug recognition

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = malloc(5 * sizeof *p);
    if (!p)
        return 1;
    p[4] = 10;
    printf("%d", p[4]);
    free(p);
    return 0;
}
```

What is the correct interpretation?

A. It safely allocates space for 5 int objects and prints `10`.
B. It allocates 5 bytes only and must fail.
C. It is invalid because `sizeof *p` cannot be used before p is initialized.
D. It leaks memory.

### Question 166 — Memory leak recognition

```c
#include <stdlib.h>

int main(void)
{
    int *p = malloc(10 * sizeof *p);
    if (!p)
        return 1;
    p[0] = 1;
    return 0;
}
```

What is the correct interpretation?

A. The allocated memory is not released before program termination; this is a memory leak pattern.
B. The code has no allocation.
C. The code frees memory automatically before return in standard C.
D. The code cannot compile because `p[0]` is invalid.


## Block 7 – String Manipulation

### Question 167 — String length excluding terminator

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "cat";
    printf("%zu", strlen(s));
    return 0;
}
```

What is the correct interpretation?

A. It prints the size of the array in bytes.
B. It prints `4`.
C. It prints `3`.
D. It fails because `strlen` cannot read arrays.

### Question 168 — Array size including terminator

```c
#include <stdio.h>

int main(void)
{
    char s[] = "cat";
    printf("%zu", sizeof s);
    return 0;
}
```

What is the correct interpretation?

A. It prints the address of `s`.
B. It prints `3`.
C. It prints `4`.
D. It fails because `sizeof` cannot be used with strings.

### Question 169 — String indexing

```c
#include <stdio.h>

int main(void)
{
    char s[] = "code";
    printf("%c", s[2]);
    return 0;
}
```

What is the correct interpretation?

A. It prints `o`.
B. It prints `d`.
C. It prints `2`.
D. It prints `e`.

### Question 170 — Null terminator character

```c
#include <stdio.h>

int main(void)
{
    char s[] = "hi";
    printf("%d", s[2] == '\0');
    return 0;
}
```

What is the correct interpretation?

A. It prints `1`.
B. It prints `2`.
C. It has undefined behavior.
D. It prints `0`.

### Question 171 — Manual string initialization

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[4] = {'C', 'L', 'E', '\0'};
    printf("%zu", strlen(s));
    return 0;
}
```

What is the correct interpretation?

A. It fails because character arrays cannot be strings.
B. It prints `4`.
C. It prints an indeterminate value.
D. It prints `3`.

### Question 172 — Missing null terminator

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[3] = {'C', 'L', 'E'};
    printf("%zu", strlen(s));
    return 0;
}
```

What is the correct interpretation?

A. It prints `3` safely.
B. It has undefined behavior because `strlen` expects a null-terminated string.
C. It fails because arrays must include `'\00'`.
D. It prints `4` safely.

### Question 173 — strcpy basic

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char dst[10];
    strcpy(dst, "sun");
    printf("%s", dst);
    return 0;
}
```

What is the correct interpretation?

A. It prints nothing because dst was uninitialized.
B. It prints `sun`.
C. It fails because strcpy cannot copy string literals.
D. It prints the address of dst.

### Question 174 — strcat appends

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[10] = "C";
    strcat(s, "LE");
    printf("%s", s);
    return 0;
}
```

What is the correct interpretation?

A. It fails because `strcat` cannot append to arrays.
B. It prints `CLE`.
C. It prints `C`.
D. It prints `LE`.

### Question 175 — Buffer capacity for string

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[4] = "abc";
    printf("%zu", sizeof s);
    return 0;
}
```

What is the correct interpretation?

A. It prints `4`.
B. It prints `3`.
C. It prints the result of `strlen`.
D. It has undefined behavior.

### Question 176 — Too small string array

```c
#include <stdio.h>

int main(void)
{
    char s[3] = "abc";
    printf("%c", s[2]);
    return 0;
}
```

What is the correct interpretation?

A. It must fail to compile in all C compilers.
B. It prints the whole string safely with `%s`.
C. It prints `c`; however the array has no room for a null terminator, so it is not a valid C string.
D. It prints `b`.

### Question 177 — ASCII arithmetic

```c
#include <stdio.h>

int main(void)
{
    char c = '0' + 5;
    printf("%c", c);
    return 0;
}
```

What is the correct interpretation?

A. It prints `5` on ASCII-compatible systems.
B. It prints an integer `5`.
C. It prints `0 + 5`.
D. It fails because char arithmetic is invalid.

### Question 178 — Character array processing

```c
#include <stdio.h>

int main(void)
{
    char s[] = "abc";
    for (int i = 0; s[i] != '\0'; i++)
        s[i] = s[i] + 1;
    printf("%s", s);
    return 0;
}
```

What is the correct interpretation?

A. It prints `bcd` on ASCII-compatible systems.
B. It prints `123`.
C. It prints `abc`.
D. It has undefined behavior because string literals are read-only.

### Question 179 — Modifying array initialized from string literal

```c
#include <stdio.h>

int main(void)
{
    char s[] = "abc";
    s[0] = 'A';
    printf("%s", s);
    return 0;
}
```

What is the correct interpretation?

A. It fails because arrays cannot be modified.
B. It prints `Abc`.
C. It has undefined behavior because all strings are read-only.
D. It prints `abc`.

### Question 180 — Modifying string literal through pointer

```c
#include <stdio.h>

int main(void)
{
    char *s = "abc";
    s[0] = 'A';
    printf("%s", s);
    return 0;
}
```

What is the correct interpretation?

A. It prints `abc`.
B. It safely prints `Abc`.
C. It has undefined behavior because it attempts to modify a string literal.
D. It fails because pointers cannot point to string literals.

### Question 181 — Pointer scanning string

```c
#include <stdio.h>

int main(void)
{
    char s[] = "abcd";
    char *p = s;
    while (*p != '\0')
        p++;
    printf("%td", p - s);
    return 0;
}
```

What is the correct interpretation?

A. It prints `3`.
B. It prints the address of the null terminator.
C. It prints `4`.
D. It prints `5`.

### Question 182 — String comparison trap

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[] = "hi";
    char b[] = "hi";
    printf("%d", strcmp(a, b) == 0);
    return 0;
}
```

What is the correct interpretation?

A. It prints `0`.
B. It prints `1`.
C. It has undefined behavior.
D. It fails because `strcmp` cannot compare arrays.

### Question 183 — Pointer equality vs string equality

```c
#include <stdio.h>

int main(void)
{
    char a[] = "hi";
    char b[] = "hi";
    printf("%d", a == b);
    return 0;
}
```

What is the correct interpretation?

A. It fails because arrays cannot appear in expressions.
B. It prints `0` because the two arrays are different objects.
C. It prints `1` because the text is the same.
D. It has undefined behavior.

### Question 184 — strcpy overlap note

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[10] = "abc";
    strcpy(s + 1, "xy");
    printf("%s", s);
    return 0;
}
```

What is the correct interpretation?

A. It prints `xyc`.
B. It prints `axy`.
C. It prints `abcxy`.
D. It fails because destination cannot be an offset.

### Question 185 — Header for string functions

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "abc";
    printf("%zu", strlen(s));
    return 0;
}
```

What is the correct interpretation?

A. `<string.h>` provides the declaration of `strlen`.
B. `strlen` is a keyword and needs no header.
C. `<stdio.h>` provides the declaration of `strlen`.
D. `strlen` is declared in `<stdlib.h>` only.

### Question 186 — Scanning a word

```c
#include <stdio.h>

int main(void)
{
    char s[20];
    scanf("%19s", s);
    printf("%c", s[0]);
    return 0;
}
```

What is the correct interpretation?

A. It fails because `%s` requires `&s`.
B. For input `code test`, it prints `c`.
C. It reads the whole line including spaces.
D. For input `code test`, it prints `t`.


## Block 8 – The Basics of Functions

### Question 187 — Function call and return value

```c
#include <stdio.h>

int add2(int x)
{
    return x + 2;
}

int main(void)
{
    printf("%d", add2(5));
    return 0;
}
```

What is the correct interpretation?

A. It prints `2`.
B. It fails because functions cannot return expressions.
C. It prints `5`.
D. It prints `7`.

### Question 188 — Pass by value

```c
#include <stdio.h>

void change(int x)
{
    x = 10;
}

int main(void)
{
    int a = 3;
    change(a);
    printf("%d", a);
    return 0;
}
```

What is the correct interpretation?

A. It fails because void functions cannot have parameters.
B. It prints `3`.
C. It prints an indeterminate value.
D. It prints `10`.

### Question 189 — Pass address to modify caller object

```c
#include <stdio.h>

void change(int *x)
{
    *x = 10;
}

int main(void)
{
    int a = 3;
    change(&a);
    printf("%d", a);
    return 0;
}
```

What is the correct interpretation?

A. It prints the address of `a`.
B. It prints `10`.
C. It fails because `&a` cannot be passed to a function.
D. It prints `3`.

### Question 190 — Function prototype use

```c
#include <stdio.h>

int square(int);

int main(void)
{
    printf("%d", square(4));
    return 0;
}

int square(int x)
{
    return x * x;
}
```

What is the correct interpretation?

A. It has undefined behavior.
B. It fails because the function is defined after main even with a prototype.
C. It prints `8`.
D. It prints `16`.

### Question 191 — Missing return in non-void function

```c
#include <stdio.h>

int f(void)
{
}

int main(void)
{
    printf("%d", f());
    return 0;
}
```

What is the correct interpretation?

A. It prints nothing and exits before main.
B. It has undefined behavior if the caller uses the returned value.
C. It always prints `0`.
D. It fails because empty function bodies are impossible.

### Question 192 — Void function side effect

```c
#include <stdio.h>

void greet(void)
{
    printf("hi");
}

int main(void)
{
    greet();
    return 0;
}
```

What is the correct interpretation?

A. It prints `hi`.
B. It prints the address of `greet`.
C. It prints nothing because void functions cannot call printf.
D. It fails because void functions must return a value.

### Question 193 — Return exits function early

```c
#include <stdio.h>

int f(int x)
{
    if (x > 0)
        return 1;
    return 0;
}

int main(void)
{
    printf("%d", f(5));
    return 0;
}
```

What is the correct interpretation?

A. It prints `1`.
B. It executes both returns and fails.
C. It prints `0`.
D. It prints `10`.

### Question 194 — Array parameter modification

```c
#include <stdio.h>

void set_first(int a[])
{
    a[0] = 99;
}

int main(void)
{
    int v[2] = {1, 2};
    set_first(v);
    printf("%d", v[0]);
    return 0;
}
```

What is the correct interpretation?

A. It fails because arrays are passed by value as full copies.
B. It has undefined behavior.
C. It prints `1`.
D. It prints `99`.

### Question 195 — Static local variable

```c
#include <stdio.h>

int next(void)
{
    static int x = 0;
    x++;
    return x;
}

int main(void)
{
    printf("%d%d", next(), next());
    return 0;
}
```

What is the correct interpretation?

A. It prints `01`.
B. It has undefined behavior because the two function calls modify the same static object in unsequenced argument evaluations.
C. It prints `12`.
D. It prints `11`.

### Question 196 — Safe static variable observation

```c
#include <stdio.h>

int next(void)
{
    static int x = 0;
    x++;
    return x;
}

int main(void)
{
    int a = next();
    int b = next();
    printf("%d%d", a, b);
    return 0;
}
```

What is the correct interpretation?

A. It prints `12`.
B. It fails because static locals reset on every call.
C. It prints `01`.
D. It prints `11`.

### Question 197 — Recursive function

```c
#include <stdio.h>

int f(int n)
{
    if (n == 0)
        return 1;
    return n * f(n - 1);
}

int main(void)
{
    printf("%d", f(4));
    return 0;
}
```

What is the correct interpretation?

A. It prints `16`.
B. It prints `24`.
C. It loops forever.
D. It prints `10`.

### Question 198 — Standard library function

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = abs(-7);
    printf("%d", x);
    return 0;
}
```

What is the correct interpretation?

A. It prints `-7`.
B. It prints an address.
C. It fails because `abs` is in `<stdio.h>` only.
D. It prints `7`.

### Question 199 — Function declaration mismatch

```c
#include <stdio.h>

int f(int x)
{
    return x + 1;
}

int main(void)
{
    printf("%d", f(2));
    return 0;
}
```

What is the correct interpretation?

A. It fails because every function must be declared with `void` parameters.
B. It has undefined behavior.
C. It prints `3`.
D. It prints `2`.

### Question 200 — Multiple parameters

```c
#include <stdio.h>

int mix(int a, int b)
{
    return a * 10 + b;
}

int main(void)
{
    printf("%d", mix(3, 7));
    return 0;
}
```

What is the correct interpretation?

A. It prints `37`.
B. It fails because C functions can take only one parameter.
C. It prints `73`.
D. It prints `10`.


---

## Answer key

| Q | Answer | Q | Answer | Q | Answer | Q | Answer |
|---:|:---:|---:|:---:|---:|:---:|---:|:---:|
| 1 | D | 51 | D | 101 | C | 151 | A |
| 2 | C | 52 | A | 102 | A | 152 | C |
| 3 | A | 53 | D | 103 | A | 153 | B |
| 4 | C | 54 | A | 104 | B | 154 | B |
| 5 | A | 55 | C | 105 | A | 155 | B |
| 6 | A | 56 | A | 106 | C | 156 | D |
| 7 | B | 57 | C | 107 | A | 157 | C |
| 8 | C | 58 | D | 108 | B | 158 | A |
| 9 | C | 59 | C | 109 | B | 159 | A |
| 10 | D | 60 | B | 110 | D | 160 | D |
| 11 | B | 61 | A | 111 | B | 161 | D |
| 12 | D | 62 | C | 112 | A | 162 | A |
| 13 | C | 63 | C | 113 | A | 163 | D |
| 14 | D | 64 | B | 114 | D | 164 | A |
| 15 | A | 65 | B | 115 | D | 165 | A |
| 16 | D | 66 | C | 116 | A | 166 | A |
| 17 | D | 67 | B | 117 | B | 167 | C |
| 18 | C | 68 | D | 118 | C | 168 | C |
| 19 | D | 69 | A | 119 | D | 169 | B |
| 20 | A | 70 | C | 120 | B | 170 | A |
| 21 | A | 71 | D | 121 | D | 171 | D |
| 22 | D | 72 | C | 122 | B | 172 | B |
| 23 | A | 73 | D | 123 | A | 173 | B |
| 24 | A | 74 | D | 124 | A | 174 | B |
| 25 | C | 75 | B | 125 | C | 175 | A |
| 26 | C | 76 | D | 126 | D | 176 | C |
| 27 | C | 77 | C | 127 | B | 177 | A |
| 28 | C | 78 | A | 128 | D | 178 | A |
| 29 | C | 79 | A | 129 | C | 179 | B |
| 30 | A | 80 | A | 130 | D | 180 | C |
| 31 | B | 81 | D | 131 | B | 181 | C |
| 32 | A | 82 | B | 132 | D | 182 | B |
| 33 | B | 83 | A | 133 | A | 183 | B |
| 34 | C | 84 | C | 134 | D | 184 | B |
| 35 | C | 85 | D | 135 | B | 185 | A |
| 36 | D | 86 | A | 136 | B | 186 | B |
| 37 | B | 87 | B | 137 | C | 187 | D |
| 38 | A | 88 | D | 138 | B | 188 | B |
| 39 | B | 89 | C | 139 | A | 189 | B |
| 40 | B | 90 | B | 140 | A | 190 | D |
| 41 | C | 91 | B | 141 | A | 191 | B |
| 42 | C | 92 | D | 142 | B | 192 | A |
| 43 | D | 93 | C | 143 | A | 193 | A |
| 44 | D | 94 | A | 144 | A | 194 | D |
| 45 | B | 95 | D | 145 | A | 195 | B |
| 46 | D | 96 | A | 146 | A | 196 | A |
| 47 | B | 97 | C | 147 | B | 197 | B |
| 48 | C | 98 | D | 148 | B | 198 | D |
| 49 | C | 99 | C | 149 | A | 199 | C |
| 50 | D | 100 | D | 150 | C | 200 | A |

## Answer distribution

- A: 57
- B: 50
- C: 46
- D: 47

## Final checklist by weak detail

- Literals: octal `010`, hexadecimal `0x10`, scientific notation, char literals, escape sequences.
- I/O: `printf` vs `puts`, `scanf` address rules, width/precision, correct headers.
- Operators: precedence, associativity, `++`, `--`, compound assignment, logical vs bitwise, short-circuiting.
- Control flow: dangling `else`, independent `if` vs `else if`, `switch` fall-through, `default` position.
- Loops: off-by-one, empty loop body, `break`, `continue`, nested loop behavior, infinite loops.
- Arrays/pointers: array decay, `sizeof` array vs pointer, `NULL`, one-past pointer, pointer arithmetic, out-of-bounds.
- Memory: `malloc`, `free`, `free(NULL)`, use-after-free, leaks.
- Strings: null terminator, `strlen`, `strcpy`, `strcat`, string literal mutability, pointer equality vs string equality.
- Functions: prototypes, pass-by-value, pointer parameters, array parameters, `return`, static locals, standard library calls.
