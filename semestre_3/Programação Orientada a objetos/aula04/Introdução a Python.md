# Elementos básicos

## Números

- inteiro(int)
	- Não tem limite
- Ponto Flutuante (float)
- 3.0 é float, mas 3 é int

## Operadores

- Binárias (2 operandos)
	- +-* / 

- Unárias(1 operando)
	- + -

- Divisão inteira ( // )
	- Divisão inteira, pega o mais próximo valor inteiro, menor do que o quociente
	- 13 // 4 = 3
	- -13 // 4 = -4

- Resto da divisão inteira ( % )
	- 13.0 % 4 = 1.0


## Variáveis e tipos

- Linguagem sem verificação estática de tipos 
	- variáveis não são declaradas


![[Pasted image 20260409144449.png]]

## String

- Strings são imutáveis
- é definida por aspas simples ( ' ) ou aspas duplas ( " )
	- nome = 'python'

```py
nome = 'python'
mensagem = "Olá, mundo!"
x = nome[2]
d = mensagem[3:8]
k = len(nome)
n = mensagem.replace("Olá", "Oi")
idade = 30
m = "Eu tenho {:d} anos".format(idade)
s = "ola, " + nome
r = 'Tenho' + str(idade) + 'anos'

```

## Listas (arrays)

- Uma sequência de elementos, que podem ser acessados pela posição

```py
numeros = [1, 2, 3 , 4, 5]
nomes = ["Alice", "Bob", "Carol"]
misturado = [1, "dois", True, 3.14]
a = nomes[0]
a = nomes[-1] # seria "Carol"
nomes.append( "Felipe Fabiano")
numeros.remove(2)
del numeros[0]
sub = numeros[1:3]
sub = numeros[1:]
numeros.insert(0, 9)
k = len(numeros)
nova = numeros + nomes
f = numeros < [1,2,3,5,6]

```

## Matrizes

- Lista de listas
- Se você cria uma matriz e faz tipo
	- b = matriz[1]
	- b[2] = 0
	- vai alterar o matriz[0][2]

```py
#copiar codigo slide
```

## Tuplas

- Lista que não pode ser modificada

## Linguagem de script

## IO

```py
x0 = float(input('Forneça o valor: '))
y = int(input("Resenha? "))
print(x0)
```

- Ler arquivos:

```py
f = open("Entrada.txt, "r")
s = f.read() #le arquivo todo
s = f.readline() #le uma linha
for s in f #le uma linha de cada vez
f.close()

f.open("Entrada.txt", "w")
f.write(str(x1) + "\n")
f.write("Solução: " + str(x1) + "Erro : " +str(erro) + "\n")
f.close()

```

## Bloco de comandos

- Python não utiliza chaves, utiliza a identação para bloco de comandos

```py
if (x == 0):
	x1 = "oi"
elif (x == 1):
	x2 = "resenha"
else:
	x3 = "tchau"

```

## Comandos

```py
match s:
	case 'u':
		t.up()
	case 'd':
		t.down()
	case _: # seria o default do switch-case
		t.right()
		
while(True):
	print("Resenha")
	
for row in self.table:
	for elem in row:
		if elem == n:
			cont += 1
	n += 1

```

## Exceções

```py
try:
	f.open()
except:
	head = []

```

## Funções

```py
def fib(x):
	if (x == 0):
		return 1
	if (x == 1):
		return 1
	return fib(x - 1) + fib(x - 2)

```

## Classe

- Construtor:

```py
class Cadeira:
	def __init__(self): # construtor
		self.posicao = "Em pé"
		self.ocupado = False

```

- Construtor com parâmetros (não pode ter dois, igual Java)

```py
class Cadeira:
	def __init__(self, p = "Em pé", oc = False): # construtor
		self.posicao = p
		self.ocupado = oc

```

- **Podemos definir mais de uma classe no mesmo arquivo**
- Para importar classes de outros arquivos:

```py
from arquivo import classe

if __name__ == "__main__":
	c1 = Cadeira()
	c1.sentar()

```