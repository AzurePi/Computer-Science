package aula17;

import java.util.ArrayList;
import java.util.List;

public class Box<T extends Number> {
    List<T> conteudo;
    int size;
    int maxSize;

    public Box(List<T> numero) {
        conteudo = numero;
        size = conteudo.size();
        maxSize = size;
    }

    public int getSize() {
        return size;
    }

    public List<T> getConteudo() {
        return conteudo;
    }

    public int getMaxSize() {
        return maxSize;
    }

    public void porNaCaixa(T numero) {
        if (!cheia()) {
            conteudo.add(numero);
            size = conteudo.size();
        } else System.out.println("A caixa já está cheia!");
    }

    public boolean cheia() {
        return size == maxSize;
    }
}
