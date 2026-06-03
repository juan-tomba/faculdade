interface I{
    void f();
}

interface I1{
    void f();
    void k();
}

class A implements I{
    public void f(){
        System.out.println("f no A");
    }

    public void g(){
        System.out.println("g no A");
    }
}

class B extends A implements I1{
    public void f(){
        System.out.println("f no B");
    }
    public void k(){
        return;
    }
}

class Malandra extends A implements I {
    public void g(){
        return;
    }
}

public class Main {
    public static void main(String [] args){
        System.out.println("Hello World");
        A a = new A();
        a.f(); 

        B b = new B();
        b.f();
        b.g();

        A a1 = new B();
        a1.f();
        // a1.k(); nao compila
        a1.g();

        // B b1 = new A(); não pode, pq o A é o "pai do B"

        I i = new A();
        i.f();
        // i1.g();
        I1 i1 = new B();
        i1.k();
    }

    void umaFuncao(I x){
        x.f();
    }
}