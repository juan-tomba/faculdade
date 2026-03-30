- **Objeto**: uma instância de uma classe
	- **estado** (atributos)
	- **comportamento** (métodos)
- **Classe**: Modelo para criar objetos, define as características em comuns a um grupo de objetos
	- Define atributos e métodos
- **Instanciar**
	- Processo de criar um objeto a partir de uma classe.
	- cadeira1 <- nova cadeira

- **Construtor**: É um método especial da classe que é automaticamente chamado quando um objeto é criado, usado para inicializar atributos.
- **Composição**: relação onde um objeto é formado por outros objetos.
- **Membros estáticos**: São atributos ou métodos que pertencem à classe, e não aos objetos.
	- class Pessoa {  static int contador;   }
	- Todos os objetos vão ter o mesmo contador (fazer acesso como Pessoa.contador e não juan.contador)
# Exemplos

## 1)

```
*pessoa*
var nome
var data_nascimento
var peso
var altura

criar(nome1, data1, peso1, altura1):
	nome = nome1
	data_nascimento = data1
	peso = peso1
	altura = altura1

set_nome(var x):
	nome <- x

get_nome():
	return (nome)
	
set_data_nascimento(var x):
	data_nascimento <- x
	
get_data_nascimento():
	return (data_nascimento)
	
set_peso(var x):
	peso <- x
	
get_peso():
	return (peso)
	
set_altura(var x):
	altura <- x
	
get_altura():
	return (altura)

calcula_idade():
	var ano_atual <- 2026
	idade = ano_atual - data_nascimento
	return (idade)
```

## 2)

```
*agenda*
pessoas[100]
var num_pessoas

criar():
	num_pessoas = 0

adicionar_pessoa(nova):
	if num_pessoas < 100 && pessoas[num_pessoas] == null:
		pessoas[num_pessoas] = nova
		num_pessoas++
		
remover_pessoa(pessoa):
	var x = achar_bynome(pessoa)
	pessoas[x] = null
			
achar_bynome(nome):
	for i < num_pessoas
		if nome == pessoas[i].nome
			return (i)
	return(null)
	
achar_pessoa(indice):
	return (pessoas[indice])
```

## 3)

```
*elevador*

var andar_atual 
var andares
var capacidade
var num_pessoas

criar(x, y):
	andar_atual = 0
	num_pessoas = 0
	andares = x
	capacidade = y
	
subir():
	if andar_atual < andares
		andar_atual++
		
descer():
	if andar_atual > 0
		andar_atual--
		
destino(x):
	if x == andar_atual
		return
	if x > andar_atual && x < andares:
		while (x > andar_atual):
			subir()
	if x < andar_atual && x > 0:
		while (x < andar_atual):
			descer()
	
add_pessoa():
	if num_pessoas < capacidade:
		num_pessoas++
	
remover_pessoa():  
	if num_pessoas > 0:  
		num_pessoas--


```

## 4)

```
*televisão*

var volume
var limite_volume
var canal
var limite_canal

criar(limite_v, limite_c):  
	volume = 0  
	canal = 0  
	limite_volume = limite_v  
	limite_canal = limite_c

get_volume():
	return (volume)
	
get_canal():
	return (canal)
```

```
*controle*

aumentar_volume(tv):
	if tv.volume < tv.limite_volume:
		tv.volume++
	
diminuir_volume(tv):
	if tv.volume > 0:
		tv.volume--
	
aumentar_canal(tv):
	if tv.canal < tv.limite_canal:
		tv.canal++
	
diminuir_canal(tv):
	if tv.canal > 0:
		tv.canal--
		
canal_direto(tv, x):
	if x >= 0 && x <= tv.limite_canal:
		tv.canal = x


```

## 5)

```
*jogo*

var size
var jogo
var vazio_i
var vazio_j

criar(x, m, n):
	size = x
	jogo = matriz x x
	vazio_i = m
	vazio_j = n
	var numero = 1
	
	for i < size
		for j < size
			if i == m && j == n
				jogo[i][j] = 0
				
			else 
				jogo[i][j] = numero
				numero++
	
mover_direita(i,j):
	if i == vazio_i && j+1 == vazio_j
		swap(jogo[i][j] , jogo[vazio_i][vazio_j])
		vazio_j = j
		
		
mover_esquerda(i,j):
	if i == vazio_i && j-1 == vazio_j
		swap(jogo[i][j] , jogo[vazio_i][vazio_j])
		vazio_j = j
		
mover_cima(i,j):
	if i+1 == vazio_i && j == vazio_j
		swap(jogo[i][j] , jogo[vazio_i][vazio_j])
		vazio_i = i
		
mover_baixo(i,j):
	if i-1 == vazio_i && j == vazio_j
		swap(jogo[i][j] , jogo[vazio_i][vazio_j])
		vazio_i = i
		
jogo_certo():
	var numero = 1
	
	for i < size
		for j < size
			if i == size-1 e j == size-1:  
				if jogo[i][j] != 0:  
					return false 
			else:  
				if jogo[i][j] != numero:  
					return false  
			numero++
			
	return true

```

## 6)

```
*dado*

var lados
var atual
var anterior

criar(x):
	if x
		lados = x
	else
		lados = 6
	var_atual = 0
	var_anterior = 0

rolar():
	var_anterior = var_atual
	var_atual = randint(1, lados)

get_anterior():
	return anterior

```