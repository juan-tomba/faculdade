public class Tabuleiro {
    private int[][] table;
    private int size;
    private int posX, posY; // rastrear espaço vazio

    // construtor do tabuleiro, com base no tamanho (calculado na main)
    public Tabuleiro(int tam, int[] config) {
        size = tam;
        table = new int[tam][tam];
        
        int k = 0;
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                table[i][j] = config[k];
                if (config[k] == 0) { // acha o vazio
                    posX = i;
                    posY = j;
                }
                k++;
            }
        }
        imprimir();
    }


    public void execMov(String movimentos) {
        for (char m : movimentos.toCharArray()) {
            switch (m) {
            case 'u': trocar(posX + 1, posY); break;
            case 'd': trocar(posX - 1, posY); break;
            case 'l': trocar(posX, posY + 1); break;
            case 'r': trocar(posX, posY - 1); break;
        }
            imprimir();
        }
        if (jogo_certo()) {
            System.out.println("Posicao final: true");
        } else {
            System.out.println("Posicao final: false");
        }
    }

    public void imprimir() {
        // cria a linha de borda
        String borda = "+";
        for (int k = 0; k < size; k++) {
            borda += "------+";
        }

        for (int i = 0; i < size; i++) {
            // imprime a borda ANTES de cada linha de números
            System.out.println(borda);
            
            for (int j = 0; j < size; j++) {
                System.out.print("|"); // inicio da célula
                if (table[i][j] > 9){
                    System.out.print("  " + table[i][j] + "  ");
                }
                else{
                    System.out.print("   " + table[i][j] + "  ");
                }
            }
            System.out.println("|"); // fecha a linha
        }
        
        // borda final
        System.out.println(borda);
        
        // pula linha
        System.out.println();
    }

    public boolean jogo_certo(){
        int num = 1;

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                if (i == 0 && j == 0){
                    if (table[i][j] != 0){
                        return false;
                    }
                }
                else{
                    if (table[i][j] != num){
                        return false;
                    }
                    num++;
                }
            }
        }
        return true;
    }

    private void trocar(int i, int j) {
        if (i >= 0 && i < size && j >= 0 && j < size) {
            int temp = table[i][j];
            table[i][j] = table[posX][posY];
            table[posX][posY] = temp;
            posX = i;
            posY = j;
        }
    }

}