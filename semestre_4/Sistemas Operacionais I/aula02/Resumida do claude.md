## Sistema Computacional

Consiste de:

- Um ou mais processadores
- Memória principal
- Discos, impressoras, teclado, monitor, interfaces de rede e outros dispositivos de E/S

---

## Importância do Sistema Operacional

**Sistemas sem S.O.:**

- Maior tempo de programação
- Maior dificuldade
- Usuário precisa se preocupar com detalhes do hardware

**Sistemas com S.O.:**

- Maior racionalidade
- Maior dedicação aos problemas de alto nível
- Maior portabilidade

O S.O. atua como uma camada entre o usuário/aplicação e o hardware.

---

## Máquina Multinível

```
Aplicações        → Bases de dados, jogos, editoração...
Software Básico    → Compiladores, editores, montadores...
                    → Sistema Operacional
Hardware           → Linguagem de máquina, microinstruções, dispositivos físicos
```

---

## Definição de Sistema Operacional

> Um sistema operacional é um programa, ou um conjunto de programas inter-relacionados, cuja finalidade é agir como **intermediário entre o usuário e o hardware**.

---

## Sistema Operacional: três visões

1. **"Fiscal"** — controla os usuários
2. **"Juiz"** — aloca corretamente os recursos ao hardware
3. **"Ilusionista"** — fornece abstrações limpas e fáceis de usar de recursos físicos
    - Memória infinita, máquina dedicada
    - Objetos de nível superior: arquivos, usuários, mensagens
    - Mascaramento de limitações, virtualização

**Objetivos contraditórios:**

- Conveniência
- Eficiência
- Facilidade de evolução
- A melhor escolha sempre **depende** de alguma coisa...

### Como Máquina Estendida (top-down)

Torna uma tarefa de baixo nível mais fácil para o usuário.

Exemplo — E/S de disco (leitura/escrita):

- **S.O. (baixo nível):** número de parâmetros, endereço do bloco, número de setores por trilha, modo de gravação
- **Usuário (alto nível):** abre o arquivo → lê/escreve → fecha o arquivo

### Como Gerenciador de Recursos/Cola (bottom-up)

Gerencia todos os dispositivos e recursos do computador.

- Ex.: dois processos disputando a mesma impressora → o S.O. estabelece a ordem
- Uso do HD, uso da memória
- Coordena alocação controlada e ordenada dos recursos

---

## Princípios do S.O. (visão em camadas)

- **Virtualizando a máquina**: hardware (processador, memória, storage, rede) abstraído pelo S.O.
- **Visão do programa compilado / programador de sistema**: a "máquina" do aplicativo é a abstração de **processo** fornecida pelo S.O.
    - Cada programa em execução roda em seu próprio processo
    - Processos oferecem: _threads_, _address spaces_, _files_, _sockets_
    - Processos fornecem interfaces mais agradáveis que o hardware bruto

### O que é um Processo?

> "Um programa em execução!!"

De que consiste um processo:

- Espaço de endereço
- Uma ou mais _threads_ de controle de execução naquele espaço
- Estado de sistema associado: arquivos abertos, _sockets_ abertos, etc.

**Minhas anotações:**

- É um programa em execução, incluindo os valores correntes, registradores, variáveis
- **Processo é dinâmico, programa é estático**
- Nem sempre um programa equivale a apenas um processo
- Em sistemas que permitem **reentrância**, o código de um programa pode gerar vários processos

### Rodar, Escalonar e Proteger Processos

O S.O.:

- Executa múltiplos processos (Process 1, Process 2...) sobre o mesmo hardware
- **Escalona** os processos (compartilhamento de processador/memória)
- **Protege** os processos entre si (isolamento de memória)

### Entrada e Saída

O S.O. faz a virtualização do hardware de E/S para os processos, com uma **fronteira de proteção** (_protection boundary_) entre software de usuário e hardware.

### Aparência e Comportamento

O processo oferece: threads, address spaces, files, sockets — todos providos pelo S.O. sobre o hardware (processador, memória, storage, redes, displays).

### Gerenciamento de Segundo Plano

O S.O. também gerencia recursos adicionais: janelas (_windows_), bateria, etc.

---

## Funções do Sistema Operacional

- Apresentar uma máquina mais flexível
- Permitir uso eficiente e controlado dos componentes de hardware
- Permitir uso compartilhado e protegido dos componentes de hardware/software por diversos usuários

O S.O. deve responder a perguntas como:

- Quais recursos de hardware existem? Qual seu uso?
- Há algum problema (segurança, falha)?
- É preciso manutenção? Chegou um e-mail? etc.
- Tudo isso via **chamadas de sistema** (system calls) / programas de sistema

---

## Suporte de Hardware

- O S.O. em si é "acidental": o resultado real são os aplicativos suportados
- Idealmente, o S.O. deve ter **baixa sobrecarga** sobre o hardware bruto
- Depende de suporte de hardware para implementar abstrações com eficiência:
    - Operação de modo duplo (usuário/kernel)
    - Interrupções, _traps_, exceções precisas
    - Unidade de gerenciamento de memória (MMU), _Translation Lookaside Buffer_ (TLB)
- Hardware e S.O. **coevoluem** — o que estudamos é resultado de décadas dessa coevolução

### Abstrações fornecidas pelo S.O.

- Sistemas de arquivos, sistemas de janelas, comunicações
- Processos, _threads_
- VMs, _Containers_
- Sistemas de nomes

### Gerenciamento de recursos compartilhados

- Memória, CPU, armazenamento

### Técnicas empregadas

- Escalonamento
- Concorrência
- Transações
- Segurança

Tudo em escala imensa (de 1 a bilhões de processos/usuários), buscando desempenho próximo ao do hardware bruto.

---

## Interação com o Sistema Operacional

**Pelo usuário:**

- Interação direta via **linguagem de comando** (ex.: JCL – _Job Control Language_, DCL – _Digital Control Language_)
- Pode ser via **interface texto** (linha de comando / prompt) ou **interface gráfica (GUI)**
- Exemplos: MS-DOS (texto), Windows XP, Mac OS (GUI)

**Pelos programas:**

- Programas de usuário invocam serviços do S.O. por meio de **chamadas ao sistema** (_system calls_)
- Fluxo: Programa do usuário → Chamada ao S.O. → Sistema Operacional → Retorno → Programa do usuário