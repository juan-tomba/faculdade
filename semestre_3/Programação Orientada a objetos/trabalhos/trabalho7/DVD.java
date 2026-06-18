package trabalhos.trabalho7;

public class DVD extends Produto {
    private String diretor;
    private int duracao; // min

    public DVD(String codigoBarras, String nome, double preco, String diretor, int duracao) {
        super(codigoBarras, nome, preco);
        this.diretor = diretor;
        this.duracao = duracao;
    }

    @Override
    public String getCategoria() {
        return "DVD";
    }

    @Override
    public String toString() {
        return "\n=== DVD ===\n" +
                super.toString() +
                "\nDiretor: " + diretor +
                "\nDuração: " + duracao + " min";
    }
}