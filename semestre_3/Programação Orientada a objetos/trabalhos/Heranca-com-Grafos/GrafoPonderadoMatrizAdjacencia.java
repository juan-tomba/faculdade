import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class GrafoPonderadoMatrizAdjacencia extends Grafo {
    private int[][] matriz = new int[100][100];
    private Map<String, Integer> indice = new HashMap<>();
    
    // array q guarda qual vertice esta em qual indice da matriz.
    private String[] nomes = new String[100];

    public GrafoPonderadoMatrizAdjacencia() {
        this.num_v = 0;
        this.num_a = 0;
        // inicializa a matriz com -1 (indicando ausência de aresta)
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                matriz[i][j] = -1;
            }
        }
    }

    @Override
    public void adicionarVertice(String vertice) {
        if (indice.containsKey(vertice)) {
            return;
        }

        // procura a primeira posição livre no array de nomes
        int pos = -1;
        for (int i = 0; i < 100; i++) {
            if (nomes[i] == null) {
                pos = i;
                break;
            }
        }

        if (pos != -1) {
            indice.put(vertice, pos);
            nomes[pos] = vertice;
            num_v++;
        }
    }

    @Override
    public void removerVertice(String vertice) {
        if (!indice.containsKey(vertice)) {
            return;
        }

        int ind = indice.get(vertice);

        // remove todas as arestas ligadas a este vértice zerando a linha e a coluna
        for (int j = 0; j < 100; j++) {
            if (matriz[ind][j] != -1) {
                matriz[ind][j] = -1;
                matriz[j][ind] = -1;
                num_a--; // reduz o total de arestas do grafo
            }
        }

        // remove do map e libera o espaço no array de nomes
        indice.remove(vertice);
        nomes[ind] = null;
        num_v--;
    }

    // Sobrecarga exigida pela classe abstrata. Se não passar peso, assumimos 1.
    @Override
    public void adicionarAresta(String origem, String destino) {
        adicionarAresta(origem, destino, 1);
    }

    // Método principal com peso
    public void adicionarAresta(String origem, String destino, int peso) {
        // se os vértices não existirem, cria eles
        if (!existeVertice(origem)) adicionarVertice(origem);
        if (!existeVertice(destino)) adicionarVertice(destino);

        int i = indice.get(origem);
        int j = indice.get(destino);

        // se a aresta ainda não existia, aumenta o contador
        if (matriz[i][j] == -1) {
            num_a++;
        }
        
        // cria ou atualiza a aresta com o peso
        matriz[i][j] = peso;
        matriz[j][i] = peso;
    }

    @Override
    public void removerAresta(String origem, String destino) {
        if (!existeVertice(origem) || !existeVertice(destino)) {
            return;
        }

        int i = indice.get(origem);
        int j = indice.get(destino);

        // remove aresta voltando para -1
        if (matriz[i][j] != -1) {
            matriz[i][j] = -1;
            matriz[j][i] = -1;
            num_a--;
        }
    }

    @Override
    public boolean existeVertice(String vertice) {
        return indice.containsKey(vertice);
    }

    @Override
    public boolean existeAresta(String origem, String destino) {
        if (!existeVertice(origem) || !existeVertice(destino)) {
            return false;
        }
        int i = indice.get(origem);
        int j = indice.get(destino);
        return matriz[i][j] != -1;
    }

    @Override
    public int grau(String vertice) {
        if (!existeVertice(vertice)) {
            return 0;
        }
        
        int ind = indice.get(vertice);
        int grauVertice = 0;
        
        // calcula grau
        for (int j = 0; j < 100; j++) {
            if (matriz[ind][j] != -1) {
                grauVertice++;
            }
        }
        return grauVertice;
    }

    @Override
    public int ordem() {
        return num_v;
    }

    @Override
    public int tamanho() {
        return num_a;
    }

    @Override
    public String toString() {
       List<String> verticesIsolados = new ArrayList<>();
        List<String> arestasFormatadas = new ArrayList<>();

        List<String> verticesOrdenados = new ArrayList<>(indice.keySet());
        Collections.sort(verticesOrdenados);

        for (int i = 0; i < verticesOrdenados.size(); i++) {
            String v1 = verticesOrdenados.get(i);
            int ind1 = indice.get(v1);

            // Verifica isolados
            if (grau(v1) == 0) {
                verticesIsolados.add("    \"" + v1 + "\";\n");
            } else {
                for (int j = i; j < verticesOrdenados.size(); j++) {
                    String v2 = verticesOrdenados.get(j);
                    int ind2 = indice.get(v2);

                    if (matriz[ind1][ind2] != -1) {
                        int peso = matriz[ind1][ind2];
                        arestasFormatadas.add("    \"" + v1 + "\" -- \"" + v2 + "\" [label=\"" + peso + "\"];\n");
                    }
                }
            }
        }

        Collections.sort(verticesIsolados);
        Collections.sort(arestasFormatadas);

        StringBuilder sb = new StringBuilder();
        sb.append("graph {\n");
        for (String v : verticesIsolados) {
            sb.append(v);
        }
        for (String aresta : arestasFormatadas) {
            sb.append(aresta);
        }
        sb.append("}\n");
        return sb.toString();
}
}