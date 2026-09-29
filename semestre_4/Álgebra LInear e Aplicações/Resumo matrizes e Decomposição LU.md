
## 1. Matrizes: operações básicas

Uma matriz $\mathbf{A}_{n\times m}$ tem $n$ **linhas** e $m$ **colunas**. Elemento $a_{ij}$ = linha $i$, coluna $j$.

- **Soma:** só para mesma dimensão, termo a termo. **Escalar:** multiplica todas as entradas.
- **Produto** $\mathbf{A}_{n\times m}\mathbf{B}_{m\times k}=\mathbf{C}_{n\times k}$: $$c_{ij}=\sum_{s=1}^{m}a_{is}b_{sj}$$ (produto escalar da **linha $i$ de A** pela **coluna $j$ de B**). Precisa: colunas de A = linhas de B.
- **Propriedades:** associativo $\mathbf{A}(\mathbf{BC})=(\mathbf{AB})\mathbf{C}$; distributivo.
- ⚠️ **Não é comutativo:** em geral $\mathbf{AB}\neq\mathbf{BA}$ (às vezes nem os dois existem).

> [!tip] Três jeitos de enxergar $\mathbf{AB}$ (úteis para provas)
> 
> - Cada **coluna** de $\mathbf{AB}$ é $\mathbf{A}$ vezes a coluna correspondente de $\mathbf{B}$.
> - Cada **linha** de $\mathbf{AB}$ é a linha correspondente de $\mathbf{A}$ vezes $\mathbf{B}$.
> - $\mathbf{Ax}$ é uma **combinação linear das colunas** de $\mathbf{A}$ com pesos $x_i$.

### Transposta e simetria

- $\mathbf{A}^\top$: linhas viram colunas; $(\mathbf{A}^\top)_{ij}=a_{ji}$. Dimensão $m\times n$.
- $(\mathbf{AB})^\top=\mathbf{B}^\top\mathbf{A}^\top$ (ordem inverte!).
- **Simétrica:** $\mathbf{A}=\mathbf{A}^\top$ (só existe se quadrada).

### Tipos especiais (quadradas $n\times n$)

|Tipo|Definição|
|---|---|
|**Diagonal**|zero fora da diagonal|
|**Identidade** $\mathbf{I}$|diagonal de 1s; $\mathbf{AI}=\mathbf{IA}=\mathbf{A}$, $\mathbf{I}^\top=\mathbf{I}$|
|**Triangular superior**|zero **abaixo** da diagonal|
|**Triangular inferior**|zero **acima** da diagonal|
|**Permutação** $\mathbf{P}$|identidade com linhas trocadas; $\mathbf{P}^\top=\mathbf{P}^{-1}$|

**Fatos sobre triangulares:**

- O produto de triangulares superiores é triangular superior (idem inferiores).
- A inversa de triangular superior (se existe) é triangular superior (idem inferiores).

### Inversa

$\mathbf{A}^{-1}$ satisfaz $\mathbf{A}^{-1}\mathbf{A}=\mathbf{A}\mathbf{A}^{-1}=\mathbf{I}$. **Nem sempre existe.** Se não existe, a matriz é **singular**.

1. $(\mathbf{AB})^{-1}=\mathbf{B}^{-1}\mathbf{A}^{-1}$
2. $(\mathbf{A}^\top)^{-1}=(\mathbf{A}^{-1})^\top$

> [!example]- Provas (cai em prova) **1.** $(\mathbf{AB})(\mathbf{B}^{-1}\mathbf{A}^{-1})=\mathbf{A}(\mathbf{BB}^{-1})\mathbf{A}^{-1}=\mathbf{AA}^{-1}=\mathbf{I}$; e o outro lado é análogo. **2.** Transponha $\mathbf{A}^{-1}\mathbf{A}=\mathbf{I}$: $\mathbf{A}^\top(\mathbf{A}^{-1})^\top=\mathbf{I}$. Logo $(\mathbf{A}^{-1})^\top$ é a inversa de $\mathbf{A}^\top$.

---

## 2. Sistemas lineares $\mathbf{Ax}=\mathbf{b}$

$\mathbf{A}$ é $n\times m$, $\mathbf{x}$ é $m\times 1$ (incógnitas), $\mathbf{b}$ é $n\times 1$.

### Duas visões (o professor gosta da geométrica)

|Visão|Interpretação|
|---|---|
|**Das linhas**|cada equação é um **hiperplano** (reta em $\mathbb R^2$, plano em $\mathbb R^3$). A solução é onde **todos se cruzam**.|
|**Das colunas**|$x_1\mathbf a_1+\dots+x_m\mathbf a_m=\mathbf b$: achar os pesos que fazem $\mathbf b$ ser **combinação linear das colunas**.|

**Número de soluções:**

- **Única:** os hiperplanos se cruzam num ponto. Requer as colunas LI e $\mathbf b$ na combinação delas.
- **Infinitas:** se cruzam num "espaço" maior (reta, plano...).
- **Nenhuma:** não há ponto comum (ex.: retas paralelas) = $\mathbf b$ **não** é combinação das colunas.

> [!example]- Exemplos do notebook
> 
> - $\begin{cases}x+2y=3 \cr 4x+5y=6\end{cases}$: duas retas se cruzando em $(-1,\ 2)$ (solução única).
> - $\begin{cases}2x-y+z=1 \cr 7x+5y+3z=7\end{cases}$: dois planos em $\mathbb R^3$ ⇒ cruzam numa reta. Isolando $z=1-2x+y$ e substituindo: $x+8y=4$, com $y$ livre ⇒ **infinitas soluções**.

**Solução única ⇒** $\mathbf A$ quadrada e invertível: $\mathbf x=\mathbf A^{-1}\mathbf b$. (Na prática **não se calcula a inversa**; usa-se LU.)

---

## 3. Eliminação de Gauss como produto de matrizes

**Operação elementar:** multiplicar uma equação por escalar e/ou somar (subtrair) um múltiplo de uma equação em outra. **Não altera a solução.**

### Passo 1: zerar a 1ª coluna abaixo do pivô

$$l_{i1}=\frac{a_{i1}}{a_{11}}$$ $\mathbf M^{(1)}$ = identidade com $-l_{i1}$ na 1ª coluna (linhas $i\geq 2$). Então: $$\mathbf A^{(1)}=\mathbf M^{(1)}\mathbf A$$ tem zeros abaixo de $a_{11}$. Em cada linha: $\text{linha}_i\leftarrow\text{linha}_i-l_{i1}\cdot\text{linha}_1$.

### Passo $k$

Mesma ideia com o pivô $a_{kk}^{(k-1)}$ e multiplicadores $l_{ik}=\dfrac{a_{ik}^{(k-1)}}{a_{kk}^{(k-1)}}$. Após $n-1$ passos: $$\mathbf U=\mathbf M^{(n-1)}\cdots\mathbf M^{(2)}\mathbf M^{(1)}\mathbf A\qquad(\mathbf U\ \text{triangular superior})$$

### Por que L é "de graça"

- **Truque das inversas:** $[\mathbf M^{(i)}]^{-1}=-\mathbf M^{(i)}$, isto é, só troca o sinal dos $l$'s.
- Logo $$\mathbf L=[\mathbf M^{(1)}]^{-1}[\mathbf M^{(2)}]^{-1}\cdots[\mathbf M^{(n-1)}]^{-1}$$ e o produto "encaixa" sem misturar nada: **$\mathbf L$ tem os multiplicadores $l_{ij}$ nas posições certas** e diagonal 1.

$$\boxed{\ \mathbf A=\mathbf L\mathbf U\ }$$

---

## 4. Decomposição LU: estrutura

|Matriz|Estrutura|
|---|---|
|$\mathbf L$|**triangular inferior com 1s na diagonal**; abaixo da diagonal ficam os multiplicadores $l_{ij}$|
|$\mathbf U$|**triangular superior**; é o resultado final da eliminação; diagonal = pivôs|

> [!warning] Cuidado com o gabarito da prova O gabarito escreve "$\mathbf L$ é uma matriz **diagonal inferior**", que é um deslize de nomenclatura. O correto é **triangular inferior** com diagonal de 1s. Escreva assim.

### Exemplo completo (à mão, sem troca de linhas)

$$\mathbf A=\begin{bmatrix}2&1&1\cr 4&3&3\cr 8&7&9\end{bmatrix}$$

**Coluna 1** (pivô 2): $l_{21}=4/2=2$, $l_{31}=8/2=4$.

- $L_2\leftarrow L_2-2L_1=(0,1,1)$ e $L_3\leftarrow L_3-4L_1=(0,3,5)$.

**Coluna 2** (pivô 1): $l_{32}=3/1=3$.

- $L_3\leftarrow L_3-3L_2=(0,0,2)$.

$$\mathbf L=\begin{bmatrix}1&0&0\cr 2&1&0\cr 4&3&1\end{bmatrix}\qquad\mathbf U=\begin{bmatrix}2&1&1\cr 0&1&1\cr 0&0&2\end{bmatrix}$$

Confira sempre multiplicando $\mathbf{LU}$ e comparando com $\mathbf A$.

---

## 5. Resolvendo $\mathbf{Ax}=\mathbf b$ com LU

$$\mathbf{Ax}=\mathbf b\ \Rightarrow\ \mathbf{LUx}=\mathbf b$$ Faça $\mathbf{Ux}=\mathbf y$ e resolva **dois sistemas triangulares**:

1. **Substituição direta** em $\mathbf{Ly}=\mathbf b$ (de cima para baixo): $$y_1=b_1,\quad y_2=b_2-l_{21}y_1,\quad y_3=b_3-l_{31}y_1-l_{32}y_2,\ \dots$$
2. **Retrosubstituição** em $\mathbf{Ux}=\mathbf y$ (de baixo para cima): $$x_n=\frac{y_n}{u_{nn}},\qquad x_{n-1}=\frac{y_{n-1}-u_{n-1,n}\ x_n}{u_{n-1,n-1}},\ \dots$$

> [!example]- Continuação do exemplo (com $\mathbf b=(4,10,24)$) $\mathbf{Ly}=\mathbf b$: $y_1=4$; $y_2=10-2\cdot4=2$; $y_3=24-4\cdot4-3\cdot2=2$. $\mathbf{Ux}=\mathbf y$: $x_3=2/2=1$; $x_2=2-1\cdot1=1$; $x_1=(4-1\cdot1-1\cdot1)/2=1$. Solução $\mathbf x=(1,1,1)$.

**Por que vale a pena?** A decomposição é feita **uma vez** (custo da ordem de $n^3$ operações) e cada novo $\mathbf b$ custa só ordem $n^2$ (dois sistemas triangulares). Ótimo para vários lados direitos.

---

## 6. Pivotamento e $\mathbf A=\mathbf P^\top\mathbf{LU}$

**Problema:** se algum pivô $a_{ii}^{(k)}$ vale zero, há divisão por zero (e pivô **quase** zero causa erro numérico grande).

**Solução:** **trocar linhas** (pivotamento).

> [!example]- Exemplo do notebook $$\begin{bmatrix}1&1&1\cr 1&1&2\cr 1&2&2\end{bmatrix}\rightarrow\begin{bmatrix}1&1&1\cr 0&0&1\cr 0&1&1\end{bmatrix}$$ O pivô da posição $(2,2)$ é 0: **falha**. Trocando as linhas 2 e 3 antes de eliminar: $$\mathbf{PA}=\begin{bmatrix}1&1&1\cr 1&2&2\cr 1&1&2\end{bmatrix},\quad \mathbf L=\begin{bmatrix}1&0&0\cr 1&1&0\cr 1&0&1\end{bmatrix},\quad \mathbf U=\begin{bmatrix}1&1&1\cr 0&1&1\cr 0&0&1\end{bmatrix}$$ com $\mathbf P=\begin{bmatrix}1&0&0\cr 0&0&1\cr 0&1&0\end{bmatrix}$.

### Resultado geral

$$\mathbf A=\mathbf P^\top\mathbf{LU}\qquad\Longleftrightarrow\qquad \mathbf{PA}=\mathbf{LU}$$

- $\mathbf P$ = **matriz de permutação** (identidade com linhas trocadas). Registra as trocas de linha.
- $\mathbf P^\top=\mathbf P^{-1}$ (ortogonal).
- É **necessária** porque nem toda matriz invertível admite $\mathbf{A}=\mathbf{LU}$ direto: às vezes precisa reordenar as equações.

### Resolvendo com pivotamento

$$\mathbf{Ax}=\mathbf b\ \Rightarrow\ \mathbf P^\top\mathbf{LUx}=\mathbf b\ \Rightarrow\ \mathbf{LUx}=\mathbf{Pb}$$

1. $\mathbf{Ly}=\mathbf{Pb}$ (substituição direta)
2. $\mathbf{Ux}=\mathbf y$ (retrosubstituição)

> [!tip] Fazendo à mão com trocas Quando trocar as linhas $i$ e $j$ no meio da eliminação, **troque também as linhas já calculadas dos multiplicadores** em $\mathbf L$ (e registre a troca em $\mathbf P$). Um jeito simples de evitar confusão: aplique todas as trocas em $\mathbf A$ primeiro ($\mathbf{PA}$) e depois faça a eliminação sem trocas.

---

## 7. Unicidade da decomposição

**Propriedade:** se $\mathbf A$ é quadrada **invertível** e $\mathbf{A}=\mathbf{LU}$ (com $\mathbf{L}$ de diagonal 1), então a decomposição é **única**.

> [!example]- Demonstração Suponha $\mathbf{L}_1\mathbf{U}_1=\mathbf{L}_2\mathbf{U}_2$. Então $$\mathbf L_2^{-1}\mathbf L_1=\mathbf U_2\mathbf U_1^{-1}.$$ O lado esquerdo é **triangular inferior**; o direito é **triangular superior**. Só podem ser iguais se ambos forem **diagonais**. Como $\mathbf L_2^{-1}\mathbf L_1$ tem diagonal de 1s, ele é $\mathbf I$. Portanto $\mathbf L_1=\mathbf L_2$ e, então, $\mathbf U_1=\mathbf U_2$. $\blacksquare$

---

## 8. Calculando a inversa via LU

Como $\mathbf{A}\mathbf{A}^{-1}=\mathbf I$, cada coluna $\mathbf a_i^{-1}$ da inversa resolve $$\mathbf{A}\ \mathbf a_i^{-1}=\mathbf I_i\quad(\text{i-ésima coluna de }\mathbf{I})\ \Longrightarrow\ \mathbf{LU}\ \mathbf a_i^{-1}=\mathbf I_i$$

- Faz-se a LU **uma única vez** e resolvem-se $n$ pares de sistemas triangulares.

---

## 9. Matrizes singulares

Uma matriz quadrada sem inversa é **singular**. Na decomposição $\mathbf{A}=\mathbf{P}^\top\mathbf{LU}$:

> [!important] Prova antiga, Q1(d) Quando $\mathbf A$ **não é invertível**, $\mathbf U$ **não tem conjunto completo de pivôs**: alguma(s) entrada(s) da diagonal de $\mathbf{U}$ é zero, e $\mathbf U$ tem **pelo menos uma linha nula**.

$$\mathbf U=\begin{bmatrix}\mathbf U_1&\mathbf U_2\cr \mathbf 0&\mathbf 0\end{bmatrix}$$ com $\mathbf U_1$ **triangular superior invertível**.

> [!example]- Exemplo $$\mathbf A=\begin{bmatrix}1&2&3\cr 2&4&6\cr 1&1&1\end{bmatrix}\quad(\text{linha 2}=2\times\text{linha 1})$$ Eliminando: $L_2-2L_1=(0,0,0)$ e $L_3-L_1=(0,-1,-2)$. O pivô em $(2,2)$ é 0, então troca-se as linhas 2 e 3: $$\mathbf U=\begin{bmatrix}1&2&3\cr 0&-1&-2\cr 0&0&0\end{bmatrix}$$ Só 2 pivôs ⇒ posto 2 (ver tópico 5). Linha nula ⇒ $\mathbf A$ singular.

**Ligação com sistemas:** com $\mathbf U$ singular, $\mathbf{Ux}=\mathbf y$ tem **infinitas soluções** (se as linhas nulas de $\mathbf U$ correspondem a $y_i=0$) **ou nenhuma** (se algum $y_i\neq0$ numa linha nula).

---

## 10. Na prática: Python (do notebook)

```python
import numpy as np
import scipy.linalg as sl

P, L, U = sl.lu(A)      # ATENÇÃO: o scipy devolve A = P @ L @ U
                        # ou seja, o "P" do scipy é o P^T da disciplina
y = sl.solve_triangular(L, P.T @ b, lower=True, unit_diagonal=True)
x = sl.solve_triangular(U, y, lower=False)
np.allclose(A, P @ L @ U)   # verificação
```

> [!warning] Armadilhas
> 
> - O `P` do scipy = $\mathbf P^\top$ do curso. Por isso o notebook usa `P.T @ b` (que é o $\mathbf{Pb}$ do curso).
> - O scipy usa **pivotamento parcial** (escolhe o maior pivô da coluna), então o $\mathbf L,\mathbf U$ dele pode diferir do que você faz à mão sem trocar linhas. Ambos são corretos.
> - `sl.solve` e `np.linalg.solve` fazem LU internamente e dão o mesmo resultado que o seu $\mathbf x_{LU}$ (o notebook confere com `np.allclose`).

---

## 11. Prova antiga (16/09/2025): o que cobrar de LU

### Questão 1 (2,5 pts): as quatro perguntas

**a) Como $\mathbf L$ e $\mathbf U$ são estruturadas?** $\mathbf L$: triangular inferior com **1s na diagonal**. $\mathbf U$: triangular **superior**.

**b) O que é $\mathbf P$ e por que é necessária?** Matriz de **permutação** que reordena as linhas de $\mathbf A$ quando um pivô é zero (ou muito pequeno). Sem isso, a eliminação pode travar por divisão por zero.

**c) Como usar $\mathbf A=\mathbf P^\top\mathbf{LU}$ para resolver $\mathbf{Ax}=\mathbf b$?** $\mathbf P^\top\mathbf{LUx}=\mathbf b$. Faça $\mathbf{Ux}=\mathbf y$. Resolva $\mathbf{Ly}=\mathbf{Pb}$ por **substituição direta** e depois $\mathbf{Ux}=\mathbf y$ por **retrosubstituição**.

**d) O que acontece com $\mathbf U$ se $\mathbf A$ não é invertível?** Não tem conjunto completo de pivôs (há zeros na diagonal, e linha(s) nula(s)); em blocos, $\mathbf U=\begin{bmatrix}\mathbf U_1&\mathbf U_2\cr \mathbf 0&\mathbf 0\end{bmatrix}$ com $\mathbf U_1$ triangular superior invertível.

> [!tip] Como escrever bem A distribuição de pontos foi ~0,6 por item. Responda cada item em 1 a 3 linhas com as palavras-chave: _triangular inferior, diagonal de 1s, triangular superior, permuta linhas, pivô zero, substituição direta, retrosubstituição, sem pivôs completos, linha nula_.

### Itens de outras questões que se conectam (tópico 5, para revisar depois)

- **Q3:** solução única ⇒ colunas LI e $\mathbf b\in\text{Col}(\mathbf A)$; infinitas ⇒ colunas LD e $\mathbf b\in\text{Col}(\mathbf A)$; nenhuma ⇒ $\mathbf b\notin\text{Col}(\mathbf A)$.
- **Q4d:** os vetores fora do espaço coluna **não** formam subespaço (nem contêm o zero).
- **Q4f:** para $\mathbf A_{m\times n}$ com $n>m$, o espaço nulo tem dimensão $>0$ (mais incógnitas que equações).

> [!question] Um possível problema no gabarito (Q4e) "Se existe $\mathbf x\neq\mathbf 0$ com $\mathbf{Ax}=\mathbf 0$, então o posto é no máximo $n-1$." Pelo teorema posto + nulidade $=n$, isso é **verdadeiro** (nulidade $\geq1$ ⇒ posto $\leq n-1$). O gabarito marca **F**, com a justificativa "pode ser que $m<n-1$", o que não invalida a afirmação ("no máximo"). Vale perguntar ao professor na vista de prova ou ao monitor.
