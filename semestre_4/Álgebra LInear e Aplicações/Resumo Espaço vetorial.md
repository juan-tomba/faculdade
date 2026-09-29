## 1. Espaço vetorial $\mathbb R^n$

Um vetor $\mathbf x\in\mathbb R^n$ é uma matriz $n\times1$. Soma e multiplicação por escalar são feitas termo a termo.

**Um espaço vetorial** é qualquer conjunto com soma e produto por escalar que satisfaçam as 8 propriedades:

1. $\mathbf x+\mathbf y=\mathbf y+\mathbf x$ (comutatividade)
2. $(\mathbf x+\mathbf y)+\mathbf z=\mathbf x+(\mathbf y+\mathbf z)$ (associatividade)
3. existe $\mathbf 0$ com $\mathbf x+\mathbf 0=\mathbf x$
4. existe $-\mathbf x$ com $\mathbf x+(-\mathbf x)=\mathbf 0$
5. $c(\mathbf x+\mathbf y)=c\mathbf x+c\mathbf y$
6. $(c+d)\mathbf x=c\mathbf x+d\mathbf x$
7. $c(d\mathbf x)=(cd)\mathbf x$
8. $1\mathbf x=\mathbf x$

$\mathbb R,\ \mathbb R^2,\ \mathbb R^3,\dots,\mathbb R^n$ são espaços vetoriais.

### Produto escalar (revisão do tópico 1, agora em $\mathbb R^n$)

$$\langle\mathbf x,\mathbf y\rangle=\sum_i x_iy_i\qquad\Vert\mathbf x\Vert=\sqrt{\langle\mathbf x,\mathbf x\rangle}$$

- Ortogonais ⇔ $\langle\mathbf x,\mathbf y\rangle=0$.
- Projeção de $\mathbf x$ em $\mathbf y$: $$\operatorname{proj}_{\mathbf y}(\mathbf x)=\langle\mathbf x,\mathbf y\rangle\frac{\mathbf y}{\Vert\mathbf y\Vert^2}$$

### Combinação linear

$$\mathbf y=c_1\mathbf x_1+c_2\mathbf x_2+\cdots+c_k\mathbf x_k$$ É o conceito central: tudo em álgebra linear é combinar vetores. Todo $\mathbf x\in\mathbb R^n$ é combinação dos canônicos $\mathbf e_1,\dots,\mathbf e_n$: $\ \mathbf x=x_1\mathbf e_1+\cdots+x_n\mathbf e_n$.

---

## 2. Subespaço vetorial

Um **subespaço** $\mathcal S\subseteq\mathbb R^n$ é um subconjunto não vazio que é ele mesmo um espaço vetorial. Na prática, testa-se:

> [!important] Teste de subespaço
> 
> 1. $\mathbf 0\in\mathcal S$ (**o vetor nulo pertence a todo subespaço**)
> 2. $\mathbf u,\mathbf v\in\mathcal S\Rightarrow\mathbf u+\mathbf v\in\mathcal S$ (fechado na soma)
> 3. $\mathbf u\in\mathcal S,\ c\in\mathbb R\Rightarrow c\mathbf u\in\mathcal S$ (fechado no produto por escalar)
> 
> (2 e 3 juntos: toda combinação linear de elementos de $\mathcal S$ fica em $\mathcal S$.)

**Geometria em $\mathbb R^3$ (o professor gosta disso):**

|É subespaço|Não é subespaço|
|---|---|
|$\lbrace\mathbf 0\rbrace$|reta ou plano **que não passa pela origem**|
|reta pela origem|uma esfera, um cone "só a parte de cima"|
|plano pela origem ($ax+by+cz=0$)|união de dois planos distintos pela origem|
|todo o $\mathbb R^3$|o conjunto de vetores fora de um subespaço|

**Exemplo do notebook:** o plano $x+y-z=0$. Os vetores $\mathbf x_1=(1,0,1)$ e $\mathbf x_2=(0,1,1)$ pertencem a ele (verifique substituindo: $1+0-1=0$ e $0+1-1=0$) e toda combinação $a\mathbf x_1+b\mathbf x_2=(a,b,a+b)$ também satisfaz a equação. Logo é subespaço.

> [!warning] Ligação com a prova antiga
> 
> - $ax+by+cz+d=0$ só é subespaço se $d=0$ (**Q4c**).
> - Os vetores **fora** do espaço coluna de $\mathbf A$ **não** formam subespaço: nem contêm o $\mathbf 0$ (**Q4d**).

---

## 3. Independência linear, base e dimensão

### LI e LD

Vetores $\mathbf x_1,\dots,\mathbf x_k$ são **linearmente independentes (LI)** se $$c_1\mathbf x_1+\cdots+c_k\mathbf x_k=\mathbf 0\ \Longrightarrow\ c_1=\cdots=c_k=0$$ Se existe combinação nula com algum $c_i\neq0$, são **linearmente dependentes (LD)** (algum vetor é combinação dos outros).

**Geometria:**

- 2 vetores LD em $\mathbb R^3$ ⇔ **colineares**.
- 3 vetores LD ⇔ **coplanares** (mesmo plano pela origem). Ligação direta com o produto misto nulo do tópico 1.
- Mais de $n$ vetores em $\mathbb R^n$ são **sempre LD**.

**Teste prático com LU:** $n$ vetores em $\mathbb R^n$, como colunas de $\mathbf X$, são LI ⇔ a $\mathbf U$ da decomposição **não tem linha nula** (pivô em todas as colunas).

### Base

Um conjunto $V=\lbrace\mathbf x_1,\dots,\mathbf x_k\rbrace$ é **base** de $\mathcal S$ se:

1. é **LI**, e
2. **gera** $\mathcal S$ (todo vetor de $\mathcal S$ é combinação de $V$).

Ou seja, base = **número mínimo** de vetores que geram o espaço.

> [!example]- Exemplo do notebook $[1,0,0],\ [0,1,0],\ [-2,-2,0]$ geram o mesmo plano ($z=0$) que $[1,0,0],\ [0,1,0]$. O terceiro é redundante (é LD), e a base tem 2 vetores.

**Coordenadas:** com uma base fixada, cada $\mathbf x\in\mathcal S$ tem **coeficientes únicos** $c_1,\dots,c_k$ tais que $\mathbf x=\sum c_i\mathbf x_i$.

> [!example]- Por que os coeficientes são únicos? Se $\mathbf x=\sum c_i\mathbf x_i=\sum a_i\mathbf x_i$, então $\sum(c_i-a_i)\mathbf x_i=\mathbf 0$. Como os $\mathbf x_i$ são LI, $c_i=a_i$.

Para achar as coordenadas de $\mathbf x_3$ na base $\lbrace\mathbf x_1,\mathbf x_2\rbrace$ de $\mathbb R^2$, resolve-se o sistema com $\mathbf x_1,\mathbf x_2$ como colunas: $$\begin{bmatrix}0.5&-0.5\cr 0.5&0.7\end{bmatrix}\begin{bmatrix}c_1\cr c_2\end{bmatrix}=\begin{bmatrix}0.8\cr -0.7\end{bmatrix}$$

Há **infinitas bases** para um mesmo espaço: qualquer conjunto LI que o gere.

### Dimensão

**$\dim(\mathcal S)$ = número de vetores de uma base** (é o mesmo para todas as bases). Em particular $\dim\mathbb R^n=n$.

> [!important] Fatos que caem em prova Em um espaço de dimensão $n$:
> 
> - nenhum conjunto com **mais** de $n$ vetores pode ser LI;
> - nenhum conjunto com **menos** de $n$ vetores pode gerar o espaço;
> - $n$ vetores: **LI ⇔ geram ⇔ base** (basta verificar uma das duas condições).

Dimensões em $\mathbb R^3$: $\lbrace\mathbf 0\rbrace$ tem dim 0, reta pela origem dim 1, plano pela origem dim 2, $\mathbb R^3$ dim 3.

---

## 4. Transformações lineares

$T:\mathbb R^n\to\mathbb R^m$ é **linear** se para todos $\mathbf x_1,\mathbf x_2$ e escalares $c_1,c_2$: $$T(c_1\mathbf x_1+c_2\mathbf x_2)=c_1T(\mathbf x_1)+c_2T(\mathbf x_2)$$ Consequências: $T(\mathbf 0)=\mathbf 0$ e $T$ leva retas pela origem em retas pela origem (ou no ponto $\mathbf 0$).

> [!warning] Teste rápido de não linearidade Se $T(\mathbf 0)\neq\mathbf 0$, **não** é linear. Ex.: $T(\mathbf x)=\mathbf x+\mathbf b$ (com $\mathbf b\neq\mathbf 0$) é uma translação, e não é linear. Também não são lineares $x\mapsto x^2$ e $x\mapsto\sin x$.

### Toda transformação linear é uma matriz

$$T(\mathbf x)=\mathbf A\mathbf x\qquad\mathbf A=\begin{bmatrix}|&&|\cr T(\mathbf e_1)&\cdots&T(\mathbf e_n)\cr |&&|\end{bmatrix}$$ **As colunas de $\mathbf A$ são as imagens dos vetores da base canônica.** Dimensão de $\mathbf A$: $m\times n$ ($m$ linhas, $n$ colunas). Esta é a resposta da **Q2a**.

> [!example]- Por quê? $\mathbf x=\sum x_i\mathbf e_i\Rightarrow T(\mathbf x)=\sum x_iT(\mathbf e_i)$, que é exatamente $\mathbf A\mathbf x$ como combinação das colunas.

**Exemplos geométricos em $\mathbb R^2$ (para desenhar):**

|Transformação|Matriz|
|---|---|
|Rotação de $\theta$|$\begin{bmatrix}\cos\theta&-\sin\theta\cr \sin\theta&\cos\theta\end{bmatrix}$|
|Reflexão no eixo $x$|$\begin{bmatrix}1&0\cr 0&-1\end{bmatrix}$|
|Projeção no eixo $x$|$\begin{bmatrix}1&0\cr 0&0\end{bmatrix}$ (**não** invertível: colapsa o plano numa reta)|
|Escala por $c$|$c\mathbf I$|

**Composição** $T_2\circ T_1$ corresponde ao produto $\mathbf A_2\mathbf A_1$ (a ordem importa).

**Posto (rank):** número de colunas LI de $\mathbf A$ = $\dim C(\mathbf A)$.

**Injetora e sobrejetora:**

- $T$ é **injetora** ⇔ $N(\mathbf A)=\lbrace\mathbf 0\rbrace$ ⇔ colunas LI ⇔ $r=n$.
- $T$ é **sobrejetora** ⇔ $C(\mathbf A)=\mathbb R^m$ ⇔ $r=m$.
- Invertível ⇔ as duas (matriz quadrada, $r=n=m$).

---

## 5. Os quatro espaços fundamentais

Seja $\mathbf A$ uma matriz $m\times n$, vista como $\mathbf A:\mathbb R^n\to\mathbb R^m$, com posto $r$.

| Espaço              | Notação             | Definição                                                                                                | Vive em       | Dimensão |
| ------------------- | ------------------- | -------------------------------------------------------------------------------------------------------- | ------------- | -------- |
| **Coluna** (imagem) | $C(\mathbf A)$      | gerado pelas colunas; $\lbrace\mathbf{Ax}\rbrace$                                                        | $\mathbb R^m$ | $r$      |
| **Nulo** (núcleo)   | $N(\mathbf A)$      | $\lbrace\mathbf x:\mathbf{Ax}=\mathbf 0\rbrace$                                                          | $\mathbb R^n$ | $n-r$    |
| **Linha**           | $C(\mathbf A^\top)$ | gerado pelas linhas                                                                                      | $\mathbb R^n$ | $r$      |
| **Nulo à esquerda** | $N(\mathbf A^\top)$ | $\lbrace\mathbf y:\mathbf A^\top\mathbf y=\mathbf 0\rbrace$, isto é, $\mathbf y^\top\mathbf A=\mathbf 0$ | $\mathbb R^m$ | $m-r$    |

> [!important] Regra para memorizar onde cada um mora Os espaços ligados às **colunas** de $\mathbf A$ vivem em $\mathbb R^m$ (tamanho de uma coluna): $C(\mathbf A)$ e $N(\mathbf A^\top)$. Os ligados às **linhas** vivem em $\mathbb R^n$ (tamanho de uma linha): $C(\mathbf A^\top)$ e $N(\mathbf A)$. **Q2b da prova antiga:** espaço linha e espaço nulo em $\mathbb R^n$; espaço coluna e nulo à esquerda em $\mathbb R^m$.

- **Espaço coluna** $C(\mathbf A)$: $\mathbf b\in C(\mathbf A)$ ⇔ $\mathbf{Ax}=\mathbf b$ tem solução. Também chamado de **espaço imagem**.
- **Espaço nulo** $N(\mathbf A)$: é subespaço, pois $\mathbf A(a_1\mathbf v_1+a_2\mathbf v_2)=a_1\mathbf{Av}_1+a_2\mathbf{Av}_2=\mathbf 0$. Também chamado de **núcleo**.
- $\mathbf A$ é injetora ⇔ $N(\mathbf A)=\lbrace\mathbf 0\rbrace$. Para $\mathbf A$ quadrada, isso equivale a ser **invertível**.
- $\dim N(\mathbf A)>0$ só ocorre se as colunas de $\mathbf A$ são **LD**.

> [!tip] Cuidado: $\mathbf A^\top$ não é a inversa $\mathbf A^\top:\mathbb R^m\to\mathbb R^n$ é uma transformação no sentido oposto, mas **não** desfaz $\mathbf A$.

---

## 6. Teoremas da dimensão

### Teorema 1: posto por linhas = posto por colunas

$$\dim C(\mathbf A)=\dim C(\mathbf A^\top)=r$$

> [!example]- Ideia da demonstração Seja $\mathbf v_1,\dots,\mathbf v_k$ base de $C(\mathbf X)$. Cada coluna é combinação delas, então $\mathbf X=\mathbf V\mathbf C$, com $\mathbf V$ de tamanho $m\times k$. Olhando por **linhas**, cada linha de $\mathbf X$ é combinação das $k$ linhas de $\mathbf C$. Logo $\dim(\text{espaço linha})\leq k=\dim C(\mathbf X)$. Aplicando o mesmo a $\mathbf X^\top$ vem a desigualdade contrária. $\blacksquare$

### Teorema 2: núcleo e imagem (posto + nulidade)

$$\boxed{\ \dim N(\mathbf A)+\dim C(\mathbf A)=n\ }$$ **dim do núcleo + dim da imagem = dim do domínio** ($n$ = número de **colunas**).

> [!example]- Ideia da demonstração Tome base $\lbrace\mathbf v_1,\dots,\mathbf v_r\rbrace$ de $N(\mathbf A)$ e estenda-a com $\mathbf w_1,\dots,\mathbf w_{n-r}$ até uma base de $\mathbb R^n$. Como $\mathbf{Av}_i=\mathbf 0$, todo $\mathbf{Ax}$ é combinação de $\mathbf{Aw}_j$. Eles são LI: se $\sum b_j\mathbf{Aw}_j=\mathbf 0$, então $\sum b_j\mathbf w_j\in N(\mathbf A)$, logo é combinação dos $\mathbf v_i$, e a independência da base de $\mathbb R^n$ força todos os coeficientes a serem zero. Portanto $\dim C(\mathbf A)=n-r$. $\blacksquare$

### Consequências (com $\dim C(\mathbf A)=r$)

1. $\dim C(\mathbf A^\top)=r$
2. $\dim N(\mathbf A)=n-r$
3. $\dim N(\mathbf A^\top)=m-r$

**Q2c da prova antiga** ($\mathbf A$ de posto $k$): espaço linha tem dimensão $k$; espaço nulo tem $n-k$.

### Quantas soluções tem $\mathbf{Ax}=\mathbf b$? (em função de $r,m,n$)

|Caso|$\mathbf{Ax}=\mathbf b$|
|---|---|
|$r=m=n$|**uma** solução para todo $\mathbf b$ (invertível)|
|$r=n<m$ (colunas LI, "alta e fina")|**0 ou 1** solução|
|$r=m<n$ ("larga e baixa")|**infinitas** para todo $\mathbf b$|
|$r<m$ e $r<n$|**0 ou infinitas**|

Resumo geométrico (é a **Q3** da prova):

- **Única:** colunas LI **e** $\mathbf b\in C(\mathbf A)$.
- **Infinitas:** colunas LD **e** $\mathbf b\in C(\mathbf A)$. A solução geral é $\mathbf x_p+N(\mathbf A)$, isto é, um ponto mais um subespaço inteiro (uma reta, um plano...).
- **Nenhuma:** $\mathbf b\notin C(\mathbf A)$.

---

## 7. Encontrando bases dos quatro espaços via LU

Use $\mathbf{PA}=\mathbf{LU}$ (ou $\mathbf A=\mathbf P^\top\mathbf{LU}$). Como $\mathbf L$ é invertível: $$\mathbf{Ax}=\mathbf 0\iff\mathbf{Ux}=\mathbf 0\ \Rightarrow\ N(\mathbf A)=N(\mathbf U),\qquad C(\mathbf A^\top)=C(\mathbf U^\top)$$ (mas $C(\mathbf A)\neq C(\mathbf U)$ em geral!)

Forma típica de $\mathbf U$ (escada), com **pivôs** (primeira entrada não nula de cada linha não nula):

$$\begin{bmatrix}\odot&\ast &\ast &\ast &\ast \cr 0&0&\odot&\ast &\ast \cr 0&0&0&0&\odot\cr 0&0&0&0&0\end{bmatrix}$$

> [!important] Receita
> 
> |Espaço|Como obter uma base|
> |---|---|
> |$C(\mathbf A)$|as colunas **de $\mathbf A$** (originais!) nas **posições dos pivôs** de $\mathbf U$|
> |$C(\mathbf A^\top)$|as **linhas não nulas de $\mathbf U$**|
> |$N(\mathbf A)$|resolver $\mathbf{Ux}=\mathbf 0$: **uma solução especial para cada variável livre** (coluna sem pivô)|
> |$N(\mathbf A^\top)$|resolver $\mathbf A^\top\mathbf y=\mathbf 0$; ou usar as linhas nulas de $\mathbf U$ (ver abaixo)|
> 
> $r$ = número de pivôs. Variáveis livres: $n-r$.

**Por que as colunas com pivô de $\mathbf A$ servem?** $\mathbf a_i=\mathbf P^\top\mathbf{Lu}_i$ e $\mathbf P^\top\mathbf L$ é invertível. Então uma combinação nula de colunas de $\mathbf A$ vira uma combinação nula das mesmas colunas de $\mathbf U$, e as colunas com pivô de $\mathbf U$ são LI. As demais são combinação das colunas com pivô.

> [!warning] Erro clássico Para a base do espaço **coluna** use as colunas de $\mathbf A$, **não** as de $\mathbf U$. A eliminação preserva o espaço linha e o núcleo, mas **muda** o espaço coluna.

**Nulo à esquerda pela LU:** se a linha $i$ de $\mathbf U$ é nula, então $\mathbf y^\top=\mathbf e_i^\top\mathbf L^{-1}\mathbf P$ satisfaz $\mathbf y^\top\mathbf A=\mathbf 0$. Equivale a resolver $\mathbf L^\top\mathbf w=\mathbf e_i$ e tomar $\mathbf y=\mathbf P^\top\mathbf w$. Cada linha nula de $\mathbf U$ dá um vetor da base ($m-r$ no total).

### Exemplo completo

$$\mathbf A=\begin{bmatrix}1&2&0&1\cr 2&4&1&4\cr 3&6&1&5\end{bmatrix}\quad(m=3,\ n=4)$$ Eliminação (sem trocas): $L_2-2L_1=(0,0,1,2)$, $L_3-3L_1=(0,0,1,2)$, $L_3-L_2=\mathbf 0$. $$\mathbf L=\begin{bmatrix}1&0&0\cr 2&1&0\cr 3&1&1\end{bmatrix}\qquad\mathbf U=\begin{bmatrix}1&2&0&1\cr 0&0&1&2\cr 0&0&0&0\end{bmatrix}$$ Pivôs nas **colunas 1 e 3** ⇒ $r=2$.

|Espaço|Base|Dimensão|
|---|---|---|
|$C(\mathbf A)\subset\mathbb R^3$|$(1,2,3)$ e $(0,1,1)$ (colunas 1 e 3 de $\mathbf A$)|$2=r$|
|$C(\mathbf A^\top)\subset\mathbb R^4$|$(1,2,0,1)$ e $(0,0,1,2)$ (linhas de $\mathbf U$)|$2=r$|
|$N(\mathbf A)\subset\mathbb R^4$|livres $x_2=s,\ x_4=t$ ⇒ $x_3=-2t,\ x_1=-2s-t$: $(-2,1,0,0)$ e $(-1,0,-2,1)$|$2=n-r$|
|$N(\mathbf A^\top)\subset\mathbb R^3$|$(1,1,-1)$ (confira: $\mathbf y^\top\mathbf A=\mathbf 0$)|$1=m-r$|

Confere os teoremas: $\dim N+\dim C=2+2=4=n$ ✔, e $\dim N(\mathbf A^\top)=3-2=1$ ✔.

---

## 8. Como os quatro espaços se encaixam (imagem mental)

```
        R^n (domínio)                        R^m (contradomínio)
  ┌─────────────────────────┐          ┌─────────────────────────┐
  │  C(Aᵀ)  dim r  (linha)  │ ──A──▶   │  C(A)   dim r  (coluna) │
  │  N(A)   dim n-r (nulo)  │ ──A──▶ 0 │  N(Aᵀ)  dim m-r         │
  └─────────────────────────┘          └─────────────────────────┘
```

- $\mathbf A$ leva o **espaço linha** de forma bijetiva sobre o **espaço coluna** (ambos de dim $r$).
- $\mathbf A$ **colapsa** o espaço nulo no vetor $\mathbf 0$.
- Nenhum vetor de $\mathbb R^n$ chega em $N(\mathbf A^\top)$ além do $\mathbf 0$.
- **Prévia do tópico 6 (ortogonalidade):** em cada lado os dois subespaços são **ortogonais** e completam o espaço: $N(\mathbf A)\perp C(\mathbf A^\top)$ em $\mathbb R^n$ e $N(\mathbf A^\top)\perp C(\mathbf A)$ em $\mathbb R^m$. (Verifique no exemplo: $(1,1,-1)\cdot(1,2,3)=0$ e $(1,1,-1)\cdot(0,1,1)=0$.)

---

## 9. Prova antiga (16/09/2025): questões deste tópico

### Q2 (2 pts): $\mathbf A:\mathbb R^n\to\mathbb R^m$ de posto $k$, com $k<n$ e $k<m$

a) **$m$ linhas e $n$ colunas.** b) Espaço **linha** e **nulo** em $\mathbb R^n$; espaço **coluna** e **nulo à esquerda** em $\mathbb R^m$. c) $\dim(\text{linha})=k$ e $\dim(\text{nulo})=n-k$.

### Q3 (2,5 pts): sistema $\mathbf{Ax}=\mathbf b$ com $\mathbf A$ $m\times n$

a) **Única:** colunas de $\mathbf A$ LI e $\mathbf b\in C(\mathbf A)$. b) **Infinitas:** colunas LD e $\mathbf b\in C(\mathbf A)$. c) **Nenhuma:** $\mathbf b\notin C(\mathbf A)$.

### Q4 (3 pts, 0,5 cada): verdadeiro ou falso

|Item|Resposta|Justificativa|
|---|---|---|
|a) $\frac{x^2}{a^2}+\frac{y^2}{b^2}=1$ em $\mathbb R^3$ é cilindro elíptico de eixo $z$|**V**|falta $z$ ⇒ cilindro; ver [[SME0142 - Resumo GA (P1)]]|
|b) $z=\frac{x^2}{a^2}-\frac{y^2}{b^2}$ é parabolóide hiperbólico de eixo $z$|**V**|sela|
|c) $ax+by+cz+d=0$ é subespaço para quaisquer $a,b,c,d$|**F**|só se $d=0$|
|d) vetores fora de $C(\mathbf A)$ formam subespaço|**F**|não contêm $\mathbf 0$ (e a soma de dois deles pode cair dentro de $C(\mathbf A)$)|
|e) se existe $\mathbf x\neq\mathbf 0$ com $\mathbf{Ax}=\mathbf 0$, o posto é no máximo $n-1$|**F** no gabarito (ver aviso)|posto + nulidade $=n$|
|f) $\mathbf A_{m\times n}$ com $n>m$ ⇒ $\dim N(\mathbf A)>0$|**V**|$\dim N=n-r\geq n-m>0$|

> [!question] Sobre o item (e) Se existe $\mathbf x\neq\mathbf 0$ no núcleo, então $\dim N(\mathbf A)\geq1$ e, pelo teorema do núcleo e da imagem, $r=n-\dim N\leq n-1$. **A afirmação parece verdadeira.** O gabarito marca **F** com a justificativa "pode ser que $m<n-1$", que não contradiz um "no máximo" (se $m<n-1$, o posto é até menor). Provável erro do gabarito; vale confirmar na vista de prova ou com o monitor. Na dúvida, escreva a justificativa completa com o teorema.

### Como responder em prova

- Q2: dê a **resposta curta** e, se sobrar espaço, cite o teorema $\dim N+\dim C=n$.
- Q3: sempre fale das **duas coisas**: independência das colunas **e** onde está $\mathbf b$.
- V/F: se falso, dê **contraexemplo ou motivo** de uma linha (ex.: "não contém o vetor nulo").

---

## 10. Perguntas de checagem

> [!question]- Como provar que um conjunto é subespaço? Verificar $\mathbf 0$ (ou não vazio), fechamento na soma e no produto por escalar. Para mostrar que **não é**, basta um contraexemplo (ex.: sem o zero).

> [!question]- Dois vetores LD em $\mathbb R^3$: qual a geometria? Estão na mesma reta pela origem (colineares). Três LD: mesmo plano pela origem.

> [!question]- Se $\mathbf A$ é $5\times3$ com posto 3, o que se pode dizer? $N(\mathbf A)=\lbrace\mathbf 0\rbrace$ (dim $0$); $\dim C(\mathbf A)=3$ em $\mathbb R^5$; $\dim N(\mathbf A^\top)=2$; $\mathbf{Ax}=\mathbf b$ tem 0 ou 1 solução.

> [!question]- Se $\mathbf A$ é $3\times5$ com posto 3? $\dim N(\mathbf A)=2$; $C(\mathbf A)=\mathbb R^3$ (sobrejetora); $N(\mathbf A^\top)=\lbrace\mathbf 0\rbrace$; $\mathbf{Ax}=\mathbf b$ sempre tem infinitas soluções.

> [!question]- Qual a diferença entre base do espaço coluna e do espaço linha via LU? Coluna: colunas **de $\mathbf A$** nas posições dos pivôs. Linha: linhas **não nulas de $\mathbf U$**.

> [!question]- Por que $N(\mathbf A)=N(\mathbf U)$ mas $C(\mathbf A)\neq C(\mathbf U)$? A eliminação faz operações **entre linhas**, que não mudam as soluções de $\mathbf{Ax}=\mathbf 0$ (nem o espaço linha), mas mudam o vetor $\mathbf{Ax}$ (portanto o espaço coluna).

> [!question]- Onde vive cada um dos quatro espaços? $C(\mathbf A),N(\mathbf A^\top)\subset\mathbb R^m$; $C(\mathbf A^\top),N(\mathbf A)\subset\mathbb R^n$.

