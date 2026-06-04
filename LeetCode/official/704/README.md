
<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 704 — Binary Search</h1>

<p align="center">
  <strong>Sorted Array + Binary Search</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Como o código funciona](#como-o-código-funciona)
  - [Por que retornar `-1`?](#por-que-retornar--1)
  - [Ponto importante sobre `static`](#ponto-importante-sobre-static)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [How the code works](#how-the-code-works)
  - [Why return `-1`?](#why-return--1)
  - [Important point about `static`](#important-point-about-static)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Binary Search** é encontrar a posição de um número dentro de um array ordenado.

Se o número existir, retornamos o índice dele.

Se o número não existir, retornamos:

```cpp
-1
````

Exemplo:

```cpp
nums = {1, 2, 3, 4, 5, 6}
target = 6
```

O número `6` existe no índice `5`, então o retorno será:

```cpp
5
```

---

## Estratégia usada

A solução usa **busca binária**.

Como o array já está ordenado, não precisamos procurar elemento por elemento.

A ideia é dividir o array ao meio repetidamente:

```cpp
int mid = start + (end - start) / 2;
```

Depois comparamos `nums[mid]` com o `target`.

Se `nums[mid]` for igual ao alvo, encontramos a resposta:

```cpp
if (nums[mid] == target)
    return mid;
```

Se `nums[mid]` for menor que o alvo, significa que precisamos procurar na metade direita:

```cpp
start = mid + 1;
```

Se `nums[mid]` for maior que o alvo, precisamos procurar na metade esquerda:

```cpp
end = mid - 1;
```

---

## Como o código funciona

Primeiro, criamos dois limites:

```cpp
int start = 0;
int end = nums.size() - 1;
```

* `start` aponta para o início da região de busca.
* `end` aponta para o final da região de busca.

Enquanto ainda existir uma região válida, o loop continua:

```cpp
while (start <= end)
```

Dentro do loop, calculamos o meio:

```cpp
int mid = start + (end - start) / 2;
```

Essa forma evita problemas de overflow que poderiam acontecer com:

```cpp
int mid = (start + end) / 2;
```

Depois analisamos o valor no meio:

```cpp
if (nums[mid] == target)
    return mid;
```

Se o valor do meio for menor que o `target`, descartamos a metade esquerda:

```cpp
else if (nums[mid] < target)
    start = mid + 1;
```

Caso contrário, descartamos a metade direita:

```cpp
else
    end = mid - 1;
```

---

## Por que retornar `-1`?

O retorno `-1` significa que o número não foi encontrado.

Quando o loop termina, significa que `start` passou de `end`.

Ou seja, não existe mais nenhuma parte válida do array para pesquisar.

```cpp
return -1;
```

Diferente do exercício **Search Insert Position**, aqui não queremos saber onde o número deveria ser inserido.

Neste exercício, queremos apenas saber se ele existe ou não.

Por isso:

* encontrou o número: retorna o índice;
* não encontrou: retorna `-1`.

---

## Ponto importante sobre `static`

No comentário, eu escrevi:

```cpp
// put static before int to test without an object
```

Se a função estiver assim:

```cpp
static int search(std::vector<int>& nums, int target)
```

você pode chamar diretamente pela classe:

```cpp
int result = Solution::search(nums, target);
```

Mas se a função não for `static`, como no código atual:

```cpp
int search(std::vector<int>& nums, int target)
```

então você precisa criar um objeto:

```cpp
Solution sol;
int result = sol.search(nums, target);
```

No LeetCode, normalmente não é necessário usar `static`, porque a plataforma cria o objeto automaticamente.

---

## Complexidade

A busca binária divide o espaço de busca pela metade a cada passo.

Por isso, a complexidade é:

* Tempo: `O(log n)`
* Espaço: `O(1)`

O espaço é constante porque usamos apenas algumas variáveis:

```cpp
int start;
int end;
int mid;
```

---

# English

## Main idea

The goal of **Binary Search** is to find the position of a number inside a sorted array.

If the number exists, we return its index.

If the number does not exist, we return:

```cpp
-1
```

Example:

```cpp
nums = {1, 2, 3, 4, 5, 6}
target = 6
```

The number `6` exists at index `5`, so the return value is:

```cpp
5
```

---

## Strategy used

This solution uses **binary search**.

Since the array is already sorted, we do not need to check every element one by one.

The idea is to repeatedly divide the array in half:

```cpp
int mid = start + (end - start) / 2;
```

Then we compare `nums[mid]` with the `target`.

If `nums[mid]` is equal to the target, we found the answer:

```cpp
if (nums[mid] == target)
    return mid;
```

If `nums[mid]` is smaller than the target, we need to search on the right half:

```cpp
start = mid + 1;
```

If `nums[mid]` is greater than the target, we need to search on the left half:

```cpp
end = mid - 1;
```

---

## How the code works

First, we create two boundaries:

```cpp
int start = 0;
int end = nums.size() - 1;
```

* `start` points to the beginning of the search range.
* `end` points to the end of the search range.

While there is still a valid search range, the loop continues:

```cpp
while (start <= end)
```

Inside the loop, we calculate the middle position:

```cpp
int mid = start + (end - start) / 2;
```

This form avoids possible overflow problems that could happen with:

```cpp
int mid = (start + end) / 2;
```

Then we analyze the middle value:

```cpp
if (nums[mid] == target)
    return mid;
```

If the middle value is smaller than the `target`, we discard the left half:

```cpp
else if (nums[mid] < target)
    start = mid + 1;
```

Otherwise, we discard the right half:

```cpp
else
    end = mid - 1;
```

---

## Why return `-1`?

The return value `-1` means that the number was not found.

When the loop ends, it means that `start` passed `end`.

In other words, there is no valid part of the array left to search.

```cpp
return -1;
```

Unlike **Search Insert Position**, here we do not want to know where the number should be inserted.

In this exercise, we only want to know whether the number exists or not.

So:

* found the number: return its index;
* did not find the number: return `-1`.

---

## Important point about `static`

In my comment, I wrote:

```cpp
// put static before int to test without an object
```

That is correct.

If the function is written like this:

```cpp
static int search(std::vector<int>& nums, int target)
```

you can call it directly through the class:

```cpp
int result = Solution::search(nums, target);
```

But if the function is not `static`, like in the current code:

```cpp
int search(std::vector<int>& nums, int target)
```

then you need to create an object:

```cpp
Solution sol;
int result = sol.search(nums, target);
```

On LeetCode, it is usually not necessary to use `static`, because the platform creates the object automatically.

---

## Complexity

Binary search divides the search space in half at each step.

Therefore, the complexity is:

* Time: `O(log n)`
* Space: `O(1)`

The space is constant because we only use a few variables:

```cpp
int start;
int end;
int mid;
```



