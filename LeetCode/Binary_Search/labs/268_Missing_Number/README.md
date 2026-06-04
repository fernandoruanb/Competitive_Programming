<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" alt="LeetCode Cover" width="700"/>
</p>

# LeetCode 268 — Missing Number

### A lesson about not forcing Binary Search everywhere

![Language](https://img.shields.io/badge/Language-C++-blue.svg)
![Topic](https://img.shields.io/badge/Topic-Math%20%7C%20Array%20%7C%20Logic-orange.svg)
![Complexity](https://img.shields.io/badge/Time-O(n)-green.svg)
![Space](https://img.shields.io/badge/Space-O(1)-green.svg)

</div>

---

## Navigation

- [English Explanation](#english-explanation)
- [Portuguese Explanation](#explicação-em-português)
- [Initial Approach: Binary Search + Sort](#initial-approach-binary-search--sort)
- [Better Approach: Mathematical Sum](#better-approach-mathematical-sum)
- [C++ Solution](#c-solution)
- [Complexity Analysis](#complexity-analysis)
- [Final Lesson](#final-lesson)

---

# English Explanation

For this exercise, my first instinct was to apply the logic of **Binary Search**, because I had just studied it and was trying to connect the concept with the problem.

However, although this problem can be solved by sorting the array and then applying a search-based strategy, the result was not optimal.

In my case, the solution using `sort` reached only around **11% runtime beats** compared to other LeetCode submissions.

That made me realize something important:

> Just because you learned a technique recently, it does not mean every problem should be forced to fit that technique.

The real lesson here is that solving a problem is not only about applying a known algorithm.  
It is about understanding the nature of the problem and choosing the most direct and efficient reasoning.

---

# Explicação em Português

Para este exercício, eu apliquei inicialmente a lógica de **Binary Search**, porque tinha acabado de estudar esse conceito e tentei conectar a ideia com o problema.

Só que, neste caso, apesar de ser possível resolver usando ordenação com `sort` e depois uma lógica baseada em busca, o resultado não foi o mais eficiente.

Minha solução usando `sort` ficou com cerca de **11% melhor que os demais usuários do LeetCode** em runtime.

Isso trouxe uma lição importante:

> Não importa se você acabou de sair de uma aula de Binary Search.  
> Você não deve forçar o mundo a funcionar com Binary Search.

Você pode até conseguir resolver, mas talvez esteja forçando a realidade a se adaptar à técnica, ignorando um raciocínio mais amplo, simples e correto.

---

# Initial Approach: Binary Search + Sort

The first approach was:

1. Sort the array.
2. Use a search-based logic to detect the missing number.

Example:

```cpp
std::sort(nums.begin(), nums.end());
````

This works, but it costs:

```txt
O(n log n)
```

The problem is that sorting is unnecessary here.

We do not actually need the array to be ordered.
We only need to know the difference between what should exist and what actually exists.

---

# Better Approach: Mathematical Sum

The better solution comes from mathematics.

The sum of numbers from `0` to `n` can be calculated using:

```txt
sum = n * (n + 1) / 2
```

So the idea is simple:

1. Calculate the expected sum.
2. Calculate the real sum of the numbers inside the array.
3. The difference is the missing number.

Example:

```txt
nums = [0, 1, 3]

Expected sum:
0 + 1 + 2 + 3 = 6

Real sum:
0 + 1 + 3 = 4

Missing number:
6 - 4 = 2
```

---

# C++ Solution

```cpp
#include <vector>

class Solution {
public:
    static int detectMissingNumber(std::vector<int>& nums) {
        int size = nums.size();
        int expected_sum = size * (size + 1) / 2;
        int real_sum = 0;

        for (int n : nums)
            real_sum += n;

        return expected_sum - real_sum;
    }
};
```

---

# Complexity Analysis

## Time Complexity

```txt
O(n)
```

We only iterate through the array once.

---

## Space Complexity

```txt
O(1)
```

We do not create any extra data structure.

---

# Final Lesson

## English

The main lesson from this problem is:

> Do not force a technique just because you recently learned it.

Binary Search is powerful, but it is not always the best tool.

Sometimes the best solution comes from stepping back and asking:

> What is the simplest property of this problem?

In this case, the key insight was not searching.
It was the mathematical relationship between the expected sum and the real sum.

---

## Português

A principal lição deste exercício é:

> Não force uma técnica apenas porque você acabou de aprendê-la.

Binary Search é poderoso, mas nem sempre é a melhor ferramenta.

Às vezes, a melhor solução aparece quando você dá um passo atrás e pergunta:

> Qual é a propriedade mais simples deste problema?

Neste caso, o ponto central não era buscar.
Era perceber a relação matemática entre a soma esperada e a soma real.

---

<div align="center">

### Strong lesson:

**Algorithmic thinking is not about forcing patterns.
It is about choosing the right pattern for the problem.**

</div>
