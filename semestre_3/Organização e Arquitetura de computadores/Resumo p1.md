# Teoria: Arquitetura e Organização de Computadores

## 1. Conceitos Fundamentais
* **Arquitetura:** Atributos visíveis ao **programador** (ex: conjunto de instruções, tipos de dados, modos de endereçamento).
* **Organização:** Como as unidades operacionais são interconectadas (**fabricante**). Refere-se ao hardware (ex: sinais de controle, interfaces, tecnologia de memória).

---

## 2. Componentes da CPU (Registradores e Unidades)
* **PC (Program Counter):** Armazena o endereço da próxima instrução a ser buscada.
* **IR (Instruction Register):** Armazena a instrução que está sendo executada no momento.
* **MAR (Memory Address Register):** Conectado ao barramento de endereços; indica *onde* na memória o dado está.
* **MBR (Memory Buffer Register):** Conectado ao barramento de dados; contém o *conteúdo* lido ou a ser gravado.
* **UC (Unidade de Controle):** Decodifica instruções e gera sinais de controle para o restante do sistema.
* **AC (Acumulador):** Registrador temporário para resultados de operações da ALU (ULA).

---

## 3. Componentes do Computador
* **CPU (UCP):** Unidade Central de Processamento (Cérebro).
* **Memória Principal:** Armazena instruções e dados (RAM).
* **Entrada e Saída (E/S):** Interface com periféricos.
* **Sistema de Barramento:** Caminhos de comunicação entre os componentes:
    * **Dados:** Transporta a informação.
    * **Endereço:** Indica a origem/destino.
    * **Controle:** Gerencia quem usa o barramento.

---

## 4. Ciclos de Instrução

### **Ciclo de Busca (Fetch)**
O processador busca a instrução na memória e prepara o próximo passo:
1. `MAR <- PC` (Endereço da instrução vai para o registrador de endereço).
2. `MBR <- Memoria(MAR)` (A instrução é lida da memória e colocada no buffer).
3. `PC <- PC + 1` (Incrementa o contador, exceto em desvios/branches).
4. `IR <- MBR` (A instrução é movida para o registrador de instrução para ser processada).

### **Ciclo de Execução**
1. **Decodificação:** A `UC` interpreta o código de operação (opcode) no `IR`.
2. **Sinais de Controle:** A `UC` determina as ações necessárias e ativa os componentes de hardware.
3. **Execução:** Realização da operação (ex: soma na ALU, acesso à memória ou E/S).

## 5. Arquitetura de Von neumann

* **Arquitetura de Von Neumann**
    * Modelo onde **dados e instruções** compartilham a mesma memória e o mesmo barramento.
    * Baseado no ciclo de busca e execução sequencial.
* **ISA (Instruction Set Architecture)**
    * É a "fronteira" entre o software e o hardware. 
    * Define o que o programador vê: conjunto de instruções (ADD, SUB, LW), registradores e modos de endereçamento.
* **Registradores**
    * Memórias ultrarrápidas localizadas dentro da CPU.
    * Armazenam operandos imediatos e endereços de controle (ex: PC, IR).
* **Linked List (Lista Ligada) em Assembly**
    * Cada "nó" da lista é um bloco de memória alocado no **Heap**.
    * Estrutura do nó (ex: 8 bytes): 
        1. Primeiros 4 bytes: **Dado** (inteiro, char, etc).
        2. Últimos 4 bytes: **Ponteiro** (endereço do próximo nó).
    * O fim da lista é marcado por um ponteiro `NULL` (valor `0`).

# Assembly RISC-V

* **ecall**
    * Chamada de sistema. O serviço é definido pelo registrador `a7`.
    * print Int = 1
    * read int = 5
    * ordem: int, float, double, string
* **Comparações (Branches)**
    * `beq` (Branch if Equal) $rs1 == rs2$
    * `bne` (Branch if Not Equal) $rs1 \neq rs2$
    * `blt` (Branch if Less Than) $rs1 < rs2$
    * `bge` (Branch if Greater or Equal) $rs1 \geq rs2$
    * `bltu` / `bgeu` (Versões para números *unsigned* / sem sinal)
* **Saltos Incondicionais**
    * `j label` (Jump) Salto direto para um rótulo.
    * `jal ra, label` (Jump and Link) Salta e salva o endereço de retorno em `ra`.
    * `jr ra` (Jump Register) Retorna ao endereço guardado em `ra`.
* **Aritmética e Lógica**
    * `add` / `sub` (Soma e Subtração)
    * `addi` (Soma imediata: reg + número fixo)
    * `mul` / `div` / `rem` (Multiplicação, Divisão e Resto)
    * `and` / `or` / `xor` (Operações lógicas bit a bit)
* **Memória (Load/Store)**
    * `la rd, label` (Load Address) Carrega o endereço de um rótulo.
    * `lw rd, offset(rs1)` (Load Word) Lê 4 bytes da memória para o registrador.
    * `sw rs2, offset(rs1)` (Store Word) Grava 4 bytes do registrador na memória.
    * `lb` / `sb` (Load/Store Byte) Manipula apenas 1 byte (útil para strings).
* **Pilha (Stack)**
    * `sp` (Stack Pointer) Registrador `x2`. Aponta para o topo da pilha.
    * **Alocar espaço**: `addi sp, sp, -N` (A pilha cresce para baixo).
    * **Salvar (Push)**: `sw s1, 0(sp)` (Guarda o valor de s1 no topo).
    * **Recuperar (Pop)**: `lw s1, 0(sp)` (Lê o valor de volta para s1).
    * **Liberar espaço**: `addi sp, sp, N` (Sobe o ponteiro após o uso).
# Registradores RISC-V (32 bits)

| Nome (ABI) | Número | Função / Uso | Preservado? |
| :--- | :--- | :--- | :--- |
| **zero** | x0 | Constante zero (sempre 0, não muda) | - |
| **ra** | x1 | **Return Address**: Endereço de retorno de funções | Não |
| **sp** | x2 | **Stack Pointer**: Aponta para o topo da pilha | Sim |
| **gp** | x3 | **Global Pointer**: Aponta para dados globais | - |
| **tp** | x4 | **Thread Pointer** | - |
| **t0 - t2** | x5 - x7 | **Temporários**: Uso livre (podem ser apagados) | Não |
| **s0 / fp** | x8 | **Saved / Frame Pointer**: Início do quadro da pilha | Sim |
| **s1** | x9 | **Saved**: Registrador preservado | Sim |
| **a0 - a1** | x10 - x11 | **Arguments**: Argumentos de função e **Retorno** | Não |
| **a2 - a7** | x12 - x17 | **Arguments**: Mais argumentos de função | Não |
| **s2 - s11** | x18 - x27 | **Saved**: Registradores que devem ser salvos | Sim |
| **t3 - t6** | x28 - x31 | **Temporários**: Mais uso livre | Não |

---

## Dicas Rápidas para a Prova:

* **x0 (zero):** Essencial para zerar outros registradores (`add t0, zero, zero`) ou fazer comparativos (`beqz`).
* **a0 e a7:** São os "astros" do `ecall`. O `a7` diz qual serviço chamar (ex: 4 para string, 5 para ler int) e o `a0` costuma levar o valor ou o endereço.
* **ra (x1):** Quando você dá um `jal`, o endereço da próxima linha de código é guardado aqui. Sem ele, a função não sabe como "voltar" para o `main`.
* **sp (x2):** Sempre que for salvar algo na pilha, você subtrai o `sp`. **Regra de ouro:** se você subtraiu no início da função, tem que somar o mesmo valor no final para não quebrar o programa.
* **Temporários (t) vs Salvos (s):**
    * Se você chamar uma função dentro de outra, a função chamada pode apagar os seus `t`. 
    * Se você precisa que um valor sobreviva a uma chamada de função, guarde-o nos `s` (mas lembre-se de salvar o valor original do `s` na pilha antes!).



### Prova 024

von neumann - dados/instruções na memória
instruction set architeture: conjunto de opcodes (add, mv)
cpu - unidade de controle de processamento, buscar e executar instruções
ciclo de busca: buscar a instrução
	mar = pc
	mbr = mem(mar)
	pc = pc + 1
	ir = mbr
ciclo de execução: uc decodifica a instrução e manda sinais de controle para os componentes envolvidos na operação
registrador: memória rápida da cpu para armazenar dados rapidamente
	

linked list:
	primeiro criaria um rótulo "header" no .data, que é uma variável que guarda o endereço do primeiro nó, para a inserção, utilizaria uma função auxiliar "malloc_no" que alocaria a memória necessária para o nó, que vou definir como 8 bytes (4 para ID e 4 para endereço do próximo), para busca iria comparando o valor do nó com o valor buscado, até o próximo ser nulo, e para remoção, basta achar o nó, colocar o próximo do anterior no próximo do nó retirado


strcpy:
	add t0, zero, a0
	add t1, zero, a1 # assumindo que foram alocados N bytes com o ecall 9
	addi t2, zero, 0 # contadora
	# s1 é N
loop:
	beq t2, s1, fim
	lb t3, 0(t0)
	sb t3, 0(t1)
	addi t0, t0, 1
	addi t1, t1, 1
	addi t2, t2, 1
	j loop
fim:
	addi t1, t1, 1
	sb zero, 0(t1) #\0
	# retorna em a1
	jr ra
	
	