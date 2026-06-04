# CPE – C++ Certified Entry-Level Programmer  
## 200 Code-Analysis Multiple-Choice Questions

**Purpose:** practice reading short C++ snippets and choosing the correct interpretation, output, compile-time result, runtime result, or semantic explanation.

**Important note:** These are original practice questions inspired by the public CPE syllabus and C++ Essentials 1 topics from the C++ Institute/OpenEDG. They are **not** official exam questions and not a dump of any real exam.

**Assumptions unless a question says otherwise:**
- Code is compiled as standard C++17.
- Required headers shown in the snippet are part of the intended question.
- Output questions ignore the process exit code.
- When a question asks about undefined behavior, the correct answer is the language-level result, not a particular compiler's accidental output.

## Coverage Map

| Block | Questions | Main focus |
|---|---:|---|
| Block 1 – Syntax, Literals, and Operators | 1–56 | syntax, keywords, literals, basic types, casts, operators, precedence, short-circuiting, streams, manipulators |
| Block 2 – Flow Control and Functions | 57–112 | if/else, switch, loops, break/continue, goto, functions, return, value/reference/pointer passing, recursion |
| Block 3 – Vectors and Pointers | 113–160 | arrays, multidimensional arrays, vectors, vector::data, pointers, nullptr, pointer arithmetic, dynamic memory |
| Block 4 – Structures and Strings | 161–200 | structs, dot/arrow access, vector of structs, std::string operations, comparisons, substr/insert/erase/find |

---

## Questions

### Question 001 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 7;
    x = x + 3;
    cout << x;
}
```

A. `3`
B. `7`
C. `73`
D. `10`

### Question 002 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    char c = 'A';
    cout << c << " " << int(c);
}
```

A. `65`
B. `A 64`
C. `A 65`
D. `65 A`

### Question 003 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    bool a = true;
    bool b = false;
    cout << a << b;
}
```

A. `truefalse`
B. `01`
C. `1 0`
D. `10`

### Question 004 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << 9 / 4;
}
```

A. `2.25`
B. `3`
C. `2`
D. `1`

### Question 005 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << 17 % 5;
}
```

A. `3`
B. `5`
C. `0`
D. `2`

### Question 006 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 2;
    cout << static_cast<double>(a) / b;
}
```

A. `2`
B. `3`
C. `2.0`
D. `2.5`

### Question 007 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << 2 + 3 * 4;
}
```

A. `24`
B. `20`
C. `14`
D. `9`

### Question 008 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << (2 + 3) * 4;
}
```

A. `14`
B. `9`
C. `20`
D. `24`

### Question 009 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 3, b = 4;
    cout << (a < b && b < 10);
}
```

A. `1`
B. `true`
C. `0`
D. `3`

### Question 010 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 0;
    if (x != 0 && 10 / x > 1)
        cout << "yes";
    else
        cout << "no";
}
```

A. `The program crashes.`
B. `The behavior is undefined.`
C. `no`
D. `yes`

### Question 011 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 0;
    if (x == 0 || 10 / x > 1)
        cout << "yes";
    else
        cout << "no";
}
```

A. `The program crashes.`
B. `no`
C. `The behavior is undefined.`
D. `yes`

### Question 012 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << (6 & 3);
}
```

A. `3`
B. `5`
C. `7`
D. `2`

### Question 013 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << (6 | 3);
}
```

A. `3`
B. `2`
C. `7`
D. `5`

### Question 014 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << (6 ^ 3);
}
```

A. `7`
B. `3`
C. `2`
D. `5`

### Question 015 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << (3 << 2);
}
```

A. `12`
B. `6`
C. `1`
D. `9`

### Question 016 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << (16 >> 2);
}
```

A. `2`
B. `4`
C. `32`
D. `8`

### Question 017 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 4;
    x += 3 * 2;
    cout << x;
}
```

A. `14`
B. `7`
C. `11`
D. `10`

### Question 018 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    a = b = c = 5;
    cout << a << b << c;
}
```

A. `15`
B. `5`
C. `555`
D. `5555`

### Question 019 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    cout << ++x << " " << x;
}
```

A. `5 5`
B. `6 5`
C. `5 6`
D. `6 6`

### Question 020 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    cout << x++ << " " << x;
}
```

A. `5 6`
B. `6 6`
C. `5 5`
D. `6 5`

### Question 021 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int y = x > 5 ? x + 1 : x - 1;
    cout << y;
}
```

A. `11`
B. `10`
C. `1`
D. `9`

### Question 022 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << sizeof(char) << " " << sizeof('A');
}
```

A. `1 1`
B. `4 1`
C. `4 4`
D. `1 4`

### Question 023 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 010;
    cout << x;
}
```

A. `10`
B. `16`
C. `2`
D. `8`

### Question 024 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 0x10;
    cout << x;
}
```

A. `8`
B. `0`
C. `16`
D. `10`

### Question 025 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 0b1010;
    cout << x;
}
```

A. `12`
B. `10`
C. `8`
D. `1010`

### Question 026 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << fixed << setprecision(2) << 3.0 / 2;
}
```

A. `1.5`
B. `1`
C. `1.50`
D. `2.00`

### Question 027 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "[" << setw(4) << 7 << "]";
}
```

A. `[7]`
B. `[  7]`
C. `[7   ]`
D. `[   7]`

### Question 028 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setw(3) << 1 << 2;
}
```

A. `  1  2`
B. ` 12`
C. `  12`
D. `12`

### Question 029 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "A" << endl << "B";
}
```

A. `B
A`
B. `AB`
C. `A
B`
D. `A B`

### Question 030 — Block 1 – Syntax, Literals, and Operators

Which statement best describes this program?

```cpp
#include <iostream>

int main() {
    cout << "Hello";
}
```

A. The program does not compile because cout is not qualified and no using declaration is present.
B. It prints `Hello`.
C. It compiles because iostream automatically imports cout.
D. It prints nothing but exits normally.

### Question 031 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using std::cout;

int main() {
    cout << "ok";
}
```

A. `The program does not compile.`
B. `ok`
C. ``
D. `std::cout`

### Question 032 — Block 1 – Syntax, Literals, and Operators

What happens when this program is compiled?

```cpp
#include <iostream>
using namespace std;

int main() {
    int class = 4;
    cout << class;
}
```

A. The program does not compile.
B. The behavior is undefined.
C. It prints `class`.
D. It prints `4`.

### Question 033 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 1;
    // x = x + 10;
    cout << x;
}
```

A. `1`
B. `11`
C. `10`
D. `The program does not compile.`

### Question 034 — Block 1 – Syntax, Literals, and Operators

What happens when this program is compiled?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x{3.7};
    cout << x;
}
```

A. It prints `3`.
B. It prints `3.7`.
C. The program does not compile.
D. It prints `4`.

### Question 035 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 3.9;
    cout << x;
}
```

A. `4`
B. `3.9`
C. `3`
D. `The program does not compile.`

### Question 036 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    double x = 5 / 2;
    cout << x;
}
```

A. `2.5`
B. `2.0`
C. `3`
D. `2`

### Question 037 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << static_cast<int>(7.8);
}
```

A. `8`
B. `7`
C. `7.8`
D. `The program does not compile.`

### Question 038 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    bool a = false;
    bool b = false;
    cout << (!a == b);
}
```

A. `0`
B. `true`
C. `1`
D. `false`

### Question 039 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << (1 < 2 < 1);
}
```

A. `1`
B. `0`
C. `2`
D. `The program does not compile.`

### Question 040 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = (1, 2, 3);
    cout << x;
}
```

A. `The program does not compile.`
B. `1`
C. `2`
D. `3`

### Question 041 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "C++\nTest";
}
```

A. `C++Test`
B. `C++\nTest`
C. `C++
Test`
D. `C++ Test`

### Question 042 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    char c = '\n';
    cout << int(c);
}
```

A. `n`
B. `0`
C. `10`
D. `The program does not compile.`

### Question 043 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    unsigned int x = 0;
    x = x - 1;
    cout << (x > 0);
}
```

A. `The behavior is undefined.`
B. `0`
C. `-1`
D. `1`

### Question 044 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << boolalpha << (3 < 5);
}
```

A. `0`
B. `true`
C. `false`
D. `1`

### Question 045 — Block 1 – Syntax, Literals, and Operators

Assume the user enters `42 13`. What is printed?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << b << ":" << a;
}
```

A. `42:13`
B. `13:42`
C. The program does not compile.
D. `42 13`

### Question 046 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << (3 < 4);
}
```

A. `0`
B. `1`
C. `3`
D. `true`

### Question 047 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << !5;
}
```

A. `The program does not compile.`
B. `1`
C. `5`
D. `0`

### Question 048 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    x *= 2 + 3;
    cout << x;
}
```

A. `13`
B. `10`
C. `25`
D. `15`

### Question 049 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 2;
    int y = 3;
    cout << x << y;
}
```

A. `32`
B. `23`
C. `5`
D. `2 3`

### Question 050 — Block 1 – Syntax, Literals, and Operators

What happens when this program is compiled?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5
    cout << x;
}
```

A. It prints `5`.
B. It prints nothing.
C. The behavior is undefined.
D. The program does not compile.

### Question 051 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    cout << (argc >= 1);
}
```

A. `The program does not compile.`
B. `0`
C. `argc`
D. `1`

### Question 052 — Block 1 – Syntax, Literals, and Operators

Which statement is true about this code?

```cpp
int main(int argc, char *argv[]) {
    return 0;
}
```

A. main must always be declared as void.
B. argc must be unsigned.
C. argv must be a vector.
D. It is a valid form of the main function.

### Question 053 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "[" << setw(3) << 12 << 34 << "]";
}
```

A. `[ 1234]`
B. `[  1234]`
C. `[1234]`
D. `[ 12 34]`

### Question 054 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    double d = 5 / 2;
    cout << d;
}
```

A. `2`
B. `2.0`
C. `3`
D. `2.5`

### Question 055 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << (true + true + false);
}
```

A. `3`
B. `2`
C. `1`
D. `true`

### Question 056 — Block 1 – Syntax, Literals, and Operators

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 8;
    cout << (x == 8 ? "match" : "miss");
}
```

A. `match`
B. `1`
C. `miss`
D. `8`

### Question 057 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 3;
    if (x > 0)
        cout << "A";
        cout << "B";
}
```

A. `AB`
B. `A`
C. `B`
D. `The program does not compile.`

### Question 058 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 2;
    if (x > 5)
        if (x > 1)
            cout << "A";
        else
            cout << "B";
    else
        cout << "C";
}
```

A. `A`
B. `B`
C. ``
D. `C`

### Question 059 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 2;
    switch (x) {
        case 1: cout << "A";
        case 2: cout << "B";
        case 3: cout << "C";
    }
}
```

A. `ABC`
B. `C`
C. `B`
D. `BC`

### Question 060 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 7;
    switch (x) {
        default: cout << "D";
        case 1: cout << "A"; break;
    }
}
```

A. `The program does not compile.`
B. `DA`
C. `A`
D. `D`

### Question 061 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    char grade = 'B';
    switch (grade) {
        case 'A': cout << 4; break;
        case 'B': cout << 3; break;
        default: cout << 0;
    }
}
```

A. `4`
B. `0`
C. `B`
D. `3`

### Question 062 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 1, sum = 0;
    while (i <= 3) {
        sum += i;
        ++i;
    }
    cout << sum;
}
```

A. `7`
B. `4`
C. `6`
D. `3`

### Question 063 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 5;
    do {
        cout << i;
        ++i;
    } while (i < 5);
}
```

A. ``
B. `The program does not compile.`
C. `5`
D. `6`

### Question 064 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 3; ++i)
        cout << i;
}
```

A. `012`
B. `123`
C. `3`
D. `0123`

### Question 065 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 5; ++i) {
        if (i == 3)
            break;
        cout << i;
    }
}
```

A. `3`
B. `012`
C. `01234`
D. `0123`

### Question 066 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 5; ++i) {
        if (i % 2 == 0)
            continue;
        cout << i;
    }
}
```

A. `01234`
B. `024`
C. `13`
D. `135`

### Question 067 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 2; ++i)
        for (int j = 1; j <= 2; ++j)
            cout << i << j << " ";
}
```

A. `11 22 `
B. `12 21 `
C. `11 12 21 22 `
D. `1 2 1 2 `

### Question 068 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 3;
    while (i > 0)
        cout << i--;
}
```

A. `320`
B. `210`
C. `123`
D. `321`

### Question 069 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "A";
    goto end;
    cout << "B";
end:
    cout << "C";
}
```

A. `AC`
B. `BC`
C. `ABC`
D. `A`

### Question 070 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int f() {
    return 4;
    return 9;
}

int main() {
    cout << f();
}
```

A. `9`
B. `4`
C. `13`
D. `The program does not compile.`

### Question 071 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

void f(int x) {
    x = x + 10;
}

int main() {
    int a = 1;
    f(a);
    cout << a;
}
```

A. `10`
B. `11`
C. `The program does not compile.`
D. `1`

### Question 072 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

void f(int &x) {
    x = x + 10;
}

int main() {
    int a = 1;
    f(a);
    cout << a;
}
```

A. `1`
B. `The program does not compile.`
C. `11`
D. `10`

### Question 073 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

void f(int *p) {
    *p = *p + 10;
}

int main() {
    int a = 1;
    f(&a);
    cout << a;
}
```

A. `10`
B. `The program does not compile.`
C. `11`
D. `1`

### Question 074 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

int main() {
    cout << fact(4);
}
```

A. `16`
B. `24`
C. `4`
D. `10`

### Question 075 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int sumTo(int n) {
    if (n == 0) return 0;
    return n + sumTo(n - 1);
}

int main() {
    cout << sumTo(4);
}
```

A. `4`
B. `10`
C. `24`
D. `6`

### Question 076 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int f(int n) {
    if (n == 0)
        return 100;
    return f(n - 1) + 1;
}

int main() {
    cout << f(2);
}
```

A. `101`
B. `2`
C. `100`
D. `102`

### Question 077 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int add(int a, int b = 5) {
    return a + b;
}

int main() {
    cout << add(3);
}
```

A. `3`
B. `The program does not compile.`
C. `5`
D. `8`

### Question 078 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int f(int x) { return x + 1; }
double f(double x) { return x + 0.5; }

int main() {
    cout << f(2);
}
```

A. `2.5`
B. `2`
C. `The call is ambiguous.`
D. `3`

### Question 079 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int square(int);

int main() {
    cout << square(5);
}

int square(int x) {
    return x * x;
}
```

A. `25`
B. `5`
C. `10`
D. `The program does not compile.`

### Question 080 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

void setFirst(int a[]) {
    a[0] = 99;
}

int main() {
    int data[2] = {1, 2};
    setFirst(data);
    cout << data[0];
}
```

A. `2`
B. `99`
C. `The program does not compile.`
D. `1`

### Question 081 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 1;
    {
        int x = 2;
        cout << x;
    }
    cout << x;
}
```

A. `22`
B. `21`
C. `11`
D. `12`

### Question 082 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

void f() {
    static int x = 0;
    ++x;
    cout << x;
}

int main() {
    f();
    f();
}
```

A. `12`
B. `22`
C. `11`
D. `The program does not compile.`

### Question 083 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int i;
    for (i = 0; i < 3; ++i);
    cout << i;
}
```

A. `3`
B. `The program does not compile.`
C. `0`
D. `2`

### Question 084 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    while (true) {
        cout << i;
        if (i == 2) break;
        ++i;
    }
}
```

A. `0123`
B. `The program never stops.`
C. `012`
D. `01`

### Question 085 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 3;
    while (n--)
        cout << n;
}
```

A. `210-1`
B. `32`
C. `210`
D. `321`

### Question 086 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    if (x = 0)
        cout << "T";
    else
        cout << "F";
    cout << x;
}
```

A. `T5`
B. `T0`
C. `F0`
D. `F5`

### Question 087 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 0;
    if (x = 5)
        cout << "T";
    else
        cout << "F";
    cout << x;
}
```

A. `F0`
B. `T5`
C. `T0`
D. `F5`

### Question 088 — Block 2 – Flow Control and Functions

What happens when this program is compiled?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 1;
    switch (x) {
        case 1: cout << "A"; break;
        case 1: cout << "B"; break;
    }
}
```

A. It prints `A`.
B. It prints `B`.
C. It prints `AB`.
D. The program does not compile.

### Question 089 — Block 2 – Flow Control and Functions

What happens when this program is compiled?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 1;
    switch (x) {
        case 1.5: cout << "A"; break;
    }
}
```

A. The behavior is undefined.
B. It prints nothing.
C. The program does not compile.
D. It prints `A`.

### Question 090 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

void down(int n) {
    if (n == 0) return;
    cout << n;
    down(n - 1);
}

int main() {
    down(3);
}
```

A. `3210`
B. `321`
C. `3`
D. `123`

### Question 091 — Block 2 – Flow Control and Functions

What happens when this program is compiled?

```cpp
#include <iostream>
using namespace std;

void f(int a = 1, int b) {
    cout << a + b;
}

int main() {
    f(2, 3);
}
```

A. The behavior is undefined.
B. The program does not compile.
C. It prints `4`.
D. It prints `5`.

### Question 092 — Block 2 – Flow Control and Functions

What happens when this program is compiled?

```cpp
#include <iostream>
using namespace std;

void inc(int &x) {
    ++x;
}

int main() {
    inc(5);
}
```

A. The behavior is undefined.
B. It prints nothing.
C. It prints `6`.
D. The program does not compile.

### Question 093 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

void safePrint(int *p) {
    if (p == nullptr)
        cout << "null";
    else
        cout << *p;
}

int main() {
    int x = 7;
    safePrint(&x);
}
```

A. `The program does not compile.`
B. `null`
C. `7`
D. `0`

### Question 094 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    do {
        ++i;
        if (i == 2)
            continue;
        cout << i;
    } while (i < 3);
}
```

A. `13`
B. `12`
C. `3`
D. `123`

### Question 095 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 4;
    if (x > 0)
        if (x % 2 == 0)
            cout << "E";
        else
            cout << "O";
}
```

A. `E`
B. ``
C. `EO`
D. `O`

### Question 096 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i < 8; i += 2)
        cout << i;
}
```

A. `135`
B. `1357`
C. `1234567`
D. `246`

### Question 097 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int f(int x) {
    int y = x + 1;
    return y;
}

int main() {
    int y = 10;
    cout << f(y) << " " << y;
}
```

A. `10 10`
B. `10 11`
C. `11 11`
D. `11 10`

### Question 098 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "ok";
}
```

A. `ok0`
B. ``
C. `The program does not compile.`
D. `ok`

### Question 099 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

enum Color { red = 1, green = 2 };

int main() {
    Color c = green;
    switch (c) {
        case red: cout << "R"; break;
        case green: cout << "G"; break;
    }
}
```

A. `The program does not compile.`
B. `R`
C. `G`
D. `RG`

### Question 100 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

void f(int *p) {
    if (p)
        cout << *p;
}

int main() {
    int x = 9;
    int *ptr = &x;
    f(ptr);
}
```

A. `ptr`
B. `0`
C. `The program does not compile.`
D. `9`

### Question 101 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int f(int &x) {
    return ++x;
}

int main() {
    int a = 4;
    cout << f(a) << " " << a;
}
```

A. `4 4`
B. `5 4`
C. `5 5`
D. `4 5`

### Question 102 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int f(int x = 1, int y = 2) {
    return x * 10 + y;
}

int main() {
    cout << f(5);
}
```

A. `12`
B. `52`
C. `5`
D. `57`

### Question 103 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    cout << fib(5);
}
```

A. `8`
B. `5`
C. `3`
D. `4`

### Question 104 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (j == 1) break;
            cout << i << j;
        }
    }
}
```

A. `01`
B. `0010`
C. `001122`
D. `000110`

### Question 105 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int firstEven(int a[], int n) {
    for (int i = 0; i < n; ++i)
        if (a[i] % 2 == 0)
            return a[i];
    return -1;
}

int main() {
    int data[] = {3, 5, 8, 10};
    cout << firstEven(data, 4);
}
```

A. `10`
B. `3`
C. `-1`
D. `8`

### Question 106 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 0;
    if (x)
        cout << "A";
    else if (!x)
        cout << "B";
    else
        cout << "C";
}
```

A. ``
B. `B`
C. `A`
D. `C`

### Question 107 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int f(int x) {
    if (x < 0)
        return -x;
    return x;
}

int main() {
    cout << f(-3) + f(2);
}
```

A. `The program does not compile.`
B. `1`
C. `5`
D. `-1`

### Question 108 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

void show(int n) {
    while (n > 0) {
        cout << n % 2;
        n /= 2;
    }
}

int main() {
    show(6);
}
```

A. `6`
B. `011`
C. `110`
D. `The program does not compile.`

### Question 109 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 1;
    switch (x + 1) {
        case 1: cout << "one"; break;
        case 2: cout << "two"; break;
        default: cout << "other";
    }
}
```

A. `The program does not compile.`
B. `one`
C. `other`
D. `two`

### Question 110 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int f(int n) {
    int r = 1;
    for (int i = 0; i < n; ++i)
        r *= 2;
    return r;
}

int main() {
    cout << f(4);
}
```

A. `8`
B. `32`
C. `16`
D. `4`

### Question 111 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int max2(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    cout << max2(3, 9);
}
```

A. `The program does not compile.`
B. `3`
C. `9`
D. `12`

### Question 112 — Block 2 – Flow Control and Functions

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 0;
start:
    cout << x;
    ++x;
    if (x < 3)
        goto start;
}
```

A. `012`
B. `The program never stops.`
C. `0`
D. `123`

### Question 113 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[4] = {1, 2};
    cout << a[0] << a[1] << a[2] << a[3];
}
```

A. `12`
B. `1200`
C. `120`
D. `The behavior is undefined.`

### Question 114 — Block 3 – Vectors and Pointers

Which statement best describes this program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[2] = {10, 20};
    cout << a[2];
}
```

A. It prints `0`.
B. It prints `20`.
C. The program does not compile.
D. The program has undefined behavior because it reads outside the array.

### Question 115 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int m[2][3] = {{1, 2, 3}, {4, 5, 6}};
    cout << m[1][2];
}
```

A. `5`
B. `2`
C. `3`
D. `6`

### Question 116 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {2, 4, 6};
    cout << v.size();
}
```

A. `2`
B. `6`
C. `3`
D. `The program does not compile.`

### Question 117 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(4);
    v.push_back(8);
    cout << v[0] + v[1];
}
```

A. `The program does not compile.`
B. `12`
C. `48`
D. `2`

### Question 118 — Block 3 – Vectors and Pointers

What happens when this program runs?

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    cout << v.at(3);
}
```

A. It prints `3`.
B. The program does not compile.
C. It throws an out_of_range exception.
D. It prints `0`.

### Question 119 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    int *p = v.data();
    p[1] = 9;
    cout << v[1];
}
```

A. `The program does not compile.`
B. `1`
C. `2`
D. `9`

### Question 120 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[3] = {4, 5, 6};
    int *p = a;
    cout << *p;
}
```

A. `The program does not compile.`
B. `6`
C. `4`
D. `5`

### Question 121 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int *p = &x;
    cout << *p;
}
```

A. `&x`
B. `10`
C. `The program does not compile.`
D. `p`

### Question 122 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int *p = nullptr;
    cout << (p == nullptr);
}
```

A. `1`
B. `The program does not compile.`
C. `nullptr`
D. `0`

### Question 123 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 2;
    int b = 3;
    int *p = &a;
    p = &b;
    cout << *p;
}
```

A. `2`
B. `3`
C. `5`
D. `The program does not compile.`

### Question 124 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[4] = {10, 20, 30, 40};
    int *p = a;
    cout << *(p + 2);
}
```

A. `10`
B. `40`
C. `30`
D. `20`

### Question 125 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 1;
    int y = 2;
    int *const p = &x;
    *p = 5;
    cout << x;
}
```

A. `2`
B. `1`
C. `5`
D. `The program does not compile.`

### Question 126 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int *p = new int(7);
    cout << *p;
    delete p;
}
```

A. `The program does not compile.`
B. `The behavior is undefined.`
C. `7`
D. `0`

### Question 127 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int *p = new int[3]{1, 2, 3};
    cout << p[0] << p[2];
    delete[] p;
}
```

A. `The program does not compile.`
B. `13`
C. `12`
D. `123`

### Question 128 — Block 3 – Vectors and Pointers

Which statement is correct about this program?

```cpp
int main() {
    int *p = new int[5];
    delete p;
}
```

A. It cannot compile because new int[5] is invalid.
B. It does not allocate memory.
C. It uses the wrong deallocation form; delete[] should be used for arrays.
D. It is always correct because delete and delete[] are interchangeable.

### Question 129 — Block 3 – Vectors and Pointers

Which statement best describes this program?

```cpp
int main() {
    int *p = new int(10);
    p = new int(20);
    delete p;
}
```

A. It leaks the first dynamically allocated int.
B. It has no dynamic allocation.
C. It deletes both allocated ints.
D. It does not compile.

### Question 130 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 3;
    int *p = &x;
    int **pp = &p;
    cout << **pp;
}
```

A. `The program does not compile.`
B. `p`
C. `&x`
D. `3`

### Question 131 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 2;
    int *p[2] = {&a, &b};
    cout << *p[1];
}
```

A. `2`
B. `1`
C. `12`
D. `The program does not compile.`

### Question 132 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 4;
    int *p = &x;
    *p += 6;
    cout << x;
}
```

A. `6`
B. `4`
C. `The program does not compile.`
D. `10`

### Question 133 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {1, 2};
    vector<int> b = a;
    b[0] = 9;
    cout << a[0] << b[0];
}
```

A. `19`
B. `91`
C. `11`
D. `99`

### Question 134 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    for (int x : v)
        x *= 2;
    cout << v[1];
}
```

A. `6`
B. `4`
C. `The program does not compile.`
D. `2`

### Question 135 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    for (int &x : v)
        x *= 2;
    cout << v[1];
}
```

A. `4`
B. `2`
C. `The program does not compile.`
D. `6`

### Question 136 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int m[2][2] = {{1, 2}, {3, 4}};
    int sum = 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            sum += m[i][j];
    cout << sum;
}
```

A. `4`
B. `10`
C. `7`
D. `12`

### Question 137 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[3] = {1, 2, 3};
    cout << *(a + 1);
}
```

A. `1`
B. `2`
C. `3`
D. `The program does not compile.`

### Question 138 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v(3, 7);
    cout << v[0] << v.size();
}
```

A. `The program does not compile.`
B. `37`
C. `73`
D. `77`

### Question 139 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v{3, 7};
    cout << v.size() << v[0];
}
```

A. `37`
B. `The program does not compile.`
C. `73`
D. `23`

### Question 140 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v(3);
    cout << v[0] << v[1] << v[2];
}
```

A. `The program does not compile.`
B. `000`
C. `333`
D. `The behavior is undefined.`

### Question 141 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {4, 5, 6};
    cout << v.front() + v.back();
}
```

A. `10`
B. `9`
C. `456`
D. `11`

### Question 142 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int *p = new int[4];
    for (int i = 0; i < 4; ++i)
        p[i] = i * i;
    cout << p[3];
    delete[] p;
}
```

A. `16`
B. `6`
C. `3`
D. `9`

### Question 143 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[3] = {1, 2, 3};
    int *p = &a[0];
    int *q = &a[2];
    cout << (q - p);
}
```

A. `2`
B. `1`
C. `The program does not compile.`
D. `3`

### Question 144 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 7, b = 2;
    cout << static_cast<double>(a / b);
}
```

A. `3`
B. `The program does not compile.`
C. `3.5`
D. `4`

### Question 145 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 7, b = 2;
    cout << static_cast<double>(a) / b;
}
```

A. `4`
B. `The program does not compile.`
C. `3.5`
D. `3`

### Question 146 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int *p = nullptr;
    if (p)
        cout << "A";
    else
        cout << "B";
}
```

A. `A`
B. `B`
C. `0`
D. `The program does not compile.`

### Question 147 — Block 3 – Vectors and Pointers

Which statement is correct about the declarations?

```cpp
int main() {
    int* p, q;
}
```

A. The declaration is invalid.
B. p is a pointer to int, but q is an int.
C. Both p and q are pointers to int.
D. Both p and q are ints.

### Question 148 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int *p = new int(5);
    delete p;
    cout << (p == nullptr);
}
```

A. `The program does not compile.`
B. `0`
C. `1`
D. `The behavior is undefined.`

### Question 149 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int *p = new int[3]{1, 2};
    cout << p[0] << p[1] << p[2];
    delete[] p;
}
```

A. `120`
B. `12`
C. `123`
D. `The behavior is undefined.`

### Question 150 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[5] = {0};
    cout << sizeof(a) / sizeof(a[0]);
}
```

A. `5`
B. `20`
C. `4`
D. `It depends on the first element value.`

### Question 151 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2};
    v.resize(4);
    cout << v[0] << v[2] << v.size();
}
```

A. `104`
B. `The program does not compile.`
C. `102`
D. `124`

### Question 152 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    v.clear();
    cout << v.size();
}
```

A. `The program does not compile.`
B. `0`
C. `1`
D. `3`

### Question 153 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

void change(int a[]) {
    a[1] = 50;
}

int main() {
    int data[3] = {10, 20, 30};
    change(data);
    cout << data[1];
}
```

A. `50`
B. `20`
C. `The program does not compile.`
D. `30`

### Question 154 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 0;
    int *p = &x;
    cout << (p != nullptr);
}
```

A. `x`
B. `0`
C. `The program does not compile.`
D. `1`

### Question 155 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 1;
    int *p = &x;
    int *r = p;
    *r = 4;
    cout << x;
}
```

A. `The program does not compile.`
B. `0`
C. `4`
D. `1`

### Question 156 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[3] = {2, 4, 6};
    int *p = a + 3;
    cout << (p == &a[3]);
}
```

A. `0`
B. `The behavior is undefined.`
C. `The program does not compile.`
D. `1`

### Question 157 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {5, 6, 7};
    int *p = v.data();
    cout << *(p + v.size() - 1);
}
```

A. `5`
B. `7`
C. `6`
D. `The program does not compile.`

### Question 158 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[2][2] = {};
    a[0][1] = 7;
    cout << a[0][0] << a[0][1];
}
```

A. `70`
B. `07`
C. `7`
D. `The behavior is undefined.`

### Question 159 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    vector<int> *p = &v;
    cout << (*p)[2];
}
```

A. `3`
B. `1`
C. `2`
D. `The program does not compile.`

### Question 160 — Block 3 – Vectors and Pointers

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 8;
    int &r = x;
    int *p = &r;
    *p = 9;
    cout << x;
}
```

A. `The program does not compile.`
B. `0`
C. `9`
D. `8`

### Question 161 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point p;
    p.x = 2;
    p.y = 3;
    cout << p.x + p.y;
}
```

A. `2`
B. `The program does not compile.`
C. `23`
D. `5`

### Question 162 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point p = {4, 6};
    cout << p.y - p.x;
}
```

A. `2`
B. `46`
C. `-2`
D. `10`

### Question 163 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int id;
    int score;
};

int main() {
    vector<Student> v = {{1, 80}, {2, 90}};
    cout << v[1].id << ":" << v[1].score;
}
```

A. `1:80`
B. `1:90`
C. `2:80`
D. `2:90`

### Question 164 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

struct Box {
    int value;
};

int main() {
    Box a = {5};
    Box b = a;
    b.value = 9;
    cout << a.value << b.value;
}
```

A. `55`
B. `95`
C. `99`
D. `59`

### Question 165 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

struct Item {
    int count;
};

int main() {
    Item item = {7};
    Item *p = &item;
    cout << p->count;
}
```

A. `7`
B. `count`
C. `0`
D. `The program does not compile.`

### Question 166 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

struct Date {
    int year;
};

struct Event {
    Date date;
    int id;
};

int main() {
    Event e = {{2026}, 4};
    cout << e.date.year + e.id;
}
```

A. `2030`
B. `20264`
C. `2026`
D. `4`

### Question 167 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "CPE";
    cout << s;
}
```

A. `The program does not compile.`
B. `s`
C. `CPE`
D. ``

### Question 168 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "exam";
    cout << s.size();
}
```

A. `5`
B. `4`
C. `3`
D. `exam`

### Question 169 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "code";
    cout << s[1];
}
```

A. `o`
B. `c`
C. `1`
D. `d`

### Question 170 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "C";
    string b = "++";
    cout << a + b;
}
```

A. `C++`
B. `++`
C. `The program does not compile.`
D. `C`

### Question 171 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "abc";
    string b = "abc";
    cout << (a == b);
}
```

A. `The program does not compile.`
B. `0`
C. `abc`
D. `1`

### Question 172 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "apple";
    string b = "banana";
    cout << (a < b);
}
```

A. `1`
B. `apple`
C. `banana`
D. `0`

### Question 173 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "cat";
    string b = "car";
    cout << (a.compare(b) > 0);
}
```

A. `0`
B. `1`
C. `car`
D. `cat`

### Question 174 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abcdef";
    cout << s.substr(2, 3);
}
```

A. `cd`
B. `def`
C. `cde`
D. `abc`

### Question 175 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abef";
    s.insert(2, "cd");
    cout << s;
}
```

A. `abcd`
B. `abcdef`
C. `abefcd`
D. `cdabef`

### Question 176 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abcdef";
    s.erase(2, 2);
    cout << s;
}
```

A. `cdef`
B. `ab`
C. `abef`
D. `abcd`

### Question 177 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "hello";
    cout << s.find("ll");
}
```

A. `2`
B. `3`
C. `1`
D. `string::npos`

### Question 178 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "hello";
    cout << (s.find("z") == string::npos);
}
```

A. `0`
B. `z`
C. `1`
D. `The program does not compile.`

### Question 179 — Block 4 – Structures and Strings

Assume the user enters `42 Fernando` and presses Enter. What is printed?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int age;
    string name;
    cin >> age;
    getline(cin, name);
    cout << "[" << name << "]";
}
```

A. `[]`
B. `[ Fernando]`
C. `[Fernando]`
D. The program does not compile.

### Question 180 — Block 4 – Structures and Strings

What happens when this program is compiled?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "a" + "b";
    cout << s;
}
```

A. It prints `a`.
B. The program does not compile.
C. It prints `ab`.
D. It prints `b`.

### Question 181 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abc";
    s += 'd';
    cout << s;
}
```

A. `abcd`
B. `The program does not compile.`
C. `abc`
D. `d`

### Question 182 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abc";
    s[0] = 'X';
    cout << s;
}
```

A. `abc`
B. `Xbc`
C. `xbc`
D. `The program does not compile.`

### Question 183 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << s.empty();
}
```

A. `The program does not compile.`
B. `0`
C. `1`
D. `empty`

### Question 184 — Block 4 – Structures and Strings

What happens when this program runs?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abc";
    cout << s.at(5);
}
```

A. It prints `c`.
B. It throws an out_of_range exception.
C. It prints an empty character.
D. The program does not compile.

### Question 185 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    string title;
    int pages;
};

int main() {
    vector<Book> books;
    books.push_back({"C++", 300});
    cout << books[0].title << ":" << books[0].pages;
}
```

A. `C++:300`
B. `300:C++`
C. `C++`
D. `The program does not compile.`

### Question 186 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

struct Pair {
    int a;
    int b;
};

Pair makePair() {
    return {2, 5};
}

int main() {
    Pair p = makePair();
    cout << p.a * p.b;
}
```

A. `25`
B. `10`
C. `The program does not compile.`
D. `7`

### Question 187 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

struct Counter {
    int value;
};

void inc(Counter c) {
    ++c.value;
}

int main() {
    Counter c = {1};
    inc(c);
    cout << c.value;
}
```

A. `0`
B. `The program does not compile.`
C. `2`
D. `1`

### Question 188 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

struct Counter {
    int value;
};

void inc(Counter &c) {
    ++c.value;
}

int main() {
    Counter c = {1};
    inc(c);
    cout << c.value;
}
```

A. `The program does not compile.`
B. `1`
C. `0`
D. `2`

### Question 189 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Cell {
    int value;
};

int main() {
    vector<Cell> cells = {{1}, {2}, {3}};
    for (Cell &c : cells)
        c.value *= 2;
    cout << cells[2].value;
}
```

A. `2`
B. `6`
C. `The program does not compile.`
D. `3`

### Question 190 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "ab";
    s.append("cd");
    cout << s;
}
```

A. `The program does not compile.`
B. `cd`
C. `ab`
D. `abcd`

### Question 191 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abXXef";
    s.replace(2, 2, "cd");
    cout << s;
}
```

A. `The program does not compile.`
B. `abXXef`
C. `abcdef`
D. `abcd`

### Question 192 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << string("hi").size();
}
```

A. `2`
B. `The program does not compile.`
C. `3`
D. `hi`

### Question 193 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << boolalpha << (string("a") < string("b"));
}
```

A. `true`
B. `0`
C. `1`
D. `false`

### Question 194 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

struct A {
    int x = 5;
};

int main() {
    A a;
    cout << a.x;
}
```

A. `The program does not compile.`
B. `undefined`
C. `0`
D. `5`

### Question 195 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point p = {9};
    cout << p.x << p.y;
}
```

A. `09`
B. `The behavior is undefined.`
C. `9`
D. `90`

### Question 196 — Block 4 – Structures and Strings

What happens when this program is compiled?

```cpp
#include <iostream>
using namespace std;

struct Bad {
    int x;
}

int main() {
    Bad b = {1};
    cout << b.x;
}
```

A. It prints `1`.
B. The behavior is undefined.
C. It prints `0`.
D. The program does not compile.

### Question 197 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abc";
    s.clear();
    cout << s.size();
}
```

A. `3`
B. `1`
C. `The program does not compile.`
D. `0`

### Question 198 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "hi";
    string b = a;
    b[0] = 'H';
    cout << a << " " << b;
}
```

A. `Hi Hi`
B. `Hi hi`
C. `hi hi`
D. `hi Hi`

### Question 199 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abc";
    const char *p = s.c_str();
    cout << p[1];
}
```

A. `c`
B. `The program does not compile.`
C. `b`
D. `a`

### Question 200 — Block 4 – Structures and Strings

What is printed by the program?

```cpp
#include <iostream>
#include <string>
using namespace std;

struct User {
    string name;
    int level;
};

int main() {
    User u = {"Ana", 3};
    cout << u.name.size() + u.level;
}
```

A. `3`
B. `Ana3`
C. `4`
D. `6`


---

## Answer Key with Explanations

### Question 001

**Answer:** D — `10`

**Explanation:** The assignment stores 10 in x before it is printed.

### Question 002

**Answer:** C — `A 65`

**Explanation:** The character is printed as a character first; casting it to int prints its ASCII/Unicode code value in the ordinary execution character set used by typical exam examples.

### Question 003

**Answer:** D — `10`

**Explanation:** Without boolalpha, bool values are printed as 1 and 0.

### Question 004

**Answer:** C — `2`

**Explanation:** Both operands are integers, so integer division discards the fractional part.

### Question 005

**Answer:** D — `2`

**Explanation:** The remainder after dividing 17 by 5 is 2.

### Question 006

**Answer:** D — `2.5`

**Explanation:** Casting a to double makes the division floating-point.

### Question 007

**Answer:** C — `14`

**Explanation:** Multiplication has higher precedence than addition.

### Question 008

**Answer:** C — `20`

**Explanation:** Parentheses force the addition to be evaluated first.

### Question 009

**Answer:** A — `1`

**Explanation:** Both relational expressions are true, so the logical AND is true and prints 1.

### Question 010

**Answer:** C — `no`

**Explanation:** Short-circuit evaluation prevents 10 / x from being evaluated when x != 0 is false.

### Question 011

**Answer:** D — `yes`

**Explanation:** Short-circuit OR stops after the first true operand.

### Question 012

**Answer:** D — `2`

**Explanation:** 6 is 110 and 3 is 011; bitwise AND gives 010.

### Question 013

**Answer:** C — `7`

**Explanation:** Bitwise OR sets every bit that is set in either operand.

### Question 014

**Answer:** D — `5`

**Explanation:** Bitwise XOR sets bits that differ: 110 xor 011 is 101.

### Question 015

**Answer:** A — `12`

**Explanation:** Left shifting 3 by 2 positions multiplies it by 4 for this positive value.

### Question 016

**Answer:** B — `4`

**Explanation:** Right shifting this positive integer divides it by 4.

### Question 017

**Answer:** D — `10`

**Explanation:** The right side is evaluated first: x += 6.

### Question 018

**Answer:** C — `555`

**Explanation:** Assignment is right-associative, so c, b, and a all become 5.

### Question 019

**Answer:** D — `6 6`

**Explanation:** Prefix increment changes x before the value is used.

### Question 020

**Answer:** A — `5 6`

**Explanation:** Postfix increment yields the old value, then x becomes 6.

### Question 021

**Answer:** A — `11`

**Explanation:** The condition is true, so the expression after ? is selected.

### Question 022

**Answer:** A — `1 1`

**Explanation:** In C++, a character literal such as 'A' has type char, not int.

### Question 023

**Answer:** D — `8`

**Explanation:** A leading zero denotes an octal integer literal.

### Question 024

**Answer:** C — `16`

**Explanation:** 0x10 is a hexadecimal literal equal to decimal 16.

### Question 025

**Answer:** B — `10`

**Explanation:** 0b1010 is a binary literal equal to decimal 10.

### Question 026

**Answer:** C — `1.50`

**Explanation:** fixed with setprecision(2) prints two digits after the decimal point.

### Question 027

**Answer:** D — `[   7]`

**Explanation:** setw(4) gives a field width of four, right-aligned by default.

### Question 028

**Answer:** C — `  12`

**Explanation:** setw affects only the next formatted insertion.

### Question 029

**Answer:** C — `A
B`

**Explanation:** endl inserts a newline and flushes the stream.

### Question 030

**Answer:** A — The program does not compile because cout is not qualified and no using declaration is present.

**Explanation:** cout is in namespace std, so the program needs std::cout or a suitable using declaration.

### Question 031

**Answer:** B — `ok`

**Explanation:** A using declaration for std::cout makes cout available unqualified.

### Question 032

**Answer:** A — The program does not compile.

**Explanation:** class is a C++ keyword and cannot be used as an identifier.

### Question 033

**Answer:** A — `1`

**Explanation:** The assignment is inside a comment and is ignored.

### Question 034

**Answer:** C — The program does not compile.

**Explanation:** List-initialization of an int from 3.7 is a narrowing conversion and is ill-formed.

### Question 035

**Answer:** C — `3`

**Explanation:** Copy-initialization allows the conversion; the fractional part is discarded.

### Question 036

**Answer:** D — `2`

**Explanation:** The integer division is done before assigning the result to double.

### Question 037

**Answer:** B — `7`

**Explanation:** The cast converts the double to int by discarding the fractional part.

### Question 038

**Answer:** A — `0`

**Explanation:** !a is true, and true == false is false.

### Question 039

**Answer:** B — `0`

**Explanation:** 1 < 2 becomes true, which converts to 1; then 1 < 1 is false.

### Question 040

**Answer:** D — `3`

**Explanation:** The comma operator evaluates left to right and yields the last expression.

### Question 041

**Answer:** C — `C++
Test`

**Explanation:** \n is an escape sequence that creates a newline.

### Question 042

**Answer:** C — `10`

**Explanation:** The newline escape character commonly has code value 10 in exam-style ASCII examples.

### Question 043

**Answer:** D — `1`

**Explanation:** Unsigned arithmetic wraps modulo the range, so x becomes a very large positive value.

### Question 044

**Answer:** B — `true`

**Explanation:** boolalpha changes the textual representation of bool values.

### Question 045

**Answer:** B — `13:42`

**Explanation:** Formatted extraction reads the first integer into a and the second into b.

### Question 046

**Answer:** B — `1`

**Explanation:** Without boolalpha, true is printed as 1.

### Question 047

**Answer:** D — `0`

**Explanation:** Any nonzero integer is true; logical NOT changes true to false.

### Question 048

**Answer:** C — `25`

**Explanation:** Compound assignment is equivalent here to x = x * (2 + 3).

### Question 049

**Answer:** B — `23`

**Explanation:** Stream insertions do not add spaces automatically.

### Question 050

**Answer:** D — The program does not compile.

**Explanation:** The declaration statement is missing a semicolon.

### Question 051

**Answer:** D — `1`

**Explanation:** A hosted C++ program receives at least the program name as one argument.

### Question 052

**Answer:** D — It is a valid form of the main function.

**Explanation:** `int main(int argc, char *argv[])` is one of the standard forms used for command-line arguments.

### Question 053

**Answer:** A — `[ 1234]`

**Explanation:** setw(3) applies only to 12; 34 is printed normally.

### Question 054

**Answer:** A — `2`

**Explanation:** Integer division produces 2, then the value is stored in a double.

### Question 055

**Answer:** B — `2`

**Explanation:** In arithmetic, bool values are promoted to integers: true is 1 and false is 0.

### Question 056

**Answer:** A — `match`

**Explanation:** The conditional operator selects the first expression because x == 8 is true.

### Question 057

**Answer:** A — `AB`

**Explanation:** Without braces, only the first statement is controlled by the if.

### Question 058

**Answer:** D — `C`

**Explanation:** The outer condition is false, so its else branch runs.

### Question 059

**Answer:** D — `BC`

**Explanation:** Execution starts at case 2 and falls through because there are no break statements.

### Question 060

**Answer:** B — `DA`

**Explanation:** default may appear before cases; without break, it falls through into case 1.

### Question 061

**Answer:** D — `3`

**Explanation:** The case label 'B' matches the char value.

### Question 062

**Answer:** C — `6`

**Explanation:** The loop sums 1 + 2 + 3.

### Question 063

**Answer:** C — `5`

**Explanation:** A do-while loop executes its body at least once.

### Question 064

**Answer:** A — `012`

**Explanation:** The loop runs with i equal to 0, 1, and 2.

### Question 065

**Answer:** B — `012`

**Explanation:** break exits the loop when i becomes 3, before printing 3.

### Question 066

**Answer:** C — `13`

**Explanation:** continue skips the output for even values.

### Question 067

**Answer:** C — `11 12 21 22 `

**Explanation:** The inner loop completes for each outer-loop value.

### Question 068

**Answer:** D — `321`

**Explanation:** The postfix decrement prints the current value before decreasing it.

### Question 069

**Answer:** A — `AC`

**Explanation:** goto jumps to the label and skips the second output.

### Question 070

**Answer:** B — `4`

**Explanation:** The first return exits the function immediately.

### Question 071

**Answer:** D — `1`

**Explanation:** Passing by value gives f a copy of a.

### Question 072

**Answer:** C — `11`

**Explanation:** Passing by reference lets f modify the original variable.

### Question 073

**Answer:** C — `11`

**Explanation:** The pointer stores the address of a, and dereferencing it modifies a.

### Question 074

**Answer:** B — `24`

**Explanation:** The recursive calls compute 4 * 3 * 2 * 1.

### Question 075

**Answer:** B — `10`

**Explanation:** The recursion sums 4 + 3 + 2 + 1.

### Question 076

**Answer:** D — `102`

**Explanation:** The base case returns 100, then two recursive returns add 1 twice.

### Question 077

**Answer:** D — `8`

**Explanation:** The second argument uses its default value.

### Question 078

**Answer:** D — `3`

**Explanation:** The int overload is the exact match for an int argument.

### Question 079

**Answer:** A — `25`

**Explanation:** The prior function declaration allows main to call square before its definition.

### Question 080

**Answer:** B — `99`

**Explanation:** An array parameter lets the function modify the original array elements.

### Question 081

**Answer:** B — `21`

**Explanation:** The inner x shadows the outer x only inside the block.

### Question 082

**Answer:** A — `12`

**Explanation:** A static local variable keeps its value between calls.

### Question 083

**Answer:** A — `3`

**Explanation:** The semicolon creates an empty loop body; after the loop, i is 3.

### Question 084

**Answer:** C — `012`

**Explanation:** The break executes when i is 2, after printing it.

### Question 085

**Answer:** C — `210`

**Explanation:** The condition uses the old value; inside the loop n has already been decremented.

### Question 086

**Answer:** C — `F0`

**Explanation:** The assignment sets x to 0; the condition is false.

### Question 087

**Answer:** B — `T5`

**Explanation:** The assignment sets x to 5; nonzero is true.

### Question 088

**Answer:** D — The program does not compile.

**Explanation:** A switch statement cannot have duplicate case labels with the same value.

### Question 089

**Answer:** C — The program does not compile.

**Explanation:** case labels must be integral constant expressions; 1.5 is not valid here.

### Question 090

**Answer:** B — `321`

**Explanation:** The function prints before making the recursive call.

### Question 091

**Answer:** B — The program does not compile.

**Explanation:** Once a default argument is provided, following parameters in that parameter list also need defaults.

### Question 092

**Answer:** D — The program does not compile.

**Explanation:** A non-const lvalue reference cannot bind directly to a literal.

### Question 093

**Answer:** C — `7`

**Explanation:** The pointer is not null and points to x.

### Question 094

**Answer:** A — `13`

**Explanation:** When i is 2, continue jumps to the while condition and skips output.

### Question 095

**Answer:** A — `E`

**Explanation:** The number is positive and even.

### Question 096

**Answer:** B — `1357`

**Explanation:** The increment expression adds 2 each iteration.

### Question 097

**Answer:** D — `11 10`

**Explanation:** The function parameter and local y do not modify main's y.

### Question 098

**Answer:** D — `ok`

**Explanation:** Falling off the end of main is equivalent to returning 0.

### Question 099

**Answer:** C — `G`

**Explanation:** The enum value green matches its case.

### Question 100

**Answer:** D — `9`

**Explanation:** The pointer points to x; dereferencing it yields 9.

### Question 101

**Answer:** C — `5 5`

**Explanation:** The reference parameter modifies a before returning it.

### Question 102

**Answer:** B — `52`

**Explanation:** x is 5 and y uses its default value 2.

### Question 103

**Answer:** B — `5`

**Explanation:** With fib(0)=0 and fib(1)=1, fib(5) is 5.

### Question 104

**Answer:** B — `0010`

**Explanation:** break exits only the inner loop.

### Question 105

**Answer:** D — `8`

**Explanation:** The function returns immediately when it sees the first even number.

### Question 106

**Answer:** B — `B`

**Explanation:** x is zero, so the first condition is false and !x is true.

### Question 107

**Answer:** C — `5`

**Explanation:** The function behaves like absolute value for this input.

### Question 108

**Answer:** B — `011`

**Explanation:** The loop prints remainders from least significant bit to most significant bit: 6 -> 0, 3 -> 1, 1 -> 1.

### Question 109

**Answer:** D — `two`

**Explanation:** The switch expression evaluates to 2.

### Question 110

**Answer:** C — `16`

**Explanation:** The loop doubles r four times.

### Question 111

**Answer:** C — `9`

**Explanation:** The first condition is false, so b is returned.

### Question 112

**Answer:** A — `012`

**Explanation:** The goto repeats the labeled block until x becomes 3.

### Question 113

**Answer:** B — `1200`

**Explanation:** Missing aggregate initializer values are zero-initialized.

### Question 114

**Answer:** D — The program has undefined behavior because it reads outside the array.

**Explanation:** Valid indexes for a two-element array are 0 and 1.

### Question 115

**Answer:** D — `6`

**Explanation:** m[1] is the second row, and [2] is its third element.

### Question 116

**Answer:** C — `3`

**Explanation:** The vector contains three elements.

### Question 117

**Answer:** B — `12`

**Explanation:** push_back appends elements to the vector.

### Question 118

**Answer:** C — It throws an out_of_range exception.

**Explanation:** at() performs bounds checking; index 3 is outside a vector of size 3.

### Question 119

**Answer:** D — `9`

**Explanation:** data() returns a pointer to the vector's contiguous storage.

### Question 120

**Answer:** C — `4`

**Explanation:** In this initialization, the array name decays to a pointer to its first element.

### Question 121

**Answer:** B — `10`

**Explanation:** The dereference operator reads the object pointed to by p.

### Question 122

**Answer:** A — `1`

**Explanation:** p was initialized with nullptr, so the comparison is true.

### Question 123

**Answer:** B — `3`

**Explanation:** After reassignment, p points to b.

### Question 124

**Answer:** C — `30`

**Explanation:** Pointer arithmetic moves by elements, not by bytes.

### Question 125

**Answer:** C — `5`

**Explanation:** A const pointer cannot be reseated, but the pointed-to int may be modified.

### Question 126

**Answer:** C — `7`

**Explanation:** new int(7) dynamically allocates an int initialized to 7.

### Question 127

**Answer:** B — `13`

**Explanation:** The dynamic array contains 1, 2, and 3.

### Question 128

**Answer:** C — It uses the wrong deallocation form; delete[] should be used for arrays.

**Explanation:** Memory allocated with new[] must be released with delete[].

### Question 129

**Answer:** A — It leaks the first dynamically allocated int.

**Explanation:** The original pointer to the first allocation is overwritten before that allocation is deleted.

### Question 130

**Answer:** D — `3`

**Explanation:** **pp dereferences the pointer-to-pointer to reach x.

### Question 131

**Answer:** A — `2`

**Explanation:** p is an array of pointers; p[1] points to b.

### Question 132

**Answer:** D — `10`

**Explanation:** Dereferencing p gives access to x.

### Question 133

**Answer:** A — `19`

**Explanation:** Vector assignment creates a separate copy of the elements.

### Question 134

**Answer:** D — `2`

**Explanation:** The range variable x is a copy, so the vector is unchanged.

### Question 135

**Answer:** A — `4`

**Explanation:** The range variable is a reference, so each element is modified.

### Question 136

**Answer:** B — `10`

**Explanation:** The nested loops sum all four elements.

### Question 137

**Answer:** B — `2`

**Explanation:** a + 1 points to the second element.

### Question 138

**Answer:** C — `73`

**Explanation:** The constructor creates three elements, each initialized to 7.

### Question 139

**Answer:** D — `23`

**Explanation:** Brace initialization creates a vector containing two elements: 3 and 7.

### Question 140

**Answer:** B — `000`

**Explanation:** vector<int>(3) value-initializes three ints to zero.

### Question 141

**Answer:** A — `10`

**Explanation:** front() is 4 and back() is 6.

### Question 142

**Answer:** D — `9`

**Explanation:** The element at index 3 is assigned 3 * 3.

### Question 143

**Answer:** A — `2`

**Explanation:** Subtracting pointers in the same array gives the distance in elements.

### Question 144

**Answer:** A — `3`

**Explanation:** The integer division a / b happens before the result is cast to double.

### Question 145

**Answer:** C — `3.5`

**Explanation:** Casting one operand first makes the division floating-point.

### Question 146

**Answer:** B — `B`

**Explanation:** A null pointer converts to false in a condition.

### Question 147

**Answer:** B — p is a pointer to int, but q is an int.

**Explanation:** The * attaches to the declarator, not to every name in the declaration.

### Question 148

**Answer:** B — `0`

**Explanation:** delete releases the object but does not automatically change the pointer value to nullptr.

### Question 149

**Answer:** A — `120`

**Explanation:** The missing initializer value is zero-initialized.

### Question 150

**Answer:** A — `5`

**Explanation:** This common idiom computes the number of elements in the array.

### Question 151

**Answer:** A — `104`

**Explanation:** resize adds value-initialized int elements, which are zero.

### Question 152

**Answer:** B — `0`

**Explanation:** clear removes all elements from the vector.

### Question 153

**Answer:** A — `50`

**Explanation:** The function modifies the original array element.

### Question 154

**Answer:** D — `1`

**Explanation:** p contains the address of x, so it is not null.

### Question 155

**Answer:** C — `4`

**Explanation:** Both pointers refer to the same int object.

### Question 156

**Answer:** D — `1`

**Explanation:** A pointer one past the last element may be formed and compared, though it must not be dereferenced.

### Question 157

**Answer:** B — `7`

**Explanation:** The pointer expression selects the last vector element.

### Question 158

**Answer:** B — `07`

**Explanation:** Empty aggregate initialization zero-initializes the whole array.

### Question 159

**Answer:** A — `3`

**Explanation:** The vector pointer is dereferenced first, then operator[] accesses index 2.

### Question 160

**Answer:** C — `9`

**Explanation:** r is another name for x, so &r is the address of x.

### Question 161

**Answer:** D — `5`

**Explanation:** The dot operator accesses structure members.

### Question 162

**Answer:** A — `2`

**Explanation:** Aggregate initialization assigns x = 4 and y = 6.

### Question 163

**Answer:** D — `2:90`

**Explanation:** v[1] is the second structure in the vector.

### Question 164

**Answer:** D — `59`

**Explanation:** Structure assignment copies the member value; b is a separate object.

### Question 165

**Answer:** A — `7`

**Explanation:** The arrow operator accesses a member through a pointer to a structure.

### Question 166

**Answer:** A — `2030`

**Explanation:** The nested member date.year is 2026 and id is 4.

### Question 167

**Answer:** C — `CPE`

**Explanation:** std::string stores and prints the text.

### Question 168

**Answer:** B — `4`

**Explanation:** size() returns the number of characters in the string.

### Question 169

**Answer:** A — `o`

**Explanation:** String indexing starts at zero.

### Question 170

**Answer:** A — `C++`

**Explanation:** The + operator concatenates string objects.

### Question 171

**Answer:** D — `1`

**Explanation:** The two strings have equal contents.

### Question 172

**Answer:** A — `1`

**Explanation:** String relational comparison is lexicographic.

### Question 173

**Answer:** B — `1`

**Explanation:** cat is lexicographically greater than car because t comes after r.

### Question 174

**Answer:** C — `cde`

**Explanation:** substr(2, 3) starts at index 2 and takes three characters.

### Question 175

**Answer:** B — `abcdef`

**Explanation:** insert places cd before the character currently at index 2.

### Question 176

**Answer:** C — `abef`

**Explanation:** erase(2, 2) removes two characters starting at index 2.

### Question 177

**Answer:** A — `2`

**Explanation:** The substring ll starts at index 2.

### Question 178

**Answer:** C — `1`

**Explanation:** find returns string::npos when the substring is not found.

### Question 179

**Answer:** B — `[ Fernando]`

**Explanation:** After reading the integer, getline reads the rest of the line, including the leading space before Fernando.

### Question 180

**Answer:** B — The program does not compile.

**Explanation:** Two string literals cannot be added directly with operator+.

### Question 181

**Answer:** A — `abcd`

**Explanation:** operator+= can append a character to a string.

### Question 182

**Answer:** B — `Xbc`

**Explanation:** operator[] provides mutable access to a string character.

### Question 183

**Answer:** C — `1`

**Explanation:** A default-constructed string is empty.

### Question 184

**Answer:** B — It throws an out_of_range exception.

**Explanation:** at() checks bounds and throws when the index is invalid.

### Question 185

**Answer:** A — `C++:300`

**Explanation:** The pushed structure has title C++ and pages 300.

### Question 186

**Answer:** B — `10`

**Explanation:** The function returns a structure initialized with a = 2 and b = 5.

### Question 187

**Answer:** D — `1`

**Explanation:** The structure is passed by value, so inc modifies only a copy.

### Question 188

**Answer:** D — `2`

**Explanation:** The reference parameter allows the function to modify the original structure.

### Question 189

**Answer:** B — `6`

**Explanation:** The range variable is a reference to each structure element.

### Question 190

**Answer:** D — `abcd`

**Explanation:** append adds the given characters to the end of the string.

### Question 191

**Answer:** C — `abcdef`

**Explanation:** replace removes two characters from index 2 and inserts cd.

### Question 192

**Answer:** A — `2`

**Explanation:** The temporary string contains two characters.

### Question 193

**Answer:** A — `true`

**Explanation:** With boolalpha, the true comparison is printed as the word true.

### Question 194

**Answer:** D — `5`

**Explanation:** The default member initializer gives x the value 5.

### Question 195

**Answer:** D — `90`

**Explanation:** The missing aggregate member is value-initialized to zero.

### Question 196

**Answer:** D — The program does not compile.

**Explanation:** A structure definition must end with a semicolon.

### Question 197

**Answer:** D — `0`

**Explanation:** clear removes all characters from the string.

### Question 198

**Answer:** D — `hi Hi`

**Explanation:** String assignment creates a separate string object.

### Question 199

**Answer:** C — `b`

**Explanation:** c_str() returns a pointer to a null-terminated character array representing the string contents.

### Question 200

**Answer:** D — `6`

**Explanation:** Ana has length 3; 3 + level 3 equals 6.
