package trabalhos.trabalho7;

public class CD extends Produto {
    private String artista;
    private int numFaixas;

    public CD(String codigoBarras, String nome, double preco, String artista, int numFaixas) {
        super(codigoBarras, nome, preco);
        this.artista = artista;
        this.numFaixas = numFaixas;
    }

    @Override
    public String getCategoria() {
        return "CD";
    }

    @Override
    public String toString() {
        return "\n=== CD ===\n" +
                super.toString() +
                "\nArtista: " + artista +
                "\nNúmero de Faixas: " + numFaixas;
    }
}