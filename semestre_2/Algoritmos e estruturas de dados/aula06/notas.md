## Filas ##

*FIFO - First in, first out*
*Fila normal é mais fácil, mas fila circular é mais barato*
*Como não temos como saber se a fila está cheia, criamos uma variável "tamanho" para tratar*
*Sem essa variável tamanho, era muito custoso implementar a fila*
**fila_inserir_normal tem custo N, já fila_inserir_circular tem custo 1**

**(I = Início; F = final; T = tamanho)**
Fila criada: *T == 0*
Fila vazia: *T == 0*
Fila cheia: *T == TAM (definido)* 

**fila->inicio = (fila->inicio + 1) % TAM**
**fila->fim = (fila->fim + 1) % TAM**

## Deques ##

*Double ended QUEue*
**fila, mas você pode inserir e remover de ambos lados**

**Operações novas**
Inserir_início *deque->inicio = (deque->inicio - 1 + TAM) % TAM*
Inserir_fim
Retirar_inicio
Retirar_fim