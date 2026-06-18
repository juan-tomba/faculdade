package trabalhos.trabalho5;

public class Fisica extends Pessoa {

    private String cpf;
    private String dataNascimento;
    private String estadoCivil;

    public Fisica(
            String nome,
            String endereco,
            String email,
            String cpf,
            String dataNascimento,
            String estadoCivil) {

        super(nome, endereco, email);

        this.cpf = cpf;
        this.dataNascimento = dataNascimento;
        this.estadoCivil = estadoCivil;
    }

    @Override
    public int getTipo() {
        return 0;
    }

    @Override
    public String getDocumento() {
        return cpf;
    }

    @Override
    public String toString() {
        return "\n=== PESSOA FÍSICA ===\n" +
                super.toString() +
                "\nCPF: " + cpf +
                "\nData de Nascimento: " + dataNascimento +
                "\nEstado Civil: " + estadoCivil;
    }
}