### Cota inferior para Ordenação

**Melhor algoritmo de ordenação POR COMPARAÇÃO: O(nlogn)**
*Prova no Slide*

### Algoritmos de busca

**Chave associada a cada registro**
**Def: algoritmo que busca uma determinada chave em uma tabela de registros**

## Busca Sequencial

**Busca mais simples possível**
*Percorre-se os registros, comparando a chave, até achar a chave buscada*
*Limitações: tamanho fixo do vetor*
**O(n)**

**Otimizações**
*Caso o vetor esteja ordenado, parar de comparar se a chave for maior que o V[i]*

*Método mover-pra-frente: sempre que uma pesquisa obter êxito, o registro é colocado no ínicio da lista*
*Lógica: se ele foi buscado, provavelmente ele seja buscado novamente*
*Desvantagem: caso não seja buscado novamente, perda de desempenho*

*Método da transposição: ?*

## Busca sequencial indexada
*(tabela ordenada)*
*armazena os índices dos valores do vetor em uma tabela separada (kindex)*
*Procura-se na tabela, em qual conjunto a chave pode estar, e depois no vetor principal, faz a busca*
