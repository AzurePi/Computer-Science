package aula7_8.predio;

import java.util.ArrayList;
import java.util.List;

/**
 * Um prédio, com endereço, lista de andares e lista de elevadores.
 * Tem, no mínimo, 5 andares e 1 elevador e, no máximo, 20 andares e 3 elevadores.
 * @author Azure
 */
public class Predio {
    private final String endereco;
    private List<Andar> andares = new ArrayList<>();
    private List<Elevador> elevadores = new ArrayList<>();
    
    /**
    * Cria um prédio com 5 andares e 1 elevador
    * @param endereco string com o endereço do prédio
    */
    public Predio(String endereco){
        this.endereco = endereco;
        
        for(int i = 0; i<5; i++){
            criarAndar();
        }
        criarElevador();
    }
    
    //setter & getters -----------------------------------
    public List<Elevador> getElevadores(){
        return elevadores;
    }
    
    public List<Andar> getAndares(){
        return andares;
    }

    // métodos -------------------------------------------
    /** Cria um andar no prédio */
    public void criarAndar(){
        andares.add(new Andar(andares.size() + 1));
    }

    /** Cria um elevador no prédio */
    public void criarElevador(){
        elevadores.add(new Elevador(elevadores.size() + 1));
    }
}
