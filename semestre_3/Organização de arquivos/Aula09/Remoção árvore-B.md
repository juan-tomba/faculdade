
- Slides em anexo, são muito bons para entender cada caso
- *Taxa de Ocupação*: mede o quão cheios estão os nós da árvore em relação à sua capacidade máxima.
	- Taxa de ocupação(nó) = num_chaves / max_chaves
	- Taxa de ocupação (árvore) = total_chaves / total_chaves_possivel
### Casos

1. Remoção de uma chave em um nó folha, sem causar underflow 
2. Remoção de uma chave em um nó não folha 
3. Remoção de uma chave em um nó, causando underflow 
4. Remoção de uma chave em um nó, causando underflow e a redistribuição não pode ser aplicada 
5. Underflow no nó pai causado pela remoção de uma chave em um nó filho 
6. Diminuição da altura da árvore

## Remoção RESUMIDO

- Começa busca pelo nó raiz (toda remoção começa pelo nó raiz)
- Até achar:
	- se for nó folha, ai vai naquele algoritmo
		- tenta redistribuir no irmão direito, depois no esquerdo
		- se não der, concatenação
	- se não for nó folha, substitui pelo:
		- mais a esquerda a direita
		- ou o mais a direita na esquerda

# Árvore B virtual

