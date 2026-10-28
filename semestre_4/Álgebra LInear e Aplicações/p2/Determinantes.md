## 1. Definição: as 3 propriedades

$\det:\mathbb{M}_n\to\mathbb{R}$ é a **única** função que atribui um número real a cada matriz $n\times n$ e satisfaz:

> [!important] Propriedades que definem o determinante
> 
> - **D1.** $\det(I)=1$.
> - **D2.** Trocar duas linhas **muda o sinal** do determinante.
> - **D3.** O determinante é **linear em relação à primeira linha**.

D3 significa duas coisas (e só vale numa linha por vez, mantendo as outras fixas):

$$ \det\begin{bmatrix}a+a' & b+b' \cr c & d\end{bmatrix}=\det\begin{bmatrix}a & b \cr c & d\end{bmatrix}+\det\begin{bmatrix}a' & b' \cr c & d\end{bmatrix} $$

$$ \det\begin{bmatrix}ta & tb \cr c & d\end{bmatrix}=t,\det\begin{bmatrix}a & b \cr c & d\end{bmatrix} $$

> [!warning] Linear em cada linha, não na matriz toda D3 **não** diz que $\det(A+B)=\det(A)+\det(B)$. Isso é **falso** em geral. A linearidade é só numa linha, com as demais fixas. Como D2 permite trocar a linha 1 com qualquer outra, a linearidade vale para **qualquer linha**.

---

## 2. Propriedades derivadas (P1 a P8)

Cada uma sai das anteriores. Entender a **cadeia** é mais importante que decorar.

### P1. Duas linhas iguais ⇒ $\det=0$

**Por quê.** Trocar as duas linhas iguais não muda a matriz, mas por D2 muda o sinal: $\det=-\det$, logo $\det=0$.

### P2. Somar a uma linha um múltiplo de outra **não altera** o determinante

Esta é a operação da eliminação de Gauss.

**Por quê.** Por D3,

$$ \det\begin{bmatrix}a+tc & b+td \cr c & d\end{bmatrix}=\det\begin{bmatrix}a & b \cr c & d\end{bmatrix}+t\underbrace{\det\begin{bmatrix}c & d \cr c & d\end{bmatrix}}_{=,0\text{ (P1)}} $$

> [!tip] Consequência Toda a eliminação de Gauss **preserva** o determinante. Só as **trocas de linha** mudam o sinal.

### P3. Linha de zeros ⇒ $\det=0$

**Por quê.** Some outra linha qualquer à linha de zeros (P2 diz que o determinante não muda). Agora há duas linhas iguais, e P1 dá $\det=0$.

### P4. Matriz triangular ⇒ $\det$ = produto da diagonal

$$\det(A)=a_{11}a_{22}\cdots a_{nn}$$

**Por quê.** Com operações de linha (que por P2 não alteram o determinante) a matriz vira diagonal. Por D3, cada elemento da diagonal sai como fator, sobrando $a_{11}\cdots a_{nn}\det(I)=a_{11}\cdots a_{nn}$.

> [!note] E se algum $a_{ii}=0$? O notebook supõe $a_{ii}\neq0$ na prova. Se algum for zero, a matriz triangular é singular, tem $\det=0$ (P5), e o produto da diagonal também é zero. A fórmula continua valendo.

### P5. Matriz singular ⇒ $\det=0$

**Por quê.** A eliminação de uma matriz singular produz uma linha de zeros. A eliminação não muda o determinante (P2) e P3 dá $\det=0$.

### P6. Matriz não singular ⇒ $\det$ = produto dos pivôs

**Por quê.** $\det(A)=\det(U)$, porque a eliminação não altera o determinante, e $U$ é triangular, então vale P4.

> [!important] Esta é a forma **prática** de calcular determinantes Elimine até chegar em $U$ e multiplique os pivôs. **Cada troca de linha multiplica o resultado por $-1$.**

### Juntando P5 e P6: o critério de invertibilidade

> [!important] Teste de invertibilidade $$A\text{ é invertível}\iff\det(A)\neq0$$

### P7. $\det(AB)=\det(A)\det(B)$

Em particular, $\det(A^{-1})=\dfrac{1}{\det(A)}$.

**Ideia da prova.**

1. Se $A$ ou $B$ é singular, $AB$ também é, e os dois lados dão zero.
2. Se ambas são invertíveis, defina $f(A)=\dfrac{\det(AB)}{\det(B)}$ e mostre que $f$ satisfaz **D1, D2 e D3**:
    - $f(I)=\det(B)/\det(B)=1$ (D1);
    - trocar duas linhas de $A$ troca as mesmas linhas em $AB$, então o sinal muda (D2);
    - a linha 1 de $AB$ é combinação linear da linha 1 de $A$ com as linhas de $B$, então $f$ é linear na primeira linha (D3).
3. Como o determinante é **a única** função com essas 3 propriedades, $f=\det$, ou seja, $\det(AB)/\det(B)=\det(A)$.

**Para a inversa:** $1=\det(I)=\det(A^{-1}A)=\det(A^{-1})\det(A)$.

> [!warning] Armadilhas
> 
> - $\det(AB)=\det(A)\det(B)$ **sim**, mas $\det(A+B)=\det(A)+\det(B)$ **não**.
> - Se $\det(A)=0$, então $A^{-1}$ não existe, então a fórmula $1/\det(A)$ só faz sentido para $A$ invertível.

### P8. $\det(A^\top)=\det(A)$

**Por quê.**

- Se $A$ é singular, $A^\top$ também é, e ambos valem 0.
- Se não, escreva $PA=LU$. Então $\det(P)\det(A)=\det(L)\det(U)$.
- Transpondo, $A^\top P^\top=U^\top L^\top$, e $\det(A^\top)\det(P^\top)=\det(U^\top)\det(L^\top)$.
- $L$ tem diagonal 1, então $\det(L)=\det(L^\top)=1$. $U$ é triangular, então $\det(U)=\det(U^\top)=$ produto dos pivôs.
- Falta mostrar $\det(P)=\det(P^\top)$. Como $PP^\top=I$, vale $\det(P)\det(P^\top)=1$. Além disso, $\det(P)=\pm1$ (identidade com linhas trocadas). Se o produto de dois números $\pm1$ é 1, eles são iguais.

> [!important] Consequência enorme **Tudo o que vale para linhas vale para colunas.**
> 
> - Duas colunas iguais ⇒ $\det=0$.
> - Trocar duas colunas muda o sinal.
> - Coluna de zeros ⇒ $\det=0$.
> - O determinante é linear em cada coluna.

---

## 3. Calculando: fórmulas e exemplo

### Matrizes 2×2 e 3×3

$$\det\begin{bmatrix}a & b \cr c & d\end{bmatrix}=ad-bc$$

Para $3\times3$, são 6 termos (os 3 "diagonais" com sinal +, os 3 "anti-diagonais" com sinal −):

$$\det(A)=a_{11}a_{22}a_{33}+a_{12}a_{23}a_{31}+a_{13}a_{21}a_{32}-a_{13}a_{22}a_{31}-a_{12}a_{21}a_{33}-a_{11}a_{23}a_{32}$$

### A fórmula geral

Aplicando a linearidade (D3) linha por linha, o determinante vira uma soma de termos, um para cada **matriz de permutação** $P$:

$$\det(A)=\sum_{P}a_{1i}a_{2j}\cdots a_{ns},\det(P)$$

Cada termo escolhe **um elemento de cada linha e de cada coluna**, e o sinal é $\det(P)=\pm1$. Há **$n!$ termos**.

> [!warning] Por que não se usa na prática $n!$ explode: para $n=10$ são mais de 3,6 milhões de termos. Para matrizes grandes, use a eliminação (P6).

### Exemplo: via eliminação

$$A=\begin{bmatrix}2 & 1 & 1 \cr 4 & 3 & 3 \cr 8 & 7 & 9\end{bmatrix};\longrightarrow;U=\begin{bmatrix}2 & 1 & 1 \cr 0 & 1 & 1 \cr 0 & 0 & 2\end{bmatrix}$$

Sem trocas de linha: $\det(A)=2\cdot1\cdot2=4$.

### Com troca de linhas

$PA=LU$ dá $\det(P)\det(A)=\det(U)$, ou seja,

$$\det(A)=\det(P)\cdot(\text{produto dos pivôs}),\qquad\det(P)=\pm1$$

O sinal depende do número de trocas: número **par** de trocas dá $+1$, **ímpar** dá $-1$.

---

## 4. Cofatores

Para um elemento $a_{ij}$, o **cofator** é

$$C_{ij}=(-1)^{i+j}\det(M_{ij})$$

onde $M_{ij}$ é a submatriz $(n-1)\times(n-1)$ obtida **removendo a linha $i$ e a coluna $j$**.

O sinal $(-1)^{i+j}$ segue o padrão de tabuleiro de xadrez:

$$\begin{bmatrix}+ & - & + \cr - & + & - \cr + & - & +\end{bmatrix}$$

> [!example] Exemplo (3×3) $C_{11}=(+1)\det\begin{bmatrix}a_{22} & a_{23} \cr a_{32} & a_{33}\end{bmatrix}$ e $C_{22}=(+1)\det\begin{bmatrix}a_{11} & a_{13} \cr a_{31} & a_{33}\end{bmatrix}$.

> [!note] Erro de digitação no notebook No notebook, $C_{22}$ aparece com a submatriz $\begin{bmatrix}a_{11} & a_{33} \cr a_{31} & a_{33}\end{bmatrix}$. O correto é $a_{13}$ no canto superior direito (removendo a linha 2 e a coluna 2 sobram as colunas 1 e 3).

### P9. Expansão por cofatores

$$\det(A)=a_{i1}C_{i1}+a_{i2}C_{i2}+\cdots+a_{in}C_{in}\qquad\text{para qualquer linha }i$$

Sai direto da fórmula geral: agrupam-se os termos pelo elemento escolhido na linha $i$. Por P8, **também vale expandindo por qualquer coluna**.

> [!tip] Estratégia prática Expanda pela **linha ou coluna com mais zeros**: cada zero elimina um cofator inteiro.

---

## 5. Inversa por cofatores

### P10

$$A^{-1}=\frac{C^\top}{\det(A)}\qquad\Longleftrightarrow\qquad(A^{-1})_{ij}=\frac{C_{ji}}{\det(A)}$$

onde $C$ é a matriz de todos os cofatores. Repare na **transposição**: o elemento $(i,j)$ da inversa usa o cofator $C_{ji}$.

**Ideia da prova.** Mostra-se que $AC^\top=\det(A),I$:

- **Diagonal:** o elemento $(i,i)$ é $a_{i1}C_{i1}+\cdots+a_{in}C_{in}=\det(A)$, pela expansão P9.
- **Fora da diagonal:** o elemento $(i,k)$ com $i\neq k$ é uma expansão por cofatores usando a linha $i$ mas com os cofatores da linha $k$. Isso equivale ao determinante de uma matriz em que **a linha $k$ foi substituída por uma cópia da linha $i$**, ou seja, com duas linhas iguais, e por P1 vale 0.

Logo $AC^\top=\det(A)I$, e dividindo por $\det(A)$ (que precisa ser $\neq0$) sai a inversa.

> [!example] Caso 2×2 (para decorar) $$\begin{bmatrix}a & b \cr c & d\end{bmatrix}^{-1}=\frac{1}{ad-bc}\begin{bmatrix}d & -b \cr -c & a\end{bmatrix}$$ Trocam-se os elementos da diagonal, invertem-se os sinais da outra diagonal e divide-se pelo determinante.

> [!warning] Aplicação teórica A fórmula é elegante, mas **cara** para calcular. Na prática, a inversa vem da LU (resolvendo $n$ sistemas). O valor de P10 é teórico e aparece na prova do Cramer.

---

## 6. Regra de Cramer

Para $A\mathbf{x}=\mathbf{b}$ com $A$ invertível:

$$x_j=\frac{\det(B_j)}{\det(A)}$$

onde $B_j$ é a matriz $A$ com a **$j$-ésima coluna substituída por $\mathbf{b}$**.

**Por quê.** Temos $\mathbf{x}=A^{-1}\mathbf{b}=\dfrac{C^\top\mathbf{b}}{\det(A)}$, então

$$x_j=\frac{C_{1j}b_1+C_{2j}b_2+\cdots+C_{nj}b_n}{\det(A)}.$$

O numerador é exatamente a **expansão por cofatores da coluna $j$** de $B_j$ (os cofatores $C_{ij}$ de $B_j$ e de $A$ coincidem, porque ambas só diferem na coluna $j$, que é removida no cálculo). Logo ele vale $\det(B_j)$.

> [!example] Exemplo 2×2 Para $\begin{cases}x+2y=3\cr 4x+5y=6\end{cases}$, temos $\det(A)=5-8=-3$. $x=\dfrac{\det\begin{bmatrix}3 & 2 \cr 6 & 5\end{bmatrix}}{-3}=\dfrac{3}{-3}=-1$ e $y=\dfrac{\det\begin{bmatrix}1 & 3 \cr 4 & 6\end{bmatrix}}{-3}=\dfrac{-6}{-3}=2$.

> [!warning] Quando usar
> 
> - Só funciona se $\det(A)\neq0$ (solução única).
> - É **muito caro** para matrizes grandes, e serve mais como resultado teórico.
> - Dá uma fórmula explícita para cada incógnita.

---

## 7. Determinantes e volumes

> [!important] Interpretação geométrica O **volume do paralelepípedo** cujas arestas são as colunas de $A$ é $|\det(A)|$.
> 
> - 2×2: área do paralelogramo.
> - 3×3: volume do paralelepípedo.
> - $n\times n$: "hipervolume" em $\mathbb{R}^n$.

**Caso com colunas ortogonais.** Se as colunas são ortogonais, a "caixa" é retangular, com volume $l_1l_2\cdots l_n$, onde $l_i=|\text{coluna }i|$.

Calculando $AA^\top$ (com colunas ortogonais, o produto $A^\top A$ é diagonal; o notebook usa $AA^\top$, que dá o mesmo determinante):

$$\det(AA^\top)=l_1^2\cdots l_n^2$$

Por P7 e P8,

$$\det(A)\det(A^\top)=\det(A)^2=l_1^2\cdots l_n^2\quad\Longrightarrow\quad|\det(A)|=l_1l_2\cdots l_n$$

> [!note] O sinal A conta dá $\det(A)^2=\ldots$, então $\det(A)=\pm l_1\cdots l_n$. O volume é o **valor absoluto**. O sinal do determinante indica a **orientação** (trocar duas colunas inverte o sinal sem mudar o volume).

O professor menciona que o resultado também vale quando as colunas **não** são ortogonais, mas não demonstra.

> [!tip] Conexão com invertibilidade $\det(A)=0$ significa volume zero: a caixa **colapsa**, ou seja, as colunas são **LD** e ficam todas num subespaço de dimensão menor. É a mesma ideia de matriz singular, vista geometricamente.

---

## 8. Determinante e o resto do curso

Para $A$ quadrada $n\times n$, as afirmações abaixo são **todas equivalentes**:

> [!important] Equivalências para matriz quadrada
> 
> - $A$ é invertível
> - $\det(A)\neq0$
> - $U$ tem $n$ pivôs (diagonal sem zeros)
> - O posto é $n$
> - As colunas (e as linhas) são LI
> - $N(A)={\mathbf{0}}$
> - $A\mathbf{x}=\mathbf{b}$ tem solução única para todo $\mathbf{b}$
> - O volume da caixa das colunas é diferente de zero

Se uma falha, todas falham, e então $\det(A)=0$.

---

## Resumo rápido

|Fato|Fórmula ou regra|
|---|---|
|Definição|D1: $\det I=1$; D2: troca de linhas inverte o sinal; D3: linear na linha|
|Duas linhas iguais|$\det=0$|
|Linha de zeros|$\det=0$|
|Somar múltiplo de uma linha em outra|não altera $\det$|
|Trocar duas linhas|multiplica $\det$ por $-1$|
|Matriz triangular|$\det$ = produto da diagonal|
|Singular|$\det=0$|
|Não singular|$\det$ = produto dos pivôs (com sinal das trocas)|
|Produto|$\det(AB)=\det A,\det B$|
|Inversa|$\det(A^{-1})=1/\det A$|
|Transposta|$\det(A^\top)=\det A$|
|Expansão por cofatores|$\det A=\sum_j a_{ij}C_{ij}$ (qualquer linha ou coluna)|
|Cofator|$C_{ij}=(-1)^{i+j}\det(M_{ij})$|
|Inversa por cofatores|$A^{-1}=C^\top/\det A$|
|Cramer|$x_j=\det(B_j)/\det(A)$|
|Volume|$\mathrm{vol}=\lvert\det A\rvert$|
|Número de termos da fórmula geral|$n!$|

> [!note] Fatos extras (não estão no notebook, mas decorrem de D3 e P7)
> 
> - $\det(cA)=c^n\det(A)$ para $A$ de tamanho $n\times n$: cada uma das $n$ linhas tem o fator $c$ que sai por D3.
> - $\det(A^k)=\det(A)^k$.
> - Matriz ortogonal: $\det(Q)=\pm1$, pois $\det(Q)^2=\det(Q^\top Q)=\det I=1$.

---

## Possíveis perguntas de prova

O professor cobra conceitos, então tente responder antes de abrir.

> [!question]- Quais propriedades definem o determinante? D1, $\det(I)=1$; D2, o sinal muda ao trocar duas linhas; D3, linearidade em relação à primeira linha (e, por D2, em relação a qualquer linha).

> [!question]- Por que uma matriz com duas linhas iguais tem determinante zero? Trocar essas linhas não altera a matriz, mas por D2 inverte o sinal do determinante. Então $\det=-\det$, ou seja, $\det=0$.

> [!question]- A eliminação de Gauss altera o determinante? Somar um múltiplo de uma linha a outra **não altera** (P2). Trocar linhas **inverte o sinal**. Multiplicar uma linha por $t$ multiplica o determinante por $t$.

> [!question]- Como calcular o determinante usando a eliminação? Faça a eliminação até obter $U$ e multiplique os pivôs da diagonal. Cada troca de linhas multiplica o resultado por $-1$, o que aparece como $\det(P)=\pm1$ em $PA=LU$.

> [!question]- Qual a relação entre determinante e invertibilidade? $A$ é invertível se e somente se $\det(A)\neq0$. Se $A$ é singular, a eliminação gera uma linha de zeros e $\det=0$. Se não é, o determinante é o produto dos pivôs, todos não nulos.

> [!question]- Por que $\det(A^{-1})=1/\det(A)$? De $A^{-1}A=I$ e $\det(AB)=\det A\det B$: $\det(A^{-1})\det(A)=\det(I)=1$.

> [!question]- Por que $\det(A^\top)=\det(A)$ é importante? Porque faz tudo o que vale para linhas valer para colunas: duas colunas iguais dão $\det=0$, trocar colunas inverte o sinal, e a expansão por cofatores pode ser feita por colunas.

> [!question]- Como a fórmula do determinante dá $n!$ termos? Aplicando a linearidade linha por linha, sobram apenas as combinações que escolhem um elemento em cada linha e em cada coluna. Cada escolha corresponde a uma matriz de permutação, e há $n!$ delas.

> [!question]- O que é o cofator $C_{ij}$? É $(-1)^{i+j}\det(M_{ij})$, onde $M_{ij}$ é a submatriz obtida removendo a linha $i$ e a coluna $j$.

> [!question]- Como se calcula a inversa usando cofatores? $A^{-1}=\dfrac{C^\top}{\det A}$, onde $C$ é a matriz dos cofatores. Há uma transposição: $(A^{-1})_{ij}=C_{ji}/\det A$.

> [!question]- Por que $AC^\top=\det(A)I$? Na diagonal, cada elemento é uma expansão por cofatores, que vale $\det A$. Fora da diagonal, é a expansão de uma matriz com duas linhas iguais, que vale zero.

> [!question]- Enuncie a regra de Cramer e explique de onde vem. $x_j=\det(B_j)/\det(A)$, onde $B_j$ é $A$ com a coluna $j$ trocada por $\mathbf{b}$. Vem de $\mathbf{x}=A^{-1}\mathbf{b}=C^\top\mathbf{b}/\det A$: o numerador de $x_j$ é a expansão por cofatores da coluna $j$ de $B_j$.

> [!question]- Qual a interpretação geométrica do determinante? $|\det A|$ é o volume do paralelepípedo cujas arestas são as colunas de $A$. Determinante zero significa que o volume colapsa: as colunas são LD.

> [!question]- V ou F: $\det(A+B)=\det(A)+\det(B)$. **F.** O determinante é linear apenas em **uma linha por vez**. O que vale é $\det(AB)=\det(A)\det(B)$.

> [!question]- V ou F: se $\det(A)=0$, então $A\mathbf{x}=\mathbf{b}$ não tem solução. **F.** Pode ter infinitas soluções (se $\mathbf{b}\in C(A)$) ou nenhuma (se $\mathbf{b}\notin C(A)$). O que se garante é que **não há solução única**.

> [!question]- V ou F: se $A$ é triangular com algum zero na diagonal, então $\det(A)=0$. **V.** O determinante é o produto da diagonal, e um fator é zero. Além disso, essa matriz é singular.

> [!question]- V ou F: trocar duas colunas de uma matriz não altera o determinante. **F.** Muda o sinal, como acontece com linhas (consequência de $\det A^\top=\det A$).