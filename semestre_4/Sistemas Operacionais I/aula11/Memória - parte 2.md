

# Aula 11 — Gerência de Memória (Parte 2)


> [!abstract] Ideia central Com paginação por demanda, uma página só vai para a RAM quando é acessada; se não estiver lá, ocorre uma **falta de página**. Quando a memória enche, o SO precisa escolher uma **página vítima**, e é aí que entram os **algoritmos de substituição**. A aula fecha com **segmentação**, **segmentação paginada** e **thrashing**.

## 1. Questões de projeto da paginação

A aula é organizada em torno destas perguntas:

1. Onde armazenar a tabela de páginas? (visto na aula 10)
2. Qual a estrutura de uma entrada da tabela?
3. Quantas páginas reais são alocadas a um processo?
4. Quando uma página deve ser carregada?
5. Como trazer uma página para a memória?
6. Como liberar espaço na memória?

## 2. Entrada da tabela de páginas

- O mais comum é uma entrada de 32 bits.
- O campo mais importante é o **número da moldura de página**, que identifica a página real.

> [!note] Complemento (não está detalhado no slide) Além da moldura, uma entrada costuma ter os bits **presente/ausente** (residência), **proteção**, **M** (modificada) e **R** (referenciada). Os bits R e M são a base de quase todos os algoritmos de substituição abaixo.

## 3. Quantas molduras por processo

**Alocação fixa (estática):** cada processo recebe um número máximo de páginas reais, definido na criação (pode ser igual para todos).

- Vantagem: simplicidade.
- Desvantagens: poucas molduras → muita paginação; molduras demais → desperdício de RAM.

A alternativa dinâmica aparece no fim da aula (ver [[#9. Thrashing]]).

## 4. Políticas de busca de página

|Política|Como funciona|
|---|---|
|**Paginação simples**|todas as páginas do processo são carregadas; todas são sempre válidas|
|**Paginação por demanda**|só as páginas efetivamente acessadas são carregadas; um bit de residência indica quais estão na RAM|
|**Paginação antecipada**|carrega a página referenciada e outras que podem (ou não) ser necessárias|

## 5. Falta de página (page fault)

Ao acessar uma **página inválida**, a MMU gera uma interrupção e aciona o SO:

- Página fora do espaço de endereçamento → o processo é **abortado**.
- Página ainda não carregada → **falta de página**.

Tratamento da falta de página:

1. O processo é suspenso e vai para a fila de processos esperando página.
2. Uma moldura livre é alocada (ou uma vítima é escolhida).
3. A página virtual é localizada no disco.
4. O **pager** lê a página do disco para a moldura.
5. A tabela de páginas é corrigida (página agora válida, apontando para a moldura).
6. O processo volta para a fila de prontos.

## 6. Troca de páginas

### Substituição local × global

||Local|Global|
|---|---|---|
|Vítima escolhida entre|páginas do próprio processo|páginas de todos os processos|
|Molduras por processo|fração fixa|varia com o tempo|
|Problema|definir quantas páginas cada processo recebe|processos de baixa prioridade ficam com poucas páginas e sofrem muitas faltas|

> [!example] Exemplo dos slides P1 e P2 têm 4 páginas virtuais cada; a RAM tem 6 molduras, com 3 páginas de cada processo carregadas. P2 tenta acessar sua página 3 (ausente) → falta de página. Como a memória está cheia, a página virtual 2 de P2 é escolhida como **vítima** e dá lugar à página 3.

### Algoritmos de substituição

#### Ótimo

- Remove a página que vai demorar mais para ser referenciada de novo.
- Impossível de implementar (exige conhecer o futuro); serve só como referência em simulações.

#### NRU (Not Recently Used)

- Usa os bits **R** (referenciada) e **M** (modificada), atualizados a cada referência.

|Classe|R|M|
|---|---|---|
|0|0|0|
|1|0|1|
|2|1|0|
|3|1|1|

- A cada interrupção de relógio o bit R é zerado (uma página da classe 3 passa para a classe 1).
- Remove uma página da classe não vazia de menor número.
- Fácil de entender e implementar, desempenho razoável.

#### FIFO

- Lista de páginas na ordem de chegada; remove a mais antiga.
- Simples, mas pode remover uma página em uso constante. Pouco utilizado.

#### Segunda Chance

- FIFO + bit R.
- A mais antiga é a candidata: se R = 0, sai; se R = 1, zera R e vai para o fim da fila.

#### Relógio

- Mesma ideia da segunda chance, em **lista circular** com um ponteiro para a página mais antiga.
- R = 0 → remove a página. R = 1 → zera R e avança o ponteiro. Repete até achar R = 0.

#### LRU (Least Recently Used)

- Remove a página **menos recentemente usada**.
- Alto custo: a lista ordenada por uso precisa ser atualizada a cada referência à memória.
- **Em hardware:** contador de 64 bits de instruções executadas; a cada referência, o valor é gravado na entrada da página; na falta de página, sai a de menor valor.
- **Em software:** aproximações (NFU e Aging).

#### NFU (Not Frequently Used)

- Um contador por página, incrementado a cada referência (na prática, soma-se o bit R a cada tick); sai a de menor contador.
- Problema: **nunca esquece**. Páginas muito usadas no passado ficam com contador alto e não saem, mesmo sem uso atual (ex.: o passo 1 de um compilador de vários passos).

#### Aging (Envelhecimento)

- Corrige o NFU: considera também **quando** a página foi referenciada.
- A cada tick: o contador é deslocado 1 bit para a direita e o bit R entra à **esquerda**.
- Sai a página de menor contador. Em geral 8 bits bastam.

> [!example] Como ler o contador `10000000` → referenciada no último tick. `00100000` → última referência há 3 ticks. Quanto mais zeros à esquerda, mais "velha" a página.

#### Working Set (conjunto de trabalho)

- **Working set:** conjunto de páginas que o processo está realmente usando num instante $t$ (na prática, as referenciadas nos últimos $\tau$ de tempo virtual).
- Objetivo: reduzir faltas de página fazendo **pré-paginação**: o processo só executa com seu working set carregado.
- Usa o bit R e o **tempo do último uso (TLU)** de cada página. Na falta de página, percorre a tabela:
    - **R = 1:** página foi usada; TLU recebe o tempo virtual atual.
    - **R = 0 e idade > τ:** fora do working set; é removida.
    - **R = 0 e idade ≤ τ:** está no working set; guarda a de maior idade como candidata.
- Idade = tempo virtual atual − TLU (ex.: 2204 − 2084 = 120).
- Se todas tiverem R = 1, escolhe uma aleatoriamente; se todas estiverem no working set, sai a mais velha com R = 0.

#### WSClock

- Relógio + Working Set: lista circular em que cada página tem bit R e tempo do último uso.
- No ponteiro:
    - **R = 1:** zera R e avança.
    - **R = 0, idade > τ e M = 0:** página limpa; troca imediatamente.
    - **R = 0, idade > τ e M = 1:** agenda a escrita em disco e continua procurando.
- Se a volta terminar e todas tiverem M = 1: escreve a página atual no disco e troca.
- Melhor desempenho, com menos acessos a disco.

### Resumo dos algoritmos

|Algoritmo|Comentário|
|---|---|
|Ótimo|não implementável; padrão de comparação|
|NRU|muito rudimentar|
|FIFO|pode descartar páginas importantes|
|Segunda Chance|FIFO bastante melhorado|
|Relógio|realista|
|LRU|excelente, mas difícil de implementar exatamente|
|NFU|aproximação bem rudimentar do LRU|
|Aging|eficiente; aproxima bem o LRU|
|Working Set|implementação cara|
|WSClock|bom e eficiente|

- **Só substituição local:** Working Set e WSClock.
- **Local ou global:** Ótimo, NRU, FIFO, Segunda Chance, Relógio, LRU.

## 7. Área de troca (swap) em disco

Para onde vai a página removida? Para a **área de troca**, gerenciada como lista de espaços livres; o endereço da área de cada processo fica na tabela de processos.

- **Área de troca estática:** ao ser criado, o processo é copiado inteiro para sua área de troca; as páginas são trazidas quando necessário. Usa áreas separadas para programa, dados e pilha, porque dados e pilha crescem.
- **Área de troca dinâmica:** nada é reservado antes; o espaço em disco é alocado só quando a página sai da RAM (exige um mapa de disco), e o processo não fica "amarrado" a uma área específica.

## 8. Segmentação

- Reflete a **visão do programador/compilador**: o programa é dividido em unidades lógicas de tamanho variável.
- **Vários espaços de endereçamento** independentes, um por segmento.
- Tabela de segmentos: cada linha guarda **base** e **limite** (tamanho).
- Endereço real = **base + deslocamento**.
- Alocação com os mesmos algoritmos da aula 10: first, best, next, worst e quick fit.
- Facilita **proteção** e **compartilhamento** de código e dados.
- **Sem fragmentação interna, com fragmentação externa.**

> [!example] Compilação Tabela de símbolos (20k), fonte (12k), constantes (2k), árvore de parser (16k) e pilha (12k) viram segmentos 0 a 4. Cada um cresce ou encolhe sem atrapalhar os outros.

> [!example] Compartilhamento P1 e P2 usam o mesmo editor: o segmento 0 dos dois tem base 43062 e limite 25286 (uma única cópia na memória física). O segmento 1 é privado: dados de P1 em 68348 (limite 4425) e de P2 em 90003 (limite 8850).

Quando há espaço livre total, mas não contíguo:

- **Realocação:** move um ou mais segmentos para abrir espaço.
- **Compactação:** junta todos os espaços livres.
- **Bloqueio:** o processo espera em fila.
- **Troca:** substitui segmentos.

### Segmentação paginada

- O espaço lógico é formado por segmentos, e **cada segmento é dividido em páginas**.
- Cada segmento tem sua própria tabela de páginas; a tabela de segmentos aponta para ela.
- Endereço lógico = **(segmento, página, deslocamento)** → endereço físico = **(moldura, deslocamento)**.

### Paginação × segmentação

|Consideração|Paginação|Segmentação|
|---|---|---|
|Programador precisa conhecer a técnica?|Não|Sim|
|Espaços de endereçamento|1|Vários|
|Espaço total pode exceder a memória física?|Sim|Sim|
|Distingue e protege procedimentos e dados?|Não|Sim|
|Acomoda tabelas de tamanho variável?|Não|Sim|
|Facilita compartilhamento de procedimentos?|Não|Sim|
|Por que existe?|obter espaço de endereçamento maior sem aumentar a memória física|dividir programas e dados em espaços logicamente independentes; compartilhamento e proteção|

## 9. Thrashing

> [!warning] Thrashing = paginação excessiva Com poucas molduras, o processo passa a maior parte do tempo esperando faltas de página. Como a troca é cara e lenta, muitos processos ficam bloqueados e o sistema quase não produz.

Como evitar:

- **Taxa máxima aceitável de troca de páginas:** acima dela, suspender alguns processos (swapping) para liberar molduras. Risco: aumenta o tempo de resposta.
- **Dividir igualmente** as molduras entre os processos em execução. Problema: processos grandes recebem o mesmo que os pequenos e paginam demais.
- **Alocação proporcional ao tamanho**, ajustada dinamicamente durante a execução.
    - **PFF (Page Fault Frequency):** indica quando aumentar ou diminuir o número de molduras de um processo, com base na sua taxa de faltas.

## Revisão rápida

- [ ] Sei descrever o passo a passo do tratamento de uma falta de página?
- [ ] Sei diferenciar paginação simples, por demanda e antecipada?
- [ ] Sei comparar substituição local e global?
- [ ] Sei as 4 classes do NRU e o papel dos bits R e M?
- [ ] Sei por que a segunda chance e o relógio melhoram o FIFO?
- [ ] Sei por que o NFU falha e como o aging corrige?
- [ ] Sei simular o aging com contadores de 8 bits?
- [ ] Sei explicar working set e as três decisões do WSClock?
- [ ] Sei diferenciar área de troca estática e dinâmica?
- [ ] Sei comparar paginação e segmentação (fragmentação, proteção, compartilhamento)?
- [ ] Sei explicar thrashing e o PFF?
