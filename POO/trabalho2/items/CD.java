package trabalho2.items;

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
        sc.close();
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
}
