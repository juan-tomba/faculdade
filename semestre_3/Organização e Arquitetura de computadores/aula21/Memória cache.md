- Faz ponte da hierarquia de memória
- Um nível mais perto do processador normalmente contém um sub????? dada de nível 
- Acesso associado

## Princípios de localidades 

- *Espacial* : se um dado é acessado existe a probabilidade de acessar um dado que está perto
- *Temporal* : Se um dado é acessado, existe a probabilidade de acessá-lo novamente

## Conceitos

- *Bloco* : menor unidade que está presente ou não na cache
- *Acerto (Hit)* : o dado foi achado na cache
- *Falha (miss)* : o dado não foi achado na cache
- *Taxa de acerto (hit role)* : número de acertos na cache / numero total de acessos
- *Taxa de falha (miss role)* : tempo para buscar um dado na cache, falhar busca no nível inferior

## Características das caches

#### Tamanho da cache

- **Depende da localização**
- Dentro do processador:
	- *L1* : 32 kb
	- *L2* : 256 kb
- Fora do processador:
	- *L3* : 10 a 20 mb

#### Tamanho do bloco

- Grande suficiente para satisfazer a localidade espacial
- Não muito grande

## Estrutura da cache

## Funções de Mapeamento

- Determina onde os blocos da MP são alocados nas caches
- 64 bytes = 6 bits
- Mapeamento Direto
- Mapeamento Associativo total
- Mapeamento Associativo por conjunto

## Mapeamento Direto

- Mapeia o bloco do MP sempre na mesma linha da cache segundo a função resto
	- i = j mod m
	- l = n° da linha da cache onde será alocado
	- j = n° do bloco da MP
	- m = n° de linhas da cache

## Mapeamento totalmente associativo

- Os blocos da MP podem ser mapeados em *qualquer* linha da cache

## Mapeamento associativo por conjunto

- Dividir a cache em *v* conjunto de *k* linhas cada conjunto
- Mapeia diretamente no conjunto e dentro do conjunto pode mapear em qualquer linha
- número de linhas da cache = v * k

## Algoritmo de Substituição

- Mapeamento direto a função hash
- Mapeamento
	- Totalmente Associativo
	- Associativo por Conjunto
		- FIFO: Linha que entrava primeiro
		- LRU (Least Recently Used) : linha que há mais tempo não é referenciada
		- LFU (Least Frequently Used) : linha que foi referenciada menos vezes
		- Aleatórias escolhas : linha escolhida aleatoriamente

## Política de escrita

### Write back

- Atualiza o nível onde o dado foi inventado e indica que a linha está suja (dirty)

### Write through

- Atualiza o nível onde o dado foi encontrado e o nível inferior

### Write miss

#### Write Allocate

- Read miss (traz para a cache o dado)
- Write hit (escreve já tendo o dado na cache)

#### Write no-allocate

- Escreve no nível que achar o dado