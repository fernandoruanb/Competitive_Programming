<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" alt="LeetCode Cover" width="700"/>
</p>

<h1 align="center">Binary Search</h1>

<p align="center">
  A simple explanation of the Binary Search technique using C++.
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Passo a passo](#passo-a-passo)
  - [Complexidade](#complexidade)
  - [Teste em C++](#teste-em-c)
- [English](#english)
  - [Main idea](#main-idea)
  - [Step by step](#step-by-step)
  - [Complexity](#complexity)
  - [Testing in C++](#testing-in-c)

---

# Portuguese

## Ideia principal

A técnica da **busca binária** consiste em procurar um valor dentro de um array ou vector de inteiros **ordenados**.

Esse detalhe é essencial: a busca binária só funciona corretamente quando os elementos estão em ordem.

Exemplo:

```cpp
std::vector<int> nums = {1, 2, 3, 4, 5, 6};
````

Se queremos encontrar o número `3`, em vez de verificar elemento por elemento, dividimos o intervalo de busca ao meio repetidamente.

Isso permite encontrar o valor com uma complexidade menor do que uma busca linear.

---

## Passo a passo

Primeiro, definimos dois índices:

```cpp
int start = 0;
int end = nums.size() - 1;
```

* `start` representa o início do intervalo.
* `end` representa o final do intervalo.

Depois, criamos um loop que continua enquanto ainda existir um intervalo válido:

```cpp
while (start <= end)
```

Essa condição significa que ainda existe pelo menos uma posição possível para verificar.

Em seguida, calculamos o índice do meio:

```cpp
int mid = start + (end - start) / 2;
```

Essa fórmula é preferida em vez de:

```cpp
int mid = (start + end) / 2;
```

porque evita possíveis problemas com números muito grandes.

Agora analisamos o valor em `nums[mid]`.

Se o valor do meio for igual ao alvo:

```cpp
return mid;
```

Encontramos o número e retornamos seu índice.

Se o valor do meio for maior que o alvo:

```cpp
end = mid - 1;
```

Descartamos o meio e todos os elementos à direita, porque eles também serão maiores.

Se o valor do meio for menor que o alvo:

```cpp
start = mid + 1;
```

Descartamos o meio e todos os elementos à esquerda, porque eles também serão menores.

Caso o número não seja encontrado, o loop termina e retornamos:

```cpp
return -1;
```

O `-1` funciona como um sinal de que o número procurado não existe no array.

---

## Complexidade

A busca binária tem complexidade:

```txt
O(log n)
```

Isso acontece porque, a cada passo, metade do array é descartada.

Comparação:

| Técnica       | Complexidade |
| ------------- | ------------ |
| Busca linear  | O(n)         |
| Busca binária | O(log n)     |

---

## Teste em C++

Para testar em C++, podemos criar uma classe com uma função `search` ou `findNumber` como `public static`.

Assim, não precisamos instanciar um objeto da classe para chamar a função.

Exemplo de chamada:

```cpp
int result = BinarySearch::findNumber(nums, target);
```

Também precisamos incluir:

```cpp
#include <iostream>
#include <vector>
```

Com isso, conseguimos testar a lógica normalmente em um LAB ou em uma solução no estilo LeetCode.

---

# English

## Main idea

The **binary search** technique is used to find a value inside a **sorted** array or vector of integers.

This detail is essential: binary search only works correctly when the elements are ordered.

Example:

```cpp
std::vector<int> nums = {1, 2, 3, 4, 5, 6};
```

If we want to find the number `3`, instead of checking each element one by one, we repeatedly divide the search range in half.

This allows us to find the value with a lower complexity than linear search.

---

## Step by step

First, we define two indexes:

```cpp
int start = 0;
int end = nums.size() - 1;
```

* `start` represents the beginning of the current range.
* `end` represents the end of the current range.

Then, we create a loop that continues while the range is still valid:

```cpp
while (start <= end)
```

This condition means that there is still at least one possible position to check.

Next, we calculate the middle index:

```cpp
int mid = start + (end - start) / 2;
```

This formula is preferred instead of:

```cpp
int mid = (start + end) / 2;
```

because it avoids possible problems with very large numbers.

Now we analyze the value at `nums[mid]`.

If the middle value is equal to the target:

```cpp
return mid;
```

We found the number and return its index.

If the middle value is greater than the target:

```cpp
end = mid - 1;
```

We discard the middle position and all elements on the right side, because they will also be greater.

If the middle value is smaller than the target:

```cpp
start = mid + 1;
```

We discard the middle position and all elements on the left side, because they will also be smaller.

If the number is not found, the loop ends and we return:

```cpp
return -1;
```

The `-1` works as a signal that the searched number does not exist in the array.

---

## Complexity

Binary search has the following complexity:

```txt
O(log n)
```

This happens because, at each step, half of the array is discarded.

Comparison:

| Technique     | Complexity |
| ------------- | ---------- |
| Linear search | O(n)       |
| Binary search | O(log n)   |

---

## Testing in C++

To test it in C++, we can create a class with a `search` or `findNumber` function as `public static`.

This way, we do not need to instantiate an object of the class to call the function.

Example call:

```cpp
int result = BinarySearch::findNumber(nums, target);
```

We also need to include:

```cpp
#include <iostream>
#include <vector>
```

With this, we can test the logic normally in a LAB or in a LeetCode-style solution.

