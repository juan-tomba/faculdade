# Filas de Prioridade

Elementos são processados de acordo com sua importância, independente do momento em que entraram na fila
## Implementações

### Sequenciais

Lista sequencial (array) ordenada ou não
Heap em arranjo

### Dinâmica

Lista encadeada ordenada 
Lista encadeada não ordenada 
Heap encadeada

## Abordagens

### Lista Ordenada

Inserção O(n)
Remoção O(1)
Próximo é O(1)

### Lista não ordenada (ou fila?)

Inserção O(1)
Remoção O(n)
Próximo O(n)

# Heap

Uma heap é uma árvore binária que satisfaz:

- *Ordem*: para cada nó v, exceto o nó raiz, tem que:
     chave(v) <= chave(pai(v)) - heap mínima
     chave(v) >= chave(pai(v)) - heap mínima
- *Completude*: é completa , ou seja, se h é a altura
     - Todo nó folha está no nível h ou h-1
     - O nível h-1 está totalmente preenchido
     - As folhas do nível h estão todas mais a esquerda

*Último nó*: nó interno mais á direita de profundidade h

## Teorema

**Uma heap armazenando n nós, possui altura h de ordem O(logn)**
(tem prova no slide)

# Fila de Prioridade com Heap

Armazena-se um item em cada nó
Mantém-se o controle sobre a localização do último nó (v)
(mais algo)
**SPOILER**: implementar sequencial é bem mais interessante, já que sabemos o índice do pai

## Inserção

Algoritmo consiste em 3 passos: (OLHAR SLIDE !!!!!!!!!)
- Encontrar e criar nó de inserção z (novo último nó depois de w)
- Armazenar o item com chave k em z
- Restaurar ordem da heap 

**Após inserir um novo item, a prioridade da fila volta a ser violada**
Olhar slide *Restauração da ordem (fix-up)*

## Remoção

Algoritmo consiste em 3 passos: (OLHAR SLIDE!!!!!!!!!!!!!!!!)
- Armazenar o conteúdo do nó raiz da heap (para retorno)
- Copiar o conteúdo de w no nó raiz e remover o nó w
- Restaurar ordem da heap

Resumo: pegar o último nó, trocar com oq vc quer remover, e reorganizar a heap

## Implementação em Array

Vetores podem representar árvores binárias
O primeiro nó fica em v[0]
**Podemos achar o índice do ítem como:
- Filho esquerdo: 2 * índice + 1
- Filho direito:  2 * índice + 2
- Pai: (índice - 1)/2

## Comparação: Filas de Prioridade

*Lista ordenada*
- Inserção O(n)
- Remoção O(1)
- Próximo O(1)

*Fila (não ordenada)*
- Inserção O(1)
- Remoção O(n)
- Próximo O(n)

*Heap*
- Inserção O(logn)
- Remoção O(logn)
- Próximo O(1)

### Aplicações de Heap

Heap é utilizado como estrutura de apoio a algoritmos clássicos
Exemplo:
- HeapSort, MergeSort
- Algoritmos em grafos (Algoritmo de Prim, Algoritmo de DIJKSTRA)


Fazer exercícios e runcodes :)



