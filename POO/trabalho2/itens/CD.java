package trabalho2.itens;

import java.util.Scanner;

/**
 * Extensão de <code>Item</code>.
 */
public class CD extends Item {
    private int volume;
    private String gravadora;

    /**
     * Cria, a partir de input no console, um novo <code>CD</code>.
     */
    public CD() {
        super();
        Scanner sc = new Scanner(System.in);
        System.out.print("Volume: ");
        volume = sc.nextInt();
        System.out.print("Gravadora: ");
        gravadora = sc.nextLine();
    }

    public int getVolume() {
        return volume;
    }

    public void setVolume(int volume) {
        this.volume = volume;
    }

    public String getGravadora() {
        return gravadora;
    }

    public void setGravadora(String gravadora) {
        this.gravadora = gravadora;
    }

    /**
     * Imprime no console as informações do <code>CD</code>.
     */
    @Override
    public void imprimir(){
        super.imprimir();
        System.out.println("Volume: " + getVolume());
        System.out.println("Número: " + getGravadora());
    }
}
