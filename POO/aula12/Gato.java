package aula12;

public class Gato extends Animal {

    public Gato(String nome, int numeroPatas) {
        super(nome, numeroPatas);
    }

    @Override
    public void emitirSom() {
        System.out.println("Miau");
    }

}
