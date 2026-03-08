# Campos

- Se todos os campos são de tamanho fixo, o registro é de tamanho fixo
> [!question]- Se o registro é de tamanho fixo, os campos são de tamanho fixo? 
>- **Não necessariamente**

## Tamanho fixo

- Cada campo ocupa um **tamanho fixo de memória**, pré-determinado

**Exemplo:**
- nome: string de 12 caracteres (12 bytes) 
- rua: string de 10 caracteres (10 bytes) 
- número: inteiro (4 bytes) 
- cidade: string de 20 caracteres (20 bytes)

![[Pasted image 20260307152819.png]]

| **Vantagens**                                                                   | **Desvantagens**                                                          |
| :------------------------------------------------------------------------------ | :------------------------------------------------------------------------ |
| Facilidade na pesquisa                                                          | Desperdício de memória                                                    |
| Situações nas quais o comprimento dos campos é fixo ou apresenta pouca variação | Possibilidade de truncamento de dados                                     |
|                                                                                 | Situações nas quais se tem grande quantidade de dados de tamanho variável |

## Indicador de tamanho

- Armazena o **tamanho de cada campo** antes do dado

![[Pasted image 20260307153558.png]]

| **Vantagens**                                                                                        | **Desvantagens**        |
| :--------------------------------------------------------------------------------------------------- | :---------------------- |
| Economia de espaço de armazenamento, mesmo gastando alguns bytes para armazenar o tamanho dos campos | Dificuldade na pesquisa |
| Dados não precisam ser truncados                                                                     |                         |
|                                                                                                      |                         |

## Delimitadores

- Utiliza **caracteres especiais** (fora do domínio do dado) inseridos ao final do campo
	- exemplo - delimitador: **|** (caractere de 1 byte)

![[Pasted image 20260307154016.png]]

| **Vantagens**                       | **Desvantagens**                                                               |
| :---------------------------------- | :----------------------------------------------------------------------------- |
| Economia no espaço de armazenamento | Dificuldade na pesquisa                                                        |
|                                     | Necessidade de escolha de um delimitador que não pertence ao domínio dos dados |
|                                     |                                                                                |

# Registros

## Tamanho fixo

- Todos os registros têm o mesmo número de bytes
- Existem:
	- registros de tamanho fixo com campos de tamanho fixo
	- registros de tamanho fixo com campos de tamanho variável
- **Um dos métodos mais utilizados em organização de arquivos**
## Registros e Campos de Tamanho Fixo

-  Registros de tamanho fixo 
	- tamanho de 46 bytes 
- Campos de tamanho fixo 
	- nome: string de 12 caracteres (12 bytes) 
	- rua: string de 10 caracteres (10 bytes) 
	- número: inteiro (4 bytes) 
	- cidade: string de 20 caracteres (20 bytes)

![[Pasted image 20260307152819.png]]

## Registros de Tamanho Fixo e Campos de Tamanho Variável

- Registros de tamanho fixo 
	- Tamanho de 46 bytes 
- Campos de tamanho variável 
	- Delimitador: | (caractere de 1 byte)

![[Pasted image 20260307173006.png]]


## Acesso direto por RRN

- **RRN (relative record number)**
	- Usado para registros de tamanho fixo
	- fornece a *posição relativa de cada registro* dentro do arquivo
	- permite calcular o byte offset no qual cada registro começa

>byte offset = RRN x tamanho do registro

![[Pasted image 20260307173157.png]]

## Indicador de tamanho

- Armazena o tamanho de cada registro em bytes
- Uso de **campos de tamanho váriavel**
> Método muito utilizado para manipular registros de tamanho variável

![[Pasted image 20260307173911.png]]

## Delimitadores

- Separar os registros por delimitadores
- O delimitador de registro é colocado ao final do registro
- Uso de **campos de tamanho váriavel**
- Não utiliza números inteiros para armazenar o tamanho, então existe **economia de memória**

![[Pasted image 20260307174026.png]]