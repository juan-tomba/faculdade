package trabalhos.trabalho6;

public class Circulo extends Figura {
    private int raio;
    private double pi = Math.PI;

    public Circulo(String cor, boolean filled, int raio) {
        super(cor, filled);

        this.raio = raio;
    }

    @Override
    public double getArea() {
        double area = pi * raio * raio;
        return area;
    }

    @Override
    public double getPerimetro() {
        double perimetro = pi * raio * 2;
        return perimetro;
    }

    @Override
    public String toString() {
        return "\n=== Círculo ===\n" +
                super.toString() +
                "\nRaio: " + raio;
    }

}
