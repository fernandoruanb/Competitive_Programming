<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 74 — Search a 2D Matrix</h1>

<p align="center">
  <strong>Matrix Traversal + Target Search</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Como o código percorre a matriz](#como-o-código-percorre-a-matriz)
  - [Por que retornar `true` ou `false`?](#por-que-retornar-true-ou-false)
  - [Ponto importante](#ponto-importante)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [How the code traverses the matrix](#how-the-code-traverses-the-matrix)
  - [Why return `true` or `false`?](#why-return-true-or-false)
  - [Important point](#important-point)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Search a 2D Matrix** é verificar se um determinado número, chamado `target`, existe dentro de uma matriz.

Se o número existir, retornamos:

```cpp
true
````

Se o número não existir, retornamos:

```cpp
false
```

Nesta solução, a ideia usada foi simples e direta: percorrer todas as linhas da matriz e verificar cada número individualmente.

---

## Estratégia usada

A solução usa uma **varredura completa da matriz**.

Primeiro, pegamos a quantidade de linhas:

```cpp
int size = matrix.size();
```

Depois, usamos um `while` para percorrer a matriz de baixo para cima:

```cpp
while (size) {
    for (int n: matrix[size - 1])
        if (n == target) return true;
    --size;
}
```

Para cada linha, o `for` percorre todos os elementos.

Se algum elemento for igual ao `target`, a função retorna `true` imediatamente.

---

## Como o código percorre a matriz

A variável `size` começa guardando a quantidade total de linhas da matriz:

```cpp
int size = matrix.size();
```

Se a matriz tiver 3 linhas, por exemplo:

```cpp
matrix = {
  {1, 3, 5, 7},
  {10, 11, 16, 20},
  {23, 30, 34, 60}
}
```

Então:

```cpp
size = 3;
```

Dentro do `while`, o código acessa:

```cpp
matrix[size - 1]
```

Ou seja, ele acessa as linhas nesta ordem:

```cpp
matrix[2]
matrix[1]
matrix[0]
```

Isso significa que a matriz é percorrida de baixo para cima.

Dentro de cada linha, este loop percorre cada número:

```cpp
for (int n: matrix[size - 1])
```

E a cada número, o código faz a comparação:

```cpp
if (n == target)
    return true;
```

---

## Por que retornar `true` ou `false`?

O tipo de retorno da função é `bool`:

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target)
```

Isso significa que a função deve responder apenas uma pergunta:

> O `target` existe dentro da matriz?

Se existe, retornamos `true`.

```cpp
if (n == target)
    return true;
```

Se o código percorreu todos os elementos e não encontrou o `target`, então retornamos `false`.

```cpp
return false;
```

---

## Ponto importante

Essa solução funciona corretamente, mas ela não aproveita totalmente o fato de a matriz estar ordenada.

Ela simplesmente verifica todos os elementos, um por um.

Isso é bom como primeira solução, porque é simples, direta e fácil de entender.

Porém, como o exercício informa que a matriz possui uma estrutura ordenada, uma solução mais otimizada poderia usar **Binary Search**.

A grande lição aqui é:

> primeiro faça uma solução que funciona; depois observe as propriedades especiais do problema para otimizar.

---

## Complexidade

Como o código percorre todos os elementos da matriz, a complexidade depende da quantidade de linhas e colunas.

Se a matriz tem `m` linhas e `n` colunas:

* Tempo: `O(m * n)`
* Espaço: `O(1)`

O espaço é constante porque usamos apenas algumas variáveis simples:

```cpp
int size;
int index;
int n;
```

Observação: a variável `index` foi criada, mas não está sendo usada no código.

---

# English

## Main idea

The goal of **Search a 2D Matrix** is to check whether a given number, called `target`, exists inside a matrix.

If the number exists, we return:

```cpp
true
```

If the number does not exist, we return:

```cpp
false
```

In this solution, the idea is simple and direct: traverse every row of the matrix and check each number individually.

---

## Strategy used

This solution uses a **full matrix traversal** approach.

First, we get the number of rows:

```cpp
int size = matrix.size();
```

Then, we use a `while` loop to traverse the matrix from bottom to top:

```cpp
while (size) {
    for (int n: matrix[size - 1])
        if (n == target) return true;
    --size;
}
```

For each row, the `for` loop checks every element.

If any element is equal to the `target`, the function immediately returns `true`.

---

## How the code traverses the matrix

The variable `size` starts by storing the total number of rows in the matrix:

```cpp
int size = matrix.size();
```

If the matrix has 3 rows, for example:

```cpp
matrix = {
  {1, 3, 5, 7},
  {10, 11, 16, 20},
  {23, 30, 34, 60}
}
```

Then:

```cpp
size = 3;
```

Inside the `while`, the code accesses:

```cpp
matrix[size - 1]
```

That means it reads the rows in this order:

```cpp
matrix[2]
matrix[1]
matrix[0]
```

So the matrix is traversed from bottom to top.

Inside each row, this loop goes through each number:

```cpp
for (int n: matrix[size - 1])
```

And for each number, the code checks:

```cpp
if (n == target)
    return true;
```

---

## Why return `true` or `false`?

The function return type is `bool`:

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target)
```

This means the function only needs to answer one question:

> Does the `target` exist inside the matrix?

If it exists, we return `true`.

```cpp
if (n == target)
    return true;
```

If the code traverses all elements and does not find the `target`, then we return `false`.

```cpp
return false;
```

---

## Important point

This solution works correctly, but it does not fully use the fact that the matrix is sorted.

It simply checks every element one by one.

This is good as a first solution because it is simple, direct, and easy to understand.

However, since the problem tells us that the matrix has a sorted structure, a more optimized solution could use **Binary Search**.

The main lesson here is:

> first build a solution that works; then observe the special properties of the problem to optimize it.

---

## Complexity

Since the code traverses every element of the matrix, the complexity depends on the number of rows and columns.

If the matrix has `m` rows and `n` columns:

* Time: `O(m * n)`
* Space: `O(1)`

The space is constant because we only use a few simple variables:

```cpp
int size;
int index;
int n;
```

Observation: the variable `index` was created, but it is not being used in the code.


