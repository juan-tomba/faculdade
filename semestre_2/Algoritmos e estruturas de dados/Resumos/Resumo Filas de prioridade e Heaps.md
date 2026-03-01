# Algoritmos e Estruturas de Dados: Filas de Prioridade e Heaps

## 1. Conceito de Fila de Prioridade
Diferente de pilhas e filas comuns (onde o processamento depende da ordem de chegada), nas **Filas de Prioridade**, os elementos são processados de acordo com sua **importância**.

* **Exemplos de uso:**
    * Atendimento preferencial.
    * Processos em sistemas operacionais.
    * Substituição de páginas de memória.

### TAD Fila de Prioridade
Um item é composto por um par `(chave, informação)`.
* **Operações Principais:**
    * `enfileirar(F, x)`: Insere um item com uma chave.
    * `desenfileirar(F)`: Remove e retorna o item de maior (ou menor) prioridade.
    * `próximo(F)`: Retorna o item de maior prioridade sem remover.

---

## 2. Implementações e Comparação
É possível implementar filas de prioridade usando listas ou vetores, mas a eficiência varia:

| Estrutura | Inserção | Remoção | Próximo |
| :--- | :---: | :---: | :---: |
| **Lista Ordenada** | $O(n)$ | $O(1)$ | $O(1)$ |
| **Lista Não Ordenada** | $O(1)$ | $O(n)$ | $O(n)$ |
| **Heap** | $O(\log n)$ | $O(\log n)$ | $O(1)$ |

> Para grandes conjuntos de dados, a abordagem via **Heap** é a mais equilibrada e eficiente.

---

## 3. Heaps
Uma Heap é uma árvore binária que satisfaz duas propriedades fundamentais:

1.  **Propriedade de Ordem:**
    * **Heap Máxima:** Para todo nó $v$ (exceto a raiz), $chave(v) \le chave(pai(v))$.
    * **Heap Mínima:** Para todo nó $v$, $chave(v) \ge chave(pai(v))$.
2.  **Propriedade de Completude:**
    * A árvore é completa até o nível $h-1$.
    * No último nível $h$, as folhas estão preenchidas da esquerda para a direita.

### Altura da Heap
Uma heap com $n$ nós possui altura $h$ de ordem $O(\log n)$.
* A prova baseia-se na soma da Progressão Geométrica do número de nós: $n \ge 2^h$ implica $h \le \log_2 n$.

---

## 4. Implementação em Arranjo (Vetor)
Heaps podem ser eficientemente representadas em vetores devido à sua completude (não há "buracos" no vetor).
* A varredura é feita nível por nível, da esquerda para a direita.
* **Mapeamento de Índices:** Dado um nó no índice $i$:
    * **Filho Esquerdo:** $2 \times i + 1$.
    * **Filho Direito:** $2 \times i + 2$.
    * **Pai:** $\lfloor (i - 1) / 2 \rfloor$.

---

## 5. Operações em Heaps

### Inserção (`fix-up`)
A inserção de um novo item pode violar a propriedade de ordem. O algoritmo segue 3 passos:
1.  Encontrar a posição de inserção (final do vetor/árvore).
2.  Armazenar o item na posição.
3.  **Restaurar a ordem (Subida/Up-heap):**
    * Enquanto o item for maior que o pai (em Max-Heap), troca-se o item com o pai.
    * O processo para quando chegar à raiz ou o pai for maior.

### Remoção (`fix-down`)
A remoção ocorre sempre na **raiz** (maior ou menor prioridade).
1.  Armazena-se o conteúdo da raiz para retorno.
2.  Copia-se o conteúdo do **último nó** para a raiz e remove-se o último nó.
    * Isso garante a manutenção da propriedade de completude.
3.  **Restaurar a ordem (Descida/Down-heap):**
    * Troca-se a raiz com o filho de maior prioridade (maior chave em Max-Heap).
    * Repete-se até que o nó seja maior que seus filhos ou se torne uma folha.

---

## 6. Aplicações
As Heaps são estruturas de apoio fundamentais para algoritmos clássicos:
* **Ordenação:** Heapsort.
* **Grafos:**
    * Algoritmo de Dijkstra (caminho mínimo).
    * Algoritmo de Prim (Árvore Geradora Mínima).