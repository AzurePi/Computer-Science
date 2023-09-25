package trabalho2.itens;

import java.util.Scanner;

/**
 * Extensão de <code>Item</code>.
 */
public class Revista extends Item {
    private int volume, numero;

    /**
     * Cria, a partir de input no console, uma nova <code>Revista</code>.
     */
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

    /**
     * Imprime no console as informações da <code>Revista</code>.
     */
    @Override
    public void imprimir() {
        super.imprimir();
        System.out.println("Volume: " + getVolume());
        System.out.println("Número: " + getNumero());
    }
}
