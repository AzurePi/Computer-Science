package aula13;

public abstract class Produto implements Comparable {
    private String nome;
    private double preco;

    //Setters & Getters --------------------------------------------------------------------
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }


    //Methods ------------------------------------------------------------------------------

    @Override
    public int compareTo(Object o) {
        return 0;
    }

    public abstract double custoBeneficio();

}
