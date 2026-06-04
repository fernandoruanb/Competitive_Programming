<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 283 — Move Zeroes</h1>

<p align="center">
  <strong>Two Pointers + In-place Array Modification</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Como `read` e `write` funcionam](#como-read-e-write-funcionam)
  - [Por que preencher zeros no final?](#por-que-preencher-zeros-no-final)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [How `read` and `write` work](#how-read-and-write-work)
  - [Why fill zeroes at the end?](#why-fill-zeroes-at-the-end)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Move Zeroes** é mover todos os zeros do array para o final, mantendo a ordem relativa dos números diferentes de zero.

Exemplo:

```cpp
nums = {0, 1, 0, 3, 12}
````

Depois da função:

```cpp
nums = {1, 3, 12, 0, 0}
```

O detalhe importante é que a modificação deve ser feita no próprio vetor, sem criar outro vetor de resposta.

---

## Estratégia usada

A solução usa dois índices:

```cpp
int write = 0;
int read = 0;
```

A ideia é:

* `read` percorre todos os elementos do vetor;
* `write` marca onde o próximo número diferente de zero deve ser colocado.

Sempre que encontramos um número diferente de zero, colocamos esse número na posição `write`.

```cpp
if (nums[read] != 0) {
    nums[write] = nums[read];
    ++write;
}
```

Depois, `read` continua avançando até o final do vetor.

---

## Como `read` e `write` funcionam

O ponteiro `read` lê cada posição do array:

```cpp
while (read <= size)
```

Se o valor atual não for zero, ele deve ser preservado:

```cpp
nums[write] = nums[read];
```

Depois disso, `write` avança:

```cpp
++write;
```

Exemplo:

```cpp
nums = {0, 1, 0, 3, 12}
```

Durante a primeira passagem:

```cpp
1  -> vai para nums[0]
3  -> vai para nums[1]
12 -> vai para nums[2]
```

Depois dessa etapa, o começo do array já contém todos os valores diferentes de zero na ordem correta:

```cpp
nums = {1, 3, 12, ?, ?}
```

Os espaços restantes serão preenchidos com zero.

---

## Por que preencher zeros no final?

Depois que todos os números diferentes de zero foram movidos para o começo, o índice `write` aponta para a primeira posição que deve receber zero.

Então usamos outro `while`:

```cpp
while (write <= size) {
    nums[write] = 0;
    ++write;
}
```

Isso completa o vetor colocando zeros no final.

Exemplo:

```cpp
nums = {1, 3, 12, ?, ?}
```

Depois do preenchimento:

```cpp
nums = {1, 3, 12, 0, 0}
```

Essa abordagem é melhor do que usar `erase` e `push_back`, porque `erase` em `vector` desloca elementos internamente e pode deixar a solução mais lenta.

---

## Complexidade

A solução percorre o vetor em duas etapas:

1. Uma passagem para mover os números diferentes de zero.
2. Uma passagem final para preencher os zeros.

Mesmo assim, cada elemento é tratado no máximo algumas vezes.

* Tempo: `O(n)`
* Espaço: `O(1)`

O espaço é constante porque a solução modifica o vetor original e usa apenas variáveis simples.

---

# English

## Main idea

The goal of **Move Zeroes** is to move all zeroes to the end of the array while keeping the relative order of the non-zero numbers.

Example:

```cpp
nums = {0, 1, 0, 3, 12}
```

After the function:

```cpp
nums = {1, 3, 12, 0, 0}
```

The important detail is that the modification must be done in-place, without creating another result vector.

---

## Strategy used

This solution uses two indexes:

```cpp
int write = 0;
int read = 0;
```

The idea is:

* `read` scans every element of the vector;
* `write` marks where the next non-zero number should be placed.

Whenever we find a non-zero number, we write it into the `write` position.

```cpp
if (nums[read] != 0) {
    nums[write] = nums[read];
    ++write;
}
```

Then, `read` keeps moving until the end of the vector.

---

## How `read` and `write` work

The `read` pointer reads each array position:

```cpp
while (read <= size)
```

If the current value is not zero, it must be preserved:

```cpp
nums[write] = nums[read];
```

After that, `write` moves forward:

```cpp
++write;
```

Example:

```cpp
nums = {0, 1, 0, 3, 12}
```

During the first pass:

```cpp
1  -> goes to nums[0]
3  -> goes to nums[1]
12 -> goes to nums[2]
```

After this step, the beginning of the array already contains all non-zero values in the correct order:

```cpp
nums = {1, 3, 12, ?, ?}
```

The remaining positions will be filled with zeroes.

---

## Why fill zeroes at the end?

After all non-zero numbers have been moved to the beginning, `write` points to the first position that should become zero.

So we use another `while` loop:

```cpp
while (write <= size) {
    nums[write] = 0;
    ++write;
}
```

This completes the vector by placing zeroes at the end.

Example:

```cpp
nums = {1, 3, 12, ?, ?}
```

After filling:

```cpp
nums = {1, 3, 12, 0, 0}
```

This approach is better than using `erase` and `push_back`, because `erase` on a `vector` shifts elements internally and can make the solution slower.

---

## Complexity

The solution scans the vector in two stages:

1. One pass to move the non-zero numbers.
2. One final pass to fill the zeroes.

Even so, each element is handled only a small constant number of times.

* Time: `O(n)`
* Space: `O(1)`

The space is constant because the solution modifies the original vector and uses only simple variables.


