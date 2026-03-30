
## Instruções para acessar a memória

- *Load*
	- Carrega dados da memória principal para o banco de registradores
	- load (AC) <- (mem)
	- **lb** - carrega 1 byte da memória para um registrador 
	- **lw** - carrega 1 palavra (word) da memória para um registrador

- *Store*
	- Armazena dados do banco de registradores na memória principal
	- store (mem) <- (AC)
	- sb - armazena 1 byte que está em um registrador na memória
	- sw - armazena 1 palavra (word) que está em um registrador na memória

## Atividades

- *Exemplo 1*
	- Implementamos um strcpy em assembly, que consiste em copiar o conteúdo de uma string (origem) em outra (destino)


