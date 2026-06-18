package trabalhos.trabalho5;

public abstract class Pessoa {
    protected String nome;
    protected String endereco;
    protected String email;

    public Pessoa(String nome, String endereco, String email) {
        this.nome = nome;
        this.endereco = endereco;
        this.email = email;
    }

    public String getNome() {
        return nome;
    }

    public abstract String getDocumento();

    public abstract int getTipo();

    @Override
    public String toString() {
        return "Nome: " + nome +
                "\nEndereço: " + endereco +
                "\nEmail: " + email;
    }
}
