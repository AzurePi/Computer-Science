package predio;

/**
 *
 * @author Azure
 */
public class Elevador {
    private final int id;
    private Predio predio; //prédio em que o elevador está
    
    //construtor
    public Elevador(int n){
        this.id = n;
    }
    
    // métodos --------------------------------
    public Andar mover(int destino){
        return predio.getAndares().get(destino);
    }
}
