package trabalho2;

import java.time.LocalDate;

public class Emprestimo {
    private final Item emprestado;
    private final LocalDate dataEmprestimo, devolucaoPrevista;
    private LocalDate dataDevolucao = null;

    public Emprestimo(Item emprestado) {
        this.emprestado = emprestado;
        dataEmprestimo = LocalDate.now();
        devolucaoPrevista = dataEmprestimo.plusWeeks(1);
    }

    public void devolucao(){
        dataDevolucao = LocalDate.now();
    }
}
