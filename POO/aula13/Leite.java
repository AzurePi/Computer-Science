package aula13;

public class Leite extends Produto {
    private int valeDias;

    //Methods ------------------------------------------------------------------------------
    @Override
    public double custoBeneficio() {
        return getPreco() / valeDias;
    }


    @Override
    public int compareTo(Object o) {
        Leite p = (Leite) o;
        return Double.compare(this.custoBeneficio(), p.custoBeneficio());
    }

}
