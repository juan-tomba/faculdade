package trabalhos.trabalho7;

import java.util.ArrayList;

public class Loja {
    private ArrayList<Produto> produtos;

    public Loja() {
        produtos = new ArrayList<>();
    }

    public void adicionarProduto(Produto produto, int quantidade) {
        Produto existente = buscarPorCodigoBarras(produto.getCodigoBarras());
        if (existente != null) {
            existente.adicionarQuantidade(quantidade);
        } else {
            produto.setQuantidade(quantidade);
            produtos.add(produto);
        }
    }

    public Produto buscarPorCodigoBarras(String codigoBarras) {
        for (Produto p : produtos) {
            if (p.getCodigoBarras().equals(codigoBarras)) {
                return p;
            }
        }
        return null;
    }

    public Produto buscarPorNome(String nome) {
        for (Produto p : produtos) {
            if (p.getNome().equalsIgnoreCase(nome)) {
                return p;
            }
        }
        return null;
    }

    public boolean venderProduto(String codigoBarras, int quantidade) {
        Produto p = buscarPorCodigoBarras(codigoBarras);
        if (p != null) {
            return p.removerQuantidade(quantidade);
        }
        return false; // nao encontrou
    }

    public void verificarEstoque() {
        int totalLivros = 0;
        int totalCDs = 0;
        int totalDVDs = 0;

        System.out.println("===== DETALHES DO ESTOQUE =====");
        for (Produto p : produtos) {
            System.out.println(p);
            System.out.println("---");

            if (p instanceof Livro) {
                totalLivros += p.getQuantidade();
            } else if (p instanceof CD) {
                totalCDs += p.getQuantidade();
            } else if (p instanceof DVD) {
                totalDVDs += p.getQuantidade();
            }
        }

        System.out.println("\n===== RESUMO POR CATEGORIA =====");
        System.out.println("Livros: " + totalLivros + " itens");
        System.out.println("CDs: " + totalCDs + " itens");
        System.out.println("DVDs: " + totalDVDs + " itens");
        System.out.println("Total Geral em Estoque: " + (totalLivros + totalCDs + totalDVDs) + " itens");
    }
}