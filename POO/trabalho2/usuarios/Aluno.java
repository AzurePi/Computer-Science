package trabalho2.usuarios;

import trabalho2.Emprestimo;
import trabalho2.itens.Item;

import java.util.Scanner;

public class Aluno extends Usuario {
    private String curso, periodo;

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

    @Override
    public double multa(Emprestimo<? extends Item> emp) {
        //se a devolução foi feita com atraso
        if (emp.getDataDevolucao().isAfter(emp.getDevolucaoPrevista())) {
            float atrasoDias = emp.getDataDevolucao().compareTo(emp.getDevolucaoPrevista());
            return atrasoDias * 5;
        }
        return 0;
    }

    @Override
    public void imprimir(){
        super.imprimir();
        System.out.println("Curso: " + getCurso());
        System.out.println("Período: " + getPeriodo());
    }

}
