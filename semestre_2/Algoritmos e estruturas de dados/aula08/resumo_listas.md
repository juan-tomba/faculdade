# Resumo: Listas Lineares Sequenciais

## Conceito

-   Lista Linear = sequência de elementos do mesmo tipo.
-   Propriedade estrutural: relação entre posições (ordem importa).
-   Representada como x1, x2, ..., xn.

## Operações principais

-   **Inserção** (em posição específica ou no fim).
-   **Remoção** (do fim, início ou meio).
-   **Busca** (por chave).
-   Alterar elementos, concatenar listas, ordenar.

## Aplicações

-   Cadastro de funcionários, estoque, notas de alunos, lista de
    tarefas.
-   Gerenciamento de memória.
-   Compiladores e simulações.

## Casos particulares

-   **Deque**: inserção/remoção apenas nas extremidades.
-   **Pilha**: inserção/remoção em um extremo (LIFO).
-   **Fila**: inserção em um extremo e remoção no outro (FIFO).

## Organização em memória

1.  **Sequencial** (array): elementos em endereços consecutivos.
2.  **Encadeada** (ponteiros): elementos ligados por referências.

## Ordenação

-   **Ordenada**: mantém elementos em ordem (facilita busca, dificulta
    inserção/remoção).
-   **Não ordenada**: inserção mais barata, busca sequencial.

## TAD Lista -- operações básicas

-   Criar lista.
-   Inserir item.
-   Remover item.
-   Recuperar item (buscar por chave).
-   Contar elementos.
-   Verificar se está vazia ou cheia.
-   Imprimir lista.

## Implementações

-   **Sequencial (array fixo)**:
    -   Simples, acesso rápido O(1).
    -   Inserção/remoção podem requerer deslocamentos (O(n)).
-   **Lista ordenada**:
    -   Busca mais eficiente (sequencial otimizada ou binária O(log n)).
    -   Inserção/remoção exigem manter ordenação (O(n)).

## Busca em listas

-   **Sequencial**: verifica cada elemento (O(n)).
-   **Sequencial otimizada** (para listas ordenadas): para quando
    elemento maior que a chave é encontrado.
-   **Binária**: divide a lista ao meio recursivamente (O(log n)), só
    funciona em listas ordenadas.

## Remoção

-   **Não ordenada**:
    -   Do fim: O(1).
    -   Do início/meio: O(n) (deslocamentos).
-   **Ordenada**:
    -   Mantém ordem → pode exigir busca e deslocamentos.

## Conclusões

-   **Vantagens**: simplicidade, acesso rápido O(1).
-   **Desvantagens**: deslocamentos em inserção/remoção, tamanho fixo em
    arrays.
-   Uso recomendado: listas pequenas, tamanho máximo conhecido, poucas
    operações de inserção/remoção.

------------------------------------------------------------------------

## Complexidade Resumida

  Operação   Sequencial                      Ordenada (com busca binária)
  ---------- ------------------------------- ------------------------------
  Inserção   O(1) no fim / O(n) em posição   O(n)
  Remoção    O(1) no fim / O(n) em posição   O(n)
  Busca      O(n)                            O(log n)
  Acesso     O(1)                            O(1)

------------------------------------------------------------------------


