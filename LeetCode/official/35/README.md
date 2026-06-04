
<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 35 — Search Insert Position</h1>

<p align="center">
  <strong>Binary Search + Insertion Position</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Por que retornar `start`?](#por-que-retornar-start)
  - [Como o código funciona](#como-o-código-funciona)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [Why return `start`?](#why-return-start)
  - [How the code works](#how-the-code-works)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Search Insert Position** é encontrar a posição de um número dentro de um array ordenado.

Se o número existir, retornamos o índice dele.

Se o número não existir, retornamos a posição onde ele deveria ser inserido para manter o array ordenado.

Exemplo:

```cpp
nums = {1, 3, 5, 6}
target = 5
````

O número `5` existe no índice `2`, então retornamos:

```cpp
2
```

Outro exemplo:

```cpp
nums = {1, 3, 5, 6}
target = 2
```

O número `2` não existe, mas deveria ficar entre `1` e `3`.

Então retornamos:

```cpp
1
```

---

## Estratégia usada

A solução usa **Binary Search**.

Como o array já está ordenado, não precisamos percorrer todos os elementos um por um.

Em vez disso, dividimos o espaço de busca ao meio a cada passo:

```cpp
int mid = start + (end - start) / 2;
```

Depois comparamos `nums[mid]` com o `target`.

Se forem iguais, encontramos a posição:

```cpp
if (nums[mid] == target)
    return mid;
```

Se `nums[mid]` for maior que `target`, precisamos procurar na metade esquerda:

```cpp
end = mid - 1;
```

Se `nums[mid]` for menor que `target`, precisamos procurar na metade direita:

```cpp
start = mid + 1;
```

---

## Por que retornar `start`?

Esse é o ponto mais importante do exercício.

Quando o `target` não existe no array, o loop termina quando `start` passa de `end`.

Nesse momento, `start` aponta exatamente para a posição onde o número deveria ser inserido.

Exemplo:

```cpp
nums = {1, 3, 5, 6}
target = 2
```

Durante a busca:

```cpp
start = 0
end = 3
```

O algoritmo ajusta os limites até perceber que o `2` deveria ficar antes do `3`.

No final, `start` fica em:

```cpp
start = 1
```

Por isso retornamos:

```cpp
return start;
```

A grande lição é que a Binary Search não serve apenas para encontrar um valor. Ela também pode revelar a posição correta onde esse valor deveria estar.

---

## Como o código funciona

Primeiro, criamos os limites da busca:

```cpp
int start = 0;
int end = nums.size() - 1;
```

Enquanto `start` for menor ou igual a `end`, ainda existe uma região válida para procurar:

```cpp
while (start <= end)
```

Calculamos o meio:

```cpp
int mid = start + (end - start) / 2;
```

Se o valor do meio for o alvo, retornamos o índice:

```cpp
if (nums[mid] == target)
    return mid;
```

Se o valor do meio for maior que o alvo, descartamos a metade direita:

```cpp
else if (nums[mid] > target)
    end = mid - 1;
```

Se o valor do meio for menor que o alvo, descartamos a metade esquerda:

```cpp
else if (nums[mid] < target)
    start = mid + 1;
```

Se o loop terminar sem encontrar o alvo, retornamos `start`:

```cpp
return start;
```

---

## Complexidade

Como a busca binária divide o espaço de busca pela metade a cada passo, a complexidade é:

* Tempo: `O(log n)`
* Espaço: `O(1)`

O espaço é constante porque usamos apenas algumas variáveis simples:

```cpp
int start;
int end;
int mid;
```

---

# English

## Main idea

The goal of **Search Insert Position** is to find the position of a number inside a sorted array.

If the number exists, we return its index.

If the number does not exist, we return the position where it should be inserted to keep the array sorted.

Example:

```cpp
nums = {1, 3, 5, 6}
target = 5
```

The number `5` exists at index `2`, so we return:

```cpp
2
```

Another example:

```cpp
nums = {1, 3, 5, 6}
target = 2
```

The number `2` does not exist, but it should be placed between `1` and `3`.

So we return:

```cpp
1
```

---

## Strategy used

This solution uses **Binary Search**.

Since the array is already sorted, we do not need to check every element one by one.

Instead, we divide the search space in half at each step:

```cpp
int mid = start + (end - start) / 2;
```

Then we compare `nums[mid]` with the `target`.

If they are equal, we found the position:

```cpp
if (nums[mid] == target)
    return mid;
```

If `nums[mid]` is greater than `target`, we need to search on the left half:

```cpp
end = mid - 1;
```

If `nums[mid]` is smaller than `target`, we need to search on the right half:

```cpp
start = mid + 1;
```

---

## Why return `start`?

This is the most important point of the exercise.

When the `target` does not exist in the array, the loop ends when `start` passes `end`.

At that moment, `start` points exactly to the position where the number should be inserted.

Example:

```cpp
nums = {1, 3, 5, 6}
target = 2
```

During the search:

```cpp
start = 0
end = 3
```

The algorithm adjusts the limits until it realizes that `2` should be placed before `3`.

At the end, `start` becomes:

```cpp
start = 1
```

That is why we return:

```cpp
return start;
```

The main lesson is that Binary Search is not only useful for finding a value. It can also reveal the correct position where that value should be.

---

## How the code works

First, we create the search boundaries:

```cpp
int start = 0;
int end = nums.size() - 1;
```

While `start` is less than or equal to `end`, there is still a valid search range:

```cpp
while (start <= end)
```

We calculate the middle position:

```cpp
int mid = start + (end - start) / 2;
```

If the middle value is the target, we return the index:

```cpp
if (nums[mid] == target)
    return mid;
```

If the middle value is greater than the target, we discard the right half:

```cpp
else if (nums[mid] > target)
    end = mid - 1;
```

If the middle value is smaller than the target, we discard the left half:

```cpp
else if (nums[mid] < target)
    start = mid + 1;
```

If the loop ends without finding the target, we return `start`:

```cpp
return start;
```

---

## Complexity

Since Binary Search divides the search space in half at each step, the complexity is:

* Time: `O(log n)`
* Space: `O(1)`

The space is constant because we only use a few simple variables:

```cpp
int start;
int end;
int mid;
```


