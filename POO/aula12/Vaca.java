package aula12;

public class Vaca extends Animal {

    public Vaca(String nome, int numeroPatas) {
        super(nome, numeroPatas);
    }

    @Override
    public void emitirSom() {
        System.out.println("Muuhhhh");
    }
}
