## 1. Problemas Clássicos de Comunicação entre Processos

### 1.1 Produtor/Consumidor

- Sistema composto por **entidades produtoras** e **consumidoras**.
- **Produtoras**: produzem itens armazenados em um **buffer (ou fila)**; itens podem ser consumidos por qualquer consumidor.
- **Consumidoras**: consomem itens do buffer; podem ser itens de qualquer produtor.
- _(Já detalhado com soluções via Sleep/Wakeup, Semáforos e Monitores nas aulas anteriores.)_

### 1.2 Leitores/Escritores

- Uma base de dados é acessada simultaneamente por diversas entidades que realizam **leitura** ou **escrita**.
- **Regras**:
    - É aceitável ter **várias leituras simultâneas**;
    - Se um processo precisa **escrever**, **nenhuma outra entidade** pode estar acessando a base (nem lendo, nem escrevendo).

### 1.3 Jantar dos Filósofos

**Cenário:**

- 5 filósofos sentados em mesa circular; cada um tem um prato de espaguete;
- Como o espaguete é escorregadio, são necessários **2 garfos** por filósofo;
- Existe **1 garfo entre cada par de pratos** (total: 5 garfos para 5 filósofos).
- A vida do filósofo alterna entre **comer** e **pensar (refletir)**.
- Quando fica com fome: tenta pegar os garfos à sua volta (esquerda e direita), **em qualquer ordem**, um de cada vez.
    - Se conseguir os dois → come; depois devolve os garfos e volta a pensar.

**Problemas a evitar:**

- **Deadlock**: todos os filósofos pegam o garfo da esquerda ao mesmo tempo → nenhum consegue o da direita → todos ficam bloqueados para sempre.
- **Starvation**: filósofos ficam indefinidamente tentando pegar garfos sem sucesso (mesmo sem deadlock total).

#### Solução 1 (ingênua) e seus problemas

- `take_fork(i)` direto: se **todos pegarem o garfo da esquerda simultaneamente**, ninguém consegue o da direita → **Deadlock**.
- **Modificação 1**: verificar se o garfo da direita está disponível antes; se não, devolve o da esquerda e tenta de novo → pode gerar **Starvation** (ciclo infinito de tentativas sincronizadas).
- **Modificação 2**: usar **tempo fixo ou aleatório** de espera antes de tentar novamente (como em redes Ethernet) → só serve para **sistemas não críticos**.

#### Solução 2 — Usando Semáforos

- **Não apresenta** deadlock nem starvation;
- Permite o **máximo de "paralelismo"** possível.

**Código (pseudocódigo em C):**

```c
#define N        5           /* número de filósofos */
#define LEFT     (i+N-1)%N   /* vizinho da esquerda de i */
#define RIGHT    (i+1)%N     /* vizinho da direita de i */
#define THINKING 0           /* filósofo pensando */
#define HUNGRY   1           /* filósofo tentando pegar garfos */
#define EATING   2           /* filósofo comendo */

typedef int semaphore;
int state[N];                /* estado de cada filósofo */
semaphore mutex = 1;         /* exclusão mútua para regiões críticas */
semaphore s[N];              /* um semáforo por filósofo */

void philosopher(int i) {
    while (TRUE) {
        think();
        take_forks(i);   /* pega os dois garfos ou bloqueia */
        eat();
        put_forks(i);    /* devolve os dois garfos */
    }
}

void take_forks(int i) {
    down(&mutex);              /* entra na região crítica */
    state[i] = HUNGRY;
    test(i);                   /* tenta pegar os 2 garfos */
    up(&mutex);                /* sai da região crítica */
    down(&s[i]);                /* bloqueia se os garfos não foram adquiridos */
}

void put_forks(int i) {
    down(&mutex);
    state[i] = THINKING;
    test(LEFT);   /* verifica se o vizinho da esquerda pode comer agora */
    test(RIGHT);  /* verifica se o vizinho da direita pode comer agora */
    up(&mutex);
}

void test(int i) {  /* i: filósofo, de 0 a N-1 */
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[i] = EATING;
        up(&s[i]);
    }
}
```

**Como funciona:**

- Um filósofo só entra em `EATING` se **estiver faminto E** nem o vizinho da esquerda nem o da direita estiverem comendo;
- `mutex` protege o acesso ao vetor `state[]` (região crítica);
- Cada filósofo tem seu próprio semáforo `s[i]`, usado para bloqueá-lo até que os garfos estejam disponíveis;
- Ao terminar de comer, `put_forks` verifica (`test`) se os vizinhos podem agora comer, evitando deadlock e permitindo paralelismo máximo entre filósofos não-adjacentes.

### 1.4 Barbeiro Sonolento (Sleeping Barber)

**Cenário:**

- Barbearia com **1 barbeiro**, **1 cadeira de barbeiro**, **N cadeiras de espera**.
- Se não há clientes, o **barbeiro dorme**.
- Quando um cliente chega:
    - Se o barbeiro está dormindo → acorda e atende;
    - Se o barbeiro está ocupado e há cadeira de espera livre → cliente senta e espera;
    - Se não há cadeira de espera disponível → **cliente vai embora**.

> Exercício sugerido: entender a solução via semáforos, identificando as regiões críticas.

### Sugestão de Exercícios (da aula)

- Entender a solução do problema dos **Filósofos** com semáforos: identificar região(ões) crítica(s) e descrever como funciona;
- Entender a solução do problema **Produtor/Consumidor** com **Monitor**: identificar região(ões) crítica(s) e descrever como funciona.

### Links de referência (applets/exemplos)

- http://users.erols.com/ziring/diningAppletDemo.html
- http://journals.ecs.soton.ac.uk/java/tutorial/java/threads/deadlock.html
- http://www.doc.ic.ac.uk/~jnm/concurrency/classes/Diners/Diners.html

---

## 2. Passagem de Mensagem (Message Passing)

### 2.1 Recapitulação: Soluções para Exclusão Mútua

1. Espera Ocupada
2. Primitivas Sleep/Wakeup
3. Semáforos
4. Monitores
5. **Passagem de Mensagem** ← foco desta seção

### 2.2 Motivação

- Mecanismos anteriores (semáforos, monitores) exigem do S.O. apenas a **sincronização**, deixando a **comunicação** (troca de dados) por conta do programador via **memória compartilhada**.
- **Não garantem controle** sobre as operações realizadas sobre o recurso.
- **Troca de mensagens**: exige do S.O. tanto **sincronização** quanto **comunicação**.
    - Assegura exclusão mútua **e** impõe restrições sobre as operações realizadas.
    - Processos **enviam e recebem mensagens**, em vez de ler/escrever em variáveis compartilhadas.

### 2.3 Sincronização e Comunicação

- **Sincronização**: garantida pela restrição de que uma mensagem só pode ser **recebida depois de enviada**.
- **Comunicação**: estabelecida pela transferência de dados entre processos, após a sincronização.

### 2.4 Primitivas de Troca de Mensagens

- **Envio**: `Envia(mensagem, processo_receptor)` ou `Send(message, receiver)`
- **Recepção**: `Recebe(mensagem, processo_emissor)` ou `Receive(message, sender)`

#### Tipos de primitivas

- **Bloqueantes**: o processo que executa fica **bloqueado** até que a operação seja bem-sucedida (mensagem efetivamente entregue/recebida).
- **Não Bloqueantes**: o processo **continua sua execução normal**, independentemente da entrega/recebimento efetivo da mensagem.

### 2.5 Implementação como Procedimentos

```c
send(destination, &message);
receive(source, &message);
```

- `send`: envia mensagem para um destino;
- `receive`: recebe mensagem de uma fonte — **bloqueia** se nenhuma mensagem estiver disponível.

### 2.6 Problemas na Troca de Mensagens (especialmente em rede)

1. **Perda de mensagem**
2. **Perda de reconhecimento (ACK)**
3. **Nomeação de processos**
4. **Autenticação**
5. Projeto para quando emissor/receptor estão na **mesma máquina**

#### Perda de Mensagens

- **Solução**: o receptor envia uma mensagem de **reconhecimento (ACK)** ao receber. Se o emissor não recebe o ACK a tempo, **retransmite** a mensagem.

#### Perda de Reconhecimento (ACK)

- Causa o problema de **receber mensagens duplicadas/idênticas**.
- **Solução**: **numerar as mensagens** (sequência de números) — o receiver verifica a identificação; se for igual a uma mensagem já recebida, **descarta a duplicata**.

#### Nomeação de Processos

- Processos devem ter nomes **únicos** para que `Send`/`Receive` não sejam ambíguos.
- Ex.: `processo@máquina` (autoridade central nomeia as máquinas);
- Com muitas máquinas: `processo@máquina.domínio`.

#### Autenticação

- Permitir comunicação/acesso apenas a usuários **autorizados**.
- Solução: **criptografar** mensagens com chave conhecida apenas por usuários autorizados.

#### Emissor e Receptor na Mesma Máquina

- Para melhorar desempenho: uso de **registradores especializados** para troca de mensagens (evita overhead de rede).

### 2.7 Problemas Gerais da Solução de Passagem de Mensagens

- Mensagens podem se **perder** durante transmissão em rede → uso de **acknowledgement**;
- Se o **ACK se perde** (mas a mensagem foi recebida): usar **números de sequência** para o `receive` detectar e **descartar retransmissões**;
- **Desempenho**: copiar mensagens entre processos é **mais lento** que operações com semáforos/monitores (que usam memória compartilhada);
- **Autenticação/Segurança** também é uma preocupação.

---

## 3. Mecanismos de Comunicação Síncronos

Três mecanismos síncronos mais importantes:

### 3.1 Rendez-vous

- Obtido por primitivas `Envia`/`Recebe` **bloqueantes** em processos distintos.
- Se as primitivas são executadas em tempos diferentes, o processo que chamar **primeiro fica bloqueado** até a sincronização com o outro processo e a transferência da mensagem.
- Depois, **ambos continuam** em paralelo.
- Exemplo de linguagem: **CSP**.

### 3.2 Rendez-vous Estendido

- Um processo consegue **comandar a execução de um trecho de programa** pré-estabelecido, pertencente a outro processo — envolve sincronização e, eventualmente, troca de mensagem.
- Exemplo de linguagem: **ADA**.

### 3.3 Chamada Remota de Procedimento (RPC — Remote Procedure Call)

- Um processo pode comandar a execução de um **procedimento situado em outro processador**.
- O processo chamador **fica bloqueado** até que o procedimento chamado termine.
- Tanto a chamada quanto o retorno podem envolver troca de mensagens (parâmetros).
- Exemplo de linguagem: **DP**.

#### RPC — Vantagens

- Cliente e servidor **não precisam saber** que mensagens estão sendo usadas — veem tudo como **chamadas de procedimento locais**.

#### RPC — Problemas

- **Passagem de parâmetros por referência**: difícil se cliente/servidor têm representações de dados diferentes (necessidade de conversão/desconversão);
- **Diferenças de arquitetura**: ex. diferença no armazenamento de palavras (endianness);
- **Falhas semânticas**: ex. servidor cai durante a execução de uma RPC — o cliente não sabe se a chamada foi executada antes ou depois da falha.
    - Abordagens possíveis: **"no mínimo uma vez"**, **"exatamente uma vez"**, **"talvez uma vez"**.

---

## 4. Outros Mecanismos de Comunicação

### RPC — Remote Procedure Call

- Rotinas que permitem comunicação de processos em **diferentes máquinas**; chamadas remotas.

### MPI — Message-Passing Interface

- Usado em **sistemas paralelos**.

### RMI Java — Remote Method Invocation

- Permite que um objeto ativo em uma JVM interaja com objetos de **outras JVMs**, independentemente da localização.

### Pipe

- Permite criar **filas de processos**;
- Ex.: `ps -ef | grep alunos`;
- A **saída de um processo é a entrada de outro**;
- Existe **apenas enquanto o processo existir** (efêmero).

### Named Pipe

- Extensão do pipe;
- **Continua existindo** mesmo depois que o processo termina;
- Criado com **chamadas de sistema**.

### Socket

- Par **endereço IP + porta** usado para comunicação entre processos em **máquinas diferentes**;
- Ex.: `Host X (192.168.1.1:1065)` ↔ `Server Y (192.168.1.2:80)`.