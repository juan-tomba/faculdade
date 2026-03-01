### Vamos ver como armazenar e recuperar informações eficientemente


**Complexidade: Número de acessos a disco**
Nosso celular utiliza ssd
Write é custoso, todo disco tem uma capacidade máxima de "writes"
Vida útil do disco - Número de writes do disco

**Fita magnética**: é um meio de armazenamento sequencial que grava dados magneticamente em uma fita plástica, muito usado para backups e arquivamento.

**Byte of 7 bits**: Era utilizado no ASC II original, 1 byte = 7 bits

SGBD (Sistema Gerenciador de Banco de Dados) - é um software que permite criar, gerenciar, manipular e consultar bancos de dados de forma eficiente, segura e organizada.


### Organização

- **Disco**: conjunto de pratos empilhados (dados são gravados nas superfícies desses pratos)
	- **Prato:** disco físico magnético dentro do HD.
- **Superfícies**: Cada lado do prato(são organizadas em trilhas)
- **Trilhas**: Organizadas em setores
	- **Setor**: menor porção endereçável do disco 
- **Cilindro**: conjunto de trilhas na mesma posição

Ao utilizar Fwrite ou Fread, você passa um endereço do setor do disco

![[Pasted image 20260228152959.png]]

### Custo de acesso ao disco

- **Tempo de acesso (Seek time)**
	- tempo para posicionar a cabeça de leitora e gravação no cilindro correto
- **Delay de rotação (Rotational delay)**
	- tempo para rotacionar o disco para que a cabeça de leitora e gravação seja posicionada no setor correto
- **Tempo de transferência (Transfer time)**
	- tempo para transferir os dados para a memória primária

**Tempo = Seek + Rotational + Transfer**
4 páginas = R1 S1 T1 + R2 S2 T2 + R3 S3 T3 + R4 S4 T4
Vamos utilizar páginas adjacentes, para minimizar o seek time das páginas 2, 3, 4.......
### Seek

- Movimento de posicionar a cabeça de read/write sobre a trilha/cilindro desejado
- O conteúdo de todo um cilindro pode ser lido com 1 único seeking
- Devemos tentar minimizar esse tempo

### Sistemas de arquivos

- **Formatação física (Disco físico/Baixo nível)**
	- Organização do disco em setores/trilhas/cilindros que já vem da fábrica
	- Define como os dados serão gravados no hardware
- **Formatação lógica (Disco Lógico/Alto nível)**
	- Prepara o disco para o sistema operacional usar.
	- Cria o **sistema de arquivos** (ex: FAT32, NTFS, ext4).
	- É o tipo de formatação que fazemos quando “formatamos um pendrive ou HD”


### Página de disco

- Também conhecido como Cluster ou Bloco de disco
- **Unidade de transferência de dados entre a RAM e o disco**
- Tamanho default: 4 KB
- O sistema **não lê registro por registro**, ele **lê a página inteira**.
- Um arquivo é visto pelo sistema de arquivos como um conjunto de páginas de disco


![[Pasted image 20260228154022.png]]

- **Vermelho**: Visão lógica usada pelo sistema operacional ou banco de dados.
- **Azul**: Local real onde os dados estão armazenados no disco.
- **Verde**: Estrutura física real do disco, organizada em setores localizados por trilha, superfície e prato
	- Identificados por setor, trilha (track), superfície (face do disco) e prato (disk platter)


obs: desfragmentador deixa as páginas adjacentes, logo, mais rápido (isso para o HD)

### Arquivos

- **Conteúdo**: Registros de dados
- **Descritor do arquivo**: estrutura usada pelo sistema de arquivos para gerenciar cada arquivo existente
	- Exemplos de conteúdo: nome do arquivo, tipo do arquivo, tamanho em bytes, proteção, data e hora do último acesso, data e hora da criação, identificação do proprietário, local onde os dados estão armazenados, ...



