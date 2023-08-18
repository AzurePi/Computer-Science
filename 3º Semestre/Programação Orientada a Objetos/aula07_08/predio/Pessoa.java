package aula07_08.predio;

import java.util.Scanner;

/**
 *
 * @author Azure
 */
public class Pessoa {
    private String nome;
    private Andar andar; //andar em que a pessoa está
    private Predio predio; //prédio em que a pessoa está
    
    // métodos -------------------------------------------

    /**
     * Imprime no console o andar atual da pessoa, pergunta ao usuário para qual andar ir, e atualiza o campo "andar"
     * @return um número que identifica o andar onde a pessoa se encontra
     */
    public int usarElevador(){
        Scanner sc =  new Scanner(System.in);
        
        System.out.println("A pessoa está no andar " + andar.getNumero());
        System.out.println("Ir para qual andar? ");
        int destino = sc.nextInt();
        
        Elevador elevador = predio.getElevadores().get((int) ((Math.random() *100) % predio.getElevadores().size()));
        
        andar = elevador.mover(destino);
        return andar.getNumero();
    }
    
}
