<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 9 — Palindrome Number</h1>

<p align="center">
  <strong>Integer Reversal + Digit Comparison</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Como o número é invertido](#como-o-número-é-invertido)
  - [Por que números negativos retornam `false`?](#por-que-números-negativos-retornam-false)
  - [Ponto importante sobre `long long int`](#ponto-importante-sobre-long-long-int)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [How the number is reversed](#how-the-number-is-reversed)
  - [Why do negative numbers return `false`?](#why-do-negative-numbers-return-false)
  - [Important point about `long long int`](#important-point-about-long-long-int)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Palindrome Number** é verificar se um número inteiro continua igual quando seus dígitos são lidos de trás para frente.

Exemplo:

```cpp
x = 121
````

Invertendo o número:

```cpp
121
```

Como o número original e o número invertido são iguais, retornamos:

```cpp
true
```

Outro exemplo:

```cpp
x = 123
```

Invertendo:

```cpp
321
```

Como `123` é diferente de `321`, retornamos:

```cpp
false
```

---

## Estratégia usada

A solução cria uma cópia do número original e constrói um novo número invertido.

```cpp
long long int copy = x;
long long int test = 0;
```

* `copy` é usado para desmontar o número original.
* `test` será usado para montar o número invertido.

Depois, o código extrai o último dígito de `copy` usando `% 10`:

```cpp
long long int num = copy % 10;
```

Esse dígito é adicionado ao número invertido:

```cpp
test *= 10;
test += num;
```

No final, comparamos o número original `x` com o número invertido `test`.

```cpp
if (x == test)
    return true;
```

---

## Como o número é invertido

A inversão acontece dentro do `while`:

```cpp
while (copy) {
    test *= 10;
    long long int num = copy % 10;
    test += num;
    copy /= 10;
}
```

Imagine:

```cpp
x = 123
```

Inicialmente:

```cpp
copy = 123
test = 0
```

Primeira volta:

```cpp
num = 123 % 10 = 3
test = 0 * 10 + 3 = 3
copy = 123 / 10 = 12
```

Segunda volta:

```cpp
num = 12 % 10 = 2
test = 3 * 10 + 2 = 32
copy = 12 / 10 = 1
```

Terceira volta:

```cpp
num = 1 % 10 = 1
test = 32 * 10 + 1 = 321
copy = 1 / 10 = 0
```

No final:

```cpp
test = 321
```

Então o código compara:

```cpp
123 == 321
```

Como é falso, o número não é palíndromo.

---

## Por que números negativos retornam `false`?

O código começa com:

```cpp
if (x < 0)
    return false;
```

Isso acontece porque números negativos possuem o sinal `-`.

Exemplo:

```cpp
x = -121
```

Lido normalmente:

```cpp
-121
```

Invertido, ele não seria igual:

```cpp
121-
```

Por isso, números negativos não são considerados palíndromos nesse problema.

---

## Ponto importante sobre `long long int`

O código usa:

```cpp
long long int copy = x;
long long int test = 0;
```

Isso ajuda a evitar problemas caso o número invertido fique grande demais para caber em um `int`.

Mesmo que `x` seja um `int`, durante o processo de inversão o valor de `test` pode crescer rapidamente.

Por isso, usar `long long int` deixa a solução mais segura.

Também é importante observar que o caso:

```cpp
x = 0
```

funciona corretamente.

Como `copy` começa com `0`, o `while` não executa, `test` continua `0`, e a comparação final fica:

```cpp
0 == 0
```

Então o retorno será:

```cpp
true
```

---

## Complexidade

A quantidade de repetições depende do número de dígitos de `x`.

Se `d` é a quantidade de dígitos:

* Tempo: `O(d)`
* Espaço: `O(1)`

Como a quantidade de dígitos de um número cresce em escala logarítmica, também podemos dizer:

```cpp
O(log10 n)
```

O espaço é constante porque usamos apenas algumas variáveis:

```cpp
copy
test
num
```

---

# English

## Main idea

The goal of **Palindrome Number** is to check whether an integer remains the same when its digits are read backward.

Example:

```cpp
x = 121
```

Reversed number:

```cpp
121
```

Since the original number and the reversed number are equal, we return:

```cpp
true
```

Another example:

```cpp
x = 123
```

Reversed:

```cpp
321
```

Since `123` is different from `321`, we return:

```cpp
false
```

---

## Strategy used

The solution creates a copy of the original number and builds a new reversed number.

```cpp
long long int copy = x;
long long int test = 0;
```

* `copy` is used to break down the original number.
* `test` is used to build the reversed number.

Then, the code extracts the last digit of `copy` using `% 10`:

```cpp
long long int num = copy % 10;
```

This digit is added to the reversed number:

```cpp
test *= 10;
test += num;
```

At the end, we compare the original number `x` with the reversed number `test`.

```cpp
if (x == test)
    return true;
```

---

## How the number is reversed

The reversal happens inside the `while` loop:

```cpp
while (copy) {
    test *= 10;
    long long int num = copy % 10;
    test += num;
    copy /= 10;
}
```

Imagine:

```cpp
x = 123
```

Initially:

```cpp
copy = 123
test = 0
```

First iteration:

```cpp
num = 123 % 10 = 3
test = 0 * 10 + 3 = 3
copy = 123 / 10 = 12
```

Second iteration:

```cpp
num = 12 % 10 = 2
test = 3 * 10 + 2 = 32
copy = 12 / 10 = 1
```

Third iteration:

```cpp
num = 1 % 10 = 1
test = 32 * 10 + 1 = 321
copy = 1 / 10 = 0
```

At the end:

```cpp
test = 321
```

Then the code compares:

```cpp
123 == 321
```

Since this is false, the number is not a palindrome.

---

## Why do negative numbers return `false`?

The code starts with:

```cpp
if (x < 0)
    return false;
```

This happens because negative numbers have the `-` sign.

Example:

```cpp
x = -121
```

Read normally:

```cpp
-121
```

Reversed, it would not be the same:

```cpp
121-
```

So negative numbers are not considered palindromes in this problem.

---

## Important point about `long long int`

The code uses:

```cpp
long long int copy = x;
long long int test = 0;
```

This helps avoid problems if the reversed number becomes too large to fit inside an `int`.

Even though `x` is an `int`, during the reversal process `test` can grow quickly.

So using `long long int` makes the solution safer.

It is also important to notice that this case:

```cpp
x = 0
```

works correctly.

Since `copy` starts as `0`, the `while` loop does not execute, `test` remains `0`, and the final comparison becomes:

```cpp
0 == 0
```

So the return value is:

```cpp
true
```

---

## Complexity

The number of iterations depends on the number of digits in `x`.

If `d` is the number of digits:

* Time: `O(d)`
* Space: `O(1)`

Since the number of digits grows logarithmically, we can also say:

```cpp
O(log10 n)
```

The space is constant because we only use a few variables:

```cpp
copy
test
num
```

