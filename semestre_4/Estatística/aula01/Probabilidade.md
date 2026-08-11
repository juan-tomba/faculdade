

## Conceitos Básicos

### Experimento (ou Fenômeno) Aleatório — $E$

Situação cujo resultado **não pode ser previsto com certeza**, mesmo sob condições idênticas.

> [!example] Exemplos
> 
> - $E_1$: Lançamento de um dado (ou moeda)
> - $E_2$: Tempo de vida útil de um componente eletrônico

Não sabemos qual resultado ocorrerá, mas podemos descrever **todos os resultados possíveis**.

### Espaço Amostral — $\Omega$

Conjunto de todos os resultados possíveis de um experimento aleatório: $$\Omega = {\omega_1, \omega_2, \dots, \omega_n, \dots}$$

> [!example] Exemplos
> 
> - $\Omega_1 = {1,2,3,4,5,6}$ (ou ${cara, coroa}$)
> - $\Omega_2 = [0, +\infty)$

### Evento

Qualquer **subconjunto** do espaço amostral $\Omega$.

- Notação: $A, B, C, \dots$
- Se $A \subset \Omega$, então $A$ é evento de $\Omega$.

#### Tipos de eventos

|Tipo|Definição|
|---|---|
|**Simples/elementar**|Um único ponto amostral: $A={\omega}$|
|**Composto**|Dois ou mais pontos: $A={\omega_1,\omega_2}$|
|**Certo**|Todos os pontos: $A=\Omega$|
|**Impossível**|Sem elementos: $A=\emptyset$|

> [!example] Exemplo — dado $D_6$
> 
> - $A_1$: "número maior que 3 e menor que 5"
> - $A_2$: "número par"
> - $A_3$: "número menor ou igual a 6" → evento **certo**
> - $A_4$: "número maior que 6" → evento **impossível**

---

## Operações com Eventos

(representadas com **diagramas de Venn**)

1. **União** ($A \cup B$): elementos de $A$, de $B$, ou de ambos.
2. **Interseção** ($A \cap B$): elementos comuns a $A$ e $B$.
    - Caso particular: se $B \subset A \Rightarrow A \cap B = B$
    - Se $A$ e $B$ são **disjuntos/mutuamente exclusivos** $\Rightarrow A \cap B = \emptyset$
3. **Diferença** ($A - B$): elementos de $A$ que não estão em $B$.
4. **Complementar** ($A^c$ ou $\bar A$): elementos de $\Omega$ que não estão em $A$.

### Leis de De Morgan

$$(A \cup B)^c = A^c \cap B^c$$ $$(A \cap B)^c = A^c \cup B^c$$

### Outras identidades úteis

$$A \cup B^c = (A \cap B) \cup B^c = A \cup (A \cup B)^c$$ $$A \cap B^c = (A \cup B) \cap B^c$$

### Outras operações

1. $A \cap \emptyset = \emptyset,\ \forall A$
2. $A \cup \emptyset = A$
3. $\emptyset^c = \Omega$
4. $\Omega^c = \emptyset$
5. $(A^c)^c = A$
6. $B = (A \cap B) \cup (A^c \cap B)$
7. $A = (A \cap B) \cup (A \cap B^c)$

> [!question] Exercício 1.1 Considere $A, B$ possíveis e não certos em $\Omega$. Usando De Morgan, qual outra representação para $A \cup (B \cap \bar A)$? (dica: $C = A \cup B$) **Resposta:** $A \cup B$

---

## Definições de Probabilidade

### 1. Espaços equiprováveis (definição clássica)

Se $\Omega={\omega_1,\dots,\omega_n}$ tem resultados **mutuamente exclusivos e igualmente possíveis**, e $A$ possui $n_A$ desses resultados: $$P(A) = \frac{n_A}{n}$$

> [!example] Exemplo 1.2 — duas moedas honestas a) P(duas faces iguais) b) P(pelo menos uma face ≠ cara)

### 2. Definição frequentista

Experimento repetido $n$ vezes ($n$ grande); $A$ ocorre $n_A$ vezes: $$fr(A) = \frac{n_A}{n}$$ Quando $n \to \infty$, $fr(A) \to P(A)$.

```python
import numpy as np
n = 100
lancamentos = np.random.randint(0, 2, size=n)  # 0=coroa, 1=cara
num_caras = np.sum(lancamentos)
freq_relativa = num_caras / n
```

### 3. Definição axiomática (Kolmogorov)

$P(A)$ satisfaz:

- (i) $P(A) \ge 0$
- (ii) $P(\Omega) = 1$
- (iii) Se $A_1, A_2, \dots$ são mutuamente exclusivos: $$P\left(\bigcup_{i=1}^{\infty} A_i\right) = \sum_{i=1}^{\infty} P(A_i)$$

---

## Propriedades da Probabilidade

-  a) $0 \le P(A) \le 1$ 
-  b) $P(\emptyset) = 0$ 
-  c) Se $A \subset \Omega$: $P(A) = 1 - P(A^c)$ 
-  d) Se $A \subset B \subset \Omega$: $P(A) \le P(B)$ 
-  e) $P(B) = P(B \cap A) + P(B \cap A^c)$ 
-  f) $P(A \cup B) = P(A) + P(B) - P(A \cap B)$ 
-  g) $P(A \cup B \cup C) = P(A)+P(B)+P(C) - P(A\cap B) - P(A\cap C) - P(B\cap C) + P(A\cap B\cap C)$

> [!question] Exercício 1.3 $P(A)=\frac12,\ P(B)=\frac13,\ P(A\cap B)=\frac14$. Calcular: a) $P(A^c \cap B^c)$ → **5/12** b) $P(A^c \cup B^c)$ → **3/4**