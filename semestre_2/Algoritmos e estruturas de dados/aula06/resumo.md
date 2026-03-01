# Resumo: Filas e Deques

## Fila (Queue)

-   **Definição**: Estrutura de dados linear que segue a política **FIFO
    (First In, First Out)**.
-   **Regras**:
    -   Inserção sempre no final (enqueue).
    -   Remoção sempre no início (dequeue).
-   **Aplicações**:
    -   Filas de espera e simulações.
    -   Buffers de E/S.
    -   Controle de impressoras em SO.
    -   Busca em largura (BFS).

### Operações principais

-   `fila_criar()` → cria fila vazia.
-   `fila_inserir(F, x)` → insere no final.
-   `fila_remover(F)` → remove do início.
-   Operações auxiliares: `fila_frente`, `fila_tamanho`, `fila_vazia`,
    `fila_cheia`.

### Implementações

1.  **Sequencial**:
    -   Array fixo.
    -   Problema: remoções exigem deslocamentos.
2.  **Sequencial Circular**:
    -   Usa aritmética modular `(i + 1) % n`.
    -   Mantém início, fim e tamanho.
    -   O(1) para inserir e remover.
3.  **Encadeada (dinâmica)**:
    -   Ponteiros para início e fim.
    -   Flexível, tamanho variável.
    -   Inserção/remoção em O(1).

------------------------------------------------------------------------

## Deques (Double Ended Queue)

-   **Definição**: Estrutura que permite inserções e remoções **nos dois
    extremos**.
-   **Aplicações**:
    -   Escalonamento em sistemas operacionais.
    -   Verificação de palíndromos.
    -   Implementação de **desfazer/refazer** em editores.

### Operações principais

-   `inserir_inicio(D, x)`
-   `inserir_fim(D, x)`
-   `remover_inicio(D)`
-   `remover_fim(D)`
-   Operações auxiliares: `primeiro`, `ultimo`, `contar`, `vazia`,
    `cheia`.

### Implementações

1.  **Sequencial Circular**:
    -   Adaptação da fila circular.
    -   Operações O(1).
2.  **Encadeada Dupla**:
    -   Lista duplamente encadeada.
    -   Permite crescimento dinâmico.

------------------------------------------------------------------------

## Exercícios sugeridos

-   Implementar fila dinâmica.
-   Implementar deque dinâmico.
-   Esvaziar fila recursivamente.
-   Inverter fila.

------------------------------------------------------------------------

## Complexidade (comparação)

  Operação   Sequencial               Encadeada
  ---------- ------------------------ -----------
  Criar      O(1)                     O(1)
  Inserir    O(1)                     O(1)
  Remover    O(n) / O(1) (circular)   O(1)
  Frente     O(1)                     O(1)
  Vazia      O(1)                     O(1)
  Cheia      O(1)                     O(1)
  Tamanho    O(1)                     O(1)

------------------------------------------------------------------------
