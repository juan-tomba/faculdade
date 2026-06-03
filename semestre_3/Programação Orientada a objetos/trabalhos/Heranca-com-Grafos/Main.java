/* Felipe Fabiano das Chagas - 16811922
   Juan Pablo Tomba - 15638548 */


import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Inicialização dos três grafos
        GrafoListaAdjacencia grafoLista = new GrafoListaAdjacencia();
        GrafoMatrizAdjacencia grafoMatriz = new GrafoMatrizAdjacencia();
        GrafoPonderadoMatrizAdjacencia grafoPonderado = new GrafoPonderadoMatrizAdjacencia();

        Scanner scanner = new Scanner(System.in);

        // Leitura contínua até o eof
        while (scanner.hasNextLine()) {
            String linha = scanner.nextLine().trim();
            if (linha.isEmpty()) continue;

            String[] partes = linha.split("\\s+");
            String comando = partes[0];

            switch (comando) {
                case "i":
                    // Comando de inserção: i v1 v2 p
                    if (partes.length >= 4) {
                        String v1 = partes[1];
                        String v2 = partes[2];
                        int p = Integer.parseInt(partes[3]);

                        // Nos grafos não ponderados, o peso p é ignorado
                        grafoLista.adicionarAresta(v1, v2);
                        grafoMatriz.adicionarAresta(v1, v2);
                        
                        // No grafo ponderado, temos o 3 argumento da func (peso)
                        grafoPonderado.adicionarAresta(v1, v2, p);
                    }
                    break;

                case "d":
                    // Comando de remoção de aresta: d v1 v2
                    if (partes.length == 3) {
                        String v1 = partes[1];
                        String v2 = partes[2];
                        
                        grafoLista.removerAresta(v1, v2);
                        grafoMatriz.removerAresta(v1, v2);
                        grafoPonderado.removerAresta(v1, v2);
                        
                    // Comando de remoção de vértice: d v1 
                    } else if (partes.length == 2) {
                        String v1 = partes[1];
                        
                        grafoLista.removerVertice(v1);
                        grafoMatriz.removerVertice(v1);
                        grafoPonderado.removerVertice(v1);
                    }
                    break;

                case "p":
                    System.out.println("Lista de Adjacencia"); 
                    System.out.print(grafoLista.toString());

                    System.out.println("Matriz de Adjacencia"); 
                    System.out.print(grafoMatriz.toString()); 

                    System.out.println("Ponderado - Matriz de Adjacencia"); 
                    System.out.print(grafoPonderado.toString()); 
                    break;

                default:
                    // ignora comandos desconhecidos
                    break;
            }
        }
        
        scanner.close();
    }
}