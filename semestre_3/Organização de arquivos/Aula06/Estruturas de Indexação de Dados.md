## Índice

- É um TAD
- Serve para descobrir em qual página de disco eu acho o meu dado rapidamente (lembra do índice do livro)
- poda (subconjunto de registros que você não verifica ao pular)
	- quanto melhor a poda, melhor o índice


### Índice Simples ou Linear

- Adequado quando cabe em memória principal
- Armazenamento em memória secundária
	- muitos acessos a disco (Busca Binária)
	- Manutenção cara (inserção/remoção)
	- Requer organizações mais apropriadas (**Árvore B**)
- **Dois arquivos: arquivo de índices e arquivo de dados**
- **índice ordenado (para Busca binária)**
- Tem dois campos:
	- Chave de busca
	- Campo de referência (*RRN* para registros de tamanho fixo ou *byte offset* para registros de tamanho variável)

- chave primária (pesquisar)
- chave secundária (pesquisar)

![[Pasted image 20260416080747.png]]

- *Exemplo*: create (campo1, campo2), por isso estão juntos no índice (FF245)

# Operações:

### Pesquisa

- Encontra a **posição da chave no arquivo de índices**
- Obtém o RRN do registro
- Encontra o registro no **arquivo de dados**
- Recupera o registro 
- *usamos BB nos índices e usamos acesso direto (ir para o RRN armazenado)*

### Criação

### Inserção

- insere ordenado no arquivo de índices
- insere sequencial no arquivo de dados
### Remoção

- faz a busca binária
- acesso direto pro RRN
- remoção lógica no arquivo de dados
- remoção no arquivo de índices

### Atualização

### Destruição

### Carregamento

- Varre o arquivo de índices sequencialmente
- Escreve na memória principal

### Reescrita

- *(quando o índice pode ser armazenado totalmente em memória principal)*
-  Atualiza o arquivo de índice em disco, com base no arquivo de índice em memória principal
-  Status (0/1)
