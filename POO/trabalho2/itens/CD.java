package trabalho2.itens;

import java.util.Scanner;

public class CD extends Item {
    private int volume;
    private String gravadora;

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

    @Override
    public void imprimir(){
        super.imprimir();
        System.out.println("Volume: " + getVolume());
        System.out.println("Número: " + getGravadora());
    }
}
