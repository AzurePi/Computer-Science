package aula17;

import java.util.ArrayList;

public class Box<T extends Number> {
    ArrayList<T> conteudo;
    int size;
    int maxSize;

    public Box(ArrayList<T> numero) {
        conteudo = numero;
        size = conteudo.size();
        maxSize = size;
    }

    public Box(ArrayList<T> numero, int maxSize) {
        conteudo = numero;
        size = conteudo.size();
        this.maxSize = maxSize;
    }

    public int getSize() {
        return size;
    }

    public ArrayList<T> getConteudo() {
        return conteudo;
    }

    public int getMaxSize() {
        return maxSize;
    }

    public void porNaCaixa(T numero) {
        if (!cheia()) {
            conteudo.add(numero);
            size = conteudo.size();
        } else System.out.println("A caixa está cheia!");
    }

    public void tiraDaCaixa(T numero) {
        if(!vazia()){
            conteudo.remove(numero);
            size = conteudo.size();
        } else System.out.println("A caixa está vazia!");
    }

    public boolean cheia() {
        return size == maxSize;
    }

    public boolean vazia(){
        return size == 0;
    }
}
