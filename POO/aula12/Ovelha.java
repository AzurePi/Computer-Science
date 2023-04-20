package aula12;

public class Ovelha extends Animal {

    public Ovelha(String nome, int numeroPatas) {
        super(nome, numeroPatas);
    }

    @Override
    public void emitirSom() {
        System.out.println("Béhhhh");
    }
}
