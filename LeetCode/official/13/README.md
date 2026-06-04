<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 13 — Roman to Integer</h1>

<p align="center">
  <strong>Hash Map + Subtractive Rule</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Como o `unordered_map` ajuda](#como-o-unordered_map-ajuda)
  - [Regra de subtração](#regra-de-subtração)
  - [Como o código funciona](#como-o-código-funciona)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [How `unordered_map` helps](#how-unordered_map-helps)
  - [Subtractive rule](#subtractive-rule)
  - [How the code works](#how-the-code-works)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Roman to Integer** é converter um número romano para seu valor inteiro.

Exemplo:

```cpp
s = "III"
````

O resultado será:

```cpp
3
```

Outro exemplo:

```cpp
s = "IV"
```

O resultado será:

```cpp
4
```

A principal dificuldade é lidar com casos especiais, como `IV`, `IX`, `XL`, `XC`, `CD` e `CM`.

---

## Estratégia usada

A solução usa um `unordered_map` para associar cada símbolo romano ao seu valor inteiro:

```cpp
unordered_map<char, int> myMap = {
    {'I', 1},  
    {'V', 5}, 
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
    {'\0', 0}
};
```

Depois, o código percorre a string caractere por caractere.

Para cada símbolo atual, ele também olha o próximo símbolo:

```cpp
auto curr = myMap.find(s[index]);
auto next = myMap.find(s[index + 1]);
```

A ideia é comparar o valor atual com o próximo valor.

---

## Como o `unordered_map` ajuda

O `unordered_map` permite transformar rapidamente um caractere romano em número.

Por exemplo:

```cpp
'I' -> 1
'V' -> 5
'X' -> 10
'M' -> 1000
```

Então, em vez de fazer vários `if` ou `else if`, o código pode buscar diretamente o valor:

```cpp
curr->second
```

Aqui:

* `curr->first` é o caractere romano;
* `curr->second` é o valor inteiro daquele caractere.

---

## Regra de subtração

Em números romanos, normalmente somamos os valores.

Exemplo:

```cpp
"VI" = 5 + 1 = 6
```

Mas quando um símbolo menor aparece antes de um símbolo maior, fazemos subtração.

Exemplo:

```cpp
"IV" = 5 - 1 = 4
```

No código, essa regra aparece aqui:

```cpp
if (curr->second < next->second) {
    result = result + (next->second - curr->second);
    index += 2;
    continue;
}
```

Se o valor atual for menor que o próximo, significa que temos um caso especial de subtração.

Então o código soma a diferença entre os dois valores e avança duas posições, porque já processou os dois símbolos.

---

## Como o código funciona

Primeiro, criamos o mapa de valores romanos:

```cpp
unordered_map<char, int> myMap = {
    {'I', 1},  
    {'V', 5}, 
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
    {'\0', 0}
};
```

Depois, criamos as variáveis principais:

```cpp
int index = 0;
int result = 0;
```

* `index` controla a posição atual da string.
* `result` acumula o valor final.

Enquanto ainda existir caractere na string, o loop continua:

```cpp
while (s[index])
```

Dentro do loop, o código busca o caractere atual e o próximo:

```cpp
auto curr = myMap.find(s[index]);
auto next = myMap.find(s[index + 1]);
```

Se algum caractere não existir no mapa, a função retorna `-1`:

```cpp
if (curr == myMap.end() || next == myMap.end())
    return (-1);
```

Isso funciona como uma proteção contra caracteres inválidos.

Depois, o código verifica se precisa aplicar a regra de subtração:

```cpp
if (curr->second < next->second)
```

Se sim, soma a diferença:

```cpp
result = result + (next->second - curr->second);
```

E avança duas posições:

```cpp
index += 2;
continue;
```

Caso contrário, soma apenas o valor atual:

```cpp
result += curr->second;
```

E avança uma posição:

```cpp
++index;
```

No final, retorna o resultado convertido:

```cpp
return result;
```

---

## Complexidade

A solução percorre a string uma única vez.

Se `n` é o tamanho da string:

* Tempo: `O(n)`
* Espaço: `O(1)`

O espaço é constante porque o mapa possui sempre a mesma quantidade de símbolos romanos.

---

# English

## Main idea

The goal of **Roman to Integer** is to convert a Roman numeral into its integer value.

Example:

```cpp
s = "III"
```

The result will be:

```cpp
3
```

Another example:

```cpp
s = "IV"
```

The result will be:

```cpp
4
```

The main difficulty is handling special cases such as `IV`, `IX`, `XL`, `XC`, `CD`, and `CM`.

---

## Strategy used

This solution uses an `unordered_map` to associate each Roman symbol with its integer value:

```cpp
unordered_map<char, int> myMap = {
    {'I', 1},  
    {'V', 5}, 
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
    {'\0', 0}
};
```

Then, the code traverses the string character by character.

For each current symbol, it also checks the next symbol:

```cpp
auto curr = myMap.find(s[index]);
auto next = myMap.find(s[index + 1]);
```

The idea is to compare the current value with the next value.

---

## How `unordered_map` helps

The `unordered_map` allows us to quickly transform a Roman character into a number.

For example:

```cpp
'I' -> 1
'V' -> 5
'X' -> 10
'M' -> 1000
```

So instead of writing many `if` or `else if` statements, the code can directly search for the value:

```cpp
curr->second
```

Here:

* `curr->first` is the Roman character;
* `curr->second` is the integer value of that character.

---

## Subtractive rule

In Roman numerals, we usually add the values.

Example:

```cpp
"VI" = 5 + 1 = 6
```

But when a smaller symbol appears before a larger symbol, we subtract.

Example:

```cpp
"IV" = 5 - 1 = 4
```

In the code, this rule appears here:

```cpp
if (curr->second < next->second) {
    result = result + (next->second - curr->second);
    index += 2;
    continue;
}
```

If the current value is smaller than the next value, we have a special subtractive case.

Then the code adds the difference between the two values and moves two positions forward, because both symbols were already processed.

---

## How the code works

First, we create the Roman value map:

```cpp
unordered_map<char, int> myMap = {
    {'I', 1},  
    {'V', 5}, 
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
    {'\0', 0}
};
```

Then, we create the main variables:

```cpp
int index = 0;
int result = 0;
```

* `index` controls the current position in the string.
* `result` stores the final accumulated value.

While there is still a character in the string, the loop continues:

```cpp
while (s[index])
```

Inside the loop, the code searches for the current character and the next one:

```cpp
auto curr = myMap.find(s[index]);
auto next = myMap.find(s[index + 1]);
```

If one of the characters does not exist in the map, the function returns `-1`:

```cpp
if (curr == myMap.end() || next == myMap.end())
    return (-1);
```

This works as protection against invalid characters.

Then, the code checks if the subtractive rule must be applied:

```cpp
if (curr->second < next->second)
```

If yes, it adds the difference:

```cpp
result = result + (next->second - curr->second);
```

And moves two positions forward:

```cpp
index += 2;
continue;
```

Otherwise, it adds only the current value:

```cpp
result += curr->second;
```

And moves one position forward:

```cpp
++index;
```

Finally, it returns the converted result:

```cpp
return result;
```

---

## Complexity

This solution traverses the string only once.

If `n` is the size of the string:

* Time: `O(n)`
* Space: `O(1)`

The space is constant because the map always stores the same fixed number of Roman symbols.

