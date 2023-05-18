package trabalho2.usuarios;

import trabalho2.Emprestimo;
import trabalho2.itens.Item;

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

    public double multa(Emprestimo<? extends Item> emp) {
        //se a devolução foi feita com atraso
        if (emp.getDataDevolucao().isAfter(emp.getDevolucaoPrevista())) {
            float atrasoDias = emp.getDataDevolucao().compareTo(emp.getDevolucaoPrevista());
            return (atrasoDias * 5) * 1.15; //15% a mais que um aluno
        }
        return 0;
    }

    @Override
    public void imprimir(){
        super.imprimir();
        System.out.println("Seção: " + getSecao());
    }
}
