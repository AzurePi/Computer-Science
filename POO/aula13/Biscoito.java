package aula13;

public class Biscoito extends Produto {
    private int cancerigenos;

    //Methods ------------------------------------------------------------------------------
    @Override
    public double custoBeneficio() {
        return getPreco() / cancerigenos;
    }

    @Override
    public int compareTo(Object o) {
        Biscoito p = (Biscoito) o;
        return Double.compare(this.custoBeneficio(), p.custoBeneficio());
    }

}
