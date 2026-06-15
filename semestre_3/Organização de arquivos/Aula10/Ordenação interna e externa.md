## Ordenação interna

### Algoritmo

- Recupera o registro da raiz do heap
- Enquanto rearranja o heap, grava esse registro no arquivo de saída
- **Rearranjo do heap**
	- Retira o elemento da raiz
	- Coloca o último elemento do k do heap como raiz
	- Enquanto k for maior do que seus filhos, troca-o de lugar com seu menor filho