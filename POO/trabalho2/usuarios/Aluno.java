package trabalho2.usuarios;

import trabalho2.Emprestimo;
import trabalho2.itens.Item;

import java.util.Scanner;

/**
 * Extensão de <code>Usuario</code>.
 */
public class Aluno extends Usuario {
    private String curso, periodo;

    /**
     * Cria, a partir de input no console, um novo <code>Aluno</code>.
     */
    public Aluno() {
        super();
        Scanner sc = new Scanner(System.in);
        System.out.print("Curso: ");
        curso = sc.nextLine();
        System.out.print("Período: ");
        periodo = sc.nextLine();
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

    /**
     * Calcula a multa a ser paga por um atraso na devolução de um <code>Emprestimo</code>.
     * Considera a taxa de um aluno, 5 reais por dia.
     *
     * @param emp o <code>Emprestimo</code> para o qual a multa está sendo calculada
     * @return o valor da multa a ser paga
     */
    @Override
    public double multa(Emprestimo<? extends Item> emp) {
        //se a devolução foi feita com atraso
        if (emp.getDataDevolucao().isAfter(emp.getDevolucaoPrevista())) {
            float atrasoDias = emp.getDataDevolucao().compareTo(emp.getDevolucaoPrevista());
            return atrasoDias * 5;
        }
        return 0;
    }

    /**
     * Imprime no console as informações do <code>Aluno</code>
     */
    @Override
    public void imprimir() {
        super.imprimir();
        System.out.println("Curso: " + getCurso());
        System.out.println("Período: " + getPeriodo());
    }

}
