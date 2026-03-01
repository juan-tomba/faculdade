- Funcional vem de função (da matemática) que contém domínio e imagem
- **FUNÇÃO SEMPRE RETORNA O MESMO VALOR COM A MESMA ENTRADA**
- obter_idade() não é uma função
- Antes da programação funcional, utilizavamos programação imperativa

### Exemplo de análise de código

```py
def plus(y):
	global x
	x = x + 1
	return x + y
```

- plus(5) -> retorna 6
- (chamou plus mais 4 vezes)
- plus(5) -> retorna 11


```py
def soma(y, z):
	return y + z
```
- Neste exemplo, o resultado sempre será o mesmo (não depende de algo externo)
- soma(6,9) sempre será 15

### Exemplo 1

```py
nums = [4, 6, 2, -9, 7, -3, 4, 2]
s = 0
forn n in nums:
	if n > 0:
		s += n*n
```
-> 125
- Neste exemplo, é utilizado programação imperativa
- Agora iremos utilizar programação funcional:

```py
sum(map(lambda2 x: x*x, filter (lambda1 x: x>0, nums)))
```

- O lambda1 testa se x é maior que 0
- O lambda 2 é a transformação de cada elemento da lista que passou no filter
- O map aplica a transformação em todos os elementos da lista (que no caso é lambda2)
- obs: esses 1 e 2 na frente do lambda são didáticos, no código não existe isso

### Exemplo 2

```py
sum(filter(lambda x: x > 10, map(lambda x: x*x, nums)))
```
-> 198
- Soma dos quadrados maiores que 10

# Haskell

- é uma linguagem de programação parelela (variáveis imutáveis)
- i++ não funciona (nem i = i + 1)
- Não tem laços
- Lazy computation (ele só faz o que precisa)
- Para rodar o código:
```bash
runghc hello.hs
# ou
ghci hello.hs

# para sair
:q
# Sempre que editar o arquivo, utilize o reload 
:r
```


- Exemplo 1 em Haskell (Soma dos quadrados dos números positivos)
```hs
nums = [5, 6, -9, 2, 4, -2, -5, 2]
sum $ map (^2) $ filter (>0) nums
```
-> 85

- Soma os números do vetor em 1, e multiplica todos os menores que 10
```hs
product $ filter (<10) $ map (+1) nums
```

- Soma dos 4 menores números positivos multiplicados por 2 de nums
```hs
sum $ take 4 $ sort $ map (*2) $ nums
```
- obs: Com o lazy computations, ele só dobra os 4 primeiros números (que serão utilizados)

### DICAS DE HASKELL

- Ler o código da direita para a esquerda
- O operador "$"
	 - "aplique a função sem precisar de parênteses"
	 - Dica para lembrar: **f $ x = f(x)**
- O operador "."
	- Serve para criar funções
	 - Dica: **f(g(x))**
- O operador ">>=" conhecido como "bind"
	- pega um valor dentro de um contexto e passa para a próxima função