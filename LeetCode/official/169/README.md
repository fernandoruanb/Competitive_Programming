
<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 169 — Majority Element</h1>

<p align="center">
  <strong>Boyer-Moore Voting Algorithm</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Como o contador funciona](#como-o-contador-funciona)
  - [Por que o candidato final é a resposta?](#por-que-o-candidato-final-é-a-resposta)
  - [Ponto importante](#ponto-importante)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [How the counter works](#how-the-counter-works)
  - [Why the final candidate is the answer](#why-the-final-candidate-is-the-answer)
  - [Important point](#important-point)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Majority Element** é encontrar o elemento que aparece mais de `n / 2` vezes dentro do array.

Ou seja, queremos encontrar o número que domina a lista.

Exemplo:

```cpp
nums = {3, 2, 3}
````

O número `3` aparece duas vezes em um array de tamanho `3`.

Como `2 > 3 / 2`, o elemento majoritário é:

```cpp
3
```

---

## Estratégia usada

Esta solução usa o algoritmo **Boyer-Moore Voting Algorithm**.

A ideia é não precisar ordenar o array e também não precisar usar `map` ou `unordered_map`.

Em vez disso, mantemos apenas duas variáveis:

```cpp
int counter = 0;
int candidate = 0;
```

* `candidate` guarda o possível elemento majoritário.
* `counter` mede a força atual desse candidato.

O algoritmo percorre o array uma única vez.

---

## Como o contador funciona

Quando o contador chega a `0`, escolhemos um novo candidato:

```cpp
if (counter == 0) {
    counter = 1;
    candidate = n;
}
```

Isso significa:

> “No momento, não tenho um candidato forte. Então este número atual será meu novo candidato.”

Se o próximo número for igual ao candidato, aumentamos o contador:

```cpp
else if (n == candidate)
    ++counter;
```

Se o próximo número for diferente, diminuímos o contador:

```cpp
else
    --counter;
```

A lógica é como uma votação:

* número igual ao candidato: voto a favor;
* número diferente: voto contra.

---

## Por que o candidato final é a resposta?

O problema garante que sempre existe um elemento majoritário.

Esse elemento aparece mais da metade das vezes.

Por isso, mesmo que outros números “cancelem” alguns votos dele, ele ainda sobra no final.

Exemplo:

```cpp
nums = {2, 2, 1, 1, 1, 2, 2}
```

O número `2` aparece `4` vezes em um array de tamanho `7`.

Durante o processo, alguns `1` cancelam votos do `2`.

Mas como `2` aparece mais que todos os outros combinados, ele termina como candidato final.

```cpp
return candidate;
```

---

## Ponto importante

A variável abaixo foi criada, mas não está sendo usada:

```cpp
int size = nums.size() - 1;
```

Ela pode ser removida sem mudar o comportamento do código.

A versão mais limpa ficaria apenas com:

```cpp
int counter = 0;
int candidate = 0;
```

A grande vantagem dessa solução é que ela é mais rápida que ordenar o array.

Uma solução com `sort` teria tempo `O(n log n)`.

Com Boyer-Moore, conseguimos resolver em tempo linear:

```cpp
O(n)
```

---

## Complexidade

A solução percorre o array apenas uma vez.

* Tempo: `O(n)`
* Espaço: `O(1)`

O espaço é constante porque usamos apenas duas variáveis principais:

```cpp
int counter;
int candidate;
```

---

# English

## Main idea

The goal of **Majority Element** is to find the element that appears more than `n / 2` times inside the array.

In other words, we want to find the number that dominates the list.

Example:

```cpp
nums = {3, 2, 3}
```

The number `3` appears twice in an array of size `3`.

Since `2 > 3 / 2`, the majority element is:

```cpp
3
```

---

## Strategy used

This solution uses the **Boyer-Moore Voting Algorithm**.

The idea is to avoid sorting the array and also avoid using a `map` or `unordered_map`.

Instead, we keep only two variables:

```cpp
int counter = 0;
int candidate = 0;
```

* `candidate` stores the possible majority element.
* `counter` measures the current strength of that candidate.

The algorithm traverses the array only once.

---

## How the counter works

When the counter becomes `0`, we choose a new candidate:

```cpp
if (counter == 0) {
    counter = 1;
    candidate = n;
}
```

This means:

> “Right now, I do not have a strong candidate. So the current number becomes my new candidate.”

If the next number is equal to the candidate, we increase the counter:

```cpp
else if (n == candidate)
    ++counter;
```

If the next number is different, we decrease the counter:

```cpp
else
    --counter;
```

The logic works like voting:

* number equal to the candidate: vote in favor;
* different number: vote against.

---

## Why the final candidate is the answer

The problem guarantees that a majority element always exists.

This element appears more than half of the time.

Because of that, even if other numbers cancel some of its votes, it still survives at the end.

Example:

```cpp
nums = {2, 2, 1, 1, 1, 2, 2}
```

The number `2` appears `4` times in an array of size `7`.

During the process, some `1`s cancel votes from `2`.

But since `2` appears more than all the other numbers combined, it ends as the final candidate.

```cpp
return candidate;
```

---

## Important point

The variable below was created, but it is not being used:

```cpp
int size = nums.size() - 1;
```

It can be removed without changing the behavior of the code.

A cleaner version only needs:

```cpp
int counter = 0;
int candidate = 0;
```

The main advantage of this solution is that it is faster than sorting the array.

A solution with `sort` would take `O(n log n)` time.

With Boyer-Moore, we solve it in linear time:

```cpp
O(n)
```

---

## Complexity

This solution traverses the array only once.

* Time: `O(n)`
* Space: `O(1)`

The space is constant because we only use two main variables:

```cpp
int counter;
int candidate;
```


