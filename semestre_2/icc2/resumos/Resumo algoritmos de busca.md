
# Resumo – Métodos de Busca

Os métodos de busca visam encontrar rapidamente um elemento dentro de uma estrutura de dados. Cada técnica tem vantagens e desvantagens dependendo da organização e do volume dos dados.

---

## 1. Acesso Sequencial
O método mais simples: percorre todos os elementos até encontrar o desejado.  
Complexidade: **O(n)**.  
É fácil de implementar, mas ineficiente para grandes conjuntos de dados.

---

## 2. Busca Binária
Funciona apenas em **estruturas ordenadas**.  
Divide o vetor ao meio repetidamente até localizar o elemento.  
Complexidade: **O(log n)**.  
É muito eficiente, mas exige que os dados estejam previamente ordenados.

---

## 3. Busca por Interpolação
Baseia-se em uma **estimativa da posição** do elemento, considerando a distribuição dos valores.  
É mais rápida que a binária quando os dados são **uniformemente distribuídos**.  
Complexidade média: **O(log log n)**.

---

## 4. Árvores de Busca
Usam uma estrutura hierárquica onde cada nó contém uma chave e dois filhos.  
A busca segue comparando valores até encontrar a chave.  
Complexidade média: **O(log n)**, mas pode chegar a **O(n)** se a árvore estiver desbalanceada.

### Árvores AVL
São árvores binárias **balanceadas automaticamente**, garantindo eficiência O(log n) em inserção, remoção e busca.  
Mais complexas de implementar, mas mantêm desempenho estável.

---

## 5. Endereçamento Direto
Cada chave é mapeada diretamente para um índice da tabela (f(k) = k).  
Acesso é imediato (**O(1)**), mas o espaço de armazenamento pode ser **muito desperdiçado** quando as chaves são grandes ou não contínuas.

---

## 6. Hashing
É uma forma de acesso **direto, mas indireto no endereço real**.  
Usa uma **função hash (h)** que transforma uma chave k em um endereço.  
Permite armazenar e recuperar elementos em tempo **O(1)** na média, independentemente do tamanho da tabela.  
Depende fortemente da qualidade da função hash e da estratégia de tratamento de colisões.

### Conceitos-Chave
- **Função hash:** transforma a chave em um valor (índice) determinístico.  
- **Colisão:** ocorre quando duas chaves diferentes produzem o mesmo endereço.  
- **Fator de carga (α):** razão entre o número de elementos (n) e o tamanho da tabela (m); controla o desempenho.

---

## 7. Tipos de Hashing

### Hashing Fechado (Estático)
Os elementos são armazenados diretamente na tabela.  
Quando ocorre colisão, aplica-se **técnica de rehash** para procurar a próxima posição livre.  
Duas técnicas comuns:
- **Overflow progressivo (sondagem linear):** tenta posições sequenciais (h(k) + i) % B.  
- **Sondagem quadrática:** tenta saltos maiores, reduzindo o agrupamento.  
- **Hash duplo:** utiliza duas funções hash diferentes (h e haux) para gerar novos índices.

Desvantagens: pode gerar **agrupamento de dados** e lentidão conforme a tabela se enche.

---

### Hashing Aberto (Encadeamento)
Cada posição (bucket) da tabela armazena uma **lista de elementos** que colidiram no mesmo endereço.  
Permite inserir um número ilimitado de chaves, mas requer mais memória.  
Se as listas forem longas, a busca se torna lenta; ordenar as listas ajuda, mas aumenta o custo.

---

## 8. Funções Hash Comuns
- **Divisão:** `h(k) = k % m` (m deve ser primo).  
- **Multiplicação:** `h(k) = (k*A % 1)*m`, com A ≈ 0,618.  
- **Hash universal:** `h(k) = ((A*k + B) % P) % m`, escolhendo A e B aleatoriamente.

Uma boa função hash deve:
- Gerar endereços bem distribuídos.
- Ser rápida de calcular.
- Minimizar colisões.

---

## 9. Desvantagens do Hashing
Apesar de ser muito rápido na média, o hashing **não mantém ordem** entre os elementos.  
Isso significa que **não é possível percorrer** a tabela de forma sequencial simples.  
Além disso, colisões são inevitáveis e precisam de tratamento eficiente.

---

## 10. Critérios de Escolha do Método de Busca
A escolha depende de:
- **Eficiência** da busca e das operações de inserção/remoção.  
- **Frequência** das operações realizadas.  
- **Complexidade de implementação.**  
- **Consumo de memória.**

Cada método deve ser escolhido conforme o tipo de dado, volume e necessidade de desempenho do sistema.
