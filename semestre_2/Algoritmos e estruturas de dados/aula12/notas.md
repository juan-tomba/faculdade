### Listas Cruzadas

## Matriz Esparsa
**Utilizar matrizes para reprentalçao em listas**
*Utilizar quando a matriz tem muitos zeros*
*Assim, não representamos os zeros*
*Matriz do tipo (linha, coluna, item, próximo)*
*Tem ponteiros para proxima linha e coluna*
*Cada elemento, gasta 28 bytes (3 int + 2 pointers) + i e j ponteiros (i = linhas e j = colunas)* 
**Regra para uso: nl + nc + 5n < nl.nc**
*Implementação facilitada por listas com nó cabeça*

**TENTAR IMPLEMENTAR A INSERÇÃO DE UMA LISTA CRUZADA**
*Algoritmo simétrico para linhas/colunas*
*Cria uma variável aux(qa), e vai incrementando "q" (q = q->abaixo), ao mesmo tempo que "qa = q" (antes de incrementar)*
*quando "q" passar da coluna, vc seta "qa->abaixo = p" e "p->abaixo = q"*