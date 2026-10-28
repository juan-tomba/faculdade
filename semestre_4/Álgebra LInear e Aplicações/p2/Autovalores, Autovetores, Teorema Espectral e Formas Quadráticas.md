

## 1. A equação $A\mathbf{x}=\lambda\mathbf{x}$

$A$ é $n\times n$. Um **autovalor** $\lambda$ e um **autovetor** $\mathbf{x}$ satisfazem

$$A\mathbf{x}=\lambda\mathbf{x}\qquad(\mathbf{x}\neq\mathbf{0})$$

A transformação $A$ **não muda a direção** de $\mathbf{x}$, só o reescala por $\lambda$.

> [!important] Duas observações do professor
> 
> 1. Autovetores **não são únicos**: se $\mathbf{x}$ serve, qualquer múltiplo $c,\mathbf{x}$ também serve.
> 2. Autovetor é **sempre não nulo**. (O zero satisfaz a equação para qualquer $\lambda$, então não diria nada.)

### Como achar: o polinômio característico

Passe tudo para um lado:

$$(A-\lambda I)\mathbf{x}=\mathbf{0}$$

Isso diz duas coisas:

1. $\mathbf{x}$ está no **espaço nulo** de $(A-\lambda I)$.
2. $\lambda$ precisa ser escolhido de modo que esse núcleo **não seja só o zero**.

Uma matriz quadrada com núcleo não trivial é **singular**, então

$$\boxed{\det(A-\lambda I)=0}$$

Esse determinante é um **polinômio de grau $n$ em $\lambda$**, o **polinômio característico**. Suas raízes são os autovalores.

> [!example] Exemplo do notebook $$A=\begin{bmatrix}4 & -5 \cr 2 & -3\end{bmatrix};\Rightarrow;\det\begin{bmatrix}4-\lambda & -5 \cr 2 & -3-\lambda\end{bmatrix}=\lambda^2-\lambda-2=0$$ Raízes: $\lambda=2$ e $\lambda=-1$.
> 
> **Autovetores** (resolvendo $(A-\lambda I)\mathbf{x}=\mathbf{0}$ para cada $\lambda$):
> 
> - $\lambda=2$: $\begin{bmatrix}2 & -5 \cr 2 & -5\end{bmatrix}\mathbf{x}=\mathbf{0}$ dá $\mathbf{x}=(5,2)$.
> - $\lambda=-1$: $\begin{bmatrix}5 & -5 \cr 2 & -2\end{bmatrix}\mathbf{x}=\mathbf{0}$ dá $\mathbf{x}=(1,1)$.
> 
> Conferindo: $A(1,1)=(-1,-1)=-1\cdot(1,1)$ ✓.

> [!tip] Receita em 2 passos
> 
> 1. Resolva $\det(A-\lambda I)=0$ para obter os autovalores.
> 2. Para cada $\lambda$, resolva $(A-\lambda I)\mathbf{x}=\mathbf{0}$ (um sistema homogêneo, com infinitas soluções) para obter os autovetores.

### Quantos autovalores?

Pelo Teorema Fundamental da Álgebra, um polinômio de grau $n$ tem **$n$ raízes**, contadas com repetição e possivelmente **complexas**. Então toda $A$ $n\times n$ tem $n$ autovalores (com repetição).

> [!warning] Matriz real pode ter autovalores complexos Por exemplo, uma rotação de 90° no plano não deixa nenhuma direção real no lugar, e seus autovalores são complexos. **Para matrizes simétricas isso não acontece** (seção 3).

### Propriedades importantes

> [!important] Traço e determinante
> 
> 1. $\mathrm{Tr}(A)=a_{11}+\cdots+a_{nn}=\lambda_1+\cdots+\lambda_n$ (a soma da diagonal é a soma dos autovalores).
> 2. $\det(A)=\lambda_1\lambda_2\cdots\lambda_n$ (o produto dos autovalores é o determinante).

Confira no exemplo: traço $=4+(-3)=1=2+(-1)$ ✓. Determinante $=-12+10=-2=2\cdot(-1)$ ✓.

> [!tip] Atalho para $2\times2$ O polinômio característico é $\lambda^2-\mathrm{Tr}(A),\lambda+\det(A)=0$. Dá para montá-lo sem calcular o determinante de $A-\lambda I$.

> [!note] Fatos extras (decorrem do que está no notebook)
> 
> - $A$ é **singular** ⇔ $0$ é autovalor (porque $\det A=\prod\lambda_i=0$).
> - Autovetores de autovalores **distintos** são sempre LI.
> - Numa matriz **triangular**, os autovalores são os elementos da diagonal.

---

## 2. Diagonalização

Suponha que $A$ tenha $n$ autovetores **LI** $\mathbf{u}_1,\dots,\mathbf{u}_n$, com autovalores $\lambda_1,\dots,\lambda_n$. Coloque os autovetores nas colunas de $S$. Como $A\mathbf{u}_i=\lambda_i\mathbf{u}_i$, todas as colunas de uma só vez dão

$$AS=S\Lambda\qquad\text{com}\qquad\Lambda=\begin{bmatrix}\lambda_1 & & \cr & \ddots & \cr & & \lambda_n\end{bmatrix}$$

Como as colunas de $S$ são LI, $S$ é **invertível**, então

$$\boxed{S^{-1}AS=\Lambda\qquad\Longleftrightarrow\qquad A=S\Lambda S^{-1}}$$

> [!important] Ideia Os autovetores formam uma **base** em que $A$ vira uma matriz **diagonal**: nessa base, $A$ só escala cada coordenada.

> [!warning] Nem toda matriz é diagonalizável É preciso ter **$n$ autovetores LI**. Se faltarem autovetores, não dá para formar $S$ invertível.
> 
> **Exemplo clássico** (extra): $\begin{bmatrix}1 & 1 \cr 0 & 1\end{bmatrix}$ tem o autovalor $1$ repetido duas vezes, mas só uma direção de autovetores, $(1,0)$. Não é diagonalizável. Ter autovalores repetidos **não** é sinônimo de não diagonalizável: a identidade tem autovalor $1$ repetido e já é diagonal.

> [!note] Para que serve (extra) $A^k=S\Lambda^kS^{-1}$: elevar $A$ a uma potência vira elevar cada $\lambda_i$ à potência, o que é trivial porque $\Lambda$ é diagonal.

> [!example] Exemplo (continuação) Com $\lambda=2\to(5,2)$ e $\lambda=-1\to(1,1)$: $S=\begin{bmatrix}5 & 1 \cr 2 & 1\end{bmatrix}$ e $\Lambda=\begin{bmatrix}2 & 0 \cr 0 & -1\end{bmatrix}$.

---

## 3. Matrizes simétricas e o Teorema Espectral

$A$ é **simétrica** se $A=A^\top$.

> [!important] Propriedade importante Se $A$ é simétrica:
> 
> 1. Seus autovalores são **reais** (e os autovetores podem ser tomados reais).
> 2. Autovetores de **autovalores distintos** são **ortogonais**. Em particular, se os $n$ autovalores são distintos, os autovetores formam uma **base ortogonal** de $\mathbb{R}^n$.

### Prova 1: os autovalores são reais

Seja $\lambda$ um autovalor (possivelmente complexo) e $\mathbf{x}$ um autovetor. Como $A$ é real, conjugando $A\mathbf{x}=\lambda\mathbf{x}$ obtemos $A\overline{\mathbf{x}}=\overline{\lambda},\overline{\mathbf{x}}$. Calculamos $\overline{\mathbf{x}}^\top A\mathbf{x}$ de duas formas:

$$\overline{\mathbf{x}}^\top A\mathbf{x}=\overline{\mathbf{x}}^\top(A\mathbf{x})=\lambda,(\overline{\mathbf{x}}^\top\mathbf{x})$$

$$\overline{\mathbf{x}}^\top A\mathbf{x}=(A^\top\overline{\mathbf{x}})^\top\mathbf{x}=(A\overline{\mathbf{x}})^\top\mathbf{x}=\overline{\lambda},(\overline{\mathbf{x}}^\top\mathbf{x})$$

A segunda igualdade usa $A^\top=A$ (**é aqui que a simetria entra**). Como $\overline{\mathbf{x}}^\top\mathbf{x}=\sum|x_i|^2>0$, podemos cancelar e sobra $\lambda=\overline{\lambda}$, isto é, $\lambda$ é real. ∎

### Prova 2: autovetores de autovalores distintos são ortogonais

Sejam $A\mathbf{x}_1=\lambda_1\mathbf{x}_1$ e $A\mathbf{x}_2=\lambda_2\mathbf{x}_2$, com $\lambda_1\neq\lambda_2$:

$$\lambda_1,\mathbf{x}_1^\top\mathbf{x}_2=(A\mathbf{x}_1)^\top\mathbf{x}_2=\mathbf{x}_1^\top A^\top\mathbf{x}_2=\mathbf{x}_1^\top A\mathbf{x}_2=\lambda_2,\mathbf{x}_1^\top\mathbf{x}_2$$

Logo $(\lambda_1-\lambda_2),\mathbf{x}_1^\top\mathbf{x}_2=0$. Como $\lambda_1\neq\lambda_2$, conclui-se que $\mathbf{x}_1^\top\mathbf{x}_2=0$. ∎

### E se houver autovalores repetidos?

Se $\lambda$ tem multiplicidade $k$, o **autoespaço** associado tem dimensão $k$, e **todo** vetor dele é autovetor de $\lambda$. Os autovetores escolhidos podem não ser ortogonais entre si, mas dá para aplicar **Gram-Schmidt dentro do autoespaço** e obter uma base ortogonal. Autovetores de autovalores diferentes continuam ortogonais, pela Prova 2.

### Teorema Espectral

> [!important] Teorema Espectral Toda matriz simétrica $A$ é diagonalizável **por uma matriz ortonormal**: $$\boxed{A=Q\Lambda Q^\top}$$ onde as colunas de $Q$ são autovetores **ortonormais** de $A$ e $\Lambda$ é diagonal com os autovalores.

**Prova** (a mesma da diagonalização, com um ganho): $AQ=Q\Lambda$. Como $Q$ é ortonormal, $Q^{-1}=Q^\top$, então $A=Q\Lambda Q^\top$. ∎

> [!tip] A diferença para a diagonalização geral No caso geral, $A=S\Lambda S^{-1}$ exige **inverter** $S$. No caso simétrico, $S$ vira $Q$ e **inverter é só transpor**. Além disso, nunca falta autovetor: toda simétrica é diagonalizável.

> [!note] Forma de soma (extra) Escrevendo coluna por coluna, $A=\lambda_1\mathbf{q}_1\mathbf{q}_1^\top+\cdots+\lambda_n\mathbf{q}_n\mathbf{q}_n^\top$: $A$ é uma soma de projeções nas direções dos autovetores, ponderadas pelos autovalores.

---

## 4. Interpretando $A\mathbf{x}$ para $A$ simétrica

Com $A=Q\Lambda Q^\top$, a transformação $\mathbf{y}=A\mathbf{x}$ acontece em **3 passos**, lendo da direita para a esquerda:

$$\mathbf{y}=Q,\big(\Lambda,(Q^\top\mathbf{x})\big)$$

|Passo|Operação|O que faz|
|---|---|---|
|1|$Q^\top\mathbf{x}$|**Projeção**: calcula as coordenadas de $\mathbf{x}$ na base dos autovetores, $\mathbf{q}_i^\top\mathbf{x}$|
|2|$\Lambda(\cdot)$|**Escala**: multiplica cada coordenada pelo autovalor $\lambda_i$|
|3|$Q(\cdot)$|**Reconstrução**: remonta o vetor, combinando os $\mathbf{q}_i$ com os novos coeficientes|

O resultado final:

$$\mathbf{y}=(\lambda_1\mathbf{q}_1^\top\mathbf{x}),\mathbf{q}_1+\cdots+(\lambda_n\mathbf{q}_n^\top\mathbf{x}),\mathbf{q}_n$$

> [!tip] Em palavras Uma matriz simétrica **estica ou encolhe $\mathbf{x}$ ao longo de cada direção de autovetor**, com fator igual ao autovalor correspondente. Autovalor grande significa muito esticamento naquela direção, e autovalor próximo de zero significa que aquela direção é quase "esmagada".

---

## 5. Formas quadráticas

Toda matriz simétrica $A$ define um polinômio quadrático, a **forma quadrática**:

$$f(\mathbf{x})=\mathbf{x}^\top A\mathbf{x}$$

Em $2\times2$:

$$\begin{bmatrix}x_1 & x_2\end{bmatrix}\begin{bmatrix}a & b \cr b & c\end{bmatrix}\begin{bmatrix}x_1 \cr x_2\end{bmatrix}=a,x_1^2+2b,x_1x_2+c,x_2^2$$

No caso geral, a diagonal dá os termos $a_{ii}x_i^2$ e cada par fora da diagonal contribui $2a_{ij}x_ix_j$.

> [!warning] O fator 2 O termo cruzado tem **coeficiente $2b$**, porque $b$ aparece nas posições $(1,2)$ e $(2,1)$. Para montar a matriz a partir do polinômio, divida o coeficiente do termo cruzado por 2.

O ponto $\mathbf{x}=\mathbf{0}$ sempre é **ponto crítico** de $f$ (com $f(\mathbf{0})=0$). Ele pode ser mínimo, máximo ou **sela**.

> [!example] Exemplos do notebook
> 
> - $A_1=\begin{bmatrix}2 & 2 \cr 2 & 1\end{bmatrix}$ dá $2x^2+4xy+y^2$. Como $\det A_1=2-4=-2<0$, os autovalores têm sinais opostos: **sela**.
> - $A_2=\begin{bmatrix}2 & 1 \cr 1 & 2\end{bmatrix}$ dá $2x^2+2xy+2y^2$. Os autovalores são $1$ e $3$, ambos positivos: **mínimo**.

### Matriz definida positiva

Uma matriz simétrica $A$ é **definida positiva** se

$$\mathbf{x}^\top A\mathbf{x}>0\qquad\text{para todo }\mathbf{x}\neq\mathbf{0}$$

Ou seja, $\mathbf{0}$ é o ponto de **mínimo** de $f$.

> [!important] Propriedade: definida positiva ⇔ todos os autovalores positivos

**Ida.** Se $\mathbf{x}$ é um autovetor: $\mathbf{x}^\top A\mathbf{x}=\lambda,\mathbf{x}^\top\mathbf{x}=\lambda|\mathbf{x}|^2>0$, então $\lambda>0$.

**Volta** (que o notebook deixa como exercício). Suponha todos os $\lambda_i>0$. Pelo Teorema Espectral, escreva $\mathbf{x}=Q\mathbf{y}$ com $\mathbf{y}=Q^\top\mathbf{x}$. Então

$$\mathbf{x}^\top A\mathbf{x}=\mathbf{y}^\top\Lambda\mathbf{y}=\lambda_1y_1^2+\cdots+\lambda_ny_n^2.$$

Se $\mathbf{x}\neq\mathbf{0}$, então $\mathbf{y}\neq\mathbf{0}$, então algum $y_i^2>0$, e como todos os $\lambda_i>0$ a soma é positiva. ∎

> [!tip] Consequência Se $A$ é definida positiva, $\det(A)=\prod\lambda_i>0$.

> [!warning] A volta dessa consequência é falsa $\det(A)>0$ **não basta** para ser definida positiva. Por exemplo, $A=-I$ em $\mathbb{R}^2$ tem $\det=1>0$, mas os autovalores são $-1$ e $-1$.

**Semi-definida positiva:** $\mathbf{x}^\top A\mathbf{x}\geq0$ para todo $\mathbf{x}$. Isso equivale a todos os autovalores satisfazerem $\lambda_i\geq0$.

> [!note] Classificação completa (extra)
> 
> |Autovalores|Tipo|Ponto $\mathbf{0}$|
> |---|---|---|
> |todos $>0$|definida positiva|mínimo|
> |todos $\geq0$|semi-definida positiva|mínimo (não estrito)|
> |todos $<0$|definida negativa|máximo|
> |sinais mistos|indefinida|sela|

---

## 6. Elipsoides

Seja $A$ definida positiva. A equação $\mathbf{x}^\top A\mathbf{x}=1$ descreve um **elipsoide** em $\mathbb{R}^n$.

**Por quê.** Com $A=Q\Lambda Q^\top$ e $\mathbf{y}=Q^\top\mathbf{x}$:

$$\mathbf{x}^\top A\mathbf{x}=(\mathbf{x}^\top Q),\Lambda,(Q^\top\mathbf{x})=\mathbf{y}^\top\Lambda\mathbf{y}=\lambda_1y_1^2+\cdots+\lambda_ny_n^2=1$$

Isso é um elipsoide "em pé" (alinhado aos eixos) no sistema de coordenadas $\mathbf{y}$. A mudança $\mathbf{y}=Q^\top\mathbf{x}$ é só uma **rotação** para o sistema dos autovetores.

> [!important] Eixos do elipsoide
> 
> - Os **autovetores** de $A$ são os **eixos principais** do elipsoide.
> - O **comprimento do semi-eixo** na direção do autovetor $\mathbf{q}_i$ é $\dfrac{1}{\sqrt{\lambda_i}}$.
> - Portanto o **maior eixo** corresponde ao **menor autovalor**, e vice-versa.

> [!question]- Por que autovalor maior dá eixo menor? Na direção $\mathbf{q}_i$ vale $\lambda_iy_i^2=1$, então $y_i=1/\sqrt{\lambda_i}$. Um $\lambda_i$ grande faz a forma quadrática crescer rápido, então você "chega em 1" depressa, perto da origem. Um $\lambda_i$ pequeno faz $f$ crescer devagar, e é preciso ir mais longe para chegar em 1.

> [!example] Exemplo do notebook $A=\begin{bmatrix}5 & 4 \cr 4 & 5\end{bmatrix}$ dá $5x_1^2+8x_1x_2+5x_2^2=1$.
> 
> - Autovalores: $\lambda=1$ e $\lambda=9$ (traço $10$, determinante $9$).
> - Autovetores: $\frac{1}{\sqrt2}(1,-1)$ para $\lambda=1$ e $\frac{1}{\sqrt2}(1,1)$ para $\lambda=9$.
> - Semi-eixos: $1/\sqrt1=1$ (ao longo de $(1,-1)$, o eixo maior) e $1/\sqrt9=1/3$ (ao longo de $(1,1)$, o eixo menor).
> 
> O elipsoide é uma elipse inclinada em 45°, alongada na direção $(1,-1)$.

---

## 7. Quociente de Rayleigh

Para $A$ simétrica (o notebook supõe definida positiva) com autovalores ordenados $\lambda_1\leq\lambda_2\leq\cdots\leq\lambda_n$:

$$R(\mathbf{x})=\frac{\mathbf{x}^\top A\mathbf{x}}{\mathbf{x}^\top\mathbf{x}}$$

Ele mede "quanto $A$ estica na direção de $\mathbf{x}$", normalizando pelo comprimento.

**Cálculo.** Com $\mathbf{x}=Q\mathbf{y}$ (e $Q^\top Q=I$):

$$R(\mathbf{x})=\frac{\mathbf{y}^\top\Lambda\mathbf{y}}{\mathbf{y}^\top\mathbf{y}}=\frac{\lambda_1y_1^2+\cdots+\lambda_ny_n^2}{y_1^2+\cdots+y_n^2};\geq;\frac{\lambda_1(y_1^2+\cdots+y_n^2)}{y_1^2+\cdots+y_n^2}=\lambda_1$$

A desigualdade vale porque $\lambda_i\geq\lambda_1$ para todo $i$. E o valor $\lambda_1$ é atingido: se $\mathbf{x}_1$ é autovetor de $\lambda_1$, então $R(\mathbf{x}_1)=\dfrac{\lambda_1\mathbf{x}_1^\top\mathbf{x}_1}{\mathbf{x}_1^\top\mathbf{x}_1}=\lambda_1$.

> [!important] Propriedade importante
> 
> - O **mínimo** de $R(\mathbf{x})$ é o **menor autovalor** $\lambda_1$, atingido no autovetor correspondente.
> - O **máximo** de $R(\mathbf{x})$ é o **maior autovalor** $\lambda_n$, atingido no autovetor correspondente (a prova é análoga, com a desigualdade invertida).

$$\lambda_1;\leq;R(\mathbf{x});\leq;\lambda_n$$

> [!tip] Interpretação $R(\mathbf{x})$ é uma **média ponderada dos autovalores**, com pesos $y_i^2/|\mathbf{y}|^2$ (que somam 1). Uma média nunca sai do intervalo entre o menor e o maior valor. É por isso que $R$ fica sempre entre $\lambda_1$ e $\lambda_n$.

> [!note] Observação A simetria é o que importa na prova. Ela funciona igual para qualquer matriz simétrica, mesmo que não seja definida positiva.

---

## Resumo rápido

|Conceito|Fato|
|---|---|
|Autovalor e autovetor|$A\mathbf{x}=\lambda\mathbf{x}$, com $\mathbf{x}\neq\mathbf{0}$|
|Como achar $\lambda$|$\det(A-\lambda I)=0$ (polinômio de grau $n$)|
|Como achar $\mathbf{x}$|resolver $(A-\lambda I)\mathbf{x}=\mathbf{0}$|
|Traço|$\mathrm{Tr}(A)=\sum\lambda_i$|
|Determinante|$\det(A)=\prod\lambda_i$|
|Diagonalização|$A=S\Lambda S^{-1}$ (precisa de $n$ autovetores LI)|
|$A$ simétrica|autovalores reais, autovetores de $\lambda$'s distintos ortogonais|
|Teorema Espectral|$A=Q\Lambda Q^\top$, com $Q$ ortonormal|
|Interpretação|projetar nos $\mathbf{q}_i$, escalar por $\lambda_i$, reconstruir|
|Forma quadrática|$f(\mathbf{x})=\mathbf{x}^\top A\mathbf{x}$, termo cruzado com fator 2|
|Definida positiva|$\mathbf{x}^\top A\mathbf{x}>0$ ⇔ todos $\lambda_i>0$ (⇒ $\det>0$)|
|Semi-definida positiva|$\mathbf{x}^\top A\mathbf{x}\geq0$ ⇔ todos $\lambda_i\geq0$|
|Elipsoide $\mathbf{x}^\top A\mathbf{x}=1$|eixos = autovetores, semi-eixos $=1/\sqrt{\lambda_i}$|
|Maior eixo|menor autovalor|
|Rayleigh|$\lambda_{\min}\leq R(\mathbf{x})\leq\lambda_{\max}$|

---

## Possíveis perguntas de prova

O professor cobra conceitos, então tente responder antes de abrir.

> [!question]- O que é um autovetor? Por que não pode ser o vetor nulo? É um vetor $\mathbf{x}\neq\mathbf{0}$ tal que $A\mathbf{x}=\lambda\mathbf{x}$: a transformação só o reescala, sem mudar a direção. O zero satisfaz a equação para qualquer $\lambda$, então não carrega informação, e por isso é excluído.

> [!question]- Por que os autovalores são raízes de $\det(A-\lambda I)=0$? $A\mathbf{x}=\lambda\mathbf{x}$ equivale a $(A-\lambda I)\mathbf{x}=\mathbf{0}$ com $\mathbf{x}\neq\mathbf{0}$, o que exige núcleo não trivial. Uma matriz quadrada com núcleo não trivial é singular, e portanto tem determinante zero.

> [!question]- Um autovalor tem um único autovetor? Não. Qualquer múltiplo não nulo de um autovetor também é autovetor. Na verdade, todos os autovetores de um mesmo $\lambda$ (mais o zero) formam o **autoespaço**, que é o núcleo de $(A-\lambda I)$.

> [!question]- Qual a relação entre traço, determinante e autovalores? A soma dos autovalores é o traço, e o produto dos autovalores é o determinante.

> [!question]- Quando uma matriz é diagonalizável? Toda matriz é? Quando tem $n$ autovetores LI, que formam as colunas de $S$ em $A=S\Lambda S^{-1}$. Nem toda matriz é: se faltarem autovetores LI (como em $\begin{bmatrix}1 & 1 \cr 0 & 1\end{bmatrix}$), não há como formar $S$ invertível.

> [!question]- Por que os autovalores de uma matriz simétrica são reais? Calcula-se $\overline{\mathbf{x}}^\top A\mathbf{x}$ de duas formas. Uma dá $\lambda,\overline{\mathbf{x}}^\top\mathbf{x}$, e a outra, usando $A=A^\top$, dá $\overline{\lambda},\overline{\mathbf{x}}^\top\mathbf{x}$. Como $\overline{\mathbf{x}}^\top\mathbf{x}>0$, conclui-se que $\lambda=\overline{\lambda}$.

> [!question]- Por que autovetores de autovalores distintos de uma simétrica são ortogonais? $\lambda_1\mathbf{x}_1^\top\mathbf{x}_2=(A\mathbf{x}_1)^\top\mathbf{x}_2=\mathbf{x}_1^\top A\mathbf{x}_2=\lambda_2\mathbf{x}_1^\top\mathbf{x}_2$. Então $(\lambda_1-\lambda_2),\mathbf{x}_1^\top\mathbf{x}_2=0$, e como $\lambda_1\neq\lambda_2$, o produto escalar é zero.

> [!question]- E se a simétrica tiver autovalores repetidos? O autoespaço de um autovalor de multiplicidade $k$ tem dimensão $k$, e qualquer vetor dele é autovetor. Aplicando Gram-Schmidt dentro do autoespaço, obtém-se uma base ortogonal. Assim, o Teorema Espectral continua valendo.

> [!question]- Enuncie o Teorema Espectral. Toda matriz simétrica se escreve como $A=Q\Lambda Q^\top$, onde $Q$ tem colunas ortonormais que são autovetores de $A$ e $\Lambda$ é a diagonal dos autovalores. A prova usa $AQ=Q\Lambda$ e $Q^{-1}=Q^\top$.

> [!question]- Qual a vantagem do Teorema Espectral sobre a diagonalização comum? Toda simétrica é diagonalizável (nunca faltam autovetores), e a matriz de autovetores é ortonormal, então sua inversa é só a transposta, sem precisar inverter nada.

> [!question]- Interprete geometricamente $A\mathbf{x}=Q\Lambda Q^\top\mathbf{x}$. Primeiro $Q^\top\mathbf{x}$ projeta $\mathbf{x}$ na base dos autovetores. Depois $\Lambda$ multiplica cada coordenada por $\lambda_i$. Por fim, $Q$ reconstrói o vetor. Ou seja, $A$ estica ou encolhe $\mathbf{x}$ ao longo de cada direção de autovetor, com fator $\lambda_i$.

> [!question]- O que é uma forma quadrática? É o polinômio $f(\mathbf{x})=\mathbf{x}^\top A\mathbf{x}$ associado a uma matriz simétrica $A$, em que todos os termos têm grau 2.

> [!question]- O que significa $A$ ser definida positiva? $\mathbf{x}^\top A\mathbf{x}>0$ para todo $\mathbf{x}\neq\mathbf{0}$. Ou seja, a origem é um ponto de mínimo da forma quadrática. É equivalente a todos os autovalores serem positivos.

> [!question]- Prove que se $\lambda_i>0$ para todo $i$, então $\mathbf{x}^\top A\mathbf{x}>0$. Escreva $\mathbf{x}=Q\mathbf{y}$. Então $\mathbf{x}^\top A\mathbf{x}=\sum\lambda_iy_i^2$. Como $\mathbf{x}\neq\mathbf{0}$, algum $y_i\neq0$, e a soma é positiva, pois todos os $\lambda_i>0$.

> [!question]- Como distinguir mínimo, máximo e sela pela matriz? Todos os autovalores positivos dão mínimo (definida positiva). Todos negativos dão máximo. Sinais mistos dão sela (indefinida).

> [!question]- Que figura é $\mathbf{x}^\top A\mathbf{x}=1$ quando $A$ é definida positiva? Quais são seus eixos? Um elipsoide. Os eixos principais são os autovetores de $A$, e o semi-eixo na direção de $\mathbf{q}_i$ mede $1/\sqrt{\lambda_i}$. O maior eixo está na direção do autovetor de menor autovalor.

> [!question]- O que é o quociente de Rayleigh e quais seus valores extremos? $R(\mathbf{x})=\dfrac{\mathbf{x}^\top A\mathbf{x}}{\mathbf{x}^\top\mathbf{x}}$. Seu mínimo é o menor autovalor e seu máximo é o maior autovalor, atingidos nos respectivos autovetores. Em qualquer outra direção, ele fica entre os dois.

> [!question]- V ou F: toda matriz real $n\times n$ tem $n$ autovalores reais. **F.** Os autovalores são as raízes de um polinômio de grau $n$, que podem ser complexas (como numa rotação de 90°). Só para matrizes **simétricas** os autovalores são garantidamente reais.

> [!question]- V ou F: se $A$ tem autovalores repetidos, então não é diagonalizável. **F.** Depende de haver autovetores LI suficientes. A identidade tem o autovalor $1$ repetido e é diagonal. Além disso, toda matriz simétrica é diagonalizável, mesmo com autovalores repetidos.

> [!question]- V ou F: se $\det(A)>0$, então $A$ é definida positiva. **F.** Por exemplo, $-I$ em $\mathbb{R}^2$ tem $\det=1>0$ e autovalores negativos. O que vale é a ida: definida positiva implica $\det>0$.

> [!question]- V ou F: se um dos autovalores de $A$ é zero, então $A$ é singular. **V.** $\det(A)=\prod\lambda_i=0$. Equivalentemente, o autovetor desse autovalor satisfaz $A\mathbf{x}=\mathbf{0}$, então $N(A)\neq{\mathbf{0}}$.

> [!question]- V ou F: autovetores de uma matriz simétrica sempre são ortogonais entre si. **F** (como afirmação geral). Autovetores de autovalores **distintos** são ortogonais. Dentro de um mesmo autoespaço (autovalor repetido), é possível escolher autovetores não ortogonais, mas sempre dá para ortogonalizá-los com Gram-Schmidt.