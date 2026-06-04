
<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 268 — Missing Number</h1>

<p align="center">
  <strong>Math Formula + Array Sum</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Por que essa fórmula funciona?](#por-que-essa-fórmula-funciona)
  - [Como o código funciona](#como-o-código-funciona)
  - [Ponto importante sobre `static`](#ponto-importante-sobre-static)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [Why does this formula work?](#why-does-this-formula-work)
  - [How the code works](#how-the-code-works)
  - [Important point about `static`](#important-point-about-static)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Missing Number** é encontrar qual número está faltando em um array que contém números de `0` até `n`.

Por exemplo:

```cpp
nums = {1, 0}
````

O tamanho do array é `2`, então os números esperados seriam:

```cpp
0, 1, 2
```

Como o array possui apenas:

```cpp
1, 0
```

O número faltando é:

```cpp
2
```

---

## Estratégia usada

A solução usa uma ideia matemática simples.

Se temos uma sequência de `0` até `n`, podemos calcular a soma esperada com a fórmula:

```cpp
int res = size * (size + 1) / 2;
```

Depois, somamos todos os valores que realmente existem dentro do array:

```cpp
for (int n: nums)
    sum += n;
```

A diferença entre a soma esperada e a soma real será o número faltando:

```cpp
return (res - sum);
```

---

## Por que essa fórmula funciona?

A soma dos números de `1` até `n` pode ser calculada assim:

```cpp
n * (n + 1) / 2
```

No problema, os números vão de `0` até `n`.

Como o `0` não muda a soma, a fórmula continua funcionando normalmente.

Exemplo:

```cpp
nums = {1, 0}
size = 2
```

A soma esperada de `0 + 1 + 2` é:

```cpp
2 * (2 + 1) / 2 = 3
```

A soma real do array é:

```cpp
1 + 0 = 1
```

Então:

```cpp
3 - 1 = 2
```

Logo, o número faltando é `2`.

---

## Como o código funciona

Primeiro, pegamos o tamanho do array:

```cpp
int size = nums.size();
```

Esse tamanho também representa o maior número esperado da sequência.

Depois, calculamos a soma esperada:

```cpp
int res = size * (size + 1) / 2;
```

Criamos uma variável para guardar a soma real:

```cpp
int sum = 0;
```

Percorremos o array inteiro:

```cpp
for (int n: nums)
    sum += n;
```

E no final retornamos a diferença:

```cpp
return (res - sum);
```

Essa diferença representa exatamente o número que não apareceu no array.

---

## Ponto importante sobre `static`

No código, a função foi marcada como `static` para facilitar o teste direto pelo `main`:

```cpp
static int missingNumber(vector<int>& nums)
```

Por isso, ela pode ser chamada assim:

```cpp
int result = Solution::missingNumber(nums);
```

Sem o `static`, seria necessário criar um objeto da classe `Solution`:

```cpp
Solution sol;
int result = sol.missingNumber(nums);
```

No LeetCode, normalmente não é necessário colocar `static`, porque a plataforma cria e chama a classe automaticamente.

---

## Complexidade

A solução percorre o array apenas uma vez.

Se `n` é o tamanho do array:

* Tempo: `O(n)`
* Espaço: `O(1)`

O espaço é constante porque usamos apenas algumas variáveis simples:

```cpp
int size;
int res;
int sum;
```

---

# English

## Main idea

The goal of **Missing Number** is to find which number is missing from an array containing numbers from `0` to `n`.

For example:

```cpp
nums = {1, 0}
```

The size of the array is `2`, so the expected numbers are:

```cpp
0, 1, 2
```

But the array only contains:

```cpp
1, 0
```

So the missing number is:

```cpp
2
```

---

## Strategy used

This solution uses a simple mathematical idea.

If we have a sequence from `0` to `n`, we can calculate the expected sum using this formula:

```cpp
int res = size * (size + 1) / 2;
```

Then, we add all the values that actually exist inside the array:

```cpp
for (int n: nums)
    sum += n;
```

The difference between the expected sum and the real sum is the missing number:

```cpp
return (res - sum);
```

---

## Why does this formula work?

The sum of the numbers from `1` to `n` can be calculated like this:

```cpp
n * (n + 1) / 2
```

In this problem, the numbers go from `0` to `n`.

Since `0` does not change the sum, the formula still works normally.

Example:

```cpp
nums = {1, 0}
size = 2
```

The expected sum of `0 + 1 + 2` is:

```cpp
2 * (2 + 1) / 2 = 3
```

The real sum of the array is:

```cpp
1 + 0 = 1
```

So:

```cpp
3 - 1 = 2
```

Therefore, the missing number is `2`.

---

## How the code works

First, we get the size of the array:

```cpp
int size = nums.size();
```

This size also represents the largest expected number in the sequence.

Then, we calculate the expected sum:

```cpp
int res = size * (size + 1) / 2;
```

We create a variable to store the real sum:

```cpp
int sum = 0;
```

We traverse the whole array:

```cpp
for (int n: nums)
    sum += n;
```

And finally, we return the difference:

```cpp
return (res - sum);
```

This difference represents exactly the number that did not appear in the array.

---

## Important point about `static`

In this code, the function was marked as `static` to make direct testing from `main` easier:

```cpp
static int missingNumber(vector<int>& nums)
```

Because of that, it can be called like this:

```cpp
int result = Solution::missingNumber(nums);
```

Without `static`, it would be necessary to create an object of the `Solution` class:

```cpp
Solution sol;
int result = sol.missingNumber(nums);
```

On LeetCode, it is usually not necessary to use `static`, because the platform creates and calls the class automatically.

---

## Complexity

This solution traverses the array only once.

If `n` is the size of the array:

* Time: `O(n)`
* Space: `O(1)`

The space is constant because we only use a few simple variables:

```cpp
int size;
int res;
int sum;
```



