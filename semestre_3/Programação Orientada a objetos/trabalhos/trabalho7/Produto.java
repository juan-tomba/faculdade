package trabalhos.trabalho7;

public abstract class Produto {
    protected String codigoBarras;
    protected String nome;
    protected double preco;
    protected int quantidade;

    public Produto(String codigoBarras, String nome, double preco) {
        this.codigoBarras = codigoBarras;
        this.nome = nome;
        this.preco = preco;
        this.quantidade = 0;
    }

    public String getCodigoBarras() {
        return codigoBarras;
    }

    public String getNome() {
        return nome;
    }

    public double getPreco() {
        return preco;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public void adicionarQuantidade(int qtd) {
        this.quantidade += qtd;
    }

    public boolean removerQuantidade(int qtd) {
        if (this.quantidade >= qtd) {
            this.quantidade -= qtd;
            return true;
        }
        return false;
    }

    public abstract String getCategoria();

    @Override
    public String toString() {
        return "Código de Barras: " + codigoBarras +
                "\nNome: " + nome +
                "\nPreço: R$ " + String.format("%.2f", preco) +
                "\nQuantidade em Estoque: " + quantidade;
    }
}