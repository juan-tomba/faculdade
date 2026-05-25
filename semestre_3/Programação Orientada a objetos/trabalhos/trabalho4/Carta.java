public class Carta implements Comparable<Carta> {
    private int valor;
    private Naipe naipe;

    public Carta(int valor, Naipe naipe) {
        this.valor = valor;
        this.naipe = naipe;
    }

    public int getValor() {
        return valor;
    }

    public Naipe getNaipe() {
        return naipe;
    }

    public String getValorString() {
        switch (valor) {
            case 11: return "J";
            case 12: return "Q";
            case 13: return "K";
            case 14: return "A";
            default: return String.valueOf(valor);
        }
    }

    public String getNaipeString() {
        return naipe.getSimbolo();
    }

    @Override
    public int compareTo(Carta outra) {
        return Integer.compare(this.valor, outra.valor);
    }
}