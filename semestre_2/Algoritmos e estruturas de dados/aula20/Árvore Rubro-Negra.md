Robert Sedgewick - Criador da Árvore Rubro-Negra

# Propriedades

Estudaremos a versão LLRB
É uma ABB
Arestas Coloridas (vermelha e preta)
**TODA INSERÇÃO COM ARESTA VERMELHA** (ai rotaciona ou inverte as cores depois)
Raiz da árvore sempre começa negra

**Regras:**
- Aresta vermelha sempre para o filho esquerdo (mas pode ser preto tambem)
- Todo nó possui, no máximo, uma aresta vermelha
- Balanceamento negro perfeito (todo filho nulo está á mesma distância da raiz - distância negra)

*Distância negra: distância entre dois nós contando apenas arestas pretas*
*Todo nó vermelho esta a esquerda, mas nem todo nó esquerdo é vermelho*

Altura no pior caso: h <= 2log(n)
## Inserção

Igual á ABB, porém, todo nó inserido possui aresta incidente vermelha
*Basicamente, não pode ter 2 nós só com arestas vermelhas seguidos*

Manutenção das 3 regras após inserção e remoção
Uso de rotações (igual AVL)

- [ ] Exercício: rubro negra com as chaves: 10, 15, 20, 17, 25, 5, 12
*Obs: lembrar de verificar a distância do filho nulo*

## Operações

preto = 0
vermelho = 1

(copiar dps as operações)

## Remoção

*Propagar aresta vermelha da raiz até a folha, se necessário*
==Para remover, o nó deve ser vermelho==
Códigos feitos ~~com o Rudinei~~

### PropagaEsquerda

- 2 Casos : depende da cor de h->dir->esq

```c
NO_T *PropragaEsquerda(NO_T *h){
	if(!vermelho(h->esq) && !vermelho(h->esq->esq)){
		inverteCor(h);
		if(vermelho(h->dir->esq)){
			h->dir = rodarDireita(h->dir);
			h = rodarEsquerda(h);
			inverteCor(h);
		}
	}
	return (h);
}

```

### PropagaDireita

- Caso 1: se h->esq é vermelho
- Caso 2 e 3 : depende da cor de h->esq->esq

```c
NO_T *PropagaDireita(NO_T *h){
	if(vermelho(h->esq)){
		h = rodarDireita(h);
	}
	if(!vermelho(h->dir) && !vermelho(h->dir->esq){
		inverteCor(h);
		if (vermelho(h->esq->esq)){
			h = rodarDireita(h);
			inverteCor(h);
		}
	}
	return(h);
}

```

### RemoveMin

```c
NO_T *RemoveMin(NO_T *h){
	if(h->esq == NULL){
		free(h);
		h = NULL;
	}
	if(!vermelho(h->esq) && !vermelho(h->esq->esq)){
		h = PropagaEsquerda(h)
	}
	h->esq = RemoveMin(h->esq);
	return (h);
}
```