<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 981 — Time Based Key-Value Store</h1>

<p align="center">
  <strong>Map + Vector of Pairs + Binary Search</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estrutura usada](#estrutura-usada)
  - [Como o `set` funciona](#como-o-set-funciona)
  - [Como o `get` funciona](#como-o-get-funciona)
  - [Como a busca binária é usada](#como-a-busca-binária-é-usada)
  - [Ponto importante](#ponto-importante)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Structure used](#structure-used)
  - [How `set` works](#how-set-works)
  - [How `get` works](#how-get-works)
  - [How binary search is used](#how-binary-search-is-used)
  - [Important point](#important-point)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Time Based Key-Value Store** é criar uma estrutura capaz de salvar valores associados a uma chave e a um tempo.

A ideia é que uma mesma chave pode receber vários valores em momentos diferentes.

Exemplo:

```cpp
set("foo", "bar", 1);
set("foo", "bar2", 4);
````

Depois disso, se chamarmos:

```cpp
get("foo", 4);
```

A resposta deve ser:

```cpp
"bar2"
```

Mas se chamarmos:

```cpp
get("foo", 3);
```

A resposta deve ser:

```cpp
"bar"
```

Porque no tempo `3`, o valor mais recente disponível ainda era o valor salvo no tempo `1`.

---

## Estrutura usada

A estrutura principal do código é:

```cpp
map<string, vector<pair<int, string>>> myMap;
```

Ela pode ser entendida assim:

```cpp
key -> lista de {timestamp, value}
```

Exemplo visual:

```cpp
"foo" -> {
  {1, "bar"},
  {4, "bar2"}
}
```

Ou seja:

* `map` guarda cada chave.
* `vector` guarda o histórico daquela chave.
* `pair<int, string>` guarda o tempo e o valor.

```cpp
pair<int, string>
```

Aqui:

* `first` é o `timestamp`;
* `second` é o `value`.

---

## Como o `set` funciona

A função `set` salva um novo valor dentro do histórico da chave:

```cpp
void set(string key, string value, int timestamp) {
    myMap[key].push_back({timestamp, value});
}
```

Se a chave ainda não existir, o `map` cria automaticamente uma entrada para ela.

Depois, o par `{timestamp, value}` é adicionado no vetor daquela chave.

Exemplo:

```cpp
set("foo", "bar", 1);
```

Gera:

```cpp
"foo" -> {
  {1, "bar"}
}
```

Depois:

```cpp
set("foo", "bar2", 4);
```

Gera:

```cpp
"foo" -> {
  {1, "bar"},
  {4, "bar2"}
}
```

---

## Como o `get` funciona

A função `get` procura a chave dentro do `map`:

```cpp
auto it = myMap.find(key);
```

Se a chave existir, chamamos a busca binária:

```cpp
return binarySearch(it, timestamp);
```

Se a chave não existir, retornamos uma string vazia:

```cpp
return "";
```

Isso acontece porque não existe nenhum valor salvo para aquela chave.

---

## Como a busca binária é usada

A função `binarySearch` procura o valor mais recente cujo timestamp seja menor ou igual ao timestamp pedido.

A lógica central é:

```cpp
if (it->second[mid].first == timestamp)
    return it->second[mid].second;
```

Se encontrarmos exatamente o timestamp, podemos retornar o valor imediatamente.

Se o timestamp do meio for maior que o timestamp pedido, precisamos procurar mais à esquerda:

```cpp
end = mid - 1;
```

Se o timestamp do meio for menor que o timestamp pedido, precisamos procurar mais à direita:

```cpp
start = mid + 1;
```

Mas antes de continuar, salvamos esse valor como candidato, porque ele é válido:

```cpp
if (it->second[mid].first <= timestamp) {
    checked = it->second[mid].first;
    value = it->second[mid].second;
}
```

A ideia é:

> mesmo que não exista um timestamp exatamente igual ao pedido, queremos o valor mais próximo antes dele.

Exemplo:

```cpp
"foo" -> {
  {1, "bar"},
  {4, "bar2"}
}
```

Se chamarmos:

```cpp
get("foo", 3);
```

Não existe timestamp `3`.

Então a resposta correta é o valor do timestamp `1`:

```cpp
"bar"
```

---

## Ponto importante

A busca binária só funciona aqui porque, para cada chave, os timestamps ficam em ordem crescente dentro do vetor.

Isso permite tratar o vetor como uma lista ordenada:

```cpp
{1, "bar"}, {4, "bar2"}, {10, "bar3"}
```

Outro ponto importante é esta parte:

```cpp
string binarySearch(auto it, int timestamp)
```

O uso de `auto` como parâmetro de função comum depende da versão do C++.

Em alguns ambientes, especialmente se estiver usando C++17, pode ser necessário trocar por um tipo explícito ou criar uma função que receba diretamente o vetor:

```cpp
vector<pair<int, string>>& values
```

No LeetCode, a ideia principal está correta: usar busca binária dentro do histórico de cada chave.

---

## Complexidade

Para `set`:

* Acesso/inserção no `map`: `O(log k)`
* Inserção no `vector`: `O(1)` amortizado

Onde `k` é o número de chaves.

Então:

```cpp
set -> O(log k)
```

Para `get`:

* Busca da chave no `map`: `O(log k)`
* Busca binária no vetor de timestamps: `O(log n)`

Onde `n` é a quantidade de valores salvos para aquela chave.

Então:

```cpp
get -> O(log k + log n)
```

Espaço:

```cpp
O(total de valores armazenados)
```

Porque cada chamada de `set` adiciona um novo par `{timestamp, value}` na estrutura.

---

# English

## Main idea

The goal of **Time Based Key-Value Store** is to create a structure that stores values associated with a key and a timestamp.

The same key can receive different values at different times.

Example:

```cpp
set("foo", "bar", 1);
set("foo", "bar2", 4);
```

After that, if we call:

```cpp
get("foo", 4);
```

The answer should be:

```cpp
"bar2"
```

But if we call:

```cpp
get("foo", 3);
```

The answer should be:

```cpp
"bar"
```

Because at timestamp `3`, the most recent available value was still the value stored at timestamp `1`.

---

## Structure used

The main structure in the code is:

```cpp
map<string, vector<pair<int, string>>> myMap;
```

It can be understood like this:

```cpp
key -> list of {timestamp, value}
```

Visual example:

```cpp
"foo" -> {
  {1, "bar"},
  {4, "bar2"}
}
```

So:

* `map` stores each key.
* `vector` stores the history of that key.
* `pair<int, string>` stores the timestamp and the value.

```cpp
pair<int, string>
```

Here:

* `first` is the `timestamp`;
* `second` is the `value`.

---

## How `set` works

The `set` function stores a new value inside the key history:

```cpp
void set(string key, string value, int timestamp) {
    myMap[key].push_back({timestamp, value});
}
```

If the key does not exist yet, the `map` automatically creates an entry for it.

Then, the pair `{timestamp, value}` is added to the vector of that key.

Example:

```cpp
set("foo", "bar", 1);
```

Creates:

```cpp
"foo" -> {
  {1, "bar"}
}
```

Then:

```cpp
set("foo", "bar2", 4);
```

Creates:

```cpp
"foo" -> {
  {1, "bar"},
  {4, "bar2"}
}
```

---

## How `get` works

The `get` function searches for the key inside the `map`:

```cpp
auto it = myMap.find(key);
```

If the key exists, we call binary search:

```cpp
return binarySearch(it, timestamp);
```

If the key does not exist, we return an empty string:

```cpp
return "";
```

That happens because there is no value stored for that key.

---

## How binary search is used

The `binarySearch` function searches for the most recent value whose timestamp is less than or equal to the requested timestamp.

The core logic is:

```cpp
if (it->second[mid].first == timestamp)
    return it->second[mid].second;
```

If we find the exact timestamp, we can return the value immediately.

If the middle timestamp is greater than the requested timestamp, we need to search on the left side:

```cpp
end = mid - 1;
```

If the middle timestamp is smaller than the requested timestamp, we need to search on the right side:

```cpp
start = mid + 1;
```

But before continuing, we save that value as a candidate because it is valid:

```cpp
if (it->second[mid].first <= timestamp) {
    checked = it->second[mid].first;
    value = it->second[mid].second;
}
```

The idea is:

> even if there is no timestamp exactly equal to the requested one, we want the closest value before it.

Example:

```cpp
"foo" -> {
  {1, "bar"},
  {4, "bar2"}
}
```

If we call:

```cpp
get("foo", 3);
```

There is no timestamp `3`.

So the correct answer is the value from timestamp `1`:

```cpp
"bar"
```

---

## Important point

Binary search works here because, for each key, the timestamps are stored in increasing order inside the vector.

That allows us to treat the vector as a sorted list:

```cpp
{1, "bar"}, {4, "bar2"}, {10, "bar3"}
```

Another important point is this part:

```cpp
string binarySearch(auto it, int timestamp)
```

Using `auto` as a normal function parameter depends on the C++ version.

In some environments, especially with C++17, it may be necessary to replace it with an explicit type or create a helper function that receives the vector directly:

```cpp
vector<pair<int, string>>& values
```

On LeetCode, the main idea is correct: use binary search inside the history of each key.

---

## Complexity

For `set`:

* Access/insertion in the `map`: `O(log k)`
* Insertion into the `vector`: `O(1)` amortized

Where `k` is the number of keys.

So:

```cpp
set -> O(log k)
```

For `get`:

* Key lookup in the `map`: `O(log k)`
* Binary search in the timestamp vector: `O(log n)`

Where `n` is the number of values stored for that key.

So:

```cpp
get -> O(log k + log n)
```

Space:

```cpp
O(total stored values)
```

Because each `set` call adds a new `{timestamp, value}` pair to the structure.

