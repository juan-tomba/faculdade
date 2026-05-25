import java.util.Collections;
import java.util.Random;
import java.util.Vector;

public class Baralho extends Vector<Carta> {
    private Random rand;

    public Baralho(int seed) {
        if (seed == 0) rand = new Random();
        else rand = new Random(seed);
        
        // preenche o baralho
        for (Naipe p : Naipe.values()) {
            for (int i = 2; i <= 14; i++) {
                this.add(new Carta(i, p));
            }
        }
        
        this.embaralha();
    }

    public void embaralha() {
        Collections.shuffle(this, rand);
    }

    public Carta comprar() {
        // tira do começo (índice 0)
        return this.remove(0);
    }
}