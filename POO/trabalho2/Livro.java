package trabalho2;

public class Livro extends Item{
    private String editora, ISBN;

    @Override
    public Item emprestimo(Item emprestado) {
        return emprestado;
    }

    @Override
    public void devolucao(Item emprestado) {

    }
}
