
<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 1 — Two Sum</h1>

<p align="center">
  <strong>Two Pointers + Sorting + Original Index Tracking</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Por que usar `pair<int, int>`?](#por-que-usar-pairint-int)
  - [Fluxo da solução](#fluxo-da-solução)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [Why use `pair<int, int>`?](#why-use-pairint-int)
  - [Solution flow](#solution-flow)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Two Sum** é encontrar dois números dentro de um array cuja soma seja igual ao `target`.

A dificuldade principal é que precisamos retornar os **índices originais** dos números, não os valores em si.

Nesta solução, a ideia foi transformar o array original em um vetor de pares:

```cpp
vector<pair<int, int>> pairs;
````

Cada par guarda duas informações:

```cpp
{valor, índice_original}
```

Exemplo:

```cpp
nums = [3, 2, 4]
target = 6
```

Depois de criar os pares:

```cpp
pairs = {
  {3, 0},
  {2, 1},
  {4, 2}
}
```

Após ordenar:

```cpp
pairs = {
  {2, 1},
  {3, 0},
  {4, 2}
}
```

Agora os valores estão ordenados, mas os índices originais ainda estão preservados.

---

## Estratégia usada

A solução usa a técnica de **dois ponteiros**.

Depois de ordenar o vetor `pairs`, criamos dois índices:

```cpp
int left = 0;
int right = nums.size() - 1;
```

* `left` começa no menor valor.
* `right` começa no maior valor.

A cada passo, fazemos:

```cpp
int sum = pairs[left].first + pairs[right].first;
```

Se a soma for igual ao `target`, encontramos a resposta.

Se a soma for maior que o `target`, diminuímos o `right`, porque precisamos de um valor menor.

```cpp
--right;
```

Se a soma for menor que o `target`, aumentamos o `left`, porque precisamos de um valor maior.

```cpp
++left;
```

---

## Por que usar `pair<int, int>`?

Porque ordenar diretamente o vetor `nums` destruiria a posição original dos elementos.

O problema pede os índices originais, então precisamos guardar o valor junto com o índice.

```cpp
pairs.push_back({value, index});
```

Aqui:

* `value` é o número atual.
* `index` é a posição original desse número em `nums`.

Assim, mesmo depois do `sort`, ainda conseguimos retornar:

```cpp
pairs[left].second
pairs[right].second
```

Ou seja, os índices verdadeiros no vetor original.

---

## Fluxo da solução

1. Criar um vetor de pares.
2. Guardar cada número junto com seu índice original.
3. Ordenar os pares pelo valor.
4. Usar dois ponteiros:

   * um no começo;
   * outro no final.
5. Somar os valores apontados.
6. Ajustar os ponteiros conforme o resultado:

   * soma alta demais: mover `right`;
   * soma baixa demais: mover `left`;
   * soma correta: retornar os índices originais.

---

## Complexidade

A ordenação domina o custo da solução.

```cpp
sort(pairs.begin(), pairs.end());
```

Portanto:

* Tempo: `O(n log n)`
* Espaço: `O(n)`

O espaço extra vem do vetor `pairs`, usado para preservar os índices originais.

---

# English

## Main idea

The goal of the **Two Sum** problem is to find two numbers inside an array whose sum is equal to the `target`.

The main difficulty is that we need to return the **original indexes** of those numbers, not the values themselves.

In this solution, the original array is transformed into a vector of pairs:

```cpp
vector<pair<int, int>> pairs;
```

Each pair stores two pieces of information:

```cpp
{value, original_index}
```

Example:

```cpp
nums = [3, 2, 4]
target = 6
```

After creating the pairs:

```cpp
pairs = {
  {3, 0},
  {2, 1},
  {4, 2}
}
```

After sorting:

```cpp
pairs = {
  {2, 1},
  {3, 0},
  {4, 2}
}
```

Now the values are sorted, but the original indexes are still preserved.

---

## Strategy used

This solution uses the **two pointers** technique.

After sorting the `pairs` vector, we create two indexes:

```cpp
int left = 0;
int right = nums.size() - 1;
```

* `left` starts at the smallest value.
* `right` starts at the largest value.

At each step, we calculate:

```cpp
int sum = pairs[left].first + pairs[right].first;
```

If the sum is equal to the `target`, we found the answer.

If the sum is greater than the `target`, we move `right` to the left, because we need a smaller value.

```cpp
--right;
```

If the sum is smaller than the `target`, we move `left` to the right, because we need a larger value.

```cpp
++left;
```

---

## Why use `pair<int, int>`?

Because sorting the original `nums` vector directly would destroy the original positions of the elements.

The problem asks for the original indexes, so we need to store each value together with its original index.

```cpp
pairs.push_back({value, index});
```

Here:

* `value` is the current number.
* `index` is the original position of that number in `nums`.

So even after sorting, we can still return:

```cpp
pairs[left].second
pairs[right].second
```

That means we return the real indexes from the original array.

---

## Solution flow

1. Create a vector of pairs.
2. Store each number together with its original index.
3. Sort the pairs by value.
4. Use two pointers:

   * one at the beginning;
   * one at the end.
5. Add the values pointed to by `left` and `right`.
6. Move the pointers based on the result:

   * sum too high: move `right`;
   * sum too low: move `left`;
   * correct sum: return the original indexes.

---

## Complexity

The sorting step dominates the cost of the solution.

```cpp
sort(pairs.begin(), pairs.end());
```

Therefore:

* Time: `O(n log n)`
* Space: `O(n)`

The extra space comes from the `pairs` vector, which is used to preserve the original indexes.


