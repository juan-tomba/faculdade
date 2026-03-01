### Resumo

**Acesso Sequencial O(n)**
**Busca Binaria O(logn)**
**Busca por interpolação O(log(logn))**
**Arvore**

### Hashing

**Hash = webster's new world dictionary (fazer picadinho ou bagunça)**
**Acesso direto, mas endereçamento indireto**
*Função de mapeamento h, assim, h(k) != k*
*a função hash é utilizada para inserir, remover ou buscar um elemento*
*colisão: ocorre quando a função hash produz o mesmo endereço para chaves diferentes*
*Resolve uso ineficiente do espaço de armazenamento*
**O(c), idealmente com c=1**
**Ideia: particionar um com conj de elementos (até infinitos) em um conj finito de classes**
*B classes, de 0 a B-1*

**Para chaves inteiras, calculas k%B, sendo que o resto indica a posição de armazenamento**
*k = valor da chave, B = tamanho do espaço de endereçamento*

**Para chave tipo string, somar os valores de cada caractere com ASCII e pegar o resto da divisão por B**
*B primo preferencialmente*

### Tipos de hashing

**Estático (fechado ou aberto)**
**Dinâmico: fora do escopo da disciplina**

**Fechado: armazenar um conjunto de informações de tamanho limitado**
*Colisões: aplicar técnicas de rehash*
*Overflow progressivo ou 2° função de hash*

**Aberto: armazenar um conj de informações de tamanho potencialmente ilimitado**
*encadeamento de elementos para tratamento de colisões*

## Técnicas de Rehash
*Se h(k) esta ocupada, aplicar tecnica de rehash sobre h(k), que deve retornar o próximo bucket livre*
*Caracteristicas de uma boa técnica de rehash: cobrir o máximo de índices entre 0 e B-1, evitar agrupamento de dados*

**Overflow Progressivo**
*h(k) = (h(k) + i) % B, com i variando de 1 até B-1* sondagem linear
*h(k) = (h(k) + c1 * i + c2 * i²) % B, constantes c1 e c2* sondagem queadrática (não compensa)
*vai uma pra frente até achar o bucket livre*

### Obs
**Dificil achar uma função hash que evite agrupamento de dados e preencha todos os índices da tabela**