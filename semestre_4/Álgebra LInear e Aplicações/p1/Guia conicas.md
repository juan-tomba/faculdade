## 0. O que é uma quádrica?

Uma **quádrica** é uma superfície em $\mathbb R^3$ dada por uma equação de **2º grau** em $x,y,z$ (aparecem termos como $x^2$, $y^2$, $z^2$, e às vezes $x$, $y$, $z$ sozinhos).

Ela é a versão 3D das cônicas (elipse, hipérbole, parábola), que são as curvas de 2º grau em $\mathbb R^2$.

Você **não precisa decorar 9 fórmulas soltas**. Basta um algoritmo de 3 perguntas e um macete de sinais.

---

## 1. O algoritmo (3 perguntas, sempre nessa ordem)

> [!important] Antes de tudo **Passo 0:** se aparecerem termos lineares junto com quadrados da mesma variável (ex.: $x^2-2x$), **complete o quadrado** para chegar em $(x-1)^2$. Isso só desloca a figura de lugar; o **tipo** não muda. **Passo 0.5:** se o lado direito for uma constante $\neq0$, **divida tudo** para o lado direito virar $+1$ (veja o exemplo mais abaixo).

### Pergunta 1: falta alguma variável?

Se a equação **não tem uma das variáveis** ($x$, $y$ ou $z$), é um **cilindro**.

- O **eixo** do cilindro é **paralelo ao eixo da variável que falta**.
- O **tipo** depende da curva que sobra no plano das outras duas variáveis (é só uma cônica):
    - elipse ⇒ cilindro **elíptico** (circunferência ⇒ circular);
    - hipérbole ⇒ cilindro **hiperbólico**;
    - parábola ⇒ cilindro **parabólico**.

> [!example] Exemplos
> 
> - $\frac{x^2}{4}+\frac{y^2}{9}=1$ em $\mathbb R^3$: falta $z$ ⇒ cilindro elíptico de eixo $z$.
> - $y^2-z^2=1$: falta $x$ ⇒ cilindro hiperbólico de eixo $x$.
> - $x=z^2$: falta $y$ ⇒ cilindro parabólico de eixo $y$.

### Pergunta 2: alguma variável aparece SEM quadrado (linear)?

Se as três variáveis existem e **uma delas aparece só linear** (sem estar ao quadrado), é um **parabolóide**.

- O **eixo** do parabolóide é a **variável linear**.
- Olhe os **sinais dos dois quadrados**:
    - **mesmo sinal** ⇒ parabolóide **elíptico** (formato de **tigela**);
    - **sinais opostos** ⇒ parabolóide **hiperbólico** (formato de **sela**, ou "batata Pringles").

> [!example] Exemplos
> 
> - $z=x^2+y^2$: $z$ linear, sinais iguais ⇒ elíptico (tigela para cima).
> - $z=x^2-y^2$: $z$ linear, sinais opostos ⇒ hiperbólico (sela).
> - $y=x^2+z^2$: agora $y$ é o linear ⇒ elíptico com **eixo $y$**.

### Pergunta 3: só quadrados (nenhuma variável linear)?

Se as três variáveis aparecem **só ao quadrado**, olhe o **lado direito**:

**(a) Lado direito $=0$ ⇒ cone.** Exemplo: $\frac{x^2}{a^2}+\frac{y^2}{b^2}=\frac{z^2}{c^2}$. O **eixo** é a variável que fica **sozinha do outro lado** (ou de sinal diferente das outras duas).

**(b) Lado direito $\neq0$ ⇒** ajuste para ficar $=+1$ e **conte os sinais negativos**:

> [!tip] O MACETE DOS SINAIS NEGATIVOS Depois de deixar o lado direito $=+1$, conte quantos termos ao quadrado têm sinal **negativo**:
> 
> |Nº de sinais negativos|Superfície|Eixo|
> |---|---|---|
> |**0**|**Elipsoide** (bola achatada)|não tem|
> |**1**|**Hiperboloide de 1 folha** ("torre de resfriamento", peça única)|a variável **negativa**|
> |**2**|**Hiperboloide de 2 folhas** (duas "tigelas" separadas)|a variável **positiva**|
> |**3**|**Vazio** (soma de negativos não dá $+1$)|não existe|
> 
> Ou seja: **número de sinais negativos = número de folhas** (0 negativos é o elipsoide, uma peça fechada).

> [!warning] Cuidado com o sinal do lado direito Se o lado direito for $-1$, **multiplique tudo por $-1$** antes de contar. Isso **troca** todos os sinais! Exemplo: $z^2-x^2-y^2=-1$ vira $x^2+y^2-z^2=1$ ⇒ **1 folha** (e não 2). Já $x^2+y^2+z^2=-1$ vira $-x^2-y^2-z^2=1$ ⇒ vazio.

---

## 2. Tabela-resumo (a "cola" para imprimir)

|Superfície|Equação típica|Reconhecer por|Eixo|
|---|---|---|---|
|**Elipsoide**|$\frac{x^2}{a^2}+\frac{y^2}{b^2}+\frac{z^2}{c^2}=1$|3 quadrados, todos $+$, $=1$|nenhum|
|**Esfera**|$x^2+y^2+z^2=r^2$|elipsoide com $a=b=c$|nenhum|
|**Hiperboloide de 1 folha**|$\frac{x^2}{a^2}+\frac{y^2}{b^2}-\frac{z^2}{c^2}=1$|1 sinal $-$, $=1$|variável do $-$ ($z$)|
|**Hiperboloide de 2 folhas**|$-\frac{x^2}{a^2}-\frac{y^2}{b^2}+\frac{z^2}{c^2}=1$|2 sinais $-$, $=1$|variável do $+$ ($z$)|
|**Cone elíptico**|$\frac{x^2}{a^2}+\frac{y^2}{b^2}=\frac{z^2}{c^2}$|só quadrados, lado direito $=0$|variável "sozinha" ($z$)|
|**Parabolóide elíptico**|$z=\frac{x^2}{a^2}+\frac{y^2}{b^2}$|1 variável linear, quadrados de **mesmo** sinal|variável linear ($z$)|
|**Parabolóide hiperbólico**|$z=\frac{x^2}{a^2}-\frac{y^2}{b^2}$|1 variável linear, quadrados de sinais **opostos**|variável linear ($z$)|
|**Cilindro elíptico**|$\frac{x^2}{a^2}+\frac{y^2}{b^2}=1$|**falta uma variável**; sobra elipse|variável que falta ($z$)|
|**Cilindro hiperbólico**|$\frac{x^2}{a^2}-\frac{y^2}{b^2}=1$|falta uma variável; sobra hipérbole|variável que falta|
|**Cilindro parabólico**|$y=x^2$|falta uma variável; sobra parábola|variável que falta ($z$)|

> [!tip] Em todos os casos, a letra do eixo muda conforme o enunciado O $z$ da tabela é só um exemplo. Se aparecer $y=x^2+z^2$, o eixo é $y$; se aparecer $x^2-y^2-z^2=1$, o negativo são dois ($y$ e $z$), então são **2 folhas** com eixo $x$.

---

## 3. A parte geométrica: cortes (traços)

O professor quer cobrar a **geometria**. A ferramenta é **cortar a superfície com planos** e ver que curva aparece. Isso permite visualizar e também justificar a resposta.

- **Corte horizontal:** $z=k$ (planos paralelos ao plano $xy$). É o "mapa de curvas de nível".
- **Cortes verticais:** $x=k$ ou $y=k$.

|Superfície|Corte $z=k$|Cortes $x=k$ e $y=k$|
|---|---|---|
|**Elipsoide**|elipses que encolhem até um **ponto** (topo) e depois **vazio**|elipses|
|**Hiperboloide de 1 folha**|**elipses** para todo $k$ (crescem com $\lvert k\rvert$; a menor está em $k=0$)|**hipérboles** (e um par de retas em certos valores de $k$)|
|**Hiperboloide de 2 folhas**|**vazio** para $\lvert k\rvert$ pequeno, um **ponto** e depois elipses que crescem|**hipérboles**|
|**Cone**|elipses que crescem com $\lvert k\rvert$; em $k=0$, só um **ponto** (o vértice)|**hipérboles**; nos planos que passam pelo eixo ($x=0$ ou $y=0$), **duas retas**|
|**Parabolóide elíptico**|**elipses** para $k>0$, **ponto** em $k=0$, **vazio** para $k<0$|**parábolas**|
|**Parabolóide hiperbólico**|**hipérboles** para $k\neq0$; em $k=0$, **duas retas** que se cruzam|**parábolas** (umas para cima, outras para baixo)|
|**Cilindro**|a **mesma cônica** para todo $k$|retas paralelas (ou a cônica, dependendo do plano)|

> [!tip] Como decorar
> 
> - **Tigela (parabolóide elíptico):** cortes horizontais são círculos/elipses, cortes verticais são parábolas.
> - **Sela (parabolóide hiperbólico):** cortes horizontais são hipérboles; um corte vertical dá parábola para cima, o outro para baixo.
> - **Cone:** corte pelo vértice dá "X" (duas retas).
> - **Hiperboloide de 2 folhas:** existe um "buraco" no meio ($z=k$ pequeno dá vazio), por isso são duas peças.

### Dois cortes que valem ouro na prova

1. **Fazer $z=0$ (ou $x=0$, $y=0$)** e ver que cônica sai. Isso confirma o tipo.
2. **Fazer $z=k$ e ver se existe** (vazio? ponto? elipse?). Quem tem "buraco" é o hiperboloide de 2 folhas.

---

## 4. Passo a passo com exemplos resolvidos

### Exemplo 1: normalizar o lado direito

$$4x^2+9y^2+36z^2=36$$ Divida por 36: $$\frac{x^2}{9}+\frac{y^2}{4}+z^2=1$$ 0 sinais negativos ⇒ **elipsoide**, com semi-eixos $3$ (em $x$), $2$ (em $y$) e $1$ (em $z$).

### Exemplo 2: completar quadrados (é uma esfera deslocada)

$$x^2+y^2+z^2-2x+4y-6z+5=0$$ Agrupe: $(x^2-2x)+(y^2+4y)+(z^2-6z)=-5$. Complete: $(x-1)^2-1+(y+2)^2-4+(z-3)^2-9=-5$, logo $$(x-1)^2+(y+2)^2+(z-3)^2=9$$ **Esfera** de centro $(1,-2,3)$ e raio $3$.

### Exemplo 3: parabolóide deslocado

$$z=x^2+y^2-2x+4y+5$$ $x^2-2x=(x-1)^2-1$ e $y^2+4y=(y+2)^2-4$. Então $z=(x-1)^2+(y+2)^2+(-1-4+5)$, ou seja $$z=(x-1)^2+(y+2)^2$$ **Parabolóide elíptico** com vértice em $(1,-2,0)$ e eixo paralelo a $z$.

### Exemplo 4: hiperboloide de 1 folha

$$x^2+y^2-z^2=1$$ 1 sinal negativo ($z$) ⇒ **1 folha**, eixo $z$. Corte $z=0$: circunferência de raio 1 (a "cintura"). Corte $z=k$: circunferência de raio $\sqrt{1+k^2}$, cresce para cima e para baixo. Como $a=b$, é de **revolução**.

### Exemplo 5: hiperboloide de 2 folhas

$$-x^2-y^2+z^2=1$$ 2 sinais negativos ⇒ **2 folhas**, eixo $z$ (o positivo). Corte $z=0$: $-x^2-y^2=1$ é **vazio**. Só existe superfície para $\lvert z\rvert\geq1$. Vértices em $(0,0,\pm1)$.

### Exemplo 6: cone

$$x^2+y^2=z^2$$ Lado direito $0$ (tudo de um lado só, sem constante) ⇒ **cone circular**, eixo $z$. Corte $z=k$: circunferência de raio $\lvert k\rvert$. Corte $y=0$: $x^2=z^2$, ou seja, **duas retas** $z=\pm x$.

### Exemplo 7: sela

$$z=x^2-y^2$$ $z$ linear, quadrados com sinais opostos ⇒ **parabolóide hiperbólico**. Corte $z=0$: $x^2=y^2$ ⇒ retas $y=\pm x$. Corte $z=1$: $x^2-y^2=1$ (hipérbole em $x$). Corte $z=-1$: $y^2-x^2=1$ (hipérbole em $y$). Por isso parece uma sela.

### Exemplo 8: cone × 1 folha × 2 folhas (a armadilha)

As três equações são muito parecidas, só muda o lado direito:

|Equação|Lado direito|Resultado|
|---|---|---|
|$x^2+y^2-z^2=0$|$0$|**cone**|
|$x^2+y^2-z^2=1$|$+1$|**1 folha**|
|$x^2+y^2-z^2=-1$|$-1$ (vira $-x^2-y^2+z^2=1$)|**2 folhas**|

---

## 5. Erros comuns

> [!failure] Não faça isso
> 
> 1. **Contar sinais sem arrumar o lado direito** (ver aviso da seção 1).
> 2. **Confundir parabolóide com cone:** o parabolóide tem uma variável **linear** ($z=\dots$); o cone tem **todas ao quadrado** e lado direito $0$.
> 3. **Chamar de "cilindro" algo que tem as 3 variáveis.** Cilindro só se **falta** uma variável.
> 4. **Esquecer que os coeficientes maiores não mudam o tipo:** $9x^2+4y^2+z^2=36$ ainda é elipsoide; só muda o tamanho.
> 5. **Achar que $x^2+y^2=1$ é uma circunferência em $\mathbb R^3$.** Em $\mathbb R^3$ é um **cilindro** (a circunferência "estica" ao longo de $z$).
> 6. **Achar o eixo errado:** eixo do parabolóide é a variável **linear**; do cilindro é a variável **que falta**; do hiperboloide de 1 folha é a variável **negativa**; do de 2 folhas é a variável **positiva**.

---

## 6. Treino (tente antes de abrir a resposta)

Identifique a superfície e o eixo. Clique no título para ver a resposta.

> [!question]- 1) $\frac{x^2}{4}+\frac{y^2}{9}+\frac{z^2}{16}=1$ **Elipsoide** (0 negativos). Semi-eixos $2$, $3$ e $4$.

> [!question]- 2) $\frac{x^2}{4}+\frac{y^2}{9}-z^2=1$ **Hiperboloide de 1 folha**, eixo $z$ (1 negativo).

> [!question]- 3) $-x^2+y^2-z^2=1$ **Hiperboloide de 2 folhas**, eixo $y$ (2 negativos; o positivo é $y$).

> [!question]- 4) $x^2+4y^2=z^2$ **Cone elíptico**, eixo $z$ (lado direito zero).

> [!question]- 5) $z=2x^2+y^2$ **Parabolóide elíptico**, eixo $z$ (linear $z$, sinais iguais).

> [!question]- 6) $y=x^2-z^2$ **Parabolóide hiperbólico**, eixo $y$ (linear $y$, sinais opostos). Corte $y=0$: $x=\pm z$ (duas retas).

> [!question]- 7) $x^2+z^2=9$ Falta $y$ ⇒ **cilindro circular** de raio $3$, eixo $y$.

> [!question]- 8) $y^2-z^2=1$ Falta $x$ ⇒ **cilindro hiperbólico**, eixo $x$.

> [!question]- 9) $x=z^2$ Falta $y$ ⇒ **cilindro parabólico**, eixo $y$.

> [!question]- 10) $9x^2+4y^2+z^2-36=0$ Passe $36$ para a direita e divida: $\frac{x^2}{4}+\frac{y^2}{9}+\frac{z^2}{36}=1$ ⇒ **elipsoide**.

> [!question]- 11) $x^2+y^2+z^2-4x+2y=4$ Complete os quadrados: $(x-2)^2+(y+1)^2+z^2=9$ ⇒ **esfera**, centro $(2,-1,0)$, raio $3$.

> [!question]- 12) $z^2-x^2-y^2=-1$ Multiplique por $-1$: $x^2+y^2-z^2=1$ ⇒ **hiperboloide de 1 folha**, eixo $z$. (Armadilha do sinal!)

> [!question]- 13) $x^2+y^2+z^2=-1$ Passa a $-x^2-y^2-z^2=1$ ⇒ 3 negativos ⇒ **conjunto vazio**.

> [!question]- 14) Um corte $z=k$ de uma superfície dá **vazio** para $\lvert k\rvert$ pequeno e elipses para $\lvert k\rvert$ grande. Qual é? **Hiperboloide de 2 folhas** (o "buraco" no meio).

> [!question]- 15) Os cortes horizontais de uma superfície são hipérboles (em $x$ para $z>0$ e em $y$ para $z<0$) e o corte $z=0$ dá duas retas. Qual é? **Parabolóide hiperbólico** (sela), por exemplo $z=x^2-y^2$.

---

## 7. Cônicas no plano (mesma ideia em 2D)

Para $Ax^2+Cy^2+Dx+Ey+F=0$ (sem termo $xy$):

|Situação|Cônica|
|---|---|
|$A$ e $C$ **mesmo sinal**, ambos $\neq0$|**elipse** (circunferência se $A=C$)|
|$A$ e $C$ **sinais opostos**|**hipérbole**|
|**um deles é zero** e o outro termo linear existe|**parábola**|

**Passo a passo:** complete os quadrados, divida para o lado direito ser $1$, leia $a$, $b$, centro. Depois use as fórmulas de foco e assíntota do [[SME0142 - Resumo GA (P1)]].

> [!tip] Elipse: qual eixo é o maior? Na forma $\frac{x^2}{p}+\frac{y^2}{q}=1$, o eixo **maior** é o da variável com **maior denominador**. Ex.: $\frac{x^2}{9}+\frac{y^2}{16}=1$ tem eixo maior em $y$.

> [!tip] Hipérbole: para onde ela abre? Ela abre na direção da variável de sinal **positivo**. $\frac{x^2}{a^2}-\frac{y^2}{b^2}=1$ abre para os lados (eixo $x$); $y^2-16x^2=1$ abre para cima e para baixo (eixo $y$).

> [!tip] Parábola: variável linear = direção do eixo $y=x^2$ tem eixo $y$; $x=2y^2-3y+1$ tem eixo $x$ (abre para a direita, pois o coeficiente é positivo).

---

## 8. Como responder na prova

**Questão de identificação (V/F ou "qual é a superfície?")**

1. Diga a superfície: "**parabolóide hiperbólico** com eixo $z$".
2. Justifique em **uma linha**: "pois $z$ aparece linear e $x^2$ e $y^2$ têm sinais opostos".
3. Se puder, cite **um corte**: "o corte $z=0$ são duas retas".

**Se for falso:** aponte o erro concreto ("falta a variável $z$, então é cilindro, não elipsoide").

**Frases-chave para memorizar**

- "Falta uma variável ⇒ cilindro com eixo naquela direção."
- "Uma variável linear ⇒ parabolóide; sinais iguais é elíptico, opostos é hiperbólico."
- "Lado direito zero ⇒ cone."
- "Nº de sinais negativos = nº de folhas (0 é elipsoide)."
