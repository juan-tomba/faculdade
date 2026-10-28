

## 1. Vetores e operações

### Conceitos básicos

- **Vetor** = classe de segmentos orientados equipolentes (mesmo módulo, direção e sentido). Na lista: confunde-se vetor com representante.
- $\vec{AB} = B - A$ (ponta menos origem).
- **Norma:** $\Vert \vec v\Vert = \sqrt{x^2+y^2+z^2}$. **Unitário:** $\hat v = \vec v/\Vert \vec v\Vert$.
- **Relação de Chasles:** $\vec{AB}+\vec{BC}=\vec{AC}$.
- **Múltiplo escalar:** $\Vert \lambda\vec v\Vert = |\lambda| \Vert \vec v\Vert$. Sentido igual se $\lambda>0$, oposto se $\lambda<0$.
- **Paralelos** ⇔ $\vec u = \lambda\vec v$ (LD). **Coplanares** ⇔ LD de 3 vetores.
- Base ortonormal $\lbrace \vec i,\vec j,\vec k\rbrace$ ⇒ coordenadas $(x,y,z)$.

> [!example]- Ex. 1 e 2 da lista (demonstrações) **Ex.1:** $\vec{AB}+\vec{AC}=\vec{BC}$ e $\vec{BC}=\vec{AC}-\vec{AB}$, logo $2\vec{AB}=\vec 0$ ⇒ $A=B$. **Ex.2:** $\Vert \lambda\vec v\Vert =\sqrt{\lambda\vec v\cdot\lambda\vec v}=\sqrt{\lambda^2 \vec v\cdot\vec v}=|\lambda| \Vert \vec v\Vert$.

### Produto escalar

$$\vec u\cdot\vec v = x_ux_v+y_uy_v+z_uz_v = \Vert \vec u\Vert \Vert \vec v\Vert \cos\theta$$

- Resultado é **número**. $\vec u\cdot\vec u=\Vert \vec u\Vert ^2$.
- **Ortogonais** ⇔ $\vec u\cdot\vec v=0$.
- Ângulo: $\cos\theta = \dfrac{\vec u\cdot\vec v}{\Vert \vec u\Vert \Vert \vec v\Vert }$.
- Propriedades: comutativo, distributivo, $(\lambda\vec u)\cdot\vec v=\lambda(\vec u\cdot\vec v)$.
- **Cauchy–Schwarz:** $|\vec u\cdot\vec v|\le\Vert \vec u\Vert \Vert \vec v\Vert$. **Triangular:** $\Vert \vec u+\vec v\Vert \le\Vert \vec u\Vert +\Vert \vec v\Vert$.

### Projeção ortogonal

$$\operatorname{proj}_{\vec v}\vec u = \frac{\vec u\cdot\vec v}{\vec v\cdot\vec v} \vec v \qquad \text{(comprimento: } |\vec u\cdot\hat v|\text{)}$$

- Geometricamente: "sombra" de $\vec u$ na reta de $\vec v$.
- Decomposição: $\vec u = \operatorname{proj}_{\vec v}\vec u + \vec u_\perp$, com $\vec u_\perp\perp\vec v$.
- Esta ideia é a semente dos **mínimos quadrados** (tópico 6).

### Produto vetorial

$$\vec u\wedge\vec v=\begin{vmatrix}\vec i&\vec j&\vec k \cr x_u&y_u&z_u \cr x_v&y_v&z_v\end{vmatrix}$$

- Resultado é **vetor**, ortogonal a $\vec u$ e $\vec v$. Sentido: regra da mão direita.
- $\Vert \vec u\wedge\vec v\Vert =\Vert \vec u\Vert \Vert \vec v\Vert \sin\theta$ = **área do paralelogramo**.
- **Anticomutativo:** $\vec u\wedge\vec v=-\vec v\wedge\vec u$. Distributivo. $\vec u\wedge\vec u=\vec 0$.
- $\vec u\wedge\vec v=\vec 0$ ⇔ paralelos (ou algum nulo).
- **NÃO é associativo.**
- Uso principal: obter um **vetor normal** a um plano ou um vetor perpendicular a dois outros.

### Produto misto

$$[\vec u,\vec v,\vec w]=\vec u\cdot(\vec v\wedge\vec w)=\begin{vmatrix}x_u&y_u&z_u \cr x_v&y_v&z_v \cr x_w&y_w&z_w\end{vmatrix}$$

- $|[\vec u,\vec v,\vec w]|$ = **volume do paralelepípedo**; tetraedro = $\frac16$ disso.
- **Coplanares** ⇔ $[\vec u,\vec v,\vec w]=0$ (Ex. 5).
- Trocar duas posições muda o sinal. Permutação cíclica mantém.

### Fórmulas geométricas rápidas

|O que|Fórmula|
|---|---|
|Área do paralelogramo|$\Vert \vec{AB}\wedge\vec{AC}\Vert$|
|Área do triângulo|$\tfrac12\Vert \vec{AB}\wedge\vec{AC}\Vert$|
|Altura do triângulo rel. a $AB$|$h=\dfrac{\Vert \vec{AB}\wedge\vec{AC}\Vert }{\Vert \vec{AB}\Vert }$|
|Volume do tetraedro|$\tfrac16 \lvert[\vec{AB},\vec{AC},\vec{AD}]\rvert$|
|Altura do paralelepípedo|$\dfrac{\lvert[\vec u,\vec v,\vec w]\rvert}{\Vert \vec u\wedge\vec v\Vert }$|

---

## 2. Retas e planos

### Reta

Ponto $P_0=(x_0,y_0,z_0)$ e direção $\vec d=(a,b,c)$:

- **Vetorial:** $P=P_0+t\vec d$
- **Paramétrica:** $x=x_0+at,\ y=y_0+bt,\ z=z_0+ct$
- **Simétrica:** $\dfrac{x-x_0}{a}=\dfrac{y-y_0}{b}=\dfrac{z-z_0}{c}$ (se $a,b,c\neq0$)
- Por dois pontos $A,B$: direção $\vec d=\vec{AB}$.
- Uma reta em $\mathbb R^3$ é **interseção de dois planos** (equações gerais).

### Plano

Ponto $P_0$ e normal $\vec n=(a,b,c)$:

- **Geral:** $ax+by+cz+d=0$, com $d=-\vec n\cdot P_0$.
- **Vetorial/paramétrico:** $P=P_0+s\vec u+t\vec v$ ($\vec u,\vec v$ LI no plano); então $\vec n=\vec u\wedge\vec v$.
- Por 3 pontos não colineares: $\vec n=\vec{AB}\wedge\vec{AC}$.
- Por reta $r$ e ponto $C\notin r$: $\vec n=\vec d_r\wedge\vec{AC}$ ($A\in r$).
- Coeficientes $(a,b,c)$ = vetor normal (geometria importa aqui).
- Variável ausente ⇒ plano paralelo ao eixo dela (ex.: $y=-z$ contém o eixo $x$).

> [!question] Cuidado (prova antiga, Q4c) $ax+by+cz+d=0$ é subespaço de $\mathbb R^3$ **só se $d=0$** (precisa conter a origem).

### Posições relativas

**Reta × reta** (direções $\vec d_1,\vec d_2$; $A_1\in r_1$, $A_2\in r_2$):

|Condição|Posição|
|---|---|
|$\vec d_1\parallel\vec d_2$ e $A_1\in r_2$|coincidentes|
|$\vec d_1\parallel\vec d_2$ e $A_1\notin r_2$|paralelas distintas|
|$\vec d_1\nparallel\vec d_2$ e $[\vec d_1,\vec d_2,\vec{A_1A_2}]=0$|**concorrentes** (1 ponto)|
|$\vec d_1\nparallel\vec d_2$ e $[\vec d_1,\vec d_2,\vec{A_1A_2}]\neq0$|**reversas** (não coplanares)|

**Reta × plano** ($\vec d\cdot\vec n$):

- $\vec d\cdot\vec n\neq0$ ⇒ transversal (1 ponto; substituir a paramétrica no plano).
- $\vec d\cdot\vec n=0$ ⇒ paralela (ou contida, se um ponto satisfaz o plano).

**Plano × plano:**

- $\vec n_1\parallel\vec n_2$ ⇒ paralelos ou coincidentes.
- Caso contrário ⇒ **concorrentes numa reta**, com direção $\vec n_1\wedge\vec n_2$.

### Ângulos

- Entre retas: $\cos\theta=\dfrac{|\vec d_1\cdot\vec d_2|}{\Vert \vec d_1\Vert \Vert \vec d_2\Vert }$
- Entre planos: $\cos\theta=\dfrac{|\vec n_1\cdot\vec n_2|}{\Vert \vec n_1\Vert \Vert \vec n_2\Vert }$
- **Reta × plano:** $\sin\theta=\dfrac{|\vec d\cdot\vec n|}{\Vert \vec d\Vert \Vert \vec n\Vert }$ ⚠️ **seno**, pois o ângulo da reta com o plano é o complemento do ângulo com a normal.

### Distâncias

|O que|Fórmula|
|---|---|
|Ponto $P$ a plano|$\dfrac{\lvert ax_0+by_0+cz_0+d\rvert}{\sqrt{a^2+b^2+c^2}}$|
|Ponto $P$ a reta ($A\in r$, direção $\vec d$)|$\dfrac{\Vert \vec{AP}\wedge\vec d\Vert }{\Vert \vec d\Vert }$|
|Entre retas reversas|$\dfrac{\lvert[\vec d_1,\vec d_2,\vec{A_1A_2}]\rvert}{\Vert \vec d_1\wedge\vec d_2\Vert }$|
|Entre planos paralelos|distância de um ponto de um ao outro|
|Reta paralela a plano|distância de um ponto da reta ao plano|

### Perpendicular comum a duas reversas

- Direção: $\vec d_1\wedge\vec d_2$.
- Achar a reta: o plano $\pi_1$ contendo $r_1$ e direção $\vec d_1\wedge\vec d_2$; então $r'=\pi_1\cap\pi_2$ (analogamente $\pi_2$ com $r_2$). Ou: impor $\vec{P_1P_2}\parallel(\vec d_1\wedge\vec d_2)$ com $P_i\in r_i$.

---

## 3. Cônicas

Lugar geométrico de $Ax^2+Bxy+Cy^2+Dx+Ey+F=0$. Formas canônicas, com centro/vértice na origem:

|Cônica|Equação|Parâmetros|Focos|Extras|
|---|---|---|---|---|
|**Elipse** (eixo maior em $x$, $a>b$)|$\dfrac{x^2}{a^2}+\dfrac{y^2}{b^2}=1$|$c^2=a^2-b^2$|$(\pm c,0)$|$e=c/a<1$|
|**Elipse** (eixo maior em $y$, $a>b$)|$\dfrac{x^2}{b^2}+\dfrac{y^2}{a^2}=1$|$c^2=a^2-b^2$|$(0,\pm c)$||
|**Hipérbole** (eixo focal $x$)|$\dfrac{x^2}{a^2}-\dfrac{y^2}{b^2}=1$|$c^2=a^2+b^2$|$(\pm c,0)$|assíntotas $y=\pm\frac bax$, $e=c/a>1$|
|**Hipérbole** (eixo focal $y$)|$\dfrac{y^2}{a^2}-\dfrac{x^2}{b^2}=1$|$c^2=a^2+b^2$|$(0,\pm c)$|assíntotas $y=\pm\frac abx$|
|**Parábola**|$x^2=4py$||$(0,p)$|diretriz $y=-p$, $e=1$|
|**Parábola**|$y^2=4px$||$(p,0)$|diretriz $x=-p$|

**Definições focais (o "porquê" geométrico):**

- Elipse: $|PF_1|+|PF_2|=2a$ (soma constante).
- Hipérbole: $\lvert \lvert PF_1\rvert-\lvert PF_2\rvert \rvert=2a$ (diferença constante).
- Parábola: $|PF|=d(P,\text{diretriz})$.
- Excentricidade unifica: $|PF|=e\cdot d(P,\text{diretriz})$.

### Como identificar e esboçar

1. **Sinais e tipo:** sem termo $xy$: $A,C$ mesmo sinal ⇒ elipse (círculo se $A=C$); sinais opostos ⇒ hipérbole; um deles zero ⇒ parábola.
2. Com $xy$: discriminante $B^2-4AC$: $<0$ elipse, $=0$ parábola, $>0$ hipérbole (não degeneradas).
3. **Completar quadrados** para achar centro/vértice (translação $x\to x-h$, $y\to y-k$).
4. Com termo $xy$: **rotação** por $\theta$ tal que $\tan 2\theta=\dfrac{B}{A-C}$ ($\cot2\theta=\frac{A-C}{B}$) elimina $xy$.
5. Esboce: eixos, vértices, focos, assíntotas (hipérbole: retângulo auxiliar $2a\times2b$).
6. Cuidado com **casos degenerados** (ponto, vazio, retas).

> [!tip] Hipérbole: qual eixo? O eixo focal é o da variável de sinal **positivo** (quando o lado direito é $+1$).

---

## 4. Superfícies quádricas

Equação de 2º grau em $x,y,z$. Formas canônicas (eixo destacado em **negrito**):

|Superfície|Equação|Como reconhecer|
|---|---|---|
|**Elipsoide**|$\frac{x^2}{a^2}+\frac{y^2}{b^2}+\frac{z^2}{c^2}=1$|3 quadrados, todos $+$, $=1$|
|**Hiperboloide de 1 folha**|$\frac{x^2}{a^2}+\frac{y^2}{b^2}-\frac{z^2}{c^2}=1$|2 sinais $+$, 1 $-$, $=1$. Eixo = variável de sinal **diferente** ($z$)|
|**Hiperboloide de 2 folhas**|$-\frac{x^2}{a^2}-\frac{y^2}{b^2}+\frac{z^2}{c^2}=1$|1 sinal $+$, 2 $-$, $=1$. Eixo = variável $+$ ($z$)|
|**Cone elíptico**|$\frac{x^2}{a^2}+\frac{y^2}{b^2}=\frac{z^2}{c^2}$|Lado direito $0$ (homogêneo)|
|**Parabolóide elíptico**|$z=\frac{x^2}{a^2}+\frac{y^2}{b^2}$|1 variável linear, quadrados de **mesmo** sinal|
|**Parabolóide hiperbólico** (sela)|$z=\frac{x^2}{a^2}-\frac{y^2}{b^2}$|1 variável linear, quadrados de sinais **opostos**|
|**Cilindro elíptico**|$\frac{x^2}{a^2}+\frac{y^2}{b^2}=1$|**Falta uma variável** ($z$)|
|**Cilindro hiperbólico**|$\frac{x^2}{a^2}-\frac{y^2}{b^2}=1$|idem|
|**Cilindro parabólico**|$y=x^2$|idem|

> [!important] Regra dos cilindros Se a equação **não contém uma das variáveis**, é um cilindro com **eixo (geratrizes) paralelo ao eixo dessa variável**, e a base é a cônica no plano das outras duas. Ex. da prova antiga: $\frac{x^2}{a^2}+\frac{y^2}{b^2}=1$ em $\mathbb R^3$ ⇒ cilindro elíptico de eixo $z$. ✅

### Técnica: traços e seções

Para visualizar e classificar, cortar por planos:

- **Traços nos planos coordenados:** $z=0$, $x=0$, $y=0$.
- **Seções paralelas:** $z=k$ (curvas de nível). Mostra como a curva cresce/encolhe com $k$.
- Exemplos:
    - Parabolóide hiperbólico $z=\frac{x^2}{a^2}-\frac{y^2}{b^2}$: $z=k\neq0$ dá **hipérboles**; $z=0$ dá **duas retas** ($y=\pm\frac bax$); $x=k$ dá parábolas voltadas p/ baixo; $y=k$ dá parábolas voltadas p/ cima.
    - Hiperboloide de 2 folhas: $z=k$ com $|k|<c$ dá **conjunto vazio** (por isso duas folhas separadas).
    - Cone: $z=k$ dá elipses; $z=0$ dá um ponto; $x=0$ dá duas retas.
- **Superfícies de revolução:** se $a=b$ nas formas acima, as seções $z=k$ são círculos.

### Translação

Completar quadrados também vale em 3D: $\frac{(x-h)^2}{a^2}+\dots$ desloca o centro para $(h,k,l)$.

---

## 5. Exercícios da Lista 1: guia + respostas para conferir

> [!warning] Confira as contas Estas respostas foram calculadas por mim. **Refaça** e compare; o exercício só vale se você fizer.

**Ex. 3** ($\vec u\perp(-3,0,1)$, etc.): sistema $c=3a$, $a+4b+5c=24$, $-a+b=1$ ⇒ $\vec u=(1,2,3)$. $\vec v=\frac{20}{\sqrt3}(1,1,1)$. $\vec t=\pm\frac{1}{\sqrt6}(1,-2,1)$ (é $(1,1,1)\wedge(1,2,3)$ normalizado). $\vec w$ não é único; ex.: $\vec w=10\sqrt2 (0,1,-1)$ ⇒ $\operatorname{proj}_{\vec u}\vec w=-\frac{5\sqrt2}{7}(1,2,3)$.

**Ex. 4:** $\vec{AB}\wedge\vec{AC}=(-1,-1,1)$, $\Vert \cdot\Vert =\sqrt3$ ⇒ área $=\frac{\sqrt3}{2}$, $h=\frac{\sqrt3}{\sqrt2}=\frac{\sqrt6}{2}$.

**Ex. 5:** coplanares ⇔ $\vec u\cdot(\vec v\wedge\vec w)=0$ (volume do paralelepípedo nulo).

**Ex. 6:** $r:(0,1,2)+t(2,0,-1)$. $\vec n_\pi=\vec{AB}\wedge\vec{AC}=(-3,5,-6)$ ⇒ $\pi:-3x+5y-6z+7=0$. $\alpha:y+z=0$ tem $\vec n=(0,1,1)$, não paralelo ⇒ concorrentes; interseção é a reta com direção $(11,3,-3)$ passando por $(\tfrac73,0,0)$.

**Ex. 7:** $B\in s$ ($A+1\cdot(0,2,1)=B$). A reta $t$ tem ponto $B$ e uma direção **à sua escolha** (não paralela a $s$). Use $d(A,t)=\Vert \vec{AB}\wedge\vec d_t\Vert /\Vert \vec d_t\Vert$ e $\cos\theta=\frac{|\vec v\cdot\vec d_t|}{\Vert \vec v\Vert \Vert \vec d_t\Vert }$. Refaça mostrando que o resultado depende da escolha.

**Ex. 8:** a) $\vec d_r=(2,4,1)\nparallel\vec d_s=(2,3,1)$ e $[\vec d_r,\vec d_s,\vec{P_rP_s}]=3\neq0$ ⇒ reversas. b) $t=-\frac5{14}$ ⇒ $P=(\frac27,-\frac{10}7,\frac{37}{14})$. $\sin\theta=\frac{28}{\sqrt{21}\sqrt{38}}$. Para $d(Q,\beta)=2$: $\frac{|10+28t|}{\sqrt{38}}=2$ ⇒ $t=\frac{-10\pm2\sqrt{38}}{28}$ (dois pontos $Q$).

**Ex. 9:** direções $(0,1,3)$ e $(1,1,1)$ não paralelas; sistema de interseção incompatível ⇒ **reversas**. Direção de $r'$: $(-2,3,-1)$. $\alpha: y+3z=11$; $\beta: x+y+z=6$.

**Ex. 10:**

- $\frac{x^2}{25}+\frac{y^2}{16}=1$: $a=5,b=4,c=3$, focos $(\pm3,0)$.
- $\frac{x^2}{9}+\frac{y^2}{16}=1$: eixo maior em $y$, $c=\sqrt7$, focos $(0,\pm\sqrt7)$.
- $25x^2-144y^2=9$ ⇒ $\frac{x^2}{9/25}-\frac{y^2}{1/16}=1$: $c=\frac{13}{20}$, focos $(\pm\frac{13}{20},0)$, assíntotas $y=\pm\frac5{12}x$.
- $y^2-16x^2=1$: eixo focal $y$, $c=\frac{\sqrt{17}}4$, focos $(0,\pm\frac{\sqrt{17}}{4})$, assíntotas $y=\pm4x$.
- $y^2=-8x$: $p=-2$, foco $(-2,0)$, diretriz $x=2$.

**Ex. 11:** o enunciado tem **erros de digitação** (ex.: "$4y^2+3y^2$" deve ser $4x^2+3y^2$; "$y^2-4y^2$" deve ser $y^2-4x^2$ ou similar). Confirme com o professor. Método: completar quadrados → identificar → focos/diretriz/assíntotas. $x=2y^2-3y+1$ é parábola com eixo horizontal.

---

## 6. Perguntas de checagem (tipo prova "geométrica")

> [!question]- Por que $\Vert \vec u\wedge\vec v\Vert$ é a área do paralelogramo? Base $\Vert \vec u\Vert$ × altura $\Vert \vec v\Vert \sin\theta$.

> [!question]- Por que o ângulo reta–plano usa seno? A normal é perpendicular ao plano; o ângulo com a reta é o complemento do ângulo com a normal, e $\cos(90°-\theta)=\sin\theta$.

> [!question]- O que $[\vec u,\vec v,\vec w]=0$ diz geometricamente? Volume do paralelepípedo zero ⇒ os vetores estão no mesmo plano.

> [!question]- Como saber se duas retas são reversas sem resolver sistema? Não paralelas + produto misto $[\vec d_1,\vec d_2,\vec{A_1A_2}]\neq0$.

> [!question]- Como distinguir um cilindro de uma cônica/quádrica "de verdade"? Falta uma variável na equação ⇒ cilindro.

> [!question]- Cone × hiperboloide × parabolóide (por sinais)? Lado direito $0$ ⇒ cone. $\pm1$ ⇒ elipsoide/hiperboloide (conte os sinais). Variável linear no lado esquerdo/direito ⇒ parabolóide (sinais iguais = elíptico; opostos = sela).

> [!question]- Por que hiperboloide de 2 folhas tem seção vazia para $|k|<c$? $\frac{x^2}{a^2}+\frac{y^2}{b^2}=\frac{k^2}{c^2}-1<0$ é impossível.

