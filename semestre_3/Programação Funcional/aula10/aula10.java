public class aula10 {
    public static void main(String[] args) {
        List<Produto> produtos = new ArrayList<Produto>();
            produtos.add(new Produto("Camiseta", 29.99, TipoProduto.VESTUARIO));
            produtos.add(new Produto("Calça Jeans", 79.99, TipoProduto.VESTUARIO));
            produtos.add(new Produto("Tênis", 149.99, TipoProduto.CALÇADOS));
            produtos.add(new Produto("Relógio", 199.99, TipoProduto.ACESSÓRIOS));
        
        produtos 
            .stream() 
            .map(Produto::getNome)    //.map(p -> p.getNome())
            .forEach(n -> {System.out.println(n);});
        
        produtos 
            .stream() 
            .peek(p -> {System.out.println("Linha 52:"+ p.getNome()); })           
            .map(p -> p.getNome()) 
            .forEach(n -> {System.out.println(n);});
    }
}