package trabalhos.trabalho7;

public class Livro extends Produto {
    private String autor;

    public Livro(String codigoBarras, String nome, double preco, String autor) {
        super(codigoBarras, nome, preco);
        this.autor = autor;
    }

    @Override
    public String getCategoria() {
        return "Livro";
    }

    @Override
    public String toString() {
        return "\n=== LIVRO ===\n" +
                super.toString() +
                "\nAutor: " + autor;
    }
}