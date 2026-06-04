
<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 414 — Third Maximum Number</h1>

<p align="center">
  <strong>Sorting + Reverse Traversal + Distinct Maximum Counting</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Como o código evita duplicatas](#como-o-código-evita-duplicatas)
  - [Por que usar `long long int`?](#por-que-usar-long-long-int)
  - [Por que retornar `first` no final?](#por-que-retornar-first-no-final)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [How the code avoids duplicates](#how-the-code-avoids-duplicates)
  - [Why use `long long int`?](#why-use-long-long-int)
  - [Why return `first` at the end?](#why-return-first-at-the-end)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Third Maximum Number** é encontrar o **terceiro maior número distinto** dentro de um array.

A palavra mais importante aqui é:

```cpp
distinct
````

Ou seja, números repetidos não devem ser contados várias vezes.

Exemplo:

```cpp
nums = {3, 2, 1}
```

O terceiro maior número é:

```cpp
1
```

Outro exemplo:

```cpp
nums = {1, 2}
```

Como não existe terceiro maior número distinto, retornamos o maior número:

```cpp
2
```

---

## Estratégia usada

A solução começa ordenando o array:

```cpp
sort(nums.begin(), nums.end());
```

Depois da ordenação, os maiores valores ficam no final do vetor.

Exemplo:

```cpp
nums = {2, 2, 3, 1}
```

Depois do `sort`:

```cpp
nums = {1, 2, 2, 3}
```

Agora podemos percorrer o vetor de trás para frente:

```cpp
int right = nums.size() - 1;
```

Assim, começamos pelo maior número e vamos descendo em direção aos menores.

---

## Como o código evita duplicatas

O código usa a variável `maximum` para guardar o último valor distinto encontrado:

```cpp
long long int maximum = 2147483649;
```

Depois, durante a navegação de trás para frente, ele só conta um número se ele for menor que o último valor contado:

```cpp
if (nums[right] < maximum) {
    maximum = nums[right];
    ++counter;
}
```

Isso evita contar duplicatas.

Exemplo:

```cpp
nums = {1, 2, 2, 3}
```

Percorrendo de trás para frente:

```cpp
3 -> conta como primeiro máximo
2 -> conta como segundo máximo
2 -> não conta, porque é duplicado
1 -> conta como terceiro máximo
```

Quando o contador chega em `3`, encontramos o terceiro maior número distinto:

```cpp
if (counter == 3)
    return static_cast<int>(maximum);
```

---

## Por que usar `long long int`?

A variável `maximum` começa com um valor maior que qualquer `int` comum:

```cpp
long long int maximum = 2147483649;
```

Isso é feito porque os valores do array podem estar dentro do limite de `int`.

Se `maximum` fosse um `int`, esse valor poderia causar problema, porque `2147483649` é maior que `INT_MAX`.

Por isso, o código usa:

```cpp
long long int
```

Assim, o primeiro número analisado sempre será menor que `maximum`, inclusive se o maior número do array for `INT_MAX`.

Uma forma ainda mais clara seria usar:

```cpp
LLONG_MAX
```

Mas, para isso, seria necessário incluir:

```cpp
#include <climits>
```

---

## Por que retornar `first` no final?

Logo depois da ordenação, o maior número está no final do vetor:

```cpp
int first = nums[right];
```

Esse valor é guardado porque, se não existir terceiro maior número distinto, o exercício pede para retornar o maior número.

Exemplo:

```cpp
nums = {1, 2}
```

Depois do `sort`:

```cpp
nums = {1, 2}
```

Não existem três números distintos.

Então o código retorna:

```cpp
return first;
```

Ou seja, retorna o maior número encontrado.

---

## Complexidade

A parte mais cara da solução é a ordenação:

```cpp
sort(nums.begin(), nums.end());
```

Por isso:

* Tempo: `O(n log n)`
* Espaço extra: `O(1)` ou `O(log n)`, dependendo da implementação interna do `sort`

A navegação final de trás para frente custa apenas:

```cpp
O(n)
```

Mas `O(n log n)` domina `O(n)`.

---

# English

## Main idea

The goal of **Third Maximum Number** is to find the **third distinct maximum number** inside an array.

The most important word here is:

```cpp
distinct
```

That means repeated numbers must not be counted multiple times.

Example:

```cpp
nums = {3, 2, 1}
```

The third maximum number is:

```cpp
1
```

Another example:

```cpp
nums = {1, 2}
```

Since there is no third distinct maximum number, we return the maximum number:

```cpp
2
```

---

## Strategy used

The solution starts by sorting the array:

```cpp
sort(nums.begin(), nums.end());
```

After sorting, the largest values are at the end of the vector.

Example:

```cpp
nums = {2, 2, 3, 1}
```

After `sort`:

```cpp
nums = {1, 2, 2, 3}
```

Now we can traverse the vector from right to left:

```cpp
int right = nums.size() - 1;
```

This way, we start from the largest number and move toward the smaller ones.

---

## How the code avoids duplicates

The code uses the variable `maximum` to store the last distinct value found:

```cpp
long long int maximum = 2147483649;
```

Then, while traversing from right to left, it only counts a number if it is smaller than the last counted value:

```cpp
if (nums[right] < maximum) {
    maximum = nums[right];
    ++counter;
}
```

This avoids counting duplicates.

Example:

```cpp
nums = {1, 2, 2, 3}
```

Traversing from right to left:

```cpp
3 -> counts as the first maximum
2 -> counts as the second maximum
2 -> does not count, because it is duplicated
1 -> counts as the third maximum
```

When the counter reaches `3`, we found the third distinct maximum number:

```cpp
if (counter == 3)
    return static_cast<int>(maximum);
```

---

## Why use `long long int`?

The variable `maximum` starts with a value greater than any common `int`:

```cpp
long long int maximum = 2147483649;
```

This is done because the array values can be inside the `int` limit.

If `maximum` were an `int`, this value could cause a problem, because `2147483649` is greater than `INT_MAX`.

That is why the code uses:

```cpp
long long int
```

This way, the first analyzed number will always be smaller than `maximum`, even if the largest number in the array is `INT_MAX`.

An even clearer option would be:

```cpp
LLONG_MAX
```

But for that, we would need:

```cpp
#include <climits>
```

---

## Why return `first` at the end?

Right after sorting, the largest number is at the end of the vector:

```cpp
int first = nums[right];
```

This value is saved because, if there is no third distinct maximum number, the problem asks us to return the maximum number.

Example:

```cpp
nums = {1, 2}
```

After `sort`:

```cpp
nums = {1, 2}
```

There are not three distinct numbers.

So the code returns:

```cpp
return first;
```

That means it returns the largest number found.

---

## Complexity

The most expensive part of the solution is sorting:

```cpp
sort(nums.begin(), nums.end());
```

Therefore:

* Time: `O(n log n)`
* Extra space: `O(1)` or `O(log n)`, depending on the internal implementation of `sort`

The final reverse traversal costs only:

```cpp
O(n)
```

But `O(n log n)` dominates `O(n)`.


