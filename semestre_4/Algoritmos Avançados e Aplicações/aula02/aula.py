from collections import deque

breakpoint() # debugger do python, comandos: next ou n (vai pra pro linha), continue (vai pro prox breakpoint), p variavel (printa a variavel)
lista = [1, 2, 3, 4]
lista.append(8)
lista = lista + [6, 7]

x = lista.pop()

fila = deque()

dictionario = {}
dictionario = {"chaves" : 40}
dictionario["oi"] = "teste"

for chave, valor in dictionario.items():
    print(chave, valor)

tupla = (3, 4, 5)

def minha_fun(a, b):
    return b, a

x, y = minha_fun(4,5)

lista = sorted(lista, key = lambda x: -x)