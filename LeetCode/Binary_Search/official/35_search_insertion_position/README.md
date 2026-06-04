<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" alt="LeetCode Cover" width="700"/>

A ideia do **LeetCode 35 — Search Insert Position** é praticamente a mesma da Binary Search clássica, com um detalhe essencial:

> Quando a busca binária termina sem encontrar o número, o `start` aponta exatamente para a posição onde o número deveria ser inserido para manter o array ordenado.

---

## Explicação em português

A lógica é a mesma da Binary Search tradicional:

```cpp
int start = 0;
int end = nums.size() - 1;
```

Enquanto `start <= end`, calculamos o meio:

```cpp
int mid = start + (end - start) / 2;
```

Se encontramos o alvo:

```cpp
return mid;
```

Mas o diferencial desse exercício está no final.

Quando o número **não existe** no array, a busca termina quando `start` passa de `end`.

Nesse momento:

```cpp
return start;
```

Porque `start` representa a primeira posição válida onde o `target` poderia entrar sem quebrar a ordem crescente do array.

---

## Exemplo

```txt
nums = [1, 3, 5, 6]
target = 2
```

O número `2` não existe.

Mas ele deveria ficar aqui:

```txt
[1, 2, 3, 5, 6]
    ^
 index 1
```

Então retornamos:

```txt
1
```

---

## English version

The logic is almost the same as classic Binary Search.

The key difference is what happens when the target is not found.

At the end of the binary search, `start` represents the exact position where the target should be inserted to keep the array sorted.

So instead of returning `-1`, we return:

```cpp
return start;
```

That is the main insight of this problem.

---

## Main learning in English

The main insight of this problem is that Binary Search does not only help us find an existing value.  
When the value does not exist, the final position of `start` tells us exactly where that value should be inserted in the sorted array.

In other words, after the binary search ends, `start` becomes the insertion position.

## Main learning in Portuguese

O principal aprendizado deste exercício é que a Binary Search não serve apenas para encontrar um valor existente.  
Quando o valor não existe, a posição final de `start` indica exatamente onde esse valor deveria ser inserido para manter o array ordenado.

Em outras palavras, ao final da busca binária, `start` se torna a posição de inserção.


Essa é uma ótima conexão mental: **Binary Search também pode encontrar posições, não apenas valores.**

