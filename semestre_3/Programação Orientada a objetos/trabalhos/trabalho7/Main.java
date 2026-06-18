package trabalhos.trabalho7;

public class Main {
    public static void main(String[] args) {
        Loja loja = new Loja();

        Livro livro1 = new Livro("9788535914849", "1984", 45.90, "George Orwell");
        Livro livro2 = new Livro("9788595084711", "O Alquimista", 39.90, "Paulo Coelho");
        CD cd1 = new CD("075678644596", "Hybrid Theory", 29.90, "Linkin Park", 12);
        DVD dvd1 = new DVD("7898494247141", "Inception", 19.90, "Christopher Nolan", 148);

        System.out.println("===== CADASTRANDO PRODUTOS =====");
        loja.adicionarProduto(livro1, 10);
        loja.adicionarProduto(livro2, 5);
        loja.adicionarProduto(cd1, 15);
        loja.adicionarProduto(dvd1, 8);

        loja.adicionarProduto(new Livro("9788535914849", "1984", 45.90, "George Orwell"), 5);

        loja.verificarEstoque();

        System.out.println("\n===== TESTE DE BUSCA POR CÓDIGO =====");
        Produto pCodigo = loja.buscarPorCodigoBarras("075678644596");
        System.out.println(pCodigo != null ? pCodigo : "Produto não encontrado.");

        System.out.println("\n===== TESTE DE BUSCA POR NOME =====");
        Produto pNome = loja.buscarPorNome("Inception");
        System.out.println(pNome != null ? pNome : "Produto não encontrado.");

        System.out.println("\n===== TESTE DE VENDAS =====");
        if (loja.venderProduto("9788535914849", 3)) {
            System.out.println("Venda de 3 unidades de '1984' realizada com sucesso!");
        } else {
            System.out.println("Falha na venda.");
        }

        if (loja.venderProduto("7898494247141", 20)) {
            System.out.println("Venda realizada com sucesso!");
        } else {
            System.out.println("Falha na venda de 'Inception': Estoque insuficiente para 20 unidades.");
        }

        System.out.println("\n===== ESTOQUE FINAL =====");
        loja.verificarEstoque();
    }
}