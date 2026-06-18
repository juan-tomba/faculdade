package trabalhos.trabalho6;

public abstract class Figura {
    protected String cor;
    protected boolean filled;

    public Figura(String cor, boolean filled) {
        this.cor = cor;
        this.filled = filled;

    }

    public String getCor() {
        return cor;
    }

    public abstract double getArea();

    public abstract double getPerimetro();

    @Override
    public String toString() {
        return "Cor: " + cor +
                "\nFilled: " + filled;
    }
}
