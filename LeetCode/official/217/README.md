<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 217 — Contains Duplicate</h1>

<p align="center">
  <strong>Sorting + Adjacent Comparison</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Como o código detecta duplicatas](#como-o-código-detecta-duplicatas)
  - [Ponto importante](#ponto-importante)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [How the code detects duplicates](#how-the-code-detects-duplicates)
  - [Important point](#important-point)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Contains Duplicate** é verificar se existe algum número repetido dentro do array.

Se existir pelo menos uma duplicata, retornamos:

```cpp
true
````

Se todos os números forem diferentes, retornamos:

```cpp
false
```

Exemplo:

```cpp
nums = {1, 2, 3, 1}
```

O número `1` aparece duas vezes, então o retorno será:

```cpp
true
```

---

## Estratégia usada

A solução começa ordenando o array:

```cpp
sort(nums.begin(), nums.end());
```

Depois da ordenação, números iguais ficam lado a lado.

Exemplo:

```cpp
nums = {1, 3, 2, 1}
```

Depois do `sort`:

```cpp
nums = {1, 1, 2, 3}
```

Agora fica muito fácil detectar duplicatas, porque basta comparar cada número com o anterior ou com um candidato salvo.

---

## Como o código detecta duplicatas

Primeiro, o código guarda o último índice válido:

```cpp
int size = nums.size() - 1;
```

Depois, começa a comparação a partir do índice `1`:

```cpp
int index = 1;
```

O primeiro número é salvo como candidato inicial:

```cpp
int candidate = nums[0];
```

Dentro do `while`, o código compara o número atual com o candidato:

```cpp
if (nums[index] == candidate)
    return true;
```

Se forem iguais, significa que encontramos uma duplicata.

Caso contrário, atualizamos o candidato para o número atual:

```cpp
candidate = nums[index];
```

Depois avançamos o índice:

```cpp
++index;
```

Assim, o código vai comparando cada elemento com o valor imediatamente anterior dentro do array ordenado.

---

## Ponto importante

A ordenação é o coração dessa solução.

Antes de ordenar, valores duplicados poderiam estar separados:

```cpp
{4, 1, 3, 1}
```

Depois de ordenar, duplicatas ficam juntas:

```cpp
{1, 1, 3, 4}
```

Por isso, uma simples comparação sequencial já resolve o problema.

Um detalhe: esta linha assume que o vetor não está vazio:

```cpp
int candidate = nums[0];
```

No LeetCode, esse problema normalmente fornece um array com pelo menos um elemento. Em código mais genérico, seria seguro verificar antes:

```cpp
if (nums.empty())
    return false;
```

---

## Complexidade

A parte mais cara da solução é a ordenação:

```cpp
sort(nums.begin(), nums.end());
```

Por isso:

* Tempo: `O(n log n)`
* Espaço extra: `O(1)` ou `O(log n)`, dependendo da implementação interna do `sort`

A varredura depois do `sort` custa apenas:

```cpp
O(n)
```

Mas `O(n log n)` domina `O(n)`.

---

# English

## Main idea

The goal of **Contains Duplicate** is to check whether there is any repeated number inside the array.

If at least one duplicate exists, we return:

```cpp
true
```

If all numbers are different, we return:

```cpp
false
```

Example:

```cpp
nums = {1, 2, 3, 1}
```

The number `1` appears twice, so the return value is:

```cpp
true
```

---

## Strategy used

The solution starts by sorting the array:

```cpp
sort(nums.begin(), nums.end());
```

After sorting, equal numbers become adjacent.

Example:

```cpp
nums = {1, 3, 2, 1}
```

After `sort`:

```cpp
nums = {1, 1, 2, 3}
```

Now detecting duplicates becomes simple, because we only need to compare each number with the previous one or with a saved candidate.

---

## How the code detects duplicates

First, the code stores the last valid index:

```cpp
int size = nums.size() - 1;
```

Then, it starts comparing from index `1`:

```cpp
int index = 1;
```

The first number is saved as the initial candidate:

```cpp
int candidate = nums[0];
```

Inside the `while`, the code compares the current number with the candidate:

```cpp
if (nums[index] == candidate)
    return true;
```

If they are equal, it means we found a duplicate.

Otherwise, we update the candidate to the current number:

```cpp
candidate = nums[index];
```

Then we move the index forward:

```cpp
++index;
```

This way, the code compares each element with the immediately previous value inside the sorted array.

---

## Important point

Sorting is the core of this solution.

Before sorting, duplicate values could be separated:

```cpp
{4, 1, 3, 1}
```

After sorting, duplicates become adjacent:

```cpp
{1, 1, 3, 4}
```

Because of that, a simple sequential comparison solves the problem.

One detail: this line assumes that the vector is not empty:

```cpp
int candidate = nums[0];
```

On LeetCode, this problem usually provides an array with at least one element. In more generic code, it would be safer to check first:

```cpp
if (nums.empty())
    return false;
```

---

## Complexity

The most expensive part of the solution is sorting:

```cpp
sort(nums.begin(), nums.end());
```

Therefore:

* Time: `O(n log n)`
* Extra space: `O(1)` or `O(log n)`, depending on the internal implementation of `sort`

The traversal after sorting costs only:

```cpp
O(n)
```

But `O(n log n)` dominates `O(n)`.

