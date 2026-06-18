package trabalhos.trabalho6;

public class Retangulo extends Figura {
    private int l1;
    private int l2;

    public Retangulo(String cor, boolean filled, int l1, int l2) {
        super(cor, filled);

        this.l1 = l1;
        this.l2 = l2;
    }

    @Override
    public double getArea() {
        double area = l1 * l2;
        return area;
    }

    @Override
    public double getPerimetro() {
        double perimetro = 2 * l1 + 2 * l2;
        return perimetro;
    }

    @Override
    public String toString() {
        return "\n=== Retangulo ===\n" +
                super.toString() +
                "\nBase: " + l1 +
                "\nALtura: " + l2;
    }

}
