### Hashing aberto

**Cria-se uma lista duplamente encadeada para cada índice**
*Caso ocorra colisão em algum índice, insere-se na lista*

*A tabela pode receber mais itens mesmo quando um bucket já foi ocupado*
*Espaço extra para as listas*
*Listas longas implicam em muito tempo de busca*
*Custo extra para ordenação das listas*

### Funções Hash

**Divisão**


**Multiplicação**
*h(k) = (k * A % I) * m, com A sendo uma constante entre 0 e 1*
*Fmod (biblioteca em C, para mod float)*
*Knugh sugere A = (\(\sqrt{5}\) - 1)/2 = 0,61.....*

**Hash universal**
*Escolhe aleatoriamente no ínicio de cada execução, alguma função hash, de forma que minimize/evite tendências das chaves*
*Ex: h(k) = ((A * k + B) % P) % m*
*P é um num primo maior do que a maior chave k*
*A é uma constante aleatória de um conj {1,2,.....,P-1}*
*m = tamanho da tabela*

### Obs
**Desvantagens**
*Não é ordenado, e sequer existe um método prático para busca*


### Resumo
**Busca sequencial**
**Busca sequencial indexada**
**Busca por Interpolação**
**Busca binária**
**Busca em árvores**
*Não balanceadas ou balanceadas (AVL's)*
**Hashing**

*Eficiência da busca*
*Eficiência de outras operações (inserção, etc)*
*Frequência das oprações realizadas*
*Consumo de memória*
*Dificuldade de implementação*