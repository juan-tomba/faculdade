## 1. Paradigma Funcional

- A **programação funcional** é um paradigma baseado no uso de **funções puras** como elemento central na construção de programas.
- Uma **função pura** sempre produz o mesmo resultado para a mesma entrada e **não causa efeitos colaterais**.
- Outros paradigmas declarativos: programação funcional, **lógica** e (debatidamente) orientada a objetos.
- A programação funcional está diretamente relacionada ao **cálculo lambda (λ-calculus)**.
- Conceitos funcionais podem ser usados em linguagens imperativas modernas como **JavaScript, Java e C++**.
- Haskell **não** é multiparadigma no sentido tradicional — é predominantemente funcional, com tipagem estática e forte.

---

## 2. Haskell — Características Gerais

- **Linguagem compilada**, fortemente tipada e com inferência de tipos.
- **Tudo em Haskell é uma expressão** — toda função e expressão deve retornar algum valor.
- Haskell possui **avaliação lazy (preguiçosa)** nativa.
- Haskell **não** suporta herança de classes no sentido OO — usa _typeclasses_.
- Haskell **não** é uma linguagem imperativa nem orientada a objetos.
- Possui suporte nativo a **funções lambda**.
- Possui sintaxe **bidimensional** (indentação importa).

---

## 3. Tipos em Haskell

|Tipo|Característica|
|---|---|
|`Int`|Inteiro com tamanho fixo (limitado pela máquina). Mais eficiente.|
|`Integer`|Inteiro de precisão arbitrária (armazena fatorial de 13 e além).|
|`Bool`|Verdadeiro ou Falso|
|`String`|Lista de `Char`|
|`Maybe a`|Representa ausência (`Nothing`) ou presença (`Just x`) de valor|

> ⚠️ `Int` **não** consegue armazenar fatorial de 13 (1.932.053.504 — overflow). `Integer` sim.

### Tipos Customizados

```haskell
data Cor = Vermelho | Verde | Azul deriving (Show, Read, Eq)
```

- `deriving Show` → gera automaticamente a representação em string.
- `deriving Read` → permite criar instâncias a partir de strings (a representação deve ser idêntica ao `show`).
- Também é possível implementar `show` manualmente via `instance Show`.

---

## 4. Funções em Haskell

### Definição e Aplicação

```haskell
f :: Int -> Int
f y = y * 2
-- f 5 = 10
```

### Currying

- Toda função em Haskell recebe **um argumento por vez**.
- `s :: Int -> (Int -> Int)` é o mesmo que `s :: Int -> Int -> Int`.
- `F x = G 5 x` é equivalente a `F = G 5` (**aplicação parcial**).

### Funções de Alta Ordem

- Funções que **recebem** ou **retornam** outras funções.
- Exemplo: `map`, `filter`, `foldr`.

### Funções Anônimas (Lambda)

```haskell
\x -> x * 2
```

- Não requerem nome nem especificação de tipo dos argumentos.
- Usadas como parâmetros ou retornos de funções.

### Pattern Matching

```haskell
len [] = 0
len (_:t) = 1 + len t   -- correto! (não len h)
```

> ⚠️ `len (h:t) = 1 + len(h)` está **errado** — o correto é `1 + len t`.

---

## 5. Operadores Importantes

### `$` — Aplicação de Função

```haskell
f $ x = f x
```

- Usado para **evitar parênteses**, controlando precedência.
- Tem a **menor precedência** entre os operadores.
- `f $ g $ x` = `f (g x)`

### `.` — Composição de Funções

```haskell
(f . g) x = f (g x)
```

- Tipo: `(b -> c) -> (a -> b) -> (a -> c)`
- Combina duas funções em uma nova função.

> ⚠️ **Resumo**: `$` é para **aplicação**, `.` é para **composição**. Os dois são funções de alta ordem.

---

## 6. Lazy Evaluation (Avaliação Preguiçosa)

- Expressões são avaliadas **somente quando seu valor é necessário**.
- Permite declarar **listas infinitas**:

```haskell
naturais = [1..]
primos = -- lista infinita de primos
```

- Exemplo de uso seguro: `take 10 [1..]` → `[1,2,3,4,5,6,7,8,9,10]`

### Lazy em outras linguagens

|Linguagem|Lazy?|
|---|---|
|Haskell|✅ Sempre|
|Java (Streams)|✅ Apenas Streams|
|Ruby|❌ Não nativo|
|JavaScript|❌ Não nativo|

> ⚠️ Lazy **não** é intrínseco a toda linguagem funcional — é uma característica de Haskell e algumas outras.

---

## 7. Listas em Haskell

```haskell
[1, 3..]       -- [1, 3, 5, 7, ...] (de 2 em 2)
[3, 5..]       -- [3, 5, 7, 9, ...] (de 2 em 2, começa em 3)
[1, 5..100]    -- [1, 5, 9, ..., 97] (de 4 em 4)
```

### List Comprehension

```haskell
f = [n * (n + 1) `div` 2 | n <- [1..]]
-- retorna [1, 3, 6, 10, 15, ...] (números triangulares)
```

### Função `filter`

```haskell
filtro :: (a -> Bool) -> [a] -> [a]
```

- Retorna apenas os elementos para os quais o predicado retorna `True`.
- Equivalente ao `select` do Ruby e ao `filter()` do Java (Streams).

---

## 8. Recursão

- Na programação funcional, **recursão substitui laços** (`for`, `while`).
- É a principal técnica para iterações.
- Toda função recursiva precisa de **caso base** para terminar.

```haskell
-- Fatorial CORRETO:
fat 0 = 1
fat n = n * fat (n - 1)

-- fat n = n * fat n - 1  ← ERRADO! (sem caso base e precedência errada)
```

---

## 9. `where` e `let`

### `where`

```haskell
circunferencia r = 2 * pi * r
  where pi = 3.14159
```

- Define funções/valores **locais** após a expressão principal.
- Não acessível fora da função onde foi declarado.
- Vincula **construtores sintáticos**.

### `let`

```haskell
let x = 5 in x * 2
```

- Vincula **expressões** a nomes locais.
- Pode ser usado dentro de expressões.

---

## 10. Typeclasses Importantes

|Typeclass|Função|
|---|---|
|`Show`|Converte para String (`show`)|
|`Read`|Cria valor a partir de String|
|`Eq`|Igualdade (`==`, `/=`)|
|`Ord`|Ordenação (`<`, `>`)|
|`Num`|Operações numéricas|

- `Eq` é uma **typeclass** (classe de tipos), não um tipo.
- Uma função da typeclass `Show` pode ser impressa no terminal.

---

## 11. `Maybe`

```haskell
data Maybe a = Nothing | Just a
```

- Representa um valor que pode estar **ausente**.
- Evita o uso de `null` e tratamentos com `if-else` para valores nulos.
- É uma abordagem funcional para lidar com ausência de valor.

---

## 12. IO em Haskell

```haskell
main :: IO ()
```

- A `main` é do tipo `IO` — pode interagir com o mundo externo.
- Funções que **imprimem no terminal** devem retornar tipo `IO`.
- `IO` é a forma de Haskell lidar com efeitos colaterais de forma controlada.

---

## 13. Funções Úteis para Prova

```haskell
-- Composição de funções
(f . g) x = f (g x)

-- Verificar palíndromo
f s = s == reverse s
-- "arara" → True, "papagaio" → False

-- Palíndromo ignorando maiúsculas e pontuação
f s = p == reverse p
  where p = map toLower $ filter isAlphaNum s
-- "A man, a plan, a canal, Panama!" → True

-- Comprimento de lista (correto)
len [] = 0
len (_:xs) = 1 + len xs

-- Sieve of Eratosthenes (lista infinita de primos)
p = f [2..]
  where f (p:xs) = p : f [x | x <- xs, x `mod` p /= 0]
```

---

## 14. Programação Funcional em C

- C **não** é uma linguagem funcional.
- É possível simular ponteiros de função:

```c
int (*filtro)(struct Aluno);
// ponteiro para função que recebe struct Aluno e retorna int
```

- A implementação mais próxima do paradigma funcional em C é o **uso de ponteiros para funções**.

---

## 🔑 Macetes Rápidos

- `$` → aplicação, evita parênteses → **menor precedência**
- `.` → composição → `(f . g) x = f (g x)`
- `where` → define localmente **após** a função
- `let` → define localmente **antes/dentro** de expressão
- `Maybe` → alternativa ao null/if-else
- `deriving Show` → gera `show` automaticamente
- `Integer` > `Int` em capacidade (mas `Int` é mais rápido)
- Haskell é **sempre lazy**; Java só é lazy em **Streams**
- Recursão = loop na programação funcional
- Funções puras = mesmo input → mesmo output, sem efeitos colaterais