interface I {
    int f(int x);
}

class A implements I {
    public int f(int x){
        return x + 1;
    }
}

class B implements I {
    public int f(int x){
        return x - 1;
    }
}

public class Main3 {
    public static void main(String[] args){
        I i = new A();
        int z = i.f(5);
        I v[] = {new A(), new B()};
        I vs[] = {x -> (x*2), x -> (x+1), x -> (x-1)};
        int y = func(5, v);
        I h = x -> (2*x + 1);
    }
    static public int func(int x, I v[]){
        int s = 0;
        for (I i : v){
            s += i.f(x);
        }
        return s;
    }
    // static List<T> filtra(Pred<T> t)
}
