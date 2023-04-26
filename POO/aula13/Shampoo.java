package aula13;

public class Shampoo extends Produto {
    private int irritabilidade;

    //Methods ------------------------------------------------------------------------------
    @Override
    public double custoBeneficio() {
        return getPreco() / irritabilidade;
    }

    @Override
    public int compareTo(Object o) {
        Shampoo p = (Shampoo) o;
        return Double.compare(custoBeneficio(), p.custoBeneficio());
    }

}
