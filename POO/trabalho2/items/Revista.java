package trabalho2.items;

import java.util.Scanner;

public class Revista extends Item {
    private int volume, numero;

    public Revista(String titulo, String autor, int anoPublicacao, int disponivel, int emprestada, int volume, int numero) {
        super(titulo, autor, anoPublicacao, disponivel, emprestada);
        this.volume = volume;
        this.numero = numero;
    }

    public Revista() {
        super();
        Scanner sc = new Scanner(System.in);
        System.out.print("Volume: ");
        volume = sc.nextInt();
        System.out.print("Número: ");
        numero = sc.nextInt();
    }

    public int getVolume() {
        return volume;
    }

    public void setVolume(int volume) {
        this.volume = volume;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }
}
