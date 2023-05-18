package trabalho2;

import trabalho2.exceptions.UnavailableItemException;
import trabalho2.exceptions.UncheckedItemException;
import trabalho2.itens.Item;
import trabalho2.usuarios.Usuario;

import java.time.LocalDate;

/**
 * Classe Emprestimo utilizada para armazenar as informações (item emprestado, datas de emprésticmo, devolução prevista, devolução) de um empréstimo de um usuário
 *
 * @param <T> Uma subclasse de Item
 */
public class Emprestimo<T extends Item> {
    private final T emprestado;
    private final LocalDate dataEmprestimo, devolucaoPrevista;
    private LocalDate dataDevolucao = null;

    /**
     * @param emprestado item sendo emprestado (de uma subclasse de <code>Item</code>)
     * @throws UnavailableItemException caso o item não esteja disponível para empréstimo
     */
    public Emprestimo(T emprestado) throws UnavailableItemException {
        emprestado.emprestimo(); //pode resultar em UnavailableItemException
        this.emprestado = emprestado;
        dataEmprestimo = LocalDate.now();
        devolucaoPrevista = dataEmprestimo.plusWeeks(1);
    }

    public T getEmprestado() {
        return emprestado;
    }

    public LocalDate getDataEmprestimo() {
        return dataEmprestimo;
    }

    public LocalDate getDevolucaoPrevista() {
        return devolucaoPrevista;
    }

    public LocalDate getDataDevolucao() {
        return dataDevolucao;
    }

    /**
     * @param user usuário dono do <code>Emprestimo</code>
     * @throws UncheckedItemException caso o item não tenha sido emprestado
     */
    public void devolver(Usuario user) throws UncheckedItemException {
        emprestado.devolucao(); //pode resultar em UncheckedItemException
        dataDevolucao = LocalDate.now();
        user.getEmprestados().remove(emprestado);
    }

    /**
     * Calcula, com base na taxa correspondente à subclasse de <code>Usuario</code>, a multa a ser paga
     *
     * @param user usuário dono do <code>Emprestimo</code>
     * @return o valor da multa a ser paga
     */
    public double calcularMulta(Usuario user) {
        return user.multa(this);
    }
}
