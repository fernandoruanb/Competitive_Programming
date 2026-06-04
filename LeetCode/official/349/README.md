<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 349 — Intersection of Two Arrays</h1>

<p align="center">
  <strong>Sorting + Two Pointers + Duplicate Control</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Como os dois ponteiros funcionam](#como-os-dois-ponteiros-funcionam)
  - [Como as duplicatas são evitadas](#como-as-duplicatas-são-evitadas)
  - [Ponto importante](#ponto-importante)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [How the two pointers work](#how-the-two-pointers-work)
  - [How duplicates are avoided](#how-duplicates-are-avoided)
  - [Important point](#important-point)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Intersection of Two Arrays** é encontrar os números que aparecem nos dois arrays.

Porém, existe um detalhe importante: o resultado deve conter apenas valores únicos.

Exemplo:

```cpp
nums1 = {1, 2, 2, 1}
nums2 = {2, 2}
````

A interseção é:

```cpp
{2}
```

Mesmo que o número `2` apareça várias vezes, ele deve aparecer apenas uma vez no resultado.

---

## Estratégia usada

A solução começa ordenando os dois arrays:

```cpp
sort(nums1.begin(), nums1.end());
sort(nums2.begin(), nums2.end());
```

Depois disso, usamos dois ponteiros:

```cpp
int i = 0;
int j = 0;
```

* `i` percorre `nums1`;
* `j` percorre `nums2`.

Como os dois arrays estão ordenados, conseguimos comparar os valores de forma inteligente.

---

## Como os dois ponteiros funcionam

O loop principal continua enquanto ainda existem elementos nos dois arrays:

```cpp
while (i <= size1 && j <= size2)
```

Dentro do loop, comparamos:

```cpp
nums1[i]
nums2[j]
```

Se os dois valores forem iguais, encontramos um número que existe nos dois arrays:

```cpp
if (nums1[i] == nums2[j])
```

Então esse número pode entrar no resultado.

Depois disso, os dois ponteiros avançam:

```cpp
++i;
++j;
```

Se `nums1[i]` for menor que `nums2[j]`, significa que precisamos avançar em `nums1`, porque o valor atual de `nums1` é pequeno demais:

```cpp
else if (nums1[i] < nums2[j])
    ++i;
```

Se `nums1[i]` for maior que `nums2[j]`, avançamos em `nums2`:

```cpp
else if (nums1[i] > nums2[j])
    ++j;
```

Essa navegação funciona porque os arrays estão ordenados.

---

## Como as duplicatas são evitadas

O problema pede uma interseção sem valores repetidos.

Por isso, antes de adicionar um número ao resultado, o código verifica:

```cpp
if (result.empty() || result.back() != nums1[i])
    result.push_back(nums1[i]);
```

Essa condição significa:

* se `result` ainda está vazio, podemos adicionar o número;
* se o último número salvo é diferente do número atual, também podemos adicionar;
* se o último número salvo é igual ao número atual, não adicionamos, porque seria duplicata.

Exemplo:

```cpp
nums1 = {1, 2, 2, 3}
nums2 = {2, 2, 4}
```

Quando o primeiro `2` é encontrado, ele entra no resultado.

Quando outro `2` aparece, o código percebe que `result.back()` já é `2`, então não adiciona novamente.

---

## Ponto importante

Essa solução é uma evolução natural da ideia de **Two Pointers**.

Antes, em problemas como **Two Sum**, os ponteiros eram usados para encontrar uma soma.

Aqui, os ponteiros são usados para sincronizar dois arrays ordenados.

A lógica central é:

> se os valores são iguais, achamos uma interseção;
> se um valor é menor, avançamos naquele array;
> se um valor é maior, avançamos no outro array.

Um pequeno detalhe: esta variável representa o último índice válido, não o tamanho total:

```cpp
int size1 = nums1.size() - 1;
int size2 = nums2.size() - 1;
```

Por isso o loop usa:

```cpp
i <= size1
j <= size2
```

---

## Complexidade

A parte mais cara da solução é a ordenação dos dois arrays:

```cpp
sort(nums1.begin(), nums1.end());
sort(nums2.begin(), nums2.end());
```

Se `n` é o tamanho de `nums1` e `m` é o tamanho de `nums2`, temos:

* Ordenação de `nums1`: `O(n log n)`
* Ordenação de `nums2`: `O(m log m)`
* Percurso com dois ponteiros: `O(n + m)`

Complexidade final:

* Tempo: `O(n log n + m log m)`
* Espaço extra: `O(1)` ignorando o vetor de resposta

O vetor `result` não costuma ser contado como espaço auxiliar, porque ele é a saída do problema.

---

# English

## Main idea

The goal of **Intersection of Two Arrays** is to find the numbers that appear in both arrays.

However, there is an important detail: the result must contain only unique values.

Example:

```cpp
nums1 = {1, 2, 2, 1}
nums2 = {2, 2}
```

The intersection is:

```cpp
{2}
```

Even if the number `2` appears multiple times, it should appear only once in the result.

---

## Strategy used

The solution starts by sorting both arrays:

```cpp
sort(nums1.begin(), nums1.end());
sort(nums2.begin(), nums2.end());
```

After that, we use two pointers:

```cpp
int i = 0;
int j = 0;
```

* `i` traverses `nums1`;
* `j` traverses `nums2`.

Since both arrays are sorted, we can compare their values intelligently.

---

## How the two pointers work

The main loop continues while there are still elements in both arrays:

```cpp
while (i <= size1 && j <= size2)
```

Inside the loop, we compare:

```cpp
nums1[i]
nums2[j]
```

If both values are equal, we found a number that exists in both arrays:

```cpp
if (nums1[i] == nums2[j])
```

So this number can be added to the result.

After that, both pointers move forward:

```cpp
++i;
++j;
```

If `nums1[i]` is smaller than `nums2[j]`, it means we need to move forward in `nums1`, because the current value from `nums1` is too small:

```cpp
else if (nums1[i] < nums2[j])
    ++i;
```

If `nums1[i]` is greater than `nums2[j]`, we move forward in `nums2`:

```cpp
else if (nums1[i] > nums2[j])
    ++j;
```

This navigation works because the arrays are sorted.

---

## How duplicates are avoided

The problem asks for an intersection without repeated values.

So before adding a number to the result, the code checks:

```cpp
if (result.empty() || result.back() != nums1[i])
    result.push_back(nums1[i]);
```

This condition means:

* if `result` is still empty, we can add the number;
* if the last saved number is different from the current number, we can also add it;
* if the last saved number is equal to the current number, we do not add it, because it would be a duplicate.

Example:

```cpp
nums1 = {1, 2, 2, 3}
nums2 = {2, 2, 4}
```

When the first `2` is found, it enters the result.

When another `2` appears, the code sees that `result.back()` is already `2`, so it does not add it again.

---

## Important point

This solution is a natural evolution of the **Two Pointers** idea.

Before, in problems like **Two Sum**, pointers were used to find a sum.

Here, the pointers are used to synchronize two sorted arrays.

The core logic is:

> if the values are equal, we found an intersection;
> if one value is smaller, move forward in that array;
> if one value is greater, move forward in the other array.

One small detail: this variable represents the last valid index, not the total size:

```cpp
int size1 = nums1.size() - 1;
int size2 = nums2.size() - 1;
```

That is why the loop uses:

```cpp
i <= size1
j <= size2
```

---

## Complexity

The most expensive part of the solution is sorting both arrays:

```cpp
sort(nums1.begin(), nums1.end());
sort(nums2.begin(), nums2.end());
```

If `n` is the size of `nums1` and `m` is the size of `nums2`, we have:

* Sorting `nums1`: `O(n log n)`
* Sorting `nums2`: `O(m log m)`
* Two-pointer traversal: `O(n + m)`

Final complexity:

* Time: `O(n log n + m log m)`
* Extra space: `O(1)` ignoring the output vector

The `result` vector is usually not counted as auxiliary space because it is the required output of the problem.


