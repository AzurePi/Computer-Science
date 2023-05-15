package trabalho2.usuarios;

import trabalho2.Emprestimo;

import java.util.Scanner;

public class AssessorTecnico extends Usuario {
    private String secao;

    public AssessorTecnico() {
        super();
        Scanner sc = new Scanner(System.in);
        System.out.println("Seção: ");
        secao = sc.nextLine();
    }

    public String getSecao() {
        return secao;
    }

    public void setSecao(String secao) {
        this.secao = secao;
    }

    @Override
    public double multa(Emprestimo emp) {
        //se a devolução foi feita com atraso
        if (emp.getDataDevolucao().isAfter(emp.getDevolucaoPrevista())) {
            float atrasoDias = emp.getDataDevolucao().compareTo(emp.getDevolucaoPrevista());
            return (atrasoDias * 5) * 1.15; //15% a mais que um aluno
        }
        return 0;
    }
}
