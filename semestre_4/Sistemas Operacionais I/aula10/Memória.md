
# Aula 10 — Gerência de Memória

> [!abstract] Ideia central A memória ideal (grande, rápida, não volátil e barata) não existe, então o SO gerencia uma **hierarquia de memórias** e decide quem ocupa a RAM. A evolução vai de partições fixas → partições variáveis → swapping → **memória virtual com paginação**, sempre apoiada pela **MMU**.

## 1. Hierarquia de memória

|Nível|Quantidade|Custo/byte|Velocidade|Volátil|
|---|---|---|---|---|
|Cache|pequena (KB)|alto|muito rápida|sim|
|Principal (RAM)|intermediária (MB/GB)|médio|média|sim|
|Disco|grande (GB/TB)|baixo|lenta|não|

- **Lei de Parkinson (adaptada):** os programas se expandem para preencher a memória disponível.
- Quanto mais perto da CPU, menor e mais rápido (registradores → cache → RAM → disco → fita).

## 2. Papel do gerenciador de memória

- Controlar quais partes estão livres e quais estão ocupadas.
- Alocar memória aos processos e liberar quando terminam.
- Localizar dados.
- Gerenciar as trocas entre níveis (RAM ↔ disco, RAM ↔ cache), incluindo o _swapping_ quando a memória é insuficiente.

Duas classes de sistema:

1. Os que movem processos entre RAM e disco durante a execução (troca de processos e paginação).
2. Os mais simples, que não fazem nem troca nem paginação.

## 3. Monoprogramação (sem troca nem paginação)

- Um único processo de usuário por vez, junto com o SO.
- Gerência trivial, mas um erro do programa pode danificar o SO (resolve-se recarregando).
- Três organizações clássicas:
    - SO na base da RAM, usuário acima (mainframes antigos).
    - SO em ROM no topo, usuário na RAM (computadores de mão, embarcados).
    - Drivers em ROM no topo (BIOS), usuário no meio, SO na base (MS-DOS).

## 4. Multiprogramação

### Modelo probabilístico de uso da CPU

Se cada processo passa uma fração $p$ do tempo esperando E/S e há $n$ processos na memória:

$$\text{Utilização da CPU} = 1 - p^n$$

> [!example] Exemplo Com $p = 0{,}8$ e $n = 4$: $1 - 0{,}8^4 \approx 59%$. Mais processos na memória → mais uso de CPU, daí a necessidade de particionar a RAM.
### Dois problemas que surgem

- **Realocação:** o programa não sabe em que endereço será carregado, então seus endereços não podem ser absolutos.
- **Proteção:** impedir que um processo acesse a área de outro ou do kernel.

### Solução: registradores base e limite (na MMU)

- **Registrador-base:** endereço de início da partição; é somado automaticamente a todo endereço gerado.
- **Registrador-limite:** tamanho da partição; endereços acima dele geram erro.
- São carregados quando o processo é escalonado.
- MMUs mais sofisticadas têm vários pares (por exemplo, um para código e outro para dados).

> [!info] MMU (Memory Management Unit) Hardware que traduz **endereços lógicos/virtuais** em **endereços físicos**. O programa só enxerga endereços lógicos, nunca os físicos.

## 5. Particionamento da memória

### Partições fixas (alocação estática)

- Número e tamanho das partições definidos na inicialização.
- Simples, mas desperdiça memória.
- **Filas múltiplas** (uma por partição): problema de filas desbalanceadas.
- **Fila única:** gerência mais fácil e melhor uso da memória.

> [!warning] Fragmentação
> 
> - **Interna:** sobra _dentro_ da área alocada. Ex.: processo de 40K em partição de 50K.
> - **Externa:** sobra _fora_, espalhada. Ex.: livres 25K + 100K = 125K, mas um processo de 110K não cabe em nenhuma.

### Partições variáveis (alocação dinâmica)

- Número e tamanho variam conforme os processos chegam e saem.
- Melhor uso da memória, porém alocação e liberação mais complexas.
- Pouca fragmentação interna, muita **fragmentação externa**.
- Solução: **compactação** (recupera os buracos, mas custa muita CPU).

## 6. Controle de espaço livre

### Bitmap

- Memória dividida em unidades de alocação; 1 bit por unidade (0 = livre, 1 = ocupado).
- Unidade pequena → bitmap grande. Unidade grande → desperdício de espaço.

### Lista encadeada

- Cada nó descreve um segmento: tipo (**P** = processo, **H** = _hole_/buraco), endereço inicial, tamanho e ponteiro para o próximo.
- Ex.: `P|0|5 → H|5|3 → P|8|6 → ...`
- Pode ser uma lista única ou listas separadas para processos e buracos (mais rápido para alocar, mais complexo para liberar).

## 7. Algoritmos de alocação

|Algoritmo|Como escolhe|Observações|
|---|---|---|
|**First Fit**|primeiro buraco que serve|rápido; meio-termo; buracos tendem a migrar para o fim da memória|
|**Next Fit**|como o first fit, mas continua de onde parou|desempenho inferior ao first fit|
|**Best Fit**|menor buraco que serve (percorre tudo)|mais lento; deixa restos minúsculos e inúteis|
|**Worst Fit**|maior buraco disponível|espalha os espaços livres; dificulta alocar jobs grandes|
|**Quick Fit**|listas separadas para os tamanhos mais pedidos|busca rápida|

> [!example] Exemplo dos slides Buracos de 18K, 16K, 32K e 28K; chegam P (14K) e depois Q (20K).
> 
> - **Best fit:** P no de 16K (sobra 2K), Q no de 28K (sobra 8K).
> - **Worst fit:** P no de 32K (sobra 18K), Q no de 28K (sobra 8K).
> - **First fit:** P no de 18K (sobra 4K), Q no de 32K (sobra 12K).

## 8. Quando a memória não basta

### Swapping

- Troca de **processos inteiros** entre RAM e disco.
- **Swap-out:** RAM → disco. **Swap-in:** disco → RAM.
- Funciona com partições fixas ou variáveis.

### Overlays

- Programas maiores que a memória eram divididos em pedaços pelo **programador**.
- Vantagem: "expande" a memória principal. Desvantagem: custo (trabalho) muito alto.

### Memória virtual (MV)

- O **SO** passa a dividir o programa e a trocar os pedaços entre RAM e disco.
- Dá a ilusão de mais memória principal do que realmente existe.
- Histórico: ATLAS (Univ. de Manchester, anos 60) foi o primeiro; IBM System/370 (1972) o primeiro comercial.
- **Espaço de endereçamento virtual:** todos os endereços que o processo pode gerar.
- **Espaço de endereçamento físico:** endereços reais aceitos pela RAM.
- A tradução (**mapeamento**) é feita pela MMU a cada instrução.
- Duas técnicas: **paginação** (blocos de tamanho fixo) e **segmentação** (blocos de tamanho arbitrário).

## 9. Paginação

- Espaço virtual dividido em **páginas virtuais**; memória real dividida em **molduras** (_page frames_) do mesmo tamanho.
- **Tabela de páginas:** entrada = nº da página virtual; saída = nº da moldura.
- Endereço virtual = **nº da página** + **deslocamento** (o deslocamento passa direto para o endereço físico).

> [!example] Exemplo básico Páginas de 4 KB, 64 KB virtuais, 32 KB reais → 16 páginas virtuais e 8 molduras. Endereço virtual de 16 bits = 4 bits de página + 12 bits de deslocamento.
> 
> Endereço virtual **8196** = `0010 000000000100` → página 2, deslocamento 4. Tabela: página 2 → moldura 6 (`110`), bit presente = 1. Endereço físico = `110 000000000100` = **24580** (15 bits).

### Tamanho da tabela

|Espaço virtual|Página|Nº de páginas / entradas|
|---|---|---|
|$2^{32}$|512 B|$2^{23}$|
|$2^{32}$|4 KB|$2^{20}$|
|$2^{64}$|4 KB|$2^{52}$|
|$2^{64}$|64 KB|$2^{48}$|

### Tamanho da página

- Normalmente definido pela MMU, não pelo SO.
- **Páginas maiores:** leitura mais eficiente, tabela menor, mais fragmentação interna.
- **Páginas menores:** leitura menos eficiente, tabela maior, menos fragmentação interna.
- Páginas livres controladas por bitmap ou lista encadeada.

### Onde guardar a tabela de páginas

|Opção|Vantagem|Desvantagem|
|---|---|---|
|**Registradores** (um por entrada)|nenhum acesso à memória na tradução|caro; recarrega tudo a cada troca de contexto|
|**Na RAM** (PTBR aponta o início, PTLR dá o nº de entradas)|hardware mínimo|dois acessos à memória por referência|
|**TLB** (cache dentro da MMU)|evita ir à tabela na RAM|poucas entradas|

## 10. Tabela de páginas multinível

- Objetivo: não manter a tabela inteira na memória o tempo todo.
- Em 32 bits com 2 níveis: **PT1 (10 bits) | PT2 (10 bits) | deslocamento (12 bits)**.
- Nível 1 tem 1024 entradas; cada uma cobre 4 MB (4 GB / 1024) e aponta para uma tabela de nível 2.
- Só existem as tabelas de nível 2 das regiões realmente usadas.

> [!example] Processo que usa só 12 MB Código (4 MB na base), dados (4 MB seguintes) e pilha (4 MB no topo) → só as entradas **0**, **1** e **1023** do nível 1 são usadas. São 4 tabelas de $2^{10}$ entradas em vez de 1 tabela de $2^{20}$. Com entradas de 16 bits: $2^{20} \times 2^4 = 16$ Mbits contra $4 \times 2^{10} \times 2^4 = 64$ Kbits.

> [!example] Traduzindo 0x00403004 Binário: `0000000001 | 0000000011 | 000000000100`
> 
> - PT1 = 1 → 2º bloco de 4 MB (4M a 8M).
> - PT2 = 3 → entrada 3 da tabela de nível 2, que informa a moldura.
> - Deslocamento = 4.
> 
> Se a página estiver na moldura 1 (4K a 8K−1): endereço físico = 4096 + 4 = **4100**.

- **Três níveis** (diretório global → diretório intermediário → tabela de páginas → página): típico de arquiteturas de 64 bits.

## 11. Tabela de páginas invertida

- Problema em 64 bits: páginas de 4 KB → $2^{52}$ entradas; a 8 bytes cada, a tabela teria dezenas de milhões de GB.
- Ideia: **uma entrada por moldura** (memória real), não por página virtual.
    - 256 MB de RAM com páginas de 4 KB → apenas 65 536 entradas ($2^{16}$).
- Cada entrada guarda o par **(PID, nº da página virtual)** que ocupa aquela moldura.
- Desvantagem: a página não serve mais de índice, então seria preciso varrer a tabela a cada referência (muito lento).
- Como acelerar:
    - **TLB** para as páginas mais referenciadas.
    - **Tabela hash** indexada pelo nº da página virtual, com colisões encadeadas em lista; cada nó guarda o par (página, quadro).

## 12. TLB (Translation Lookaside Buffer)

- Também chamada de **memória associativa**.
- Hardware dentro da MMU com poucas entradas (de 64 a 4096) que guarda parte da tabela de páginas do processo em execução.
- Funciona por causa do **princípio da localidade** (temporal e espacial): programas referenciam muito um conjunto pequeno de páginas.
- Campos de cada entrada: válido, página virtual, modificado, proteção (RW, RX), moldura.
- Fluxo: procura na TLB → se achou (_hit_), monta o endereço físico; se não (_miss_), consulta a tabela de páginas na memória.

### Hit ratio

$$T_{hit} = T_{TLB} + T_{MEM}$$

$$T_{miss} = T_{TLB} + 2,T_{MEM}$$

$$T_{médio} = hr \cdot T_{hit} + (1 - hr) \cdot T_{miss}$$

> [!example] Exemplo $T_{hit} = 20$ ns, $T_{miss} = 39$ ns, $hr = 90%$ $T_{médio} = 0{,}9 \times 20 + 0{,}1 \times 39 = 21{,}9$ ns
> 
> Com hr = 0% todo mapeamento vai pela tabela (39 ns); com hr = 100% tudo sai da TLB (20 ns).

## Revisão rápida

- [ ] Sei explicar por que existe hierarquia de memória?
- [ ] Sei diferenciar fragmentação interna e externa, com exemplo?
- [ ] Sei o papel dos registradores base e limite?
- [ ] Sei comparar first, next, best, worst e quick fit?
- [ ] Sei diferenciar swapping, overlays e memória virtual?
- [ ] Consigo traduzir um endereço virtual em físico (1 nível e 2 níveis)?
- [ ] Sei por que usar tabela multinível e tabela invertida?
- [ ] Sei calcular o tempo médio de acesso com TLB?

> [!note] Próxima aula Continuação de gerência de memória.