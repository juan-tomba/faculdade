package trabalhos.trabalho5;

public class Main {

    public static void main(String[] args) {

        Agenda agenda = new Agenda();

        agenda.adicionarContato(
                new Fisica(
                        "Juan",
                        "São Carlos",
                        "juan@email.com",
                        "12345678900",
                        "18/11/2004",
                        "Casado"));

        agenda.adicionarContato(
                new Juridica(
                        "Gamerboxd",
                        "São Carlos",
                        "gamerboxd@email.com",
                        "12345678000199",
                        "123456789",
                        "Gamerboxd LTDA"));

        agenda.listarContatos();

        System.out.println(
                agenda.buscarPorNome("Juan"));

        System.out.println("===== LISTA ORIGINAL =====");
        agenda.listarContatos();

        System.out.println("\n===== BUSCA POR NOME =====");
        System.out.println(agenda.buscarPorNome("Juan"));

        System.out.println("\n===== BUSCA POR DOCUMENTO =====");
        System.out.println(agenda.buscarPorDocumento("12345678900"));

        System.out.println("\n===== ORDENANDO =====");
        agenda.ordena();
        agenda.listarContatos();

        System.out.println("\n===== REMOVENDO Juan =====");
        agenda.removerContato("12345678900");
        agenda.listarContatos();

    }
}
