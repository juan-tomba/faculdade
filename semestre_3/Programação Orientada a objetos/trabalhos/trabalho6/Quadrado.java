package trabalhos.trabalho6;

public class Quadrado extends Figura {
    private int lado;

    public Quadrado(String cor, boolean filled, int lado) {
        super(cor, filled);

        this.lado = lado;
    }

    @Override
    public double getArea() {
        double area = lado * lado;
        return area;
    }

    @Override
    public double getPerimetro() {
        double perimetro = 4 * lado;
        return perimetro;
    }

    @Override
    public String toString() {
        return "\n=== Quadrado ===\n" +
                super.toString() +
                "\nLados: " + lado;
    }

}
