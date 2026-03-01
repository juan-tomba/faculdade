### 1. Formas de Análise
- [cite_start]**Empírico**: Executa e mede o tempo e a memória gastos[cite: 8, 9].
- [cite_start]**Analítico**: Determina uma expressão matemática que descreve o comportamento do algoritmo[cite: 12].
- [cite_start]Foco em **operações**, sendo independente de hardware, SO ou linguagem[cite: 14, 15].

---

### 2. Modelo de Análise Teórica
- [cite_start]**Objetivo**: Estimar qual o melhor algoritmo sem precisar executá-lo[cite: 19].
- [cite_start]Avalia **comportamento assintótico**, válido quando a quantidade de dados cresce[cite: 22, 23].
- [cite_start]**Constantes** aditivas ou multiplicativas são desconsideradas[cite: 24].
- [cite_start]Apenas a **operação dominante** é considerada[cite: 27].

---

### 3. Regras para Cálculo de Complexidade

**Laços (Repetições):**
- [cite_start]Custo = (custo dos comandos internos) × (número de iterações)[cite: 94].

**Laços Aninhados:**
- [cite_start]A análise é feita de **dentro para fora**[cite: 98].
- [cite_start]Custo total = produto do tamanho de todos os laços[cite: 99].
- [cite_start]Exemplo: 2 laços de `n` → **O(n²)**[cite: 101].

**Comandos Consecutivos:**
- [cite_start]Custo total = **soma** dos tempos de cada comando[cite: 108].
- [cite_start]Na notação Big-O, considera-se o **máximo** entre eles[cite: 108].
- [cite_start]Exemplo: `O(n)` seguido de `O(n²)` → **O(n²)**[cite: 109].

**Condicionais (if-else):**
- [cite_start]Custo ≤ (custo do teste) + (custo do **maior caminho** entre `if` e `else`)[cite: 115].

**Chamadas de Sub-rotinas:**
- [cite_start]A sub-rotina é analisada primeiro e seu custo é **incorporado** ao chamador[cite: 124].

---

### 4. Análise de Algoritmos Recursivos
- [cite_start]Recursões simples podem ser um "disfarce" para repetição (Ex: Fatorial → **O(n)**)[cite: 180].
- [cite_start]Casos complexos (dividir-e-conquistar) exigem **análise de recorrência**[cite: 201, 202, 204].
- [cite_start]**Recorrência**: Equação que descreve uma função em termos de seu valor para entradas menores[cite: 203].

---

### 5. Métodos para Resolver Recorrências
- [cite_start]Principais métodos: **Substituição**, **Árvore de Recursão** e **Mestre**[cite: 260].

**Método da Substituição:**
- [cite_start]**1º Passo**: Supor ("chutar") um limite para a função (Ex: `T(n) = O(2ⁿ)`)[cite: 267, 277].
- [cite_start]**2º Passo**: Usar **indução matemática** para provar que o limite é válido[cite: 268].

**Método da Árvore de Recursão:**
- [cite_start]**1º Passo**: Desenhar uma árvore que representa as chamadas recursivas[cite: 370].
- [cite_start]**2º Passo**: Acumular os custos em cada nó e nível da árvore[cite: 371].
- [cite_start]**3º Passo**: Somar todos os custos para obter a estimativa final[cite: 373].
- [cite_start]Usado para fazer uma suposição mais informada para o método da substituição[cite: 374].
- Ex. [cite_start]Busca Binária: `T(n) = T(n/2) + c` → **O(log n)**[cite: 345, 390].
- Ex. [cite_start]Mergesort: `T(n) = 2T(n/2) + n` → **O(n log n)**[cite: 544, 594].