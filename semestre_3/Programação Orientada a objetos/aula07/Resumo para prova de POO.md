## 📌 O que é POO?

POO é um **paradigma imperativo** que organiza o código em torno de **objetos** — entidades que possuem **estado (atributos)** e **comportamento (métodos)**.

- Todo objeto é uma **instância** de uma **classe**
- Objetos se comunicam trocando **mensagens** (chamando métodos uns dos outros)
- Linguagens: Java, C++, Python, C#

---

## 1. 🔒 Encapsulamento e Ocultação de Informação

### Conceito

Encapsular = juntar dados e comportamentos numa só unidade (a classe) **e esconder o estado interno** do mundo externo. Ninguém acessa os atributos diretamente — só via métodos controlados.

### Modificadores de acesso

|Modificador|Acesso permitido|
|---|---|
|`private`|Só dentro da própria classe|
|`protected`|Classe + subclasses + mesmo pacote|
|`public`|Qualquer lugar|
|_(sem nada)_|Só dentro do mesmo pacote|

### Getters e Setters

São métodos `public` que controlam o acesso a atributos `private`:

```java
public class Pessoa {
    private String nome;
    private int idade;

    // getter — só lê
    public String getNome() {
        return nome;
    }

    // setter — pode validar antes de alterar
    public void setIdade(int idade) {
        if (idade >= 0) {
            this.idade = idade; // "this" = o objeto atual
        }
    }
}
```

### Construtores

Método especial chamado ao criar um objeto com `new`. Mesmo nome da classe, sem tipo de retorno.

```java
public class Carro {
    private String modelo;
    private int ano;

    // construtor
    public Carro(String modelo, int ano) {
        this.modelo = modelo;
        this.ano = ano;
    }
}

// Criando um objeto:
Carro c = new Carro("Fusca", 1980);
```

> **`this`** → referência ao objeto atual. Usado para diferenciar atributo do parâmetro quando têm o mesmo nome.

---

## 2. 🧩 Separação de Comportamento e Implementação

### Conceito

Definir **o que** um objeto faz (interface/contrato) separado de **como** ele faz (implementação). Isso permite trocar implementações sem quebrar quem usa.

### Classe Abstrata (`abstract class`)

- Não pode ser instanciada diretamente (`new` não funciona)
- Pode ter métodos concretos E métodos abstratos (sem corpo)
- Subclasses **obrigadas** a implementar os métodos abstratos

```java
abstract class Forma {
    String cor;

    abstract double calcularArea(); // sem corpo — cada forma calcula diferente

    void exibirCor() { // método concreto — herdado por todas
        System.out.println("Cor: " + cor);
    }
}

class Circulo extends Forma {
    double raio;

    @Override
    double calcularArea() {
        return Math.PI * raio * raio; // implementação obrigatória
    }
}
```

### Interface (`interface`)

- Define **apenas** o contrato (o que fazer), sem implementação (em Java 7 e antes)
- Uma classe pode implementar **múltiplas** interfaces
- Todos os métodos são implicitamente `public abstract`

```java
interface Voador {
    void voar();
}

interface Nadador {
    void nadar();
}

class Pato implements Voador, Nadador { // implementa duas interfaces
    public void voar() { System.out.println("Pato voando"); }
    public void nadar() { System.out.println("Pato nadando"); }
}
```

### Diferença: Classe Abstrata vs Interface

||Classe Abstrata|Interface|
|---|---|---|
|Instanciar?|❌ Não|❌ Não|
|Atributos com estado?|✅ Sim|❌ Não (só constantes)|
|Métodos concretos?|✅ Sim|⚠️ Só com `default` (Java 8+)|
|Herança múltipla?|❌ Não (só 1 `extends`)|✅ Sim (vários `implements`)|
|Palavra-chave|`extends`|`implements`|

---

## 3. 🏗️ Classes e Subclasses

### Classe

Molde que define atributos e métodos. Uma classe pode ter:

- **Atributos** → variáveis que guardam o estado
- **Métodos** → funções que definem o comportamento
- **Construtores** → inicializam o objeto

```java
public class Aluno {
    // atributos
    private String nome;
    private double nota;

    // construtor
    public Aluno(String nome, double nota) {
        this.nome = nome;
        this.nota = nota;
    }

    // método
    public boolean passou() {
        return nota >= 5.0;
    }
}
```

### Objeto (instância)

```java
Aluno a1 = new Aluno("João", 7.5);
Aluno a2 = new Aluno("Maria", 4.0);

System.out.println(a1.passou()); // true
System.out.println(a2.passou()); // false
```

### Subclasse

Herda da superclasse com `extends`. Pode adicionar atributos/métodos novos e sobrescrever existentes.

```java
class AlunoGraduacao extends Aluno {
    private String curso;

    public AlunoGraduacao(String nome, double nota, String curso) {
        super(nome, nota); // chama construtor da superclasse
        this.curso = curso;
    }

    public String getCurso() { return curso; }
}
```

> **`super`** → acessa construtor ou método da superclasse.

---

## 4. 🧬 Herança

### Conceito

Subclasse **herda automaticamente** todos os atributos e métodos `public` e `protected` da superclasse. Não herda `private`.

```java
class Animal {
    protected String nome;

    public Animal(String nome) {
        this.nome = nome;
    }

    public void comer() {
        System.out.println(nome + " está comendo.");
    }
}

class Cachorro extends Animal {
    public Cachorro(String nome) {
        super(nome); // obrigatório chamar construtor do pai
    }

    public void latir() {
        System.out.println(nome + " diz: Au!");
    }
}

// Uso:
Cachorro d = new Cachorro("Rex");
d.comer();  // herdado de Animal → "Rex está comendo."
d.latir();  // próprio de Cachorro → "Rex diz: Au!"
```

### O que é herdado?

- ✅ Atributos `public` e `protected`
- ✅ Métodos `public` e `protected`
- ✅ Construtores **não** são herdados — mas o construtor da subclasse deve chamar `super()`
- ❌ Atributos e métodos `private` (existem no objeto, mas não são acessíveis diretamente)

### `final`

- Classe `final` → não pode ser estendida
- Método `final` → não pode ser sobrescrito

---

## 5. 🎭 Polimorfismo

### Conceito

"Muitas formas" — o mesmo código se comporta de jeitos diferentes dependendo do tipo real do objeto.

### Override (Sobrescrita) — polimorfismo em tempo de execução

Subclasse **redefine** um método da superclasse com a mesma assinatura.

```java
class Animal {
    public void fazerSom() {
        System.out.println("Som genérico");
    }
}

class Cachorro extends Animal {
    @Override
    public void fazerSom() {
        System.out.println("Au!");
    }
}

class Gato extends Animal {
    @Override
    public void fazerSom() {
        System.out.println("Miau!");
    }
}
```

### Uso polimórfico — a mágica do POO

```java
Animal[] animais = { new Cachorro(), new Gato(), new Cachorro() };

for (Animal a : animais) {
    a.fazerSom(); // Java decide em tempo de execução qual método chamar
}
// Saída:
// Au!
// Miau!
// Au!
```

> A variável é do tipo `Animal`, mas o objeto real é `Cachorro` ou `Gato`. Java chama o método do **objeto real**, não da variável.

### Overload (Sobrecarga) — mesmo nome, parâmetros diferentes

```java
class Calculadora {
    public int somar(int a, int b) { return a + b; }
    public double somar(double a, double b) { return a + b; } // mesmo nome, tipos diferentes
    public int somar(int a, int b, int c) { return a + b + c; } // mesmo nome, mais parâmetros
}
```

### Override vs Overload

||Override|Overload|
|---|---|---|
|Onde ocorre?|Entre superclasse e subclasse|Na mesma classe|
|Assinatura|**Igual**|**Diferente** (parâmetros)|
|Retorno|Igual (ou covariante)|Pode ser diferente|
|Anotação|`@Override`|Nenhuma|
|Decisão|Tempo de **execução**|Tempo de **compilação**|

### Casting de tipos

```java
Animal a = new Cachorro(); // upcasting — automático, seguro
Cachorro c = (Cachorro) a; // downcasting — manual, pode falhar

// Para evitar erro, use instanceof:
if (a instanceof Cachorro) {
    Cachorro c2 = (Cachorro) a;
    c2.latir();
}
```

---

## 6. 🌳 Hierarquias de Classes

### Conceito

Classes organizadas em árvore de herança. Quanto mais alto, mais genérico; quanto mais baixo, mais específico.

```
Object  ← raiz de tudo em Java
  └── Animal
        ├── Mamifero
        │     ├── Cachorro
        │     └── Gato
        │           └── GatoSiames
        └── Ave
              ├── Papagaio
              └── Pinguim
```

### Regras importantes

- Em Java, herança é **simples**: uma classe só pode ter **uma** superclasse direta
- Toda classe em Java herda de `Object` automaticamente (métodos `toString()`, `equals()`, `hashCode()`)
- Uma referência de tipo superclasse pode apontar para objeto de qualquer subclasse

```java
Animal a1 = new Cachorro(); // válido
Animal a2 = new GatoSiames(); // válido — GatoSiames é um Animal
```

### Sobrescrevendo `toString()` (muito cobrado em prova)

```java
class Produto {
    private String nome;
    private double preco;

    public Produto(String nome, double preco) {
        this.nome = nome;
        this.preco = preco;
    }

    @Override
    public String toString() {
        return "Produto[" + nome + ", R$" + preco + "]";
    }
}

Produto p = new Produto("Caneta", 2.50);
System.out.println(p); // chama toString() automaticamente → Produto[Caneta, R$2.5]
```

---

## 7. 📦 Classes de Coleções e Métodos de Iteração

### O que são Coleções?

Estruturas que guardam **grupos de objetos**. Ficam no pacote `java.util`.

### ArrayList — a mais usada

```java
import java.util.ArrayList;

ArrayList<String> lista = new ArrayList<>();

// Adicionar
lista.add("Ana");
lista.add("Bruno");
lista.add("Carlos");

// Acessar por índice
System.out.println(lista.get(0)); // "Ana"

// Tamanho
System.out.println(lista.size()); // 3

// Remover
lista.remove("Bruno");       // por valor
lista.remove(0);             // por índice

// Verificar existência
lista.contains("Carlos");    // true ou false
```

### Formas de iterar

```java
// 1. for-each (mais simples)
for (String nome : lista) {
    System.out.println(nome);
}

// 2. for clássico com índice
for (int i = 0; i < lista.size(); i++) {
    System.out.println(lista.get(i));
}

// 3. Iterator
import java.util.Iterator;
Iterator<String> it = lista.iterator();
while (it.hasNext()) {
    System.out.println(it.next());
}
```

### ArrayList com objetos próprios

```java
ArrayList<Aluno> turma = new ArrayList<>();
turma.add(new Aluno("João", 8.0));
turma.add(new Aluno("Maria", 4.5));

for (Aluno a : turma) {
    if (a.passou()) {
        System.out.println(a.getNome() + " passou!");
    }
}
```

### Outras coleções (conhecer o conceito)

|Coleção|Característica|
|---|---|
|`ArrayList<E>`|Lista ordenada, acesso por índice, permite duplicatas|
|`LinkedList<E>`|Lista encadeada, boa para inserção/remoção no meio|
|`HashSet<E>`|Sem ordem, sem duplicatas|
|`HashMap<K,V>`|Par chave-valor, acesso por chave|

```java
import java.util.HashMap;

HashMap<String, Integer> notas = new HashMap<>();
notas.put("João", 8);
notas.put("Maria", 6);

System.out.println(notas.get("João")); // 8

for (String aluno : notas.keySet()) {
    System.out.println(aluno + ": " + notas.get(aluno));
}
```

---

## 🗺️ Resumo Visual

```
CLASSE
├── Atributos (estado) → normalmente private
├── Construtor → inicializa com new
└── Métodos (comportamento) → public/protected

ENCAPSULAMENTO → private + getters/setters
HERANÇA → extends + super()
POLIMORFISMO → @Override + variável do tipo pai
ABSTRAÇÃO → abstract class / interface
COLEÇÕES → ArrayList<Tipo> + for-each
```

---

## ✅ Checklist para a prova

- [ ] Saber criar uma classe com atributos `private`, construtor e getters/setters
- [ ] Usar `this` e `super` corretamente
- [ ] Criar subclasse com `extends` e chamar `super()` no construtor
- [ ] Diferenciar `private`, `protected` e `public`
- [ ] Criar e usar classe `abstract` com método abstrato
- [ ] Criar e implementar uma `interface`
- [ ] Saber a diferença entre override e overload
- [ ] Escrever código polimórfico (variável do tipo pai, objeto do tipo filho)
- [ ] Usar `instanceof` antes de fazer downcasting
- [ ] Sobrescrever `toString()` com `@Override`
- [ ] Criar `ArrayList`, adicionar, remover, acessar por índice e iterar
- [ ] Montar uma hierarquia de classes coerente (ex: exame pede: "crie Animal, Cachorro, Gato")
