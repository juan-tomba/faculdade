class A<T>{ // esse <T> serve para generalizar nossa class 
    private T val;
    public T getval() {
        return val;
    }
    public void setVal(T v) {
        val = v;
    }
}


public class Main2 {
    public static void main(String[] args){
        System.out.println("Hello World");
        A<String> a = new A<String>();
        // A<Venda> b = new A<Venda>(); isso pode
    }
}
