public class Placar {
    private int creditos;

    public Placar(int creditosIniciais) {
        this.creditos = creditosIniciais;
    }

    public int getCreditos() {
        return creditos;
    }

    public void debitar(int valor) {
        creditos -= valor;
    }

    public void adicionar(int valor) {
        creditos += valor;
    }
}