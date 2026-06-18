package trabalhos.trabalho5;

import java.util.ArrayList;

public class Agenda {

    private ArrayList<Pessoa> contatos;

    public Agenda() {
        contatos = new ArrayList<>();
    }

    public void adicionarContato(Pessoa pessoa) {
        contatos.add(pessoa);
    }

    public boolean removerContato(String documento) {
        return contatos.removeIf(
                p -> p.getDocumento().equals(documento));
    }

    public Pessoa buscarPorNome(String nome) {
        for (Pessoa p : contatos) {
            if (p.getNome().equalsIgnoreCase(nome)) {
                return p;
            }
        }
        return null;
    }

    public Pessoa buscarPorDocumento(String documento) {
        for (Pessoa p : contatos) {
            if (p.getDocumento().equals(documento)) {
                return p;
            }
        }
        return null;
    }

    public void listarContatos() {
        for (Pessoa p : contatos) {
            System.out.println(p);
            System.out.println("---");
        }
    }

    private int comparar(Pessoa p1, Pessoa p2) {

        if (p1.getTipo() != p2.getTipo()) {
            return p1.getTipo() - p2.getTipo();
        }

        return p1.getDocumento().compareTo(p2.getDocumento());
    }

    public void ordena() {

        for (int i = 1; i < contatos.size(); i++) {

            Pessoa atual = contatos.get(i);
            int j = i - 1;

            while (j >= 0 && comparar(contatos.get(j), atual) > 0) {

                contatos.set(j + 1, contatos.get(j));
                j--;
            }

            contatos.set(j + 1, atual);
        }
    }
}