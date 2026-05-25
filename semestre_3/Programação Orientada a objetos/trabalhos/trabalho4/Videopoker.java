import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Videopoker {
    private Scanner scanner;

    public Videopoker() {
        this.scanner = new Scanner(System.in);
    }

    public void jogar() {
        System.out.print("Semente: ");
        int seed = 0;
        if (scanner.hasNextLine()) {
            try { seed = Integer.parseInt(scanner.nextLine().trim()); } catch (Exception e) {}
        }

        System.out.print("Saldo inicial: ");
        int saldoInicial = 200;
        if (scanner.hasNextLine()) {
            try { saldoInicial = Integer.parseInt(scanner.nextLine().trim()); } catch (Exception e) {}
        }

        Placar placar = new Placar(saldoInicial);
        
        // cria o baralho 
        Baralho baralho = new Baralho(seed);
        
        // embaralha dnv
        baralho.embaralha();

        while (placar.getCreditos() > 0) {
            System.out.println("Saldo atual: $" + placar.getCreditos());
            System.out.print("Digite o valor da aposta of 'F' para terminar ==> ");
            
            if (!scanner.hasNextLine()) break;
            String entrada = scanner.nextLine().trim();
            
            if (entrada.equalsIgnoreCase("F")) {
                System.out.println("Terminando o jogo... Parabéns você ainda tem saldo de $" + placar.getCreditos());
                break;
            }

            int aposta = 0;
            try {
                aposta = Integer.parseInt(entrada);
            } catch (NumberFormatException e) {
                continue;
            }

            if (aposta > placar.getCreditos()) {
                System.out.println("Saldo insuficiente. Tecle enter para continuar");
                if (scanner.hasNextLine()) scanner.nextLine(); 
                continue;
            }
            
            if (aposta <= 0) continue;

            placar.debitar(aposta);

            Carta[] mao = new Carta[5];
            ArrayList<Carta> descarte = new ArrayList<>();

            // tira as 5 primeiras cartas
            for (int i = 0; i < 5; i++) {
                mao[i] = baralho.comprar();
            }

            mostrarMao(mao);

            // trocas
            for (int rodada = 0; rodada < 2; rodada++) {
                System.out.print("Digite o número das cartas que você deseja trocar, separados por espaços: ");
                if (!scanner.hasNextLine()) break;
                String trocasStr = scanner.nextLine().trim();
                
                if (!trocasStr.isEmpty()) {
                    boolean[] trocar = new boolean[5];
                    String[] indices = trocasStr.split("\\s+");
                    
                    // quais posições devem ser trocadas
                    for (String idx : indices) {
                        try {
                            int pos = Integer.parseInt(idx) - 1;
                            if (pos >= 0 && pos < 5) {
                                trocar[pos] = true;
                            }
                        } catch (Exception e) {}
                    }
                    
                    // executa as trocas da esquerda para a direita
                    for (int i = 0; i < 5; i++) {
                        if (trocar[i]) {
                            // carta atual vai pro descarte
                            Carta substituida = mao[i];
                            descarte.add(substituida);
                            
                            // nova carta vem do topo do baralho
                            mao[i] = baralho.comprar();
                        }
                    }
                }
                mostrarMao(mao);
            }

            int multiplicador = avaliarMao(mao);
            if (multiplicador > 0) {
                int premio = multiplicador * aposta;
                placar.adicionar(premio);
                System.out.println("Parabéns. Você acrescentou $" + premio + " ao seu saldo");
            } else {
                System.out.println("Peninha... não ganhou nada nessa rodada");
            }
            
            
            // joga a mão pro final do baralho
            for (int i = 0; i < 5; i++) {
                baralho.add(mao[i]);
            }
            
            // joga o descarte pro final do baralho
            for (Carta c : descarte) {
                baralho.add(c);
            }
            
            // embaralha para a próxima rodada
            baralho.embaralha();

            System.out.println("Tecle enter para continuar");
            if (scanner.hasNextLine()) scanner.nextLine(); 
        }
        
        if (placar.getCreditos() <= 0) {
            System.out.println("Seu saldo acabou. Tente jogar outra vez.");
        }
    }

    private void mostrarMao(Carta[] mao) {
        System.out.print("\n");
        System.out.println("+-----+ +-----+ +-----+ +-----+ +-----+ ");
        System.out.println("|     | |     | |     | |     | |     | ");
        
        for (int i = 0; i < 5; i++) {
            String val = mao[i].getValorString();
            String naipe = mao[i].getNaipeString();
            String meio = (val.length() == 1) ? val + " " + naipe : val + naipe;
            System.out.print("| " + meio + " | ");
        }
        System.out.println();
        
        System.out.println("|     | |     | |     | |     | |     | ");
        System.out.println("+-----+ +-----+ +-----+ +-----+ +-----+ ");
        System.out.println("  (1)     (2)     (3)     (4)     (5)");
    }

    private int avaliarMao(Carta[] maoOrig) {
        Carta[] mao = maoOrig.clone();
        Arrays.sort(mao); 

        int[] contagemValores = new int[15];
        int[] contagemNaipes = new int[4];

        for (Carta c : mao) {
            contagemValores[c.getValor()]++;
            contagemNaipes[c.getNaipe().ordinal()]++;
        }

        boolean isFlush = false;
        for (int qte : contagemNaipes) {
            if (qte == 5) isFlush = true;
        }

        boolean isStraight = false;
        int sequenciaAtual = 0;
        for (int i = 2; i <= 14; i++) {
            if (contagemValores[i] == 1) {
                sequenciaAtual++;
                if (sequenciaAtual == 5) isStraight = true;
            } else {
                if (sequenciaAtual < 5) sequenciaAtual = 0;
            }
        }

        boolean isRoyal = isStraight && (mao[4].getValor() == 14 && mao[0].getValor() == 10);

        int pares = 0, trincas = 0, quadras = 0;
        for (int cont : contagemValores) {
            if (cont == 2) pares++;
            if (cont == 3) trincas++;
            if (cont == 4) quadras++;
        }

        if (isRoyal && isFlush) return 200;
        if (isStraight && isFlush) return 100;
        if (quadras == 1) return 50;
        if (trincas == 1 && pares == 1) return 20;
        if (isFlush) return 10;
        if (isStraight) return 5;
        if (trincas == 1) return 2;
        if (pares == 2) return 1;

        return 0;
    }
}