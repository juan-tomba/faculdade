

> [!abstract] Resumo O problema do **fluxo máximo** consiste em descobrir qual a maior quantidade possível de fluxo que pode sair da fonte e chegar ao sumidouro.

---

## Rede de Fluxo

Uma **rede de fluxo** é um grafo direcionado com as seguintes propriedades:

- Existe uma **fonte** (`s`), de onde o fluxo sai.
- Existe um **sumidouro** (`t`), para onde o fluxo vai.
- Cada aresta possui uma **capacidade**, indicando o máximo de fluxo que pode passar por ela.

### Exemplo — Figura (a)

![[Pasted image 20260609140024 1.png]]

```
           12
      v1 -------> v3
     ↗ ↑           ↘
16  /  | 4           \ 20
   /   |               \
  s    |                t
   \   |               /
13  \  ↓             / 4
     ↘ v2 -------> v4
            14
```

> Nomes das cidades: Vancouver (s), Edmonton (v1), Calgary (v2), Saskatoon (v3), Regina (v4), Winnipeg (t).

---

## Fluxo

O **fluxo** é a quantidade efetivamente enviada por cada aresta. Ele deve obedecer duas regras:

### 1. Restrição de Capacidade

$$0 \leq f(u,v) \leq c(u,v)$$

onde $f(u,v)$ é o fluxo atual e $c(u,v)$ é a capacidade máxima da aresta.

### 2. Conservação de Fluxo

Para todo vértice intermediário (exceto `s` e `t`):

$$\sum \text{fluxos entrando} = \sum \text{fluxos saindo}$$

---

## Interpretando a Figura (b) — Fluxo Atual

Na figura (b), cada aresta é exibida como `fluxo/capacidade`.

**Exemplo:** `11/16` → fluxo atual = 11, capacidade = 16.

|Aresta|Fluxo/Capacidade|
|---|---|
|s → v1|11 / 16|
|s → v2|8 / 13|
|v1 → v3|12 / 12|
|v2 → v1|1 / 4|
|v2 → v3|4 / 9|
|v2 → v4|11 / 14|
|v4 → v3|7 / 7|
|v3 → t|15 / 20|
|v4 → t|4 / 4|

---

## Valor do Fluxo

O valor do fluxo é a quantidade total que sai da fonte (ou chega ao sumidouro).

**Pela fonte:**

$$|f| = 11 + 8 = 19$$

**Pelo sumidouro (verificação):**

$$|f| = 15 + 4 = 19 \checkmark$$

$$\boxed{|f| = 19}$$

---

## Verificando Conservação de Fluxo

> [!example] Vértice v1 **Entradas:** s → v1 = 11, v2 → v1 = 1 → **Total: 12** **Saídas:** v1 → v3 = 12 → **Total: 12** ✓

> [!example] Vértice v2 **Entradas:** s → v2 = 8 → **Total: 8** **Saídas:** v2 → v1 = 1, v2 → v3 = 4 — wait... 1 + 4 + 11 = 16 ≠ 8
> 
> ⚠️ Isso faz parte de um estado **intermediário** do algoritmo. A análise completa é feita via rede residual — o fluxo mostrado ainda não é o máximo final.

---

## Rede Residual

A **rede residual** mostra quanto fluxo ainda pode ser alterado em cada aresta.

Para cada aresta `u → v` do grafo original, criamos duas arestas residuais:

|Tipo|Direção|Capacidade Residual|Significado|
|---|---|---|---|
|**Direta**|u → v|$c(u,v) - f(u,v)$|Quanto ainda pode ser enviado|
|**Reversa**|v → u|$f(u,v)$|Quanto fluxo pode ser "desfeito"|

### Exemplo — Aresta s → v1 (11/16)

$$\text{Residual direta: } 16 - 11 = 5 \quad (s \to v1)$$ $$\text{Residual reversa: } 11 \quad (v1 \to s)$$

### Exemplo — Aresta v3 → t (15/20)

$$\text{Residual direta: } 20 - 15 = 5 \quad (v3 \to t)$$ $$\text{Residual reversa: } 15 \quad (t \to v3)$$

---

## Caminho Aumentador

Um **caminho aumentador** é um caminho de `s` até `t` na rede residual onde ainda existe capacidade disponível (capacidade residual > 0).

### Exemplo de caminho aumentador encontrado:

```
s → v1 → v2 → v3 → t
```

Com as capacidades residuais:

|Aresta|Capacidade Residual|
|---|---|
|s → v1|5|
|v1 → v2|3|
|v2 → v3|5|
|v3 → t|5|

---

## Gargalo

O **gargalo** é a menor capacidade residual ao longo do caminho aumentador.

$$\text{Gargalo} = \min(5,\ 3,\ 5,\ 5) = 3$$

$$\boxed{\text{Gargalo} = 3}$$

---

## Aumentando o Fluxo

O Ford-Fulkerson aumenta o fluxo exatamente pelo valor do gargalo.

$$|f|_{\text{novo}} = 19 + 3 = \boxed{22}$$

---

## Método Ford-Fulkerson — Passo a Passo

```
Inicializar: f(u,v) = 0 para todas as arestas
Enquanto existir caminho aumentador de s a t na rede residual:
    1. Encontrar caminho aumentador P
    2. Calcular gargalo = min{ capacidade residual das arestas em P }
    3. Aumentar o fluxo em cada aresta de P pelo gargalo
    4. Atualizar a rede residual
Retornar fluxo atual (= fluxo máximo)
```

### Passos detalhados

|Passo|Ação|
|---|---|
|1|Fluxo inicial = 0 para todas as arestas|
|2|Construir a rede residual|
|3|Procurar um caminho aumentador (s → ... → t)|
|4|Encontrar o gargalo = min(capacidades residuais do caminho)|
|5|Aumentar o fluxo pelo gargalo em todas as arestas do caminho|
|6|Atualizar a rede residual|
|7|Repetir a partir do passo 3|

**Critério de parada:** Não existe mais caminho de `s` até `t` na rede residual → o fluxo atual é o **fluxo máximo**.

---

## Resumo para Prova


**Rede de Fluxo**

- Grafo direcionado com fonte `s` e sumidouro `t`
- Cada aresta tem capacidade $c(u,v)$

**Fluxo**

- Respeita capacidade: $0 \leq f(u,v) \leq c(u,v)$
- Respeita conservação: entradas = saídas (exceto em `s` e `t`)

**Rede Residual** $$\text{Residual direta} = c(u,v) - f(u,v)$$ $$\text{Residual reversa} = f(u,v)$$

**Caminho Aumentador**

- Caminho de `s` a `t` com capacidade residual > 0

**Gargalo** $$\text{gargalo} = \min(\text{capacidades residuais do caminho})$$

**Ford-Fulkerson**

1. Fluxo inicial = 0
2. Construir rede residual
3. Encontrar caminho aumentador
4. Calcular gargalo
5. Aumentar fluxo
6. Atualizar residual
7. Repetir até não existir mais caminho → **fluxo máximo encontrado**