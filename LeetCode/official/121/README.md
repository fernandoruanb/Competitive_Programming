<p align="center">
  <img src="https://assets.leetcode.com/static_assets/public/images/LeetCode_Sharing.png" width="100%" alt="LeetCode Cover"/>
</p>

<h1 align="center">LeetCode 121 — Best Time to Buy and Sell Stock</h1>

<p align="center">
  <strong>Minimum Price Tracking + Maximum Profit</strong>
</p>

---

## Navigation

- [Português](#português)
  - [Ideia principal](#ideia-principal)
  - [Estratégia usada](#estratégia-usada)
  - [Como o `buy` funciona](#como-o-buy-funciona)
  - [Como o lucro é calculado](#como-o-lucro-é-calculado)
  - [Ponto importante](#ponto-importante)
  - [Complexidade](#complexidade)
- [English](#english)
  - [Main idea](#main-idea)
  - [Strategy used](#strategy-used)
  - [How `buy` works](#how-buy-works)
  - [How profit is calculated](#how-profit-is-calculated)
  - [Important point](#important-point)
  - [Complexity](#complexity)

---

# Português

## Ideia principal

O objetivo do exercício **Best Time to Buy and Sell Stock** é descobrir o maior lucro possível comprando uma ação em um dia e vendendo em outro dia depois da compra.

Ou seja, primeiro precisamos comprar, depois vender.

Exemplo:

```cpp
prices = {7, 1, 5, 3, 6, 4}
````

A melhor escolha seria:

```cpp
comprar em 1
vender em 6
```

Lucro:

```cpp
6 - 1 = 5
```

Então a resposta é:

```cpp
5
```

---

## Estratégia usada

A solução percorre o array apenas uma vez.

Durante a navegação, guardamos duas informações:

```cpp
int buy = 2147483647;
int profit = 0;
```

* `buy` guarda o menor preço encontrado até agora.
* `profit` guarda o maior lucro encontrado até agora.

A grande ideia é:

> para cada preço atual, perguntar: se eu vendesse hoje usando o menor preço anterior como compra, qual seria meu lucro?

---

## Como o `buy` funciona

A variável `buy` começa com um valor muito alto:

```cpp
int buy = 2147483647;
```

Esse valor representa o maior valor possível para um `int`.

Assim, qualquer preço real dentro do array será menor que ele no começo.

Durante o loop:

```cpp
for (int n: prices)
```

Se encontramos um preço menor que o preço de compra atual, atualizamos `buy`:

```cpp
if (buy > n) {
    buy = n;
    continue;
}
```

Isso significa:

> encontrei um preço melhor para comprar.

O `continue` faz sentido porque, se acabamos de atualizar o menor preço de compra, não precisamos calcular lucro nesse mesmo passo.

---

## Como o lucro é calculado

Quando o preço atual não é menor que `buy`, podemos testar uma possível venda.

```cpp
int profitCalc = n - buy;
```

Aqui:

* `n` é o preço atual;
* `buy` é o menor preço visto antes ou até agora;
* `profitCalc` é o lucro se vendermos no preço atual.

Depois, verificamos se esse lucro é maior que o melhor lucro já salvo:

```cpp
if (profitCalc > profit)
    profit = profitCalc;
```

Se for maior, atualizamos `profit`.

No final, retornamos:

```cpp
return profit;
```

---

## Ponto importante

Essa solução não tenta testar todos os pares possíveis de compra e venda.

Uma solução brute force poderia comparar cada dia com todos os dias seguintes, gerando:

```cpp
O(n²)
```

Mas aqui a estratégia é mais inteligente.

Nós carregamos o menor preço visto até o momento e calculamos o lucro possível em cada posição.

Isso transforma o problema em uma varredura linear:

```cpp
O(n)
```

Também é importante perceber que a venda sempre acontece depois da compra, porque o código percorre os preços da esquerda para a direita.

Então `buy` sempre representa um preço encontrado antes ou no dia atual.

---

## Complexidade

A solução percorre o array uma única vez.

* Tempo: `O(n)`
* Espaço: `O(1)`

O espaço é constante porque usamos apenas algumas variáveis simples:

```cpp
int buy;
int profit;
int profitCalc;
```

---

# English

## Main idea

The goal of **Best Time to Buy and Sell Stock** is to find the maximum possible profit by buying a stock on one day and selling it on a later day.

So, first we need to buy, then we need to sell.

Example:

```cpp
prices = {7, 1, 5, 3, 6, 4}
```

The best choice would be:

```cpp
buy at 1
sell at 6
```

Profit:

```cpp
6 - 1 = 5
```

So the answer is:

```cpp
5
```

---

## Strategy used

This solution scans the array only once.

While traversing the prices, we keep two pieces of information:

```cpp
int buy = 2147483647;
int profit = 0;
```

* `buy` stores the lowest price found so far.
* `profit` stores the best profit found so far.

The main idea is:

> for each current price, ask: if I sold today using the lowest previous price as the buy price, what would my profit be?

---

## How `buy` works

The variable `buy` starts with a very high value:

```cpp
int buy = 2147483647;
```

This value represents the maximum value of a common `int`.

Because of that, any real price inside the array will be smaller than it at the beginning.

During the loop:

```cpp
for (int n: prices)
```

If we find a price smaller than the current buying price, we update `buy`:

```cpp
if (buy > n) {
    buy = n;
    continue;
}
```

This means:

> I found a better price to buy.

The `continue` makes sense because, if we just updated the lowest buying price, we do not need to calculate profit in that same step.

---

## How profit is calculated

When the current price is not smaller than `buy`, we can test a possible sale.

```cpp
int profitCalc = n - buy;
```

Here:

* `n` is the current price;
* `buy` is the lowest price seen before or so far;
* `profitCalc` is the profit if we sell at the current price.

Then, we check whether this profit is greater than the best profit already saved:

```cpp
if (profitCalc > profit)
    profit = profitCalc;
```

If it is greater, we update `profit`.

At the end, we return:

```cpp
return profit;
```

---

## Important point

This solution does not try every possible buy and sell pair.

A brute force solution could compare each day with every following day, resulting in:

```cpp
O(n²)
```

But here the strategy is smarter.

We carry the lowest price seen so far and calculate the possible profit at each position.

This turns the problem into a linear scan:

```cpp
O(n)
```

It is also important to notice that the sale always happens after the purchase, because the code scans prices from left to right.

So `buy` always represents a price found before or on the current day.

---

## Complexity

This solution traverses the array only once.

* Time: `O(n)`
* Space: `O(1)`

The space is constant because we only use a few simple variables:

```cpp
int buy;
int profit;
int profitCalc;
```
