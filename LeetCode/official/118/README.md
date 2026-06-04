<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 118 — Pascal's Triangle</h1>

<p align="center">
  <strong>Dynamic Row Building + Previous Row Reference</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Como cada linha é construída](#como-cada-linha-é-construída)
  - [Por que usar `prev`?](#por-que-usar-prev)
  - [Casos especiais](#casos-especiais)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [How each row is built](#how-each-row-is-built)
  - [Why use `prev`?](#why-use-prev)
  - [Special cases](#special-cases)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Pascal's Triangle** é gerar as primeiras `numRows` linhas do Triângulo de Pascal.

Cada linha começa e termina com `1`.

Os valores do meio são formados pela soma de dois valores da linha anterior.

Exemplo:

```cpp
numRows = 5
````

Resultado:

```cpp
[
  [1],
  [1, 1],
  [1, 2, 1],
  [1, 3, 3, 1],
  [1, 4, 6, 4, 1]
]
```

A regra principal é:

```cpp
linha_atual[i] = linha_anterior[i - 1] + linha_anterior[i]
```

---

## Estratégia usada

A solução constrói o triângulo linha por linha.

Primeiro, cria as duas primeiras linhas manualmente:

```cpp
vector<int> prev = {1};
vector<int> curr = {1, 1};
```

Depois, adiciona a primeira linha ao resultado:

```cpp
result.push_back(prev);
```

Se `numRows` for maior que `2`, o código começa a gerar as próximas linhas usando a linha anterior como base.

```cpp
prev = curr;
```

A partir daí, cada nova linha é construída dentro do `while`.

---

## Como cada linha é construída

A variável `size` representa o tamanho da próxima linha a ser criada.

```cpp
int size = 3;
```

A terceira linha tem tamanho `3`:

```cpp
[1, 2, 1]
```

Dentro do `while`, criamos uma nova linha vazia:

```cpp
vector<int> r;
```

Toda linha do Triângulo de Pascal começa com `1`:

```cpp
r.push_back(1);
```

Depois, calculamos os valores do meio:

```cpp
for (int counter = 1; counter < size - 1; ++counter) {
    r.push_back(prev[counter - 1] + prev[counter]);
}
```

Essa é a parte central da lógica.

Para cada posição do meio, somamos dois valores da linha anterior.

Exemplo:

```cpp
prev = [1, 2, 1]
```

A próxima linha começa assim:

```cpp
r = [1]
```

Valores do meio:

```cpp
1 + 2 = 3
2 + 1 = 3
```

Depois colocamos o último `1`:

```cpp
r.push_back(1);
```

Resultado:

```cpp
r = [1, 3, 3, 1]
```

---

## Por que usar `prev`?

A variável `prev` guarda a linha anterior.

Ela é necessária porque cada nova linha depende diretamente da linha que veio antes.

```cpp
prev[counter - 1] + prev[counter]
```

Depois que uma nova linha é criada, ela passa a ser a linha anterior da próxima iteração:

```cpp
prev = r;
```

Então o fluxo é:

```cpp
[1, 1]       -> gera [1, 2, 1]
[1, 2, 1]   -> gera [1, 3, 3, 1]
[1, 3, 3, 1] -> gera [1, 4, 6, 4, 1]
```

Essa é uma forma natural de construir o Triângulo de Pascal dinamicamente.

---

## Casos especiais

O código trata separadamente os casos em que `numRows` é `1` ou `2`.

Se `numRows == 1`, retornamos apenas:

```cpp
[[1]]
```

Código:

```cpp
if (numRows == 1)
    return result;
```

Se `numRows == 2`, adicionamos a segunda linha e retornamos:

```cpp
[[1], [1, 1]]
```

Código:

```cpp
if (numRows == 2) {
    result.push_back(curr);
    return result;
}
```

Isso evita que o `while` precise lidar com linhas pequenas demais.

---

## Complexidade

O código precisa construir todas as linhas do triângulo.

A quantidade total de elementos gerados é aproximadamente:

```cpp
1 + 2 + 3 + ... + numRows
```

Isso resulta em:

```cpp
O(numRows²)
```

Portanto:

* Tempo: `O(numRows²)`
* Espaço: `O(numRows²)`

O espaço é `O(numRows²)` porque o vetor `result` armazena todas as linhas geradas.

---

# English

## Main idea

The goal of **Pascal's Triangle** is to generate the first `numRows` rows of Pascal's Triangle.

Each row starts and ends with `1`.

The middle values are formed by adding two values from the previous row.

Example:

```cpp
numRows = 5
```

Result:

```cpp
[
  [1],
  [1, 1],
  [1, 2, 1],
  [1, 3, 3, 1],
  [1, 4, 6, 4, 1]
]
```

The main rule is:

```cpp
current_row[i] = previous_row[i - 1] + previous_row[i]
```

---

## Strategy used

This solution builds the triangle row by row.

First, it creates the first two rows manually:

```cpp
vector<int> prev = {1};
vector<int> curr = {1, 1};
```

Then, it adds the first row to the result:

```cpp
result.push_back(prev);
```

If `numRows` is greater than `2`, the code starts generating the next rows using the previous row as a reference.

```cpp
prev = curr;
```

From that point, each new row is built inside the `while` loop.

---

## How each row is built

The variable `size` represents the size of the next row to create.

```cpp
int size = 3;
```

The third row has size `3`:

```cpp
[1, 2, 1]
```

Inside the `while`, we create a new empty row:

```cpp
vector<int> r;
```

Every row in Pascal's Triangle starts with `1`:

```cpp
r.push_back(1);
```

Then, we calculate the middle values:

```cpp
for (int counter = 1; counter < size - 1; ++counter) {
    r.push_back(prev[counter - 1] + prev[counter]);
}
```

This is the core logic.

For each middle position, we add two values from the previous row.

Example:

```cpp
prev = [1, 2, 1]
```

The next row starts as:

```cpp
r = [1]
```

Middle values:

```cpp
1 + 2 = 3
2 + 1 = 3
```

Then we add the final `1`:

```cpp
r.push_back(1);
```

Result:

```cpp
r = [1, 3, 3, 1]
```

---

## Why use `prev`?

The variable `prev` stores the previous row.

It is necessary because each new row depends directly on the row before it.

```cpp
prev[counter - 1] + prev[counter]
```

After a new row is created, it becomes the previous row for the next iteration:

```cpp
prev = r;
```

So the flow is:

```cpp
[1, 1]        -> generates [1, 2, 1]
[1, 2, 1]    -> generates [1, 3, 3, 1]
[1, 3, 3, 1] -> generates [1, 4, 6, 4, 1]
```

This is a natural way to build Pascal's Triangle dynamically.

---

## Special cases

The code handles separately the cases where `numRows` is `1` or `2`.

If `numRows == 1`, we return only:

```cpp
[[1]]
```

Code:

```cpp
if (numRows == 1)
    return result;
```

If `numRows == 2`, we add the second row and return:

```cpp
[[1], [1, 1]]
```

Code:

```cpp
if (numRows == 2) {
    result.push_back(curr);
    return result;
}
```

This prevents the `while` loop from dealing with rows that are too small.

---

## Complexity

The code needs to build every row of the triangle.

The total number of generated elements is approximately:

```cpp
1 + 2 + 3 + ... + numRows
```

This results in:

```cpp
O(numRows²)
```

Therefore:

* Time: `O(numRows²)`
* Space: `O(numRows²)`

The space is `O(numRows²)` because the `result` vector stores all generated rows.
