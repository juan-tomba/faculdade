import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        if (!scanner.hasNextLine()){
            scanner.close();
            return;
        }

        // leitura das strings de inicialização
        Tabuleiro tabuleiro = entrada_tab(scanner.nextLine());
        
        // le os movimentos
        if (scanner.hasNextLine()) {
            tabuleiro.execMov(scanner.nextLine());
        }

        scanner.close();
    }

    private static Tabuleiro entrada_tab(String linha) {
        String[] partes = linha.trim().split("\\s+"); // remove espaços
        int n = (int) Math.sqrt(partes.length); // calcula dimensao do tabuleiro
        int[] config = new int[partes.length];
        
        for (int i = 0; i < partes.length; i++) {
            config[i] = Integer.parseInt(partes[i]);
        }
        
        return new Tabuleiro(n, config); // chama construtor
    }
}