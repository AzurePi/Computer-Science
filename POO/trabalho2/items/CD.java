package trabalho2.items;

import java.util.Scanner;

public class CD extends Item {
    private int volume;
    private String gravadora;

    public CD(String titulo, String autor, int anoPublicacao, int disponivel, int emprestada, int volume, String gravadora) {
        super(titulo, autor, anoPublicacao, disponivel, emprestada);
        this.volume = volume;
        this.gravadora = gravadora;
    }

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
}
