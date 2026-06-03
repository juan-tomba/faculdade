import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class GrafoListaAdjacencia extends Grafo{
    
    // Criando um mapa para ter a lista
    private Map<String, List<String>> lista;

    // nosso construtor
    public GrafoListaAdjacencia() {
        this.lista = new HashMap<>();
        this.num_v = 0;
        this.num_a = 0;
    }


    @Override
    // Funcao para adicionar vertice
    public void adicionarVertice(String vertice){
        // verifica se existe antes
        if(!existeVertice(vertice)){
            lista.put(vertice, new ArrayList<>());
            this.num_v++;
        }
    }
    

    @Override
    public void removerVertice(String vertice){
        // verifica se ele existe
       if (existeVertice(vertice)) {
            // Cria uma cópia da lista de adjacencia
            List<String> adjacentes = new ArrayList<>(lista.get(vertice));
            
            // Remove a aresta com cada vizinho
            for (String adj : adjacentes) {
                removerAresta(vertice, adj);
            }    
            // Remove o vértice do mapa de vertices
            lista.remove(vertice);
            this.num_v--;
        }
    }

    @Override
    public void adicionarAresta(String origem, String destino){
        // cria o vertice caso no exista
        adicionarVertice(origem);
        adicionarVertice(destino);

        if(!existeAresta(origem, destino)) {
            lista.get(origem).add(destino);
            
            // verifica se é um laço, para não inserir duas vezes
            if (!origem.equals(destino)) {
                lista.get(destino).add(origem);
            }
            this.num_a++;
        }
    }

    @Override
    public void removerAresta(String origem, String destino){
        // verifica se existe a aresta e remove, e também faz a verificação para remover correto (nas duas listas) caso nao seja laço
        if (existeAresta(origem, destino)) {
            lista.get(origem).remove(destino);
            if (!origem.equals(destino)) {
                lista.get(destino).remove(origem);
            }
            this.num_a--;
        }
    }

    @Override
    public boolean existeVertice(String vertice){
        // só retorna um true ou false se contem
        return lista.containsKey(vertice);
    }   

    @Override
    public boolean existeAresta(String origem, String destino){
        // se os 2 vertices existirem, retorna se tem aresta
        if (existeVertice(origem) && existeVertice(destino)) {
            return lista.get(origem).contains(destino);
        } 
        // se um dos vertices nao existir ja é falso
        return false;
    }

    @Override
    public int grau(String vertice){
        // tamanho da lista de adjacencia (qtd de arestas) do vertice escolhido
        if (existeVertice(vertice)) {
            return lista.get(vertice).size();
        }
        return 0;
    }

    @Override
    public int ordem(){
        return this.num_v;
    }

    @Override
    public int tamanho(){
        return this.num_a;
    }

    @Override
    public String toString(){
        List<String> verticesIsolados = new ArrayList<>();
        List<String> arestasFormatadas = new ArrayList<>();
        
        for (String origem : lista.keySet()) {
            // Se a lista do vértice estiver vazia, ele é isolado
            if (lista.get(origem).isEmpty()) {
                verticesIsolados.add("    \"" + origem + "\";\n");
            } else {
                for (String destino : lista.get(origem)) {
                    if (origem.compareTo(destino) <= 0) {
                        arestasFormatadas.add("    \"" + origem + "\" -- \"" + destino + "\";\n");
                    }
                }
            }
        }
        
        // Ordena separadamente
        Collections.sort(verticesIsolados);
        Collections.sort(arestasFormatadas);
        
        StringBuilder sb = new StringBuilder();
        sb.append("graph {\n");
        // Imprime os isolados primeiro (igual à saída esperada)
        for (String v : verticesIsolados) {
            sb.append(v);
        }
        // Depois imprime as arestas
        for (String aresta : arestasFormatadas) {
            sb.append(aresta);
        }
        sb.append("}\n");
        
        return sb.toString();

}
}
