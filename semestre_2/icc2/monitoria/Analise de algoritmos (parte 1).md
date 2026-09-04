
# Análise de Algoritmos — Parte 1

## O que é um algoritmo

Conjunto de instruções bem definidas que transforma uma entrada em uma saída, resolvendo um problema computacional específico. Um bom algoritmo precisa **terminar** e ser **correto** — as duas coisas juntas, porque nada garante que um algoritmo qualquer vá de fato parar.

## Por que só medir tempo de execução não basta

Dizer "meu algoritmo roda em 14,2s e o outro em 42,1s" não significa muita coisa sozinho, porque entram no meio fatores como:

- hardware usado no teste
- linguagem (compilada vs. interpretada, alto vs. baixo nível)
- qualidade da implementação
- quantidade de dados processados

Por isso a área de análise/complexidade de algoritmos busca comparar **algoritmos**, e não **programas** — de forma independente de máquina, linguagem ou habilidade do programador.

## A ideia central

Mede-se a eficiência em função do **tamanho da entrada (n)**, contando o número de operações realizadas — não o tempo real cronometrado. Assume-se que cada operação básica (soma, comparação, atribuição etc.) custa uma unidade de tempo constante; o que muda é a **quantidade de vezes** que ela é executada.

### Exemplo clássico: TripleX vs. SimpleX

- TripleX: f(n) = n² + n
- SimpleX: g(n) = 1000n

Para entradas pequenas o TripleX parece pior, mas a partir de **n = 1000** ele passa a crescer muito mais rápido e vira a pior opção. Isso mostra por que só interessa o comportamento **assintótico** (quando n fica grande), e não pontos isolados das funções.

## Notações assintóticas

| Notação | Significado |
|---|---|
| O(f(n)) | limite superior — taxa de crescimento não maior que f(n) |
| Ω(f(n)) | limite inferior — taxa de crescimento não menor que f(n) |
| Θ(f(n)) | O e Ω valem ao mesmo tempo — taxa de crescimento igual |
| o(f(n)) | crescimento estritamente menor que f(n) |

**Regras práticas:**
- Descarta-se constantes e termos de menor ordem: não se escreve O(2n²) nem O(n²+n), só **O(n²)**.
- Se T(x) é um polinômio de grau n, então T(x) = Θ(xⁿ).
- logᵏn = O(n) para qualquer constante k (logaritmo cresce muito devagar).
- Se T₁(n) = O(f(n)) e T₂(n) = O(g(n)):
  - T₁(n) + T₂(n) = max(O(f(n)), O(g(n))) → laços sequenciais
  - T₁(n) * T₂(n) = O(f(n) * g(n)) → laços aninhados

## Ordem de crescimento (do melhor pro pior)

```
c  <  log n  <  log²n  <  n  <  n log n  <  n²  <  n³  <  2ⁿ  <  aⁿ
```

Exemplo prático: comparando f(n) = n^1.5 com g(n) = n log n, dividindo ambos por n e elevando ao quadrado, conclui-se que n log n cresce mais devagar → é a opção mais eficiente para entradas grandes.

## Modelo de análise usado

- Computador tradicional, instruções executadas sequencialmente, memória infinita (simplificação).
- Cada instrução simples custa 1 unidade de tempo.
- Calcula-se T_melhor(n), T_médio(n) e T_pior(n), sendo sempre T_melhor ≤ T_médio ≤ T_pior.
- **Na prática, usa-se o pior caso (T_pior)**, pois garante um limite válido para qualquer entrada, inclusive as mais desfavoráveis. O caso médio é útil às vezes, mas é mais difícil de calcular.

## Exemplo real: soma da subsequência máxima

Comparando 4 algoritmos diferentes para o mesmo problema:

| Algoritmo | Complexidade | n = 100.000 |
|---|---|---|
| 1 | O(n³) | não termina em tempo viável |
| 2 | O(n²) | não termina em tempo viável |
| 3 | O(n log n) | ~8 segundos |
| 4 | O(n) | ~0,3 segundos |

**Conclusões importantes:**
- Para entradas pequenas, quase não importa qual algoritmo usar — todos rodam rápido.
- Para entradas grandes, a diferença é brutal, e só a análise assintótica prevê isso.