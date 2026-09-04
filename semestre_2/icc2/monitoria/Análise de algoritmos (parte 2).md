

## 1. Abordagens de Avaliação

Existem basicamente duas formas de estimar o tempo de execução de programas para decidir qual é o melhor.

* **Método Empírico:** Consiste em executar o código anotando o tempo de processamento e a quantidade de memória gasta. Como diferentes complexidades geram tempos diferentes, a medição é feita na prática[.
* **Método Analítico ou Teórico:** Determina uma expressão matemática que descreve o comportamento do algoritmo (tempo e memória) baseando-se no número de operações realizadas. Essa contagem independe do computador, sistema operacional ou linguagem de programação.

> **O Modelo Analítico** 
> O objetivo é obter uma expressão sem executar o código, focando apenas no **comportamento assintótico** (quando a quantidade de dados cresce o suficiente). Neste modelo, desconsideram-se constantes aditivas ou multiplicativas e avalia-se apenas a operação dominante[.

---

## 2. Regras Práticas para Cálculo de Complexidade

Para não contar cada instrução individualmente, utilizam-se regras para blocos de código[cite: 1]:

* **Comandos Consecutivos:** O tempo é a soma dos tempos de cada comando[cite: 1]. Em termos assintóticos, isso significa assumir o tempo máximo (maior grandeza) entre eles[cite: 1].
* **Se... então... senão (If/Else):** O tempo de execução nunca ultrapassa o tempo do teste (a condição) somado ao maior tempo entre os comandos do bloco *então* e os comandos do bloco *senão*[cite: 1].
* **Repetições (Laços):** O tempo de execução é pelo menos o tempo dos comandos internos (incluindo os testes do laço) vezes o número de repetições[cite: 1].
* **Repetições Aninhadas:** A análise ocorre sempre de dentro para fora[cite: 1]. Multiplica-se o tempo de execução dos comandos internos pelo produto do tamanho de todas as repetições[cite: 1].
* **Chamadas a Sub-rotinas:** A sub-rotina deve ser analisada isoladamente primeiro; depois, suas unidades de tempo são incorporadas à rotina principal que fez a chamada[cite: 1].

---

## 3. Algoritmos Recursivos e Recorrência

* Se a recursão for apenas um "disfarce" para uma repetição simples, ela é analisada diretamente como um laço comum[cite: 1]. 
* Em algoritmos do tipo **dividir-e-conquistar** (que quebram o problema em subproblemas menores, resolvem-nos e combinam as soluções), costuma ser necessário recorrer à **análise de recorrência**[cite: 1].
* Uma recorrência é uma equação ou desigualdade que descreve uma função em termos de seu valor em entradas menores[cite: 1].

**Exemplos Clássicos Modelados:**
* **Sequência de Fibonacci:** $T(n) = T(n-1) + T(n-2) + 6$, o que resulta em uma complexidade de tempo exponencial $O(2^n)$[cite: 1].
* **Busca Binária:** $T(n) = T(n/2) + O(c)$, resultando em tempo logarítmico $O(\log n)$[cite: 1].
* **Mergesort (Ordenação por Intercalação):** O algoritmo divide o vetor na metade, chama-se recursivamente e depois intercala os resultados[cite: 1]. A equação gerada é $T(n) = 2T(n/2) + n$, resultando em complexidade $O(n \log n)$[cite: 1].

---

## 4. Métodos para Resolução de Recorrências

Quando a complexidade não é trivial, aplicam-se três métodos matemáticos principais para resolver a equação de recorrência[cite: 1]:

### I. Método da Substituição
* Supõe-se um limite superior para a função de tempo (um "palpite" baseado na experiência do analista)[cite: 1].
* Utiliza-se prova por **indução matemática** para verificar se a função não extrapola esse limite[cite: 1].
* Pode-se ir "apertando" o palpite para achar limites mais precisos[cite: 1].

### II. Método da Árvore de Recursão
* Esboça-se uma árvore que representa as chamadas recursivas, nível a nível[cite: 1].
* Em cada nó/nível da árvore, são acumulados os tempos de processamento[cite: 1].
* A estimativa de tempo final é a soma total da árvore (ex: no mergesort, a altura da árvore é $\log n + 1$, e cada nível custa $n$, resultando em $n \log n + n$)[cite: 1].
* Serve também para embasar um palpite inicial mais sólido a ser provado no Método da Substituição[cite: 1].

### III. Método Mestre
Fornece limites diretos para recorrências no formato específico **$T(n) = aT(n/b) + f(n)$**, assumindo constantes $a \ge 1$, $b > 1$ e uma função dada $f(n)$[cite: 1]. A resolução depende de comparar $f(n)$ com a potência $n^{\log_b a}$ através de três casos básicos[cite: 1]:

1. **Caso 1:** Se $f(n) = O(n^{\log_b a - x})$ para algum $x > 0$, então:
   $$T(n) = \Theta(n^{\log_b a})$$[cite: 1]
2. **Caso 2:** Se $f(n) = \Theta(n^{\log_b a})$, então:
   $$T(n) = \Theta(n^{\log_b a} \log n)$$[cite: 1]
3. **Caso 3:** Se $f(n) = \Omega(n^{\log_b a + x})$ para algum $x > 0$, e a condição de regularidade se aplica ($a \cdot f(n/b) \le c \cdot f(n)$ para algum $c < 1$), então:
   $$T(n) = \Theta(f(n))$$[cite: 1]
```