package trabalho2;

import trabalho2.exceptions.UnavailableItemException;
import trabalho2.items.Item;
import trabalho2.usuarios.Usuario;

import java.time.LocalDate;

public class Emprestimo<T extends Item> {
    private final T emprestado;
    private final LocalDate dataEmprestimo, devolucaoPrevista;
    private LocalDate dataDevolucao = null;

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

    public void setDataDevolucao(LocalDate dataDevolucao) {
        this.dataDevolucao = dataDevolucao;
    }

    public double calcularMulta(Usuario user) {
        return user.multa(this);
    }
}
