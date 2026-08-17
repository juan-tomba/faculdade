

## Probabilidade Condicional

### Definição

Sejam $A, B \subset \Omega$. A probabilidade condicional de $A$ dado $B$: $$P(A|B) = \frac{P(A \cap B)}{P(B)}, \quad P(B) > 0$$

**Regra do produto:** $$P(A \cap B) = P(A|B),P(B)$$

> [!example] Exemplo 1.4 — computadores em escritório
> 
> ||Desktop (D)|Laptop (L)|Total|
> |---|---|---|---|
> |Novo (N)|40|30|70|
> |Usado (U)|20|10|30|
> |Total|60|40|100|
> 
> Escolhido um laptop ao acaso, qual a P(ser novo)?

### Árvore de Probabilidades

Representação útil para eventos condicionais:

- Ramo $B$: $P(A|B)$ e $P(A^c|B)$
- Ramo $B^c$: $P(A|B^c)$ e $P(A^c|B^c)$

> [!example] Exemplo 1.5 Usando a árvore de probabilidades do Exemplo 1.4, calcular P(desktop usado).

### Propriedades da probabilidade condicional

a) $P(\emptyset|B) = 0$ b) Se $A \subset \Omega$: $P(A|B) = 1 - P(A^c|B)$ c) $P(A \cup C|B) = P(A|B) + P(C|B) - P(A \cap C|B)$

---

##  Independência de Eventos

### Definição

$A$ e $B$ são **independentes** se a ocorrência de $B$ não altera a probabilidade de $A$: $$P(A|B) = P(A), \quad P(B)>0$$

Equivalentemente: $$P(A \cap B) = P(A),P(B)$$

> [!example] Exemplo 1.6 — recuperação de dados
> 
> - Algoritmo A recupera com prob. 30%
> - Algoritmo B recupera com prob. 50%
> - Resultados independentes → P(pelo menos um recuperar)?

### Independência de 3 eventos

$A, B, C$ são independentes ⟺: a) $P(A \cap B) = P(A)P(B)$ b) $P(A \cap C) = P(A)P(C)$ c) $P(B \cap C) = P(B)P(C)$ d) $P(A \cap B \cap C) = P(A)P(B)P(C)$

### Resultado importante

Se $A$ e $B$ são independentes, então também são independentes: (i) $A$ e $B^c$ (ii) $A^c$ e $B$ (iii) $A^c$ e $B^c$

> [!warning] Cuidado — não confundir!
> 
> - **Mutuamente exclusivos:** $P(A \cap B) = 0$
> - **Independentes:** $P(A \cap B) = P(A)P(B)$
> 
> São conceitos diferentes!

**Demonstração de (i):** como $A = (A\cap B^c)\cup(A\cap B)$ (união disjunta): $$P(A\cap B^c) = P(A) - P(A\cap B) = P(A) - P(A)P(B) = P(A)(1-P(B)) = P(A)P(B^c)$$

> [!example] Exemplo 1.7 — detecção de ataques
> 
> - Sistema A detecta 80% dos ataques
> - Sistema B detecta 70% dos ataques
> - Independentes → P(pelo menos um detectar)?

---

##  Teorema de Bayes

### Partição do espaço amostral

$A_1, A_2, \dots, A_k$ formam uma **partição** de $\Omega$ se: (i) $A_i \cap A_j = \emptyset,\ \forall i \ne j$ (disjuntos dois a dois) (ii) $\bigcup_{i=1}^{k} A_i = \Omega$ (cobrem todo o espaço)

### Lema da Probabilidade Total

Se $A_1,\dots,A_k$ particionam $\Omega$, então para qualquer evento $B$: $$P(B) = \sum_{i=1}^{k} P(B\cap A_i) = \sum_{i=1}^{k} P(B|A_i)P(A_i)$$

### Fórmula de Bayes

$$P(A_i|B) = \frac{P(A_i \cap B)}{P(B)} = \frac{P(B|A_i)P(A_i)}{\sum_{j=1}^{k} P(B|A_j)P(A_j)}$$

> [!example] Exemplo 1.8 — diagnóstico de falhas
> 
> - Servidor A: recebe 30% das requisições, falha em 10% delas
> - Servidor B: recebe 70% das requisições, falha em 5% delas
> 
> Calcular:
> 
> 1. P(requisição apresentar falha)
> 2. P(processada por A | apresentou falha)

> [!question] Exercício proposto 1.4 — filtro de spam
> 
> - 40% das mensagens são spam
> - Filtro identifica 100% dos spams corretamente
> - Classifica erroneamente como spam 5% das mensagens legítimas
> 
> Se uma mensagem foi classificada como spam, qual a P(ser realmente spam)? **Resposta:** 0,9302 (≈ 93,02%)

> [!question] Exercício proposto 1.5 — qualidade de código
> 
> - 25% bons (B), 50% médios (M), 25% fracos (F)
> - $P(A|B)=0{,}8$, $P(A|M)=0{,}5$, $P(A|F)=0{,}2$ (A = aprovado)
> 
> Se o módulo foi aprovado, qual a P(ser fraco)? **Resposta:** 0,1 (10%)
