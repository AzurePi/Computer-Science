package trabalho2.usuarios;

import trabalho2.Emprestimo;
import trabalho2.items.Item;

import java.util.ArrayList;

public class Aluno extends Usuario {
    private String curso, periodo;

    public Aluno(String nome, int matricula, ArrayList<Emprestimo<? extends Item>> emprestados, String curso, String periodo) {
        super(nome, matricula, emprestados);
        this.curso = curso;
        this.periodo = periodo;
    }

    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    public String getPeriodo() {
        return periodo;
    }

    public void setPeriodo(String periodo) {
        this.periodo = periodo;
    }

    @Override
    public double multa(Emprestimo<? extends Item> emp) {
        //se a devolução foi feita com atraso
        if (emp.getDataDevolucao().isAfter(emp.getDevolucaoPrevista())) {
            float atrasoDias = emp.getDataDevolucao().compareTo(emp.getDevolucaoPrevista());
            return atrasoDias * 5;
        }
        return 0;
    }
}
