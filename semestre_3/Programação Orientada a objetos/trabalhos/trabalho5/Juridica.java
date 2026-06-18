package trabalhos.trabalho5;

public class Juridica extends Pessoa {

    private String cnpj;
    private String inscricaoEstadual;
    private String razaoSocial;

    public Juridica(
            String nome,
            String endereco,
            String email,
            String cnpj,
            String inscricaoEstadual,
            String razaoSocial) {

        super(nome, endereco, email);

        this.cnpj = cnpj;
        this.inscricaoEstadual = inscricaoEstadual;
        this.razaoSocial = razaoSocial;
    }

    @Override
    public int getTipo() {
        return 1;
    }

    @Override
    public String getDocumento() {
        return cnpj;
    }

    @Override
    public String toString() {
        return "\n=== PESSOA JURÍDICA ===\n" +
                super.toString() +
                "\nCNPJ: " + cnpj +
                "\nInscrição Estadual: " + inscricaoEstadual +
                "\nRazão Social: " + razaoSocial;
    }
}