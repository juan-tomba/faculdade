# Árvores Binárias de Busca (ABB)

**Tags:** #algoritmos #estruturas-de-dados #arvores #resumo #cs

---

## 1. Definição e Propriedades
Uma **Árvore Binária de Busca (ABB)** é uma estrutura de dados dinâmica onde cada nó possui uma chave distinta e obedece às seguintes regras recursivas:

1.  **Sub-árvore Esquerda:** Todos os nós na sub-árvore esquerda de um nó pai possuem valores **menores** que o pai.
2.  **Sub-árvore Direita:** Todos os nós na sub-árvore direita de um nó pai possuem valores **maiores** que o pai.

> [!NOTE] Propriedade de Ordem
> Um percurso **em-ordem** (in-order) — visitar esquerda, visitar raiz, visitar direita — em uma ABB resulta na sequência de chaves ordenadas de forma **crescente**.

---

## 2. Por que usar ABB?
A grande utilidade da ABB é combinar as vantagens de acesso dinâmico das listas encadeadas com a velocidade de busca dos vetores ordenados.

| Estrutura de Dados | Busca | Inserção/Remoção | Problema Principal |
| :--- | :--- | :--- | :--- |
| **Vetor (Array)** | $O(\log n)$ (Binária) | $O(n)$ | Inserção lenta (necessita deslocar elementos). |
| **Lista Encadeada** | $O(n)$ | $O(1)$ (após achar) | Busca lenta (acesso sequencial). |
| **ABB Balanceada** | **$O(\log n)$** | **$O(\log n)$** | Combina o melhor dos dois mundos. |

---

## 3. Operações Fundamentais

### A. Busca
A busca define a eficiência da árvore. O algoritmo compara a chave buscada com a raiz atual:
* Se a chave for **igual**: Item encontrado.
* Se a chave for **menor**: Continua a busca na sub-árvore **esquerda**.
* Se a chave for **maior**: Continua a busca na sub-árvore **direita**.
* Se o ponteiro for nulo: Item não existe.

### B. Inserção
A inserção sempre ocorre nas folhas (ou onde um ponteiro é `NULL`).
1.  Realiza-se uma busca para encontrar onde a chave deveria estar.
2.  Ao atingir um local vazio (`NULL`), cria-se o novo nó e conecta-o ali.
    * *Nota:* A forma final da árvore depende da ordem de inserção. Inserir dados já ordenados (1, 2, 3...) cria uma árvore "degenerada" (parecida com uma lista), o que é ruim para a performance.

### C. Remoção
É a operação mais complexa, pois a remoção não pode quebrar a regra de ordenação da árvore. Existem 3 cenários:

1.  **Nó Folha (sem filhos):** Basta remover o nó e zerar o ponteiro do pai.
2.  **Nó com 1 filho:** O pai do nó removido passa a apontar diretamente para o único filho do nó removido (o filho "sobe" de nível).
3.  **Nó com 2 filhos:** Não é possível remover diretamente. Estratégia:
    * Encontra-se o nó com o **maior valor da sub-árvore esquerda** (ou o menor da direita).
    * Troca-se o valor do nó a ser removido com esse valor encontrado.
    * Remove-se o nó original (que agora está em uma posição de folha ou com 1 filho) recursivamente.

---

## 4. Análise de Complexidade

O custo de todas as operações (busca, inserção, remoção) é proporcional à **altura** da árvore ($h$).

* **Pior Caso (Árvore Degenerada):**
    * Ocorre quando inserimos dados ordenados.
    * Altura $\approx n$.
    * Complexidade: **$O(n)$** (tão lento quanto uma lista).
* **Caso Médio / Balanceado:**
    * Ocorre com inserções aleatórias ou balanceamento forçado.
    * Altura $\approx \log_2 n$.
    * Complexidade: **$O(\log n)$**.

> [!INFO] Estatística
> Em uma ABB gerada aleatoriamente, o número esperado de comparações é cerca de **1.39** vezes o logaritmo de $n$.

---

## 5. Balanceamento (Reconstrução)

Para evitar o pior caso ($O(n)$), pode-se reconstruir a árvore para que fique "perfeitamente balanceada" (altura mínima possível).

**Algoritmo de Balanceamento:**
1.  Percorrer a árvore atual em **em-ordem** para extrair os dados já ordenados em um vetor.
2.  Usar uma função recursiva de divisão e conquista:
    * Pegar o elemento do **meio** do vetor e inseri-lo como Raiz.
    * Chamar a função para a metade esquerda do vetor (vira sub-árvore esquerda).
    * Chamar a função para a metade direita do vetor (vira sub-árvore direita).