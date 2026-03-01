### Continuação ABB's

*Nós externos*: são os ponteiros para os próximos valores das folhas (não definidos ainda)
*ABB's não balanceadas aumentam o custo de remoção e busca consideravelmente*
Algoritmo para balancear a árvores (slide 43)
Para manter o balanceamento, ou você utiliza o algoritmo (custo alto), ou utiliza AVL

# Árvores AVL

Tem operações de rebalanceamento da árvores
Existe o *Fator de Balanceamento de nó*, que é: a altura de sua sub-árvore esquerda menos a altura de sua sub-árvore direita
## Rotações

**Fator de desbalanceamento >0, rotação direita**
**Fator de desbalanceamento <0, rotação esquerda**
LEMBRAR DO ESQUEMA, MUITO IMPORTANTE
### Rotação direita

Obs: não sei pq, mas escrevi elemento vermelho, que é o elemento a ser inserido
Realizar rotação ao inserir e dois elementos estão desbalanceados em sequência (A e B)

**Rotação direita** (levar em conta o exemplo do slide)
- A vai para a direita, B sobe para a raiz
- T2 e T3 filhos de A (nessa ordem)
- T1 filho esquerdo de B, e A filho direito
- Elemento vermelho inserido como filho de T1

**Exemplo real do slide**:
- 7 é o nó mais jovem desbalanceado (nosso A)
- 5 é o B
- 8 é o T3
- 4 e 6 são T1 e T2
- 2 é o elemento vermelho

**Exemplo: Inserir em uma árvore AVL os elementos 5,4,3,2,1 em ordem:**
- Rotaciona quando tem 5,4,3 ( 5 = A, 4 = B e 3 = elemento vermelho)
- Depois rotaciona com 3 = A, 2 = B e 1 = elemento vermelho

### Rotação esquerda

Mesma coisa, mas invertido (se olhar o esquema vc entende)

Exemplo slide:
- 20 = A, 25 = B e 30 = elemento a ser inserido

*Fazer exemplo: inserção árvore AVL 1,2,3,4,5*

### Rotações Duplas

As rotações simples não funcionam para todos os casos, nesses casos, é necessário utilizar rotação dupla
**Olhar esquema!!!!!!!!**
Usar quando A e B tem sinais trocados
No esquema, realizar rotação esquerda em B e depois rotação direita em A