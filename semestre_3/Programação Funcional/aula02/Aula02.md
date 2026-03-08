
- **ghci**: Glasgow Haskell Compiler Interactive
- :t - qual o tipo de algo (domínio e contra-domínio)
	- :t x
		- x :: Num a => a

![[Pasted image 20260305103119.png]]

- **Curry**: Transformar uma função que recebe vários argumentos em várias funções que recebem um argumento por vez.
	- Função: plus 5 7
		- O que realmente acontece: (plus 5) 7

![[Pasted image 20260305104548.png]]

- **Head**: primeiro elemento de uma lista
- **lenght**: comprimento de uma lista

![[Pasted image 20260305110101.png]]

- **filter**: retorna os valores dado uma condição
- map ($ nums) (map filter [(<0), (>0)])
	- retorna uma lista de listas
- da pra concatenar com:
	- [4,3,2] ++ [2,1]

