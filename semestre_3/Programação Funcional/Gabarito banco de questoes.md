# ✅ Gabarito — Questões de Programação Funcional

> Legenda: ✅ Verdadeiro | ❌ Falso | ⚠️ Parcialmente verdadeiro / depende do contexto

---

## Questões e Respostas

---

**"Em Haskell, o `$` é uma função que serve para determinar precedências, enquanto o `.` é uma função que acessa os atributos de um struct"** ❌ **FALSO** O `$` serve para aplicação de função com baixa precedência (correto). Mas o `.` é o operador de **composição de funções**, não acessa atributos de struct. Haskell não tem structs.

---

**"Em Java, os trechos funcionais são executados de forma lazy, já em Ruby, não."** ⚠️ **PARCIALMENTE VERDADEIRO** Em Java, apenas **Streams** têm comportamento lazy. Não são todos os trechos funcionais. Ruby de fato não é lazy nativamente.

---

**"Dada a função `f :: Int -> Int`, definida como `f y = y * 2`. Se for aplicada `f 5` o resultado será 10."** ✅ **VERDADEIRO** `f 5 = 5 * 2 = 10`.

---

**"Haskell é uma linguagem multiparadigma, a qual permite o desenvolvimento de software de forma imperativa, orientada a objetos e funcional."** ❌ **FALSO** Haskell é predominantemente **funcional**. Não suporta imperativo tradicional nem orientação a objetos (sem herança de classes OO).

---

**"A programação funcional não está diretamente relacionada ao cálculo lambda."** ❌ **FALSO** A programação funcional tem origem direta no **cálculo lambda** de Alonzo Church.

---

**"Funções anônimas são funções sem nome, geralmente usadas como parâmetros de funções."** ✅ **VERDADEIRO** Correto. Em Haskell: `\x -> x * 2`.

---

**"Em Haskell existem as instruções `if`, `then` e `else`."** ✅ **VERDADEIRO** Haskell possui `if-then-else`, mas é uma **expressão** (não instrução), e o `else` é obrigatório.

---

**"É aceitável declarar uma lista infinita em Haskell desde que o programa não precise utilizá-la por completo?"** ✅ **VERDADEIRO** Graças à **lazy evaluation**, listas infinitas são perfeitamente válidas se não forem avaliadas por completo.

---

**"O tipo `Integer` pode armazenar o fatorial de 13, enquanto o tipo `Int` não."** ✅ **VERDADEIRO** `Integer` tem precisão arbitrária. `Int` tem tamanho fixo e sofre overflow com valores grandes como `fat 13 = 6.227.020.800`.

---

**"A única forma possível de realizar o mapeamento de representação de instância em string é utilizando `deriving`."** ❌ **FALSO** Também é possível implementar manualmente via `instance Show MeuTipo where show x = ...`.

---

**"C é uma linguagem funcional."** ❌ **FALSO** C é uma linguagem **imperativa/procedural**.

---

**"É possível passar uma função como argumento em C, utilizando ponteiros de função."** ✅ **VERDADEIRO** Ex: `int (*f)(int)` declara um ponteiro para função.

---

**"Em Java, mesmo em um trecho de código funcional, não será executado de forma preguiçosa (lazy)."** ❌ **FALSO** Em Java, **Streams** utilizam lazy evaluation.

---

**"Uma lista declarada como `[3,5..]` começa no 3 e vai de 5 em 5 até o infinito."** ❌ **FALSO** `[3,5..]` começa em 3 e vai **de 2 em 2** (o passo é `5-3=2`), gerando `[3,5,7,9,...]`.

---

**"A linguagem Haskell possui avaliação lazy, ou seja, as expressões são avaliadas somente quando seu valor é realmente necessário."** ✅ **VERDADEIRO** Definição correta de lazy evaluation em Haskell.

---

**"Haskell possui suporte nativo para funções lambda?"** ✅ **VERDADEIRO** Sintaxe: `\x -> expressão`.

---

**"Tupla é um tipo de estrutura de dados do Python que tem como principal característica ser imutável."** ✅ **VERDADEIRO** Tuples em Python são imutáveis (e também existem em Haskell com semântica similar).

---

**"A função `f = [n * (n + 1) \`div` 2 | n <- [1..]]`retorna a lista`[1, 3, 6, 10, 15 ...]`"** ✅ **VERDADEIRO** São os números triangulares: T(1)=1, T(2)=3, T(3)=6, T(4)=10...

---

**"Ao invés de usar recursão, como é comum em paradigmas imperativos, a programação funcional é baseada na utilização de laços para a construção de programas."** ❌ **FALSO** É o **contrário**: programação funcional usa **recursão** em vez de laços. Laços são comuns em paradigmas **imperativos**.

---

**"Na programação funcional não é possível realizar atividades repetitivas, porque não se usa a estrutura `for`."** ❌ **FALSO** É possível, usando **recursão** e funções de alta ordem como `map`, `filter`, `fold`.

---

**"`filtro :: (a -> Bool) -> [a] -> [a]` — essa função retorna uma lista que contém apenas os elementos para os quais a função de teste retorna true."** ✅ **VERDADEIRO** Essa é a assinatura e comportamento correto do `filter`.

---

**"Ruby off rails foi o framework que fez Ruby se tornar popular?"** ❌ **FALSO** O framework é **Ruby on Rails** (não "off rails").

---

**"A função `.` (ponto), utilizada para composição de funções, tem tipo `(a->b) -> (a->b) -> (a->b)`"** ❌ **FALSO** O tipo correto é `(b->c) -> (a->b) -> (a->c)`. As funções compostas têm tipos diferentes entre si.

---

**"Ruby on Rails não deu certo por conta da demora e dificuldade para construir projetos."** ❌ **FALSO** Ruby on Rails foi um **grande sucesso** — ficou famoso justamente por permitir criar projetos **rapidamente**.

---

**"O `where` serve para localizar uma função dentro de outra."** ⚠️ **PARCIALMENTE FALSO** `where` serve para **definir** funções ou valores locais dentro de outra função, não para "localizar".

---

**"Todo e qualquer problema é melhor resolvido por programação funcional."** ❌ **FALSO** Cada paradigma tem seus pontos fortes. Não há paradigma universalmente superior.

---

**"Programação funcional utiliza de recursão?"** ✅ **VERDADEIRO** Recursão é a principal técnica iterativa na programação funcional.

---

**"A diferença entre `Let` e `Where` é que: o `let` vincula expressões a si e o `where` vincula somente construtores sintáticos."** ✅ **VERDADEIRO** (segundo a especificação de Haskell) `let` é uma expressão; `where` é uma construção sintática vinculada à declaração da função.

---

**"Em Haskell, toda expressão e função tem que retornar alguma coisa."** ✅ **VERDADEIRO** Haskell não possui "void". Toda expressão tem um tipo, inclusive `IO ()`.

---

**"O cálculo do comprimento de uma lista genérica pode ser definido por `len [] = 0` e `len (h:t) = 1 + len(h)`."** ❌ **FALSO** `len(h)` está errado — `h` é o **cabeça** (head) da lista, não a lista. O correto é `1 + len t`.

---

**"A função dólar `f ($) x = f x` é utilizada como alternativa aos parênteses."** ✅ **VERDADEIRO** `f $ x` equivale a `f x`, útil para evitar parênteses em encadeamentos.

---

**"Em geral, o operador `$` é usado para composição de funções, enquanto o operador `.` é usado para aplicação de funções."** ❌ **FALSO** É o **inverso**: `$` é aplicação, `.` é composição.

---

**"A programação funcional incentiva o uso de expressões lambda."** ✅ **VERDADEIRO** Funções anônimas (lambda) são centrais no paradigma funcional.

---

**"`deriving(Read)` permite gerar estruturas a partir de strings. A representação em string deve ser idêntica à exibida por `show`."** ✅ **VERDADEIRO** `read (show x) == x` deve ser válido para o `deriving` funcionar corretamente.

---

**"Se o método `show` em Haskell faz a amostragem de um tipo, ele pode fazer a amostragem de uma lista do tipo."** ✅ **VERDADEIRO** Haskell deriva automaticamente `show` para listas de tipos que instanciam `Show`.

---

**"A `Lazy Computation` consiste em apenas avaliar trechos do código absolutamente necessários."** ✅ **VERDADEIRO** Definição correta.

---

**"Programação funcional, orientada a objetos e lógica são exemplos de paradigmas declarativos."** ⚠️ **PARCIALMENTE VERDADEIRO** Programação funcional e lógica são declarativas. Orientação a objetos é geralmente considerada **imperativa** (com encapsulamento).

---

**"Em Haskell, é possível definir funções de alta ordem."** ✅ **VERDADEIRO** `map`, `filter`, `foldr` são exemplos clássicos.

---

**"Java só é lazy quando se manuseiam streams."** ✅ **VERDADEIRO** Apenas a API de Streams do Java tem avaliação lazy.

---

**"`s x y = x + y` com x e y inteiros — sua definição de tipo é `s :: Int -> (Int -> Int)`"** ✅ **VERDADEIRO** Por currying, `s :: Int -> Int -> Int` é equivalente a `s :: Int -> (Int -> Int)`.

---

**"`f s = s == reverse s` retorna verdadeiro para `"arara"` e falso para `"papagaio"`"** ✅ **VERDADEIRO** "arara" é palíndromo; "papagaio" não é.

---

**"Uma função da typeclass `Show` pode ser printada."** ✅ **VERDADEIRO** Tipos que instanciam `Show` podem ser exibidos com `print` ou `putStrLn . show`.

---

**"Em um programa feito em Haskell, nem todas as cláusulas precisam ser comparáveis."** ✅ **VERDADEIRO** Nem todos os tipos precisam instanciar `Eq` ou `Ord`.

---

**"A filtragem de objetos com parâmetros específicos em Java é feita através do método `filter()`."** ✅ **VERDADEIRO** Em Java Streams: `stream.filter(predicado)`.

---

**"As funções locais definidas com `where` não são acessíveis fora da função principal onde foram declaradas."** ✅ **VERDADEIRO** `where` tem **escopo local**.

---

**"A programação funcional não permite efeito colateral — uma função pura sempre produzirá o mesmo resultado para a mesma entrada."** ✅ **VERDADEIRO** Definição de função pura.

---

**"Na programação funcional, é comum usar recursão em vez de laços."** ✅ **VERDADEIRO**

---

**"A programação funcional é um paradigma que enfatiza funções puras e evita estados mutáveis."** ✅ **VERDADEIRO**

---

**"Em Haskell, `F x = G 5 x` é o mesmo que `F = G 5`."** ✅ **VERDADEIRO** Aplicação parcial (currying): eliminar o parâmetro dos dois lados é válido (eta-reduction).

---

**"Lazy Evaluation consiste em esperar para processar uma expressão até o exato momento em que o resultado é utilizado."** ✅ **VERDADEIRO**

---

**"`Eq` em Haskell é uma typeclass ou tipo de tipo?"** ✅ `Eq` é uma **typeclass** (classe de tipos).

---

**"`len [] = 0` / `len(h:t) = 1 + len t` — o código acima calcula o tamanho de uma lista?"** ✅ **VERDADEIRO** Essa é a implementação correta do `length`.

---

**"A definição `fat n = n * fat n - 1` em Haskell é suficiente para calcular o fatorial de qualquer número n."** ❌ **FALSO** Dois problemas: (1) sem **caso base** (`fat 0 = 1`), gera recursão infinita; (2) precedência errada — deveria ser `fat (n - 1)`, não `fat n - 1`.

---

**"Funções de alta ordem são funções que podem receber outras funções como parâmetro."** ✅ **VERDADEIRO** (também podem retornar funções).

---

**"Laziness é um conceito intrínseco a toda linguagem funcional."** ❌ **FALSO** Lazy evaluation é característica de Haskell e algumas outras, mas **não** de todas as linguagens funcionais (ex: Scheme, ML, Erlang são estritas por padrão).

---

**"A stream em Java segue a lazy evaluation, passando objetos um a um apenas quando solicitado."** ✅ **VERDADEIRO**

---

**"`Maybe` é uma abordagem que evita o uso de `if-else` em programação funcional."** ✅ **VERDADEIRO** `Maybe` evita verificações explícitas de nulo com pattern matching.

---

**"A linguagem Haskell é fortemente tipada?"** ✅ **VERDADEIRO** Haskell é fortemente e estaticamente tipada, com inferência de tipos.

---

**"Em Haskell, é possível usar funções dentro de comparação para retornar um valor booleano."** ✅ **VERDADEIRO** Ex: `f s = s == reverse s` retorna `Bool`.

---

**"As linguagens funcionais possibilitam escrever códigos curtos, rápidos e de fácil manutenção."** ⚠️ **GENERALIZANDO** Em geral sim, mas depende do problema e da experiência do programador.

---

**"Linguagens funcionais não permitem a implementação de métodos de ordenação."** ❌ **FALSO** Haskell tem `sort`, `sortBy` e suporte total a algoritmos de ordenação.

---

**"A implementação mais próxima do paradigma funcional em C está relacionada ao uso de ponteiro para funções."** ✅ **VERDADEIRO**

---

**"Haskell tem uma sintaxe bidimensional."** ✅ **VERDADEIRO** A indentação é parte da sintaxe em Haskell (layout rule).

---

**"Como em Haskell não é possível alterar o valor de variáveis, não existem structs."** ❌ **FALSO** Haskell tem tipos de dados customizados (equivalentes a structs) com `data`. A imutabilidade não impede isso.

---

**"`x = [1,5..100]` gera uma lista que vai de 1 até 100, com intervalo de 4 em 4?"** ✅ **VERDADEIRO** O passo é `5-1=4`, então: `[1,5,9,13,...,97]`.

---

**"Um dos problemas em Haskell é que a linguagem não permite a definição de tipos de dados com múltiplos construtores e parâmetros."** ❌ **FALSO** Haskell permite tipos com múltiplos construtores e parâmetros normalmente: `data Shape = Circle Float | Rect Float Float`.

---

**"A recursão é uma das técnicas em programação funcional para suprir a falta de laços iterativos."** ✅ **VERDADEIRO**

---

**"`f x y = x + y` — seu tipo é `f :: Num a => a -> a -> a`, podendo ser usada com inteiros e reais."** ✅ **VERDADEIRO** A restrição `Num a` permite uso com qualquer tipo numérico.

---

**"A função `p = f [2..] where f (p:xs) = p : f [x | x <- xs, x \`mod` p /= 0]`retorna uma lista que pode ser impressa sem risco de loop infinito, devido à laziness."** ✅ **VERDADEIRO** Usando`take n p` é seguro; a lista é gerada preguiçosamente.

---

**"Na lazy evaluation, todas as expressões são calculadas imediatamente, mesmo que não sejam utilizadas."** ❌ **FALSO** É exatamente o **contrário** — lazy evaluation **adia** o cálculo até que seja necessário.

---

**"Em Haskell, tanto o `$` quanto o `.` são funções que recebem uma função como argumento e retornam uma função."** ✅ **VERDADEIRO** Ambos são funções de alta ordem.

---

**"A expressão `where` em Haskell é usada para definir funções locais dentro de outras funções."** ✅ **VERDADEIRO**

---

**"Em C, `int (*filtro)(struct Aluno)` — o parâmetro `filtro` é um ponteiro para uma função que recebe uma struct Aluno e retorna um inteiro."** ✅ **VERDADEIRO**

---

**"A `main` em Haskell é do tipo IO, ou seja, pode 'mudar o mundo'."** ✅ **VERDADEIRO** `main :: IO ()` pode realizar I/O e efeitos colaterais.

---

**"O `case` em Haskell é amplamente utilizado para realizar expressões de casamento de padrões em listas e tuplas."** ✅ **VERDADEIRO**

---

**"A função `f s = p == reverse p where p = map toLower $ filter isAlphaNum s`, quando aplicada à string `"A man, a plan, a canal, Panama!"`, retorna:"** ✅ **`True`** A string, sem espaços/pontuação e em minúsculas, é `"amanaplanacanalpanama"`, que é um palíndromo.

---

**"Ruby é uma linguagem de programação preguiçosa."** ❌ **FALSO** Ruby usa avaliação **estrita** (eager) por padrão.

---

**"Linguagens de programação que usam o paradigma funcional devem implementar o Lazy Evaluation."** ❌ **FALSO** Lazy evaluation não é requisito do paradigma funcional — é uma característica opcional.

---

**"Haskell, Java com strings e JavaScript são todas linguagens 'preguiçosas'."** ❌ **FALSO** Apenas Haskell é lazy por padrão. Java e JavaScript são estritos (eager).

---

**"`Maybe` é uma maneira de lidar com o valor nulo ou vazio em programação funcional."** ✅ **VERDADEIRO**

---

**"Haskell é a única linguagem que utiliza funções puras."** ❌ **FALSO** Outras linguagens também suportam funções puras (Elm, PureScript, F#, etc.).

---

**"O principal aspecto da programação funcional é ser baseada em funções puras."** ✅ **VERDADEIRO**

---

**"Haskell suporta herança de classes?"** ❌ **FALSO** Haskell não tem herança OO. Usa **typeclasses** com uma forma de hierarquia, mas não herança de implementação.

---

**"Linguagens funcionais são especialmente adequadas para lidar com concorrência em sistemas distribuídos."** ✅ **VERDADEIRO** A imutabilidade e ausência de estado compartilhado facilitam a concorrência.

---

**"O tipo `Int` é geralmente mais eficiente em termos de uso de memória e desempenho em comparação com `Integer`."** ✅ **VERDADEIRO** `Int` usa tamanho fixo de máquina; `Integer` é arbitrário e usa mais memória.

---

**"Closure é um conceito usado apenas em linguagens de programação funcional."** ❌ **FALSO** Closures existem em JavaScript, Python, Go, Ruby, entre outras linguagens não puramente funcionais.

---

**"Haskell é uma linguagem em que tudo é função."** ⚠️ **APROXIMADAMENTE VERDADEIRO** Quase tudo pode ser tratado como função, mas literais e tipos de dados não são funções em sentido estrito.

---

**"A programação funcional é um paradigma baseado principalmente em estruturas de repetição como laços `for` e `while`."** ❌ **FALSO** É o **oposto** — programação funcional evita laços e usa recursão e funções de alta ordem.

---

**"Em Java existe uma função `peek` que pode ser usada para depuração ou para observar o fluxo de elementos sem modificá-los."** ✅ **VERDADEIRO** `stream.peek()` é usada para depuração intermediária em Streams Java.

---

**"`function(int var)` — em C, `if(function(x) == function(x))` sempre executará o código dentro do `if`."** ❌ **FALSO** Em C, funções podem ter **efeitos colaterais**, então duas chamadas à mesma função podem retornar valores diferentes. Não há garantia.

---

**"É possível implementar conceitos funcionais em linguagens imperativas modernas como JavaScript, Java e C++."** ✅ **VERDADEIRO**

---

**"A programação funcional é exclusiva de linguagens como Haskell e Lisp."** ❌ **FALSO** Conceitos funcionais estão presentes em JavaScript, Python, Java, C++, Ruby, etc.

---

**"`select` de Ruby tem função similar a `filter` de Haskell."** ✅ **VERDADEIRO** `[1,2,3,4].select { |n| n.even? }` → `[2, 4]`.

---

**"Em Haskell, se uma função imprime algo no terminal, essa função deve retornar um tipo IO."** ✅ **VERDADEIRO**

---

**"`function' :: (Num b) => [a] -> b` / `function' [] = 0` / `function' (_:xs) = 1 + function' xs` — essa função calcula o comprimento de uma lista."** ✅ **VERDADEIRO** Implementação correta de `length` genérica.

---

**"A função lambda sempre requer a especificação do tipo de seus argumentos."** ❌ **FALSO** Haskell tem **inferência de tipos** — não é necessário especificar o tipo de argumentos lambda.

---

**"Java e C++ possuem possibilidade funcional, apesar de C++ ser uma opção melhor para o uso funcional."** ⚠️ **CONTROVERSO / FALSO** Java tem suporte funcional robusto (lambdas, Streams). C++ também, mas Java é tipicamente considerado mais idiomático para código funcional moderno.

---

**"A ordem de consideração dos parâmetros de uma função em Haskell é sempre da esquerda para a direita?"** ✅ **VERDADEIRO** Aplicação de função em Haskell é associativa à esquerda; parâmetros são consumidos da esquerda para a direita.

---

**"É possível chamar outra função dentro de uma função diferente?"** ✅ **VERDADEIRO** Em Haskell e em qualquer linguagem de programação.

---

**"As três declarações em JavaScript `const f = (x) => { return x + 42; }`, `const f = (x) => (x + 42)` e `const f = x => x + 42` são equivalentes?"** ✅ **VERDADEIRO** As três formas de arrow function em JS são equivalentes para um único argumento e retorno simples.

---

**"A programação funcional se baseia no uso de funções como parte fundamental na construção de programas."** ✅ **VERDADEIRO**

---

**"A programação funcional em Java também é lazyness."** ❌ **FALSO** Java só é lazy em **Streams** — não em toda a programação funcional disponível na linguagem.

---

**"Haskell é uma linguagem de programação compilada?"** ✅ **VERDADEIRO** O compilador padrão é o **GHC** (Glasgow Haskell Compiler).

---

**"A função lambda é definida diretamente na expressão em que será usada, não precisando de palavras-chave como `def` ou `function`."** ✅ **VERDADEIRO** Em Haskell: `\x -> x + 1`. Em Python: `lambda x: x + 1`.

---

**"Programação funcional consiste em passar trechos de código que se repetem como parâmetro de uma função, tornando o código mais flexível."** ⚠️ **INCOMPLETO** Essa é uma das características (funções de alta ordem), mas a programação funcional abrange muito mais (imutabilidade, funções puras, etc.).

---

**"Soluções recursivas são padrão em linguagens funcionais."** ✅ **VERDADEIRO**

---

**"A avaliação preguiçosa (lazy) em Haskell permite que todas as expressões sejam avaliadas imediatamente, mesmo que não sejam necessárias?"** ❌ **FALSO** É o **contrário** — lazy evaluation **evita** avaliação desnecessária.
