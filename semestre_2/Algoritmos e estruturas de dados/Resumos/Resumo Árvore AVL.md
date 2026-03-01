# Árvores AVL (Adelson-Velsky e Landis)

**Tags:** #algoritmos #estruturas-de-dados #arvores #avl #resumo #cs

---

## 1. Definição e Conceito
A **Árvore AVL** (proposta em 1962) é uma Árvore Binária de Busca (ABB) **auto-balanceada**. O objetivo principal é evitar a degeneração da árvore (onde ela se torna uma lista encadeada), garantindo a eficiência das operações.

### Propriedade Fundamental
Para todo nó da árvore, a diferença de altura entre a sub-árvore esquerda e a sub-árvore direita não pode ser maior que **1**.

> [!NOTE] Altura
> A altura de um nó é a maior distância até uma folha (profundidade).

---

## 2. Fator de Balanceamento (FB)
Para controlar o equilíbrio, calcula-se o Fator de Balanceamento para cada nó:

$$FB = \text{Altura}(\text{Esq}) - \text{Altura}(\text{Dir})$$

* **Nó Balanceado:** $FB \in \{-1, 0, 1\}$
* **Nó Desbalanceado:** $FB \le -2$ ou $FB \ge 2$

Se um nó atinge um FB de 2 ou -2, é necessário aplicar uma **rotação** para rebalancear a árvore.

---

## 3. Rotações (Rebalanceamento)
As rotações são operações locais que alteram a estrutura da árvore preservando a ordem da ABB (em-ordem). Existem 4 tipos, dependendo de onde ocorreu a inserção/desbalanceamento.

### A. Rotações Simples
Usadas quando o desbalanceamento é linear (os sinais dos FBs do pai e do filho são **iguais**).

1.  **Rotação Direita (Simples):**
    * **Cenário:** O nó está "pesado para a esquerda" ($FB = +2$) e seu filho esquerdo também ($FB \ge 0$).
    * **Ação:** O filho esquerdo sobe e se torna o pai do nó desbalanceado.
2.  **Rotação Esquerda (Simples):**
    * **Cenário:** O nó está "pesado para a direita" ($FB = -2$) e seu filho direito também ($FB \le 0$).
    * **Ação:** O filho direito sobe e se torna o pai do nó desbalanceado.

### B. Rotações Duplas
Usadas quando há um "joelho" ou zigue-zague (os sinais dos FBs do pai e do filho são **diferentes**).

1.  **Rotação Dupla Esquerda-Direita:**
    * **Cenário:** Pai positivo ($+2$, esquerda), Filho negativo (direita).
    * **Ação:** Rotação **Esquerda** no filho, depois Rotação **Direita** no pai.
2.  **Rotação Dupla Direita-Esquerda:**
    * **Cenário:** Pai negativo ($-2$, direita), Filho positivo (esquerda).
    * **Ação:** Rotação **Direita** no filho, depois Rotação **Esquerda** no pai.

---

## 4. Regra Prática: Qual Rotação Usar?

Ao identificar o nó desbalanceado ($A$), verifique o sinal do seu filho ($B$) no lado mais pesado.

| FB do Pai ($A$) | FB do Filho ($B$) | Sinais | Tipo de Rotação |
| :---: | :---: | :---: | :--- |
| $+2$ | $+1$ ou $0$ | **Iguais** | **Simples Direita** |
| $-2$ | $-1$ ou $0$ | **Iguais** | **Simples Esquerda** |
| $+2$ | $-1$ | **Diferentes** | **Dupla Esquerda-Direita** |
| $-2$ | $+1$ | **Diferentes** | **Dupla Direita-Esquerda** |

> [!TIP] Macete
> * **Sinais Iguais (+/+ ou -/-):** Rotação Simples.
> * **Sinais Diferentes (+/- ou -/+):** Rotação Dupla.

---

## 5. Algoritmos de Operação

### Inserção
1.  Insere-se o nó normalmente como em uma ABB (descendo a árvore recursivamente).
2.  Na volta da recursão (subindo a árvore):
    * Atualiza-se a altura do nó atual.
    * Calcula-se o $FB$.
    * Se $|FB| == 2$, aplica-se a rotação adequada baseada na regra prática acima.

### Remoção
1.  Remove-se o nó (seguindo as regras de ABB: folha, 1 filho, ou 2 filhos).
2.  Assim como na inserção, na volta da recursão, verifica-se o $FB$ de cada nó ancestral.
3.  Aplica-se rotações se necessário.
    * *Nota:* Diferente da inserção (que resolve com 1 rotação), a remoção pode exigir rotações em cascata até a raiz.

---

## 6. Complexidade e Desempenho

A grande vantagem da AVL é garantir que a altura da árvore ($h$) seja sempre logarítmica em relação ao número de nós ($n$).

* **Altura Máxima:** $\approx 1.44 \log_2 n$
* **Busca:** $O(\log n)$
* **Inserção:** $O(\log n)$ (custo de busca + custo constante de rebalanceamento).
* **Remoção:** $O(\log n)$.

> [!INFO] Estatística
> Na prática, para $n$ grande, o tempo de busca é próximo de $\log_2 n + 0.25$. Rotações são necessárias em aproximadamente 46,5% das inserções.

---