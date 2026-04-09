## BFS

```
Funcao BFS(Grafo, Origem):
    
    // 1. Inicializa todos os vértices do grafo 
    Para cada vertice 'u' no Grafo:
        cor[u] = BRANCO
        distancia[u] = INFINITO
        pai[u] = NULO
        
    // 2. Configura o vértice de origem 
    cor[Origem] = CINZA
    distancia[Origem] = 0
    
    // 3. Cria a Fila e enfileira a Origem 
    Fila Q
    Q.enfileirar(Origem)
    
    // 4. Loop Principal 
    Enquanto a Fila Q nao estiver vazia:
        u = Q.desenfileirar() // Tira o primeiro da fila 
        
        // Avalia todos os vizinhos do vértice atual 
        Para cada 'vizinho' de 'u':
            Se cor[vizinho] == BRANCO: // Se o vizinho é inédito 
                cor[vizinho] = CINZA // Marca que foi encontrado 
                distancia[vizinho] = distancia[u] + 1 //A distância é a do pai + 1 
                pai[vizinho] = u // Registra de onde viemos 
                
                Q.enfileirar(vizinho) // Coloca o vizinho na fila para explorar depois 
                
        // Após avaliar todos os vizinhos de 'u', ele está totalmente processado
        cor[u] = PRETO 
```


## DFS

```
// Variável global para rastrear os passos
Inteiro tempo = 0

Funcao DFS_Principal(Grafo):
    
    // 1. Inicializa todos os vértices 
    Para cada vertice 'u' no Grafo:
        cor[u] = BRANCO
        pai[u] = NULO
        
    // 2. Garante que vai visitar todos os componentes do grafo 
    // (Útil se o grafo for desconexo e tiver "ilhas" separadas)
    Para cada vertice 'u' no Grafo:
        Se cor[u] == BRANCO: 
            DFS_Recursiva(u) 


// Função Auxiliar Recursiva 
Funcao DFS_Recursiva(u):
    
    // Marca como descoberto e anota o tempo de início 
    cor[u] = CINZA
    tempo = tempo + 1
    tempo_descoberta[u] = tempo
    
    // Explora os vizinhos mergulhando profundamente em cada um 
    Para cada 'vizinho' de 'u':
        Se cor[vizinho] == BRANCO: 
            pai[vizinho] = u 
            DFS_Recursiva(vizinho) // A mágica acontece aqui: ele entra no vizinho antes de terminar 'u' 
            
    // Após voltar de todas as recursões dos vizinhos, finaliza o vértice atual
    cor[u] = PRETO 
    tempo = tempo + 1 
    tempo_finalizacao[u] = tempo 
```