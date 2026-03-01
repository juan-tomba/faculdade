### Ordenação por Contagem de Menores

**Saber quantos elementos são menores que X**
*Exemplo: se temos 5 valores menores que 7, ele será inserido na 6° posição*
*Utiliza-se um vetor auxiliar para contagem*
*Vetor A não ordenado*
*Vetor auxiliar= X[i] = número de elementos no vetor A menores que A[i]*
*Vetor final = A[i] vai para a posição X[i] de B*

### Contagem de tipos(counting sort)

**Conta-se o número de vezes que cada elemento ocorre no arranjo: se há k elementos antes dele, ele será inserido na posição k+1 no arranjo ordenado**
*Ideia parecida com o contagem de menores*
*Armzena quantas vezes cada valor aparece*
*Vetor auxiliar = [max+1] (em que max = maior número do vetor original)*

*Para números negativos, temos que pegar o maior e o menor*
*Nesse caso, vetor auxiliar = [max-min+1], já que min é negativo* 
**O(3n), se max <= n**
**Ele tem esse O, porque não é baseado em comparar elementos**