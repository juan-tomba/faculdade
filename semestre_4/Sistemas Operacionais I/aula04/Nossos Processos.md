## 1. Hierarquia de Processos

- Um processo **pai** pode criar processos **filhos**, que por sua vez criam seus próprios filhos → formação de **hierarquia**.
- **Unix**: chama isso de "grupo de processos" (_process group_).
- **Windows**: não possui conceito de hierarquia — todos os processos são criados da mesma forma.

## 2. Processos — visão do S.O.

O S.O. é responsável por:

- Criação e remoção (destruição) de processos
- Controle do progresso dos processos
- Tratar condições excepcionais (interrupções, erros aritméticos)
- Alocação de recursos de hardware entre processos
- Fornecer comunicação entre processos (mensagens/sinais)

### Tipos de sistemas quanto aos processos

- **Estáticos**: uma única aplicação; todos os processos já existem quando o sistema inicia.
- **Dinâmicos**: número variável de processos; precisa criar/destruir processos durante a execução.

## 3. Estados de um Processo

Um processo passa por 4 estados possíveis:

|Estado|Descrição|
|---|---|
|**Indefinido**|Desconhecido ao S.O. (antes de criado / depois de destruído)|
|**Bloqueado**|Parado esperando ocorrência de um evento|
|**Pronto para execução**|Não executa só porque a CPU está ocupada por outro processo|
|**Em execução**|Usando a CPU normalmente|

### Diagrama de transições (3 estados básicos)

```
Bloqueado ⇄ (1) Executando ⇄ (2) 
Executando → (3) → Pronto
Bloqueado → (4) → Pronto
```

## 4. Ações que mudam o estado

- **Criar**: coloca o processo na memória (torna-o conhecido ao sistema)
- **Acordar**: bloqueado → pronto (evento ocorreu)
- **Despachar**: pronto → executando (escalonador escolhe)
- **Bloquear**: executando → bloqueado (espera evento)
- **Preempção/Suspender**: executando → pronto (fatia de tempo esgotada)
- **Destruir**: libera a memória, processo volta a "indefinido"

> O **Escalonador** (dentro do núcleo do S.O.) gerencia a fila de prontos, o despacho e a preempção usando o **BCP** (Bloco de Controle de Processo).

## 5. Classificação por uso de recursos

- **CPU-bound**: usa muito o processador; tempo definido pelos ciclos de CPU.
- **I/O-bound**: usa muito E/S; tempo definido pela duração das operações de E/S.
- **Ideal**: balancear processos CPU-bound e I/O-bound no sistema.

## 6. Escalonamento — Conceitos Gerais

- Escalonador escolhe qual processo usa a CPU.
- Chaveamento (troca) de processos é **custoso** → afeta desempenho e satisfação do usuário.
- **Mudança de Contexto**: salvar registradores do processo que sai + carregar registradores do processo que entra (via BCP). Gera _overhead_.

### Quando o escalonamento é necessário

- Novo processo criado
- Processo termina execução
- Processo é bloqueado (semáforo, E/S)
- Interrupção de E/S ocorre

### Tipos de algoritmos

- **Preemptivo**: suspende o processo em execução.
- **Não-preemptivo**: processo roda até bloquear voluntariamente.

## 7. Categorias de Ambientes

|Ambiente|Característica|Tipo de algoritmo|
|---|---|---|
|**Batch**|Sem espera de resposta rápida|Preemptivo ou não|
|**Interativo**|Interação constante do usuário|Preemptivo|
|**Tempo Real**|Tempo é crucial (sistemas críticos)|Depende|

### Métricas por ambiente

- **Batch**: throughput, turnaround time, tempo de espera, eficiência (CPU 100% ocupada)
- **Interativo**: tempo de resposta, satisfação do usuário
- **Tempo Real**: prevenir perda de dados, previsibilidade

### Critérios gerais de bons algoritmos

- **Justiça (Fairness)**: parcela justa de CPU para cada processo
- **Balanceamento**: reduzir ociosidade do sistema
- **Políticas do sistema**: prioridades

## 8. Algoritmos para Sistemas Batch

### FCFS (First-Come First-Served / FIFO)

- Não-preemptivo
- Ordem de chegada
- Simples, mas ineficiente com processos longos

### SJF (Shortest Job First)

- Não-preemptivo
- Executa o processo mais curto primeiro
- Minimiza o turnaround médio
- Desvantagem: baixo desempenho com poucos processos prontos

**Exemplo (turnaround médio):**

- Ordem de chegada (A=8,B=4,C=4,D=4): médio = 14
- Menor job primeiro (B,C,D,A): médio = 11 → melhor!

### SRTN (Shortest Remaining Time Next)

- Versão **preemptiva** do SJF
- Se chega processo mais curto que o tempo restante do atual, ele assume a CPU
- Desvantagem: processos longos podem sofrer _starvation_

## 9. Algoritmos para Sistemas Interativos

(Escalonamento em dois níveis: CPU + Memória)

### Round-Robin

- Mais simples e mais usado
- Preemptivo
- Cada processo recebe um **quantum** de tempo
- **Quantum muito pequeno** → muitas trocas → baixa eficiência
- **Quantum muito grande** → tempo de resposta ruim
- Quantum razoável: **20–50 ms**

### Escalonamento por Prioridade

- Processos com maior prioridade executam primeiro
- Prioridades estáticas ou dinâmicas
- Para evitar _starvation_: diminuir prioridade do processo corrente após uso da CPU (chaveamento)

### Múltiplas Filas (ex: CTSS)

- Cada classe de prioridade tem um quantum diferente
- Quanto mais o processo executa, maior o quantum recebido (menos frequente na CPU) → melhora eficiência

### Shortest Process Next

- Igual ao SJF, mas para sistemas interativos
- Tempo de execução não é conhecido → usa **estimativa**

### Outros

- **Garantido**: garante 1/n do tempo de CPU para n usuários
- **Lottery**: processos recebem "bilhetes" (tickets) que dão direito à execução
- **Fair-Share**: considera o _dono_ do processo (usuário com mais processos não domina a CPU)

## 10. Sistemas em Tempo Real (STR)

- Tempo é **fator crítico**
- Aplicações: aviões, hospitais, usinas nucleares, bancos, multimídia
- Resposta atrasada é tão ruim quanto não ter resposta

### Tipos

- **Hard Real Time**: atrasos NÃO toleráveis (aviões, usinas nucleares, hospitais)
- **Soft Real Time**: atrasos toleráveis (bancos, multimídia)

### Eventos

- **Periódicos**: intervalos regulares
- **Aperiódicos**: intervalos irregulares

### Algoritmos

- **Estáticos**: decisão de escalonamento antes do sistema iniciar
- **Dinâmicos**: decisão em tempo de execução