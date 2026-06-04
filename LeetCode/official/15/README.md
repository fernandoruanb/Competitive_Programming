
<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 15 — 3Sum</h1>

<p align="center">
  <strong>Sorting + Fixed Index + Two Pointers + Duplicate Control</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Por que ordenar o array?](#por-que-ordenar-o-array)
  - [Como os ponteiros funcionam](#como-os-ponteiros-funcionam)
  - [Como as duplicatas são evitadas](#como-as-duplicatas-são-evitadas)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [Why sort the array?](#why-sort-the-array)
  - [How the pointers work](#how-the-pointers-work)
  - [How duplicates are avoided](#how-duplicates-are-avoided)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **3Sum** é encontrar todos os trios de números dentro de um array cuja soma seja igual a `0`.

Ou seja, precisamos encontrar combinações como:

```cpp
nums[i] + nums[left] + nums[right] == 0
````

A dificuldade principal é que o exercício não aceita trios duplicados.

Por isso, a solução precisa fazer duas coisas ao mesmo tempo:

1. Encontrar os trios corretos.
2. Evitar repetir combinações iguais.

---

## Estratégia usada

A solução começa ordenando o array:

```cpp
sort(nums.begin(), nums.end());
```

Depois disso, usamos uma estratégia parecida com o **Two Sum com dois ponteiros**, mas agora fixando um número primeiro.

A ideia é:

1. Escolher um número fixo com `i`.
2. Usar `left` logo depois de `i`.
3. Usar `right` no final do array.
4. Procurar dois números que, junto com `nums[i]`, somem `0`.

```cpp
left = i + 1;
right = nums.size() - 1;
```

Então, para cada posição `i`, o código procura uma dupla entre `left` e `right`.

---

## Por que ordenar o array?

Ordenar o array permite usar dois ponteiros de forma inteligente.

Depois da ordenação:

* Se a soma for menor que `0`, precisamos de um valor maior.
* Se a soma for maior que `0`, precisamos de um valor menor.

Isso só funciona porque os números estão em ordem.

```cpp
if (sum < 0)
    ++left;
else
    --right;
```

Sem ordenação, não teríamos essa direção clara para mover os ponteiros.

---

## Como os ponteiros funcionam

Para cada `i`, o código calcula:

```cpp
int sum = nums[i] + nums[left] + nums[right];
```

Se a soma for igual a `0`, encontramos um trio válido:

```cpp
result.push_back({nums[i], nums[left], nums[right]});
```

Se a soma for menor que `0`, significa que precisamos aumentar o valor total.

Como o array está ordenado, movemos `left` para a direita:

```cpp
++left;
```

Se a soma for maior que `0`, significa que precisamos diminuir o valor total.

Então movemos `right` para a esquerda:

```cpp
--right;
```

Essa navegação elimina a necessidade de testar todas as combinações possíveis com três loops.

---

## Como as duplicatas são evitadas

Esse exercício exige que o resultado não tenha trios repetidos.

A primeira duplicata evitada é a do índice `i`.

```cpp
if (i > 0 && nums[i] == nums[i - 1]) {
    ++i;
    continue;
}
```

Isso impede que o mesmo valor fixo seja usado novamente para gerar os mesmos trios.

Depois, quando um trio válido é encontrado, o código também pula valores repetidos em `left` e `right`.

```cpp
while (left < right && nums[left] == nums[left + 1])
    ++left;

while (left < right && nums[right] == nums[right - 1])
    --right;
```

Por fim, os ponteiros ainda são movidos uma vez:

```cpp
++left;
--right;
```

Esse movimento final é importante porque, depois de salvar um trio válido, precisamos continuar procurando novas combinações sem repetir a mesma.

---

## Complexidade

A ordenação custa:

```cpp
O(n log n)
```

Depois disso, temos um loop principal com `i`, e dentro dele os ponteiros `left` e `right` percorrem o array.

Isso gera:

```cpp
O(n²)
```

Como `O(n²)` domina `O(n log n)`, a complexidade final é:

* Tempo: `O(n²)`
* Espaço extra: `O(1)` ignorando o vetor de resposta

O vetor `result` não conta como espaço auxiliar comum, porque ele é a saída do problema.

---

# English

## Main idea

The goal of **3Sum** is to find all triplets inside an array whose sum is equal to `0`.

In other words, we need to find combinations like:

```cpp
nums[i] + nums[left] + nums[right] == 0
```

The main difficulty is that the problem does not allow duplicate triplets.

So the solution needs to do two things at the same time:

1. Find the correct triplets.
2. Avoid repeated combinations.

---

## Strategy used

The solution starts by sorting the array:

```cpp
sort(nums.begin(), nums.end());
```

After that, we use an idea similar to **Two Sum with two pointers**, but now we fix one number first.

The idea is:

1. Choose a fixed number with `i`.
2. Place `left` right after `i`.
3. Place `right` at the end of the array.
4. Search for two numbers that, together with `nums[i]`, sum to `0`.

```cpp
left = i + 1;
right = nums.size() - 1;
```

So, for each position `i`, the code searches for a pair between `left` and `right`.

---

## Why sort the array?

Sorting the array allows us to use two pointers intelligently.

After sorting:

* If the sum is smaller than `0`, we need a larger value.
* If the sum is greater than `0`, we need a smaller value.

This only works because the numbers are ordered.

```cpp
if (sum < 0)
    ++left;
else
    --right;
```

Without sorting, we would not have a clear direction to move the pointers.

---

## How the pointers work

For each `i`, the code calculates:

```cpp
int sum = nums[i] + nums[left] + nums[right];
```

If the sum is equal to `0`, we found a valid triplet:

```cpp
result.push_back({nums[i], nums[left], nums[right]});
```

If the sum is smaller than `0`, it means we need to increase the total value.

Since the array is sorted, we move `left` to the right:

```cpp
++left;
```

If the sum is greater than `0`, it means we need to decrease the total value.

So we move `right` to the left:

```cpp
--right;
```

This navigation avoids the need to test every possible combination with three nested loops.

---

## How duplicates are avoided

This problem requires the result to contain no repeated triplets.

The first duplicate control happens at index `i`.

```cpp
if (i > 0 && nums[i] == nums[i - 1]) {
    ++i;
    continue;
}
```

This prevents the same fixed value from being used again to generate the same triplets.

Then, when a valid triplet is found, the code also skips repeated values on `left` and `right`.

```cpp
while (left < right && nums[left] == nums[left + 1])
    ++left;

while (left < right && nums[right] == nums[right - 1])
    --right;
```

Finally, the pointers are moved one more time:

```cpp
++left;
--right;
```

This final movement is important because, after saving a valid triplet, we need to keep searching for new combinations without repeating the same one.

---

## Complexity

Sorting costs:

```cpp
O(n log n)
```

After that, we have a main loop with `i`, and inside it the `left` and `right` pointers scan the array.

This gives:

```cpp
O(n²)
```

Since `O(n²)` dominates `O(n log n)`, the final complexity is:

* Time: `O(n²)`
* Extra space: `O(1)` ignoring the output vector

The `result` vector is usually not counted as auxiliary space because it is the required output of the problem.

