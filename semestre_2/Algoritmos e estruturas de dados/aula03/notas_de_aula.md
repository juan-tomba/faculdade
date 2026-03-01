*Pilhas*

Exemplos:
    -botão back de um navegador web.
    -controle de chamada de procedimentos.
    -estrutura de dados auxiliar em alguns algoritmos (como busca em profundidade).

-O topo de uma pilha é sempre o ultimo elemento a ser adicionado (que será o primeiro a ser retirado), e a base é o oposto.
-Exemplo de representar um numero decimal em binário nos códigos da aula (com vetor e com pilha).
-No exemplo acima, a pilha é menos eficiente, mas elegante. Já o vetor é mais eficiente.
-Mas tem situações que pilha é mais eficiente!!!!!

## Definição da interface para operações
 PILHA *pilha_criar(void);
 void pilha_apagar(PILHA **pilha);
 bool pilha_vazia(PILHA *pilha);
 bool pilha_cheia(PILHA *pilha);
 int pilha_tamanho(PILHA *pilha);
 ITEM *pilha_topo(PILHA *pilha);
 bool pilha_empilhar(PILHA *pilha, ITEM *item);
 ITEM *pilha_desempilhar(PILHA *pilha);
 void pilha_print(PILHA *p);
 void pilha_inverter(PILHA *p);

*Organização vs Alocação de memória*

-Alocação estática: Reserva de memória em tempo de compilação
-Alocação dinâmica: Em tempo de execução
*tabela com tipos de alocação do slide
-Saber conciliar o que usar


*Anotações TAD*

-Lembrar de colocar if (item!=NULL) ao manipular ponteiros no "programa.c".
-TAD tem que ter função para: criar, imprimir, get, set e apagar.
-O ponteiro do programa cliente, deve ser apagado, passando por referência (circ_apagar(&ponteiro)) e dentro do programa.c deve 
receber como **ponteiro, para dar free e setar *ponteiro = NULL.
-Caso passe por cópia (circ_apagar(ponteiro)), nao irá alterar o valor no programa cliente.
