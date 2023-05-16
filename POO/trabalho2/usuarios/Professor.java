package trabalho2.usuarios;

import trabalho2.Emprestimo;
import trabalho2.items.Item;

import java.util.Scanner;

public class Professor extends Usuario {
    private String departamento, titulacao;

    public Professor() {
        super();
        Scanner sc = new Scanner(System.in);
        System.out.print("Departamento: ");
        departamento = sc.nextLine();
        System.out.println("Titulação: ");
        titulacao = sc.nextLine();
        sc.close();
    }

    public String getDepartamento() {
        return departamento;
    }

    public void setDepartamento(String departamento) {
        this.departamento = departamento;
    }

    public String getTitulacao() {
        return titulacao;
    }

    public void setTitulacao(String titulacao) {
        this.titulacao = titulacao;
    }

    @Override
    public double multa(Emprestimo<? extends Item> emp) {
        //se a devolução foi feita com atraso
        if (emp.getDataDevolucao().isAfter(emp.getDevolucaoPrevista())) {
            float atrasoDias = emp.getDataDevolucao().compareTo(emp.getDevolucaoPrevista());
            return (atrasoDias * 5) * 1.25; //25% a mais que um aluno
        }
        return 0;
    }
}
