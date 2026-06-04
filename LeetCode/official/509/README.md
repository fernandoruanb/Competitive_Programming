<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 509 — Fibonacci Number</h1>

<p align="center">
  <strong>Recursion + Base Cases</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [O que são casos base?](#o-que-são-casos-base)
  - [Como a recursão funciona](#como-a-recursão-funciona)
  - [Ponto importante](#ponto-importante)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [What are base cases?](#what-are-base-cases)
  - [How recursion works](#how-recursion-works)
  - [Important point](#important-point)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Fibonacci Number** é calcular o valor de `fib(n)` na sequência de Fibonacci.

A sequência começa assim:

```cpp
0, 1, 1, 2, 3, 5, 8, 13...
````

A regra é:

```cpp
fib(n) = fib(n - 1) + fib(n - 2)
```

Ou seja, cada número é formado pela soma dos dois anteriores.

Exemplo:

```cpp
fib(4)
```

Resultado:

```cpp
3
```

Porque:

```cpp
fib(4) = fib(3) + fib(2)
fib(4) = 2 + 1
fib(4) = 3
```

---

## Estratégia usada

Esta solução usa **recursão**.

A função chama ela mesma para resolver partes menores do problema:

```cpp
return (fib(n - 1) + fib(n - 2));
```

A ideia é quebrar `fib(n)` em dois subproblemas:

```cpp
fib(n - 1)
fib(n - 2)
```

Depois, somamos os dois resultados.

---

## O que são casos base?

Casos base são as condições que impedem a recursão de continuar para sempre.

Neste código, temos:

```cpp
if (n == 0)
    return 0;
else if (n == 1)
    return 1;
```

Esses são os dois primeiros valores da sequência de Fibonacci:

```cpp
fib(0) = 0
fib(1) = 1
```

Sem esses casos base, a função continuaria chamando `fib(n - 1)` e `fib(n - 2)` infinitamente.

---

## Como a recursão funciona

Exemplo com:

```cpp
fib(4)
```

A função se divide assim:

```cpp
fib(4)
= fib(3) + fib(2)
= (fib(2) + fib(1)) + (fib(1) + fib(0))
= ((fib(1) + fib(0)) + fib(1)) + (fib(1) + fib(0))
= ((1 + 0) + 1) + (1 + 0)
= 3
```

O código vai quebrando o problema até chegar nos casos base:

```cpp
fib(0)
fib(1)
```

Depois, os resultados começam a voltar e são somados.

---

## Ponto importante

Esta parte do código trata valores negativos:

```cpp
else if (n < 0)
    return -1;
```

No LeetCode, normalmente o valor de `n` já vem dentro das restrições do problema, então essa verificação não é obrigatória.

Mas ela mostra uma preocupação defensiva:

> se alguém chamar `fib` com número negativo, a função retorna `-1`.

Outro ponto importante: essa solução é correta, mas não é a mais eficiente.

Como a função recalcula os mesmos valores várias vezes, ela pode ficar lenta para valores maiores de `n`.

Por exemplo, `fib(5)` calcula `fib(3)` mais de uma vez.

---

## Complexidade

A solução recursiva simples gera muitas chamadas repetidas.

* Tempo: `O(2^n)`
* Espaço: `O(n)`

O tempo é exponencial porque cada chamada pode gerar duas novas chamadas.

O espaço é `O(n)` por causa da profundidade da pilha de recursão.

---

# English

## Main idea

The goal of **Fibonacci Number** is to calculate the value of `fib(n)` in the Fibonacci sequence.

The sequence starts like this:

```cpp
0, 1, 1, 2, 3, 5, 8, 13...
```

The rule is:

```cpp
fib(n) = fib(n - 1) + fib(n - 2)
```

In other words, each number is formed by the sum of the two previous numbers.

Example:

```cpp
fib(4)
```

Result:

```cpp
3
```

Because:

```cpp
fib(4) = fib(3) + fib(2)
fib(4) = 2 + 1
fib(4) = 3
```

---

## Strategy used

This solution uses **recursion**.

The function calls itself to solve smaller parts of the problem:

```cpp
return (fib(n - 1) + fib(n - 2));
```

The idea is to break `fib(n)` into two smaller subproblems:

```cpp
fib(n - 1)
fib(n - 2)
```

Then, we add both results.

---

## What are base cases?

Base cases are the conditions that stop recursion from continuing forever.

In this code, we have:

```cpp
if (n == 0)
    return 0;
else if (n == 1)
    return 1;
```

These are the first two values of the Fibonacci sequence:

```cpp
fib(0) = 0
fib(1) = 1
```

Without these base cases, the function would keep calling `fib(n - 1)` and `fib(n - 2)` forever.

---

## How recursion works

Example with:

```cpp
fib(4)
```

The function expands like this:

```cpp
fib(4)
= fib(3) + fib(2)
= (fib(2) + fib(1)) + (fib(1) + fib(0))
= ((fib(1) + fib(0)) + fib(1)) + (fib(1) + fib(0))
= ((1 + 0) + 1) + (1 + 0)
= 3
```

The code keeps breaking the problem down until it reaches the base cases:

```cpp
fib(0)
fib(1)
```

Then, the results return and are added together.

---

## Important point

This part of the code handles negative values:

```cpp
else if (n < 0)
    return -1;
```

On LeetCode, `n` usually already follows the problem constraints, so this check is not required.

But it shows defensive thinking:

> if someone calls `fib` with a negative number, the function returns `-1`.

Another important point: this solution is correct, but it is not the most efficient one.

Since the function recalculates the same values many times, it can become slow for larger values of `n`.

For example, `fib(5)` calculates `fib(3)` more than once.

---

## Complexity

The simple recursive solution creates many repeated calls.

* Time: `O(2^n)`
* Space: `O(n)`

The time is exponential because each call can create two new calls.

The space is `O(n)` because of the recursion call stack depth.
