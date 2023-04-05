package predio;

import java.util.Scanner;

/**
 *
 * @author Azure
 */
public class Pessoa {
    private String nome;
    private float peso;
    private Andar andar; //andar em que a pessoa está
    private Predio predio; //prédio em que a pessoa está
    
    // métodos --------------------------------
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
