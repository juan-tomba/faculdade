
## 1. Vetores ortogonais

O produto escalar pode ser escrito como um produto de matrizes, tratando vetores como colunas:

$$\langle\mathbf{u},\mathbf{v}\rangle=\mathbf{u}^\top\mathbf{v}=\mathbf{v}^\top\mathbf{u}$$

- $\mathbf{u}^\top\mathbf{v}=0$: os vetores são **ortogonais** (90°).
- $\mathbf{u}^\top\mathbf{v}>0$: o ângulo é menor que 90°.
- $\mathbf{u}^\top\mathbf{v}<0$: o ângulo é maior que 90°.

### Ortogonais ⇒ LI

> [!important] Propriedade Vetores **não nulos** e ortogonais dois a dois são sempre **LI**.

**Por quê.** Parta de $c_1\mathbf{u}_1+\cdots+c_k\mathbf{u}_k=\mathbf{0}$ e multiplique os dois lados por $\mathbf{u}_i^\top$. Todos os termos $\mathbf{u}_i^\top\mathbf{u}_j$ com $j\neq i$ valem zero, e sobra

$$c_i,\mathbf{u}_i^\top\mathbf{u}_i=0.$$

Como $\mathbf{u}_i^\top\mathbf{u}_i=|\mathbf{u}_i|^2\neq0$, conclui-se que $c_i=0$. Isso vale para todo $i$. ∎

> [!warning] A volta é falsa Vetores LI não precisam ser ortogonais. Por exemplo, $(1,0)$ e $(1,1)$ são LI, mas não são perpendiculares.

---

## 2. Subespaços ortogonais

Dois subespaços $\mathcal{S}_1$ e $\mathcal{S}_2$ são **ortogonais** quando **todo** vetor de um é ortogonal a **todo** vetor do outro.

Em $\mathbb{R}^3$:

- duas retas podem ser ortogonais;
- uma reta e um plano podem ser ortogonais;
- **dois planos nunca são subespaços ortogonais.**

> [!question]- Por que dois planos em ℝ³ nunca são ortogonais? Dois planos que passam pela origem sempre se cruzam numa reta, porque $2+2>3$. Um vetor $\mathbf{v}\neq\mathbf{0}$ dessa reta pertence aos dois planos. Se os planos fossem ortogonais, teríamos $\mathbf{v}^\top\mathbf{v}=0$, ou seja, $\mathbf{v}=\mathbf{0}$, o que é uma contradição. (Dois planos _geometricamente_ perpendiculares, como uma parede e o chão, não são subespaços ortogonais nesse sentido.)

### Espaço linha ⊥ espaço nulo

Se $A\mathbf{x}=\mathbf{0}$, cada entrada do produto é o produto escalar de uma linha de $A$ com $\mathbf{x}$:

$$A\mathbf{x}=\begin{bmatrix}\mathbf{a}_1^\top\mathbf{x}\\vdots\\mathbf{a}_m^\top\mathbf{x}\end{bmatrix}=\begin{bmatrix}0\\vdots\0\end{bmatrix}$$

Então $\mathbf{x}$ é ortogonal a **todas as linhas** de $A$, e portanto a qualquer combinação delas, ou seja, a todo o espaço linha.

> [!important] Conclusão $N(A)\perp C(A^\top)$. Aplicando o mesmo raciocínio a $A^\top$: $N(A^\top)\perp C(A)$.

> [!example] Exemplo do notebook $A=\begin{bmatrix}1&0&1\end{bmatrix}$. O espaço linha tem dimensão 1, então $\dim N(A)=3-1=2$. Os vetores do núcleo são exatamente os ortogonais a $(1,0,1)$, como $(1,0,-1)$ e $(0,1,0)$. Truque útil: para achar $N(A)$, procure vetores perpendiculares às linhas.

---

## 3. Complemento ortogonal

O **complemento ortogonal** $\mathcal{S}^\perp$ é o conjunto de **todos** os vetores ortogonais a $\mathcal{S}$.

> [!important] Quando $\mathcal{S}_1$ e $\mathcal{S}_2$ são complementos ortogonais em $\mathbb{R}^n$
> 
> 1. São ortogonais entre si.
> 2. $\dim\mathcal{S}_1+\dim\mathcal{S}_2=n$.

Ser ortogonal **não basta**: as dimensões também precisam completar o espaço.

> [!question]- Por que as retas geradas por $(1,0,0)$ e $(0,1,0)$ são ortogonais mas não são complementos? Elas são ortogonais, mas $1+1=2\neq3$. O complemento de uma reta em $\mathbb{R}^3$ é um **plano**: o complemento do eixo $x$ é o plano $yz$ inteiro, não só o eixo $y$. Por exemplo, $(0,0,1)$ é ortogonal ao eixo $x$, mas não está no eixo $y$.

---

## 4. Teorema Fundamental da Álgebra Linear

Para qualquer $A_{m\times n}$ de posto $r$:

|Em $\mathbb{R}^n$|Em $\mathbb{R}^m$|
|---|---|
|$C(A^\top)$, dim $r$|$C(A)$, dim $r$|
|$N(A)$, dim $n-r$|$N(A^\top)$, dim $m-r$|
|**complementos ortogonais** ($r+(n-r)=n$)|**complementos ortogonais** ($r+(m-r)=m$)|

> [!important] Teorema
> 
> 1. O espaço linha $C(A^\top)$ é o complemento ortogonal do espaço nulo $N(A)$.
> 2. O espaço coluna $C(A)$ é o complemento ortogonal do espaço nulo à esquerda $N(A^\top)$.

A prova junta duas coisas já vistas: os espaços são ortogonais (seção 2), e as dimensões somam $n$ (ou $m$) pelo teorema do núcleo e da imagem.

### Como $A$ mapeia os espaços

Todo $\mathbf{x}\in\mathbb{R}^n$ se decompõe em uma parte no espaço linha e outra no núcleo:

$$\mathbf{x}=\underbrace{\mathbf{u}}_{\in C(A^\top)}+\underbrace{\mathbf{v}}_{\in N(A)}\quad\Rightarrow\quad A\mathbf{x}=A\mathbf{u}+\underbrace{A\mathbf{v}}_{=,\mathbf{0}}=A\mathbf{u}$$

> [!tip] Resumo do mapeamento
> 
> - $A$ leva o **espaço linha** no **espaço coluna**, e essa correspondência é **bijetiva**.
> - A parte de $\mathbf{x}$ que está no **núcleo** vai para a **origem** de $\mathbb{R}^m$.
> - Toda a "informação" que $A$ preserva está na parte de $\mathbf{x}$ que mora no espaço linha.

---

## 5. Bases ortonormais e matrizes ortogonais

Uma base $\mathbf{q}_1,\dots,\mathbf{q}_k$ é **ortonormal** quando os vetores são ortogonais entre si e têm norma 1:

$$\mathbf{q}_i^\top\mathbf{q}_j=\begin{cases}0 & i\neq j\1 & i=j\end{cases}$$

Uma base **ortogonal** dividida pelas normas vira **ortonormal**.

### Matriz com colunas ortonormais

Se as colunas de $Q$ são ortonormais, então

$$Q^\top Q=I.$$

Se $Q$ for **quadrada**, ela se chama **matriz ortogonal**, e nesse caso:

- $Q^{-1}=Q^\top$: inverter é só transpor;
- $QQ^\top=I$ também, então **as linhas também são ortonormais**.

> [!warning] Cuidado Se $Q$ não é quadrada, vale $Q^\top Q=I$, mas **não** $QQ^\top=I$.

### Propriedades

**1. Preserva comprimento:** $|Q\mathbf{x}|=|\mathbf{x}|$. A conta é

$$|Q\mathbf{x}|^2=(Q\mathbf{x})^\top(Q\mathbf{x})=\mathbf{x}^\top Q^\top Q\mathbf{x}=\mathbf{x}^\top\mathbf{x}=|\mathbf{x}|^2.$$

Exemplos de transformações assim são rotações e reflexões.

**2. Coordenadas por produto escalar.** Se $\mathbf{x}=c_1\mathbf{q}_1+\cdots+c_k\mathbf{q}_k$ com base ortonormal, então

$$c_i=\mathbf{q}_i^\top\mathbf{x}.$$

Para conferir, multiplique por $\mathbf{q}_i^\top$: todos os outros termos somem e sobra $c_i,\mathbf{q}_i^\top\mathbf{q}_i=c_i$.

> [!tip] Por que bases ortonormais são boas Numa base qualquer, achar as coordenadas exige **resolver um sistema**. Numa base ortonormal, basta fazer **produtos escalares**.

---

## 6. Gram-Schmidt e fatoração QR

### Gram-Schmidt

O processo transforma uma base qualquer $\mathbf{u}_1,\dots,\mathbf{u}_k$ numa base **ortonormal** $\mathbf{q}_1,\dots,\mathbf{q}_k$ do **mesmo espaço**.

A ideia: de cada vetor, **retire as componentes nas direções já construídas** (as projeções) e normalize o que sobrar.

$$\mathbf{q}_1=\frac{\mathbf{u}_1}{|\mathbf{u}_1|}$$

$$\tilde{\mathbf{q}}_2=\mathbf{u}_2-(\mathbf{u}_2^\top\mathbf{q}_1)\mathbf{q}_1,\qquad \mathbf{q}_2=\frac{\tilde{\mathbf{q}}_2}{|\tilde{\mathbf{q}}_2|}$$

Caso geral:

$$\tilde{\mathbf{q}}_i=\mathbf{u}_i-\sum_{j=1}^{i-1}(\mathbf{u}_i^\top\mathbf{q}_j),\mathbf{q}_j,\qquad \mathbf{q}_i=\frac{\tilde{\mathbf{q}}_i}{|\tilde{\mathbf{q}}_i|}$$

O termo $(\mathbf{u}_i^\top\mathbf{q}_j)\mathbf{q}_j$ é a **projeção** de $\mathbf{u}_i$ na direção $\mathbf{q}_j$. Depois de subtrair todas essas projeções, o que sobra é perpendicular a todos os $\mathbf{q}$ anteriores.

### Fatoração QR

Isolando cada $\mathbf{u}_i$ nas fórmulas do Gram-Schmidt, ele aparece como combinação de $\mathbf{q}_1,\dots,\mathbf{q}_i$ (só os vetores até o índice $i$):

$$\mathbf{u}_i=r_{1i}\mathbf{q}_1+\cdots+r_{ii}\mathbf{q}_i$$

Em forma de matriz:

$$\underbrace{\begin{bmatrix}|&&|\\mathbf{u}_1&\cdots&\mathbf{u}_k\|&&|\end{bmatrix}}_{A}=\underbrace{\begin{bmatrix}|&&|\\mathbf{q}_1&\cdots&\mathbf{q}_k\|&&|\end{bmatrix}}_{Q}\underbrace{\begin{bmatrix}r_{11}&r_{12}&\cdots&r_{1k}\0&r_{22}&\cdots&r_{2k}\\vdots&&\ddots&\vdots\0&0&\cdots&r_{kk}\end{bmatrix}}_{R}$$

- **$Q$** tem colunas ortonormais e o **mesmo espaço coluna** de $A$.
- **$R$** é **triangular superior**. Fora da diagonal, $r_{ji}=\mathbf{q}_j^\top\mathbf{u}_i$. Na diagonal, $r_{ii}=|\tilde{\mathbf{q}}_i|$.
- Cada coluna $\mathbf{a}_i$ de $A$ é combinação das colunas de $Q$, com coeficientes dados pela coluna $i$ de $R$.

> [!tip] Para que serve
> 
> - QR de $A$ dá uma **base ortonormal de $C(A)$**.
> - QR de $A^\top$ dá uma **base ortonormal do espaço linha**.
> - A QR "completa" (`mode='complete'` no numpy) gera vetores extras, que formam uma base ortonormal do **complemento**: $N(A^\top)$, ou $N(A)$ se aplicada em $A^\top$.

> [!note] Comparando com a LU Na LU, temos $L$ triangular inferior e $U$ triangular superior, e a fatoração serve para resolver sistemas. Na QR, temos $Q$ ortonormal e $R$ triangular superior, e a fatoração serve para construir bases ortonormais.

---

## 7. Mínimos quadrados e a equação normal

> [!warning] Notação do notebook Aqui $A$ tem **$n$ linhas e $k$ colunas**, com $n\geq k$: mais equações que incógnitas.

**O problema.** $A\mathbf{x}=\mathbf{b}$ só tem solução se $\mathbf{b}\in C(A)$. Com muitas equações, como ao ajustar uma reta a 100 pontos, quase sempre $\mathbf{b}\notin C(A)$ e o sistema **não tem solução**.

**A ideia.** Em vez de resolver exatamente, buscamos o $\mathbf{x}$ que **minimiza o erro**:

$$\min_{\mathbf{x}}|A\mathbf{x}-\mathbf{b}|^2$$

**A geometria.** $A\mathbf{x}$ percorre o espaço coluna, então queremos o ponto $\mathbf{p}=A\mathbf{x}$ de $C(A)$ **mais próximo de $\mathbf{b}$**. O ponto mais próximo é aquele em que o erro $\mathbf{e}=\mathbf{b}-\mathbf{p}$ é **perpendicular** a $C(A)$.

> [!question]- Por que o erro tem que ser perpendicular a C(A)? Pense num triângulo retângulo. Se $\mathbf{b}-\mathbf{p}\perp C(A)$, então para qualquer outro ponto $\mathbf{y}\in C(A)$, Pitágoras dá $|\mathbf{b}-\mathbf{y}|^2=|\mathbf{b}-\mathbf{p}|^2+|\mathbf{p}-\mathbf{y}|^2\geq|\mathbf{b}-\mathbf{p}|^2$. Ou seja, qualquer outro ponto está mais longe. A distância mínima de um ponto a um plano é sempre medida na direção perpendicular.

**Dedução da equação normal.** Perpendicular a $C(A)$ significa perpendicular a todas as colunas de $A$:

$$A^\top(\mathbf{b}-A\mathbf{x})=\mathbf{0}\quad\Longrightarrow\quad \boxed{A^\top A,\mathbf{x}=A^\top\mathbf{b}}$$

Essa é a **equação normal**. $A^\top A$ é uma matriz quadrada $k\times k$.

> [!tip] Ligação com o Teorema Fundamental A condição $A^\top\mathbf{e}=\mathbf{0}$ diz que o erro $\mathbf{e}$ está em $N(A^\top)$, que é o complemento ortogonal de $C(A)$. O vetor $\mathbf{b}$ se decompõe em uma parte em $C(A)$ (a projeção $\mathbf{p}$) e uma parte em $N(A^\top)$ (o erro $\mathbf{e}$).

### Quando a equação normal tem solução única?

> [!important] Propriedade $N(A^\top A)=N(A)$.

**Prova.** Se $A\mathbf{x}=\mathbf{0}$, então $A^\top A\mathbf{x}=\mathbf{0}$. Na outra direção, se $A^\top A\mathbf{x}=\mathbf{0}$, multiplicando por $\mathbf{x}^\top$ vem $\mathbf{x}^\top A^\top A\mathbf{x}=|A\mathbf{x}|^2=0$, e portanto $A\mathbf{x}=\mathbf{0}$. ∎

Conclusão: **se as colunas de $A$ são LI**, então $N(A)={\mathbf{0}}$, logo $N(A^\top A)={\mathbf{0}}$ e $A^\top A$ é **invertível**. A equação normal tem solução única:

$$\mathbf{x}=(A^\top A)^{-1}A^\top\mathbf{b}$$

> [!warning] Confusão comum O $\mathbf{x}$ obtido **não** é um ponto do espaço coluna. Ele são os **coeficientes** da combinação das colunas. O ponto projetado é $\mathbf{p}=A\mathbf{x}$.

---

## 8. Projeção em subespaços

Substituindo $\mathbf{x}$ em $\mathbf{p}=A\mathbf{x}$:

$$\mathbf{p}=\underbrace{A(A^\top A)^{-1}A^\top}_{P},\mathbf{b}$$

$P=A(A^\top A)^{-1}A^\top$ é a **matriz de projeção** sobre $C(A)$: ela projeta qualquer vetor no espaço coluna.

> [!note] Propriedades extras (não estão no notebook, mas são clássicas)
> 
> - $P^2=P$: projetar duas vezes não muda nada.
> - $P^\top=P$: a matriz é simétrica.
> - Com base ortonormal ($A=Q$), $Q^\top Q=I$ e a fórmula fica $P=QQ^\top$.
> - Projeção numa reta (uma coluna $\mathbf{a}$): $\mathbf{p}=\dfrac{\mathbf{a}^\top\mathbf{b}}{\mathbf{a}^\top\mathbf{a}},\mathbf{a}$, a mesma fórmula da geometria analítica.

> [!warning] Não confunda as letras Essa $P$ (projeção) não tem nada a ver com a $P$ de permutação da LU.

> [!example] Exemplo do notebook Para projetar pontos de $\mathbb{R}^3$ no plano $x+y+z=0$:
> 
> 1. Ache uma base do plano e coloque-a nas colunas de $A$, por exemplo $(1,0,-1)$ e $(0,-1,1)$.
> 2. Resolva $A^\top A\mathbf{x}=A^\top\mathbf{b}$.
> 3. A projeção é $\mathbf{p}=A\mathbf{x}$.

---

## 9. Aproximação de funções (ajuste de curvas)

Temos amostras $(t_i, f(t_i))$, $i=1,\dots,n$, e queremos uma função que passe "perto" de todas.

### Reta: $f(t)=a_1+a_2t$

Queremos $a_1+a_2t_i\approx f(t_i)$ para todo $i$. Em forma de matriz:

$$\underbrace{\begin{bmatrix}1&t_1\1&t_2\\vdots&\vdots\1&t_n\end{bmatrix}}_{A}\underbrace{\begin{bmatrix}a_1\a_2\end{bmatrix}}_{\boldsymbol\alpha}\approx\underbrace{\begin{bmatrix}f(t_1)\\vdots\f(t_n)\end{bmatrix}}_{\mathbf{f}}$$

São $n$ equações e só 2 incógnitas, então não há solução exata. Resolve-se a equação normal $A^\top A\boldsymbol\alpha=A^\top\mathbf{f}$.

Geometricamente, as 2 colunas de $A$ geram um plano dentro de $\mathbb{R}^n$, e projetamos $\mathbf{f}$ nesse plano.

### Outras funções

O método funciona para **qualquer função que seja linear nos coeficientes**. Basta trocar as colunas de $A$:

- cúbica, $a_0+a_1t+a_2t^2+a_3t^3$: colunas $1,\ t_i,\ t_i^2,\ t_i^3$;
- trigonométrica, $a_0+a_1\sin t+a_2\cos t$: colunas $1,\ \sin t_i,\ \cos t_i$.

> [!tip] Ponto-chave A função pode ser não linear em $t$. O que precisa ser **linear** é a dependência nos **coeficientes** $a_i$. Cada coluna de $A$ é uma "função base" avaliada nos pontos.

### Erro médio quadrático

$$\text{Erro}=\frac{1}{n}|A\boldsymbol\alpha-\mathbf{f}|^2$$

O $\boldsymbol\alpha$ dos mínimos quadrados dá o **menor erro possível** entre todos os $\boldsymbol\alpha$.

---

## 10. Mínimos quadrados ponderados

**O problema.** O método é **muito sensível a outliers**: poucos pontos ruins "puxam" a curva, porque o erro é elevado ao quadrado e pesa muito.

**A solução.** Dar **pesos** aos pontos com uma matriz diagonal $W$ e minimizar $|W(A\boldsymbol\alpha-\mathbf{f})|^2$. Isso leva a

$$A^\top W^\top W A,\boldsymbol\alpha=A^\top W^\top W,\mathbf{f}$$

**Como escolher os pesos** (abordagem do notebook):

1. Resolva os mínimos quadrados comuns.
2. Calcule o erro de cada ponto.
3. Dê **peso maior a pontos com erro menor**, por exemplo $w_i=e^{-\text{erro}_i^2}$.
4. Resolva de novo com os pesos.

---

## 11. Pseudoinversa de Moore-Penrose

Para $A$ com mais linhas que colunas e **colunas LI** ($A^\top A$ invertível):

$$A^+=(A^\top A)^{-1}A^\top$$

É exatamente a matriz que aparece na solução dos mínimos quadrados: $\mathbf{x}=A^+\mathbf{b}$.

Ela satisfaz as 4 condições de Moore-Penrose:

1. $AA^+A=A$
2. $A^+AA^+=A^+$
3. $(AA^+)^\top=AA^+$
4. $(A^+A)^\top=A^+A$

Com as colunas LI, vale $A^+A=I$. A pseudoinversa é **única**.

> [!note] Erro de digitação no notebook O teorema no notebook diz "se $(A^\top A)^{-1}A^\top$ é invertível". O correto é "se **$A^\top A$** é invertível".

> [!tip] Interpretação geométrica $A$ é uma **bijeção** entre o espaço linha e o espaço coluna. É injetiva porque, se $A\mathbf{v}_1=A\mathbf{v}_2$ com os dois vetores no espaço linha, então $\mathbf{v}_1-\mathbf{v}_2$ está no núcleo e no espaço linha ao mesmo tempo, e o único vetor assim é o zero. Por isso existe o caminho de volta: $A^+$ leva $\mathbf{u}=A\mathbf{v}$ de volta a $\mathbf{v}$. **$A^+$ é a "inversa possível"** de $A$.

---

## Resumo rápido

|Conceito|Fórmula ou fato|
|---|---|
|Ortogonais|$\mathbf{u}^\top\mathbf{v}=0$|
|Ortogonais não nulos|⇒ LI (a volta é falsa)|
|Complementos ortogonais|ortogonais **e** dims somam $n$|
|Teorema Fundamental|$N(A)=C(A^\top)^\perp$ em $\mathbb{R}^n$; $N(A^\top)=C(A)^\perp$ em $\mathbb{R}^m$|
|Mapeamento|$A$: espaço linha → espaço coluna (bijeção); núcleo → $\mathbf{0}$|
|Colunas ortonormais|$Q^\top Q=I$|
|Matriz ortogonal (quadrada)|$Q^{-1}=Q^\top$, preserva norma|
|Coordenadas em base ortonormal|$c_i=\mathbf{q}_i^\top\mathbf{x}$|
|Gram-Schmidt|subtrai projeções e normaliza|
|QR|$A=QR$, $Q$ ortonormal, $R$ triangular superior|
|Equação normal|$A^\top A\mathbf{x}=A^\top\mathbf{b}$|
|Solução única|colunas de $A$ LI, pois $N(A^\top A)=N(A)$|
|Projeção|$\mathbf{p}=A(A^\top A)^{-1}A^\top\mathbf{b}$|
|Erro|$\mathbf{e}=\mathbf{b}-\mathbf{p}\in N(A^\top)$|
|Pseudoinversa|$A^+=(A^\top A)^{-1}A^\top$|

---

## Possíveis perguntas de prova

O professor cobra conceitos, então tente responder antes de abrir cada uma.

> [!question]- Qual a relação entre o espaço linha e o espaço nulo de uma matriz? São **complementos ortogonais** em $\mathbb{R}^n$. Todo vetor do núcleo é ortogonal a todas as linhas (porque $A\mathbf{x}=\mathbf{0}$ significa linha·$\mathbf{x}=0$ para cada linha), e as dimensões somam $r+(n-r)=n$.

> [!question]- Dois subespaços ortogonais são sempre complementos ortogonais? Não. Também é preciso que as dimensões somem $n$. Por exemplo, os eixos $x$ e $y$ em $\mathbb{R}^3$ são ortogonais, mas não complementos.

> [!question]- O que acontece com um vetor x quando aplicamos A? $\mathbf{x}$ se decompõe em uma parte no espaço linha e outra no núcleo. A parte do núcleo vai para o zero, e a parte do espaço linha é levada ao espaço coluna, de forma bijetiva.

> [!question]- Qual a inversa de uma matriz ortogonal? Por quê? $Q^{-1}=Q^\top$, porque as colunas ortonormais dão $Q^\top Q=I$.

> [!question]- Por que uma matriz ortogonal preserva comprimentos? $|Q\mathbf{x}|^2=\mathbf{x}^\top Q^\top Q\mathbf{x}=\mathbf{x}^\top\mathbf{x}=|\mathbf{x}|^2$.

> [!question]- Qual a vantagem de uma base ortonormal? As coordenadas saem por produto escalar, $c_i=\mathbf{q}_i^\top\mathbf{x}$, sem precisar resolver um sistema.

> [!question]- O que faz o Gram-Schmidt e qual a sua relação com QR? Ele transforma uma base em uma base ortonormal do mesmo espaço, subtraindo de cada vetor suas projeções nos anteriores e normalizando. Escrevendo cada $\mathbf{u}_i$ em função dos $\mathbf{q}_j$, obtém-se $A=QR$, com $R$ triangular superior.

> [!question]- Quando usamos mínimos quadrados? Quando $A\mathbf{x}=\mathbf{b}$ não tem solução porque $\mathbf{b}\notin C(A)$, o típico com mais equações que incógnitas. Buscamos o $\mathbf{x}$ que minimiza $|A\mathbf{x}-\mathbf{b}|^2$.

> [!question]- Como se deduz a equação normal? O ponto de $C(A)$ mais próximo de $\mathbf{b}$ é aquele em que o erro $\mathbf{b}-A\mathbf{x}$ é perpendicular a $C(A)$, ou seja, a todas as colunas: $A^\top(\mathbf{b}-A\mathbf{x})=\mathbf{0}$. Isso dá $A^\top A\mathbf{x}=A^\top\mathbf{b}$.

> [!question]- Quando a equação normal tem solução única? Quando as colunas de $A$ são LI. Como $N(A^\top A)=N(A)$, nesse caso $A^\top A$ é invertível.

> [!question]- O x da equação normal é a projeção de b? Não. $\mathbf{x}$ são os coeficientes; a projeção é $\mathbf{p}=A\mathbf{x}$.

> [!question]- Em que espaço fundamental fica o erro dos mínimos quadrados? Em $N(A^\top)$, porque $A^\top\mathbf{e}=\mathbf{0}$. Ele é ortogonal ao espaço coluna.

> [!question]- Como ajustar uma parábola a pontos usando mínimos quadrados? Monte $A$ com as colunas $1,\ t_i,\ t_i^2$, coloque os valores $f(t_i)$ em $\mathbf{f}$ e resolva $A^\top A\boldsymbol\alpha=A^\top\mathbf{f}$. Funciona porque o modelo é linear nos coeficientes.

> [!question]- Para que servem os mínimos quadrados ponderados? Para reduzir a influência de outliers, dando peso menor a pontos com erro grande: $A^\top W^\top WA\boldsymbol\alpha=A^\top W^\top W\mathbf{f}$.

> [!question]- V ou F: vetores LI são ortogonais. **F.** A volta é que vale: vetores ortogonais não nulos são LI.

> [!question]- V ou F: dois planos em ℝ³ que passam pela origem podem ser subespaços ortogonais. **F.** Eles se cruzam numa reta, e um vetor não nulo dessa reta teria que ser ortogonal a si mesmo.

> [!question]- V ou F: se Q tem colunas ortonormais, então QQᵀ = I. **F** em geral. Isso só vale se $Q$ for quadrada. Sempre vale $Q^\top Q=I$.