
<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 1351 — Count Negative Numbers in a Sorted Matrix</h1>

<p align="center">
  <strong>Matrix Traversal + Counting Negative Values</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Como o código percorre a matriz](#como-o-código-percorre-a-matriz)
  - [Ponto importante](#ponto-importante)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [How the code traverses the matrix](#how-the-code-traverses-the-matrix)
  - [Important point](#important-point)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Count Negative Numbers in a Sorted Matrix** é contar quantos números negativos existem dentro de uma matriz.

Nesta solução, a ideia usada foi direta: percorrer todas as linhas da matriz e verificar cada número individualmente.

Sempre que um número menor que zero aparece, aumentamos o contador:

```cpp
if (n < 0)
    negativeNumbers += 1;
````

---

## Estratégia usada

A solução usa uma abordagem de **varredura completa da matriz**.

Primeiro, pegamos a quantidade de linhas:

```cpp
int size = grid.size();
```

Depois, usamos esse valor para percorrer a matriz de baixo para cima:

```cpp
while (size) {
    for (int n: grid[size - 1])
        if (n < 0) negativeNumbers += 1;
    --size;
}
```

O `size - 1` acessa a última linha disponível no momento.

Exemplo:

```cpp
grid = {
  {4, 3, 2, -1},
  {3, 2, 1, -1},
  {1, 1, -1, -2},
  {-1, -1, -2, -3}
}
```

O código começa lendo a última linha:

```cpp
{-1, -1, -2, -3}
```

Depois sobe para a linha anterior:

```cpp
{1, 1, -1, -2}
```

E continua até chegar na primeira linha.

---

## Como o código percorre a matriz

A variável `size` começa com o número total de linhas:

```cpp
int size = grid.size();
```

Se a matriz tem 4 linhas, então:

```cpp
size = 4;
```

Dentro do `while`, o código acessa:

```cpp
grid[size - 1]
```

Ou seja:

```cpp
grid[3]
grid[2]
grid[1]
grid[0]
```

Isso significa que a matriz é percorrida de baixo para cima.

Dentro de cada linha, o `for` percorre todos os valores:

```cpp
for (int n: grid[size - 1])
```

Então, para cada número `n`, verificamos se ele é negativo.

---

## Ponto importante

Essa solução funciona corretamente, mas ela não aproveita totalmente o fato de a matriz estar ordenada.

Ela simplesmente olha todos os elementos da matriz, um por um.

Isso é simples e seguro, mas não é a solução mais otimizada possível para esse problema.

A grande lição aqui é: antes de tentar otimizar, primeiro é válido criar uma solução que funcione. Depois, podemos observar a propriedade especial do problema: a matriz está ordenada.

---

## Complexidade

Como o código percorre todos os elementos da matriz, a complexidade depende do número de linhas e colunas.

Se a matriz tem `m` linhas e `n` colunas:

* Tempo: `O(m * n)`
* Espaço: `O(1)`

O espaço é constante porque usamos apenas variáveis simples, como:

```cpp
int size;
int negativeNumbers;
int index;
```

Observação: a variável `index` foi criada, mas não está sendo usada no código.

---

# English

## Main idea

The goal of **Count Negative Numbers in a Sorted Matrix** is to count how many negative numbers exist inside a matrix.

In this solution, the idea is straightforward: traverse every row of the matrix and check each number individually.

Whenever a number smaller than zero appears, we increase the counter:

```cpp
if (n < 0)
    negativeNumbers += 1;
```

---

## Strategy used

This solution uses a **full matrix traversal** approach.

First, we get the number of rows:

```cpp
int size = grid.size();
```

Then, we use this value to traverse the matrix from bottom to top:

```cpp
while (size) {
    for (int n: grid[size - 1])
        if (n < 0) negativeNumbers += 1;
    --size;
}
```

The expression `size - 1` accesses the last available row at that moment.

Example:

```cpp
grid = {
  {4, 3, 2, -1},
  {3, 2, 1, -1},
  {1, 1, -1, -2},
  {-1, -1, -2, -3}
}
```

The code starts reading the last row:

```cpp
{-1, -1, -2, -3}
```

Then it moves up to the previous row:

```cpp
{1, 1, -1, -2}
```

And continues until it reaches the first row.

---

## How the code traverses the matrix

The variable `size` starts with the total number of rows:

```cpp
int size = grid.size();
```

If the matrix has 4 rows, then:

```cpp
size = 4;
```

Inside the `while`, the code accesses:

```cpp
grid[size - 1]
```

That means:

```cpp
grid[3]
grid[2]
grid[1]
grid[0]
```

So the matrix is traversed from bottom to top.

Inside each row, the range-based `for` loop checks every value:

```cpp
for (int n: grid[size - 1])
```

Then, for each number `n`, we verify whether it is negative.

---

## Important point

This solution works correctly, but it does not fully use the fact that the matrix is sorted.

It simply checks every element one by one.

This is simple and safe, but it is not the most optimized possible solution for this problem.

The main lesson here is: before optimizing, it is valid to first build a solution that works. After that, we can analyze the special property of the problem: the matrix is sorted.

---

## Complexity

Since the code traverses every element of the matrix, the complexity depends on the number of rows and columns.

If the matrix has `m` rows and `n` columns:

* Time: `O(m * n)`
* Space: `O(1)`

The space is constant because we only use simple variables, such as:

```cpp
int size;
int negativeNumbers;
int index;
```


