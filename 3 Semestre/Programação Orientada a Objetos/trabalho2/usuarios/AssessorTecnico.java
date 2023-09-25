package trabalho2.usuarios;

import trabalho2.Emprestimo;
import trabalho2.itens.Item;

import java.util.Scanner;

/**
 * Extensão de <code>Usuario</code>.
 */
public class AssessorTecnico extends Usuario {
    private String secao;

    /**
     * Cria, a partir de input no console, um novo <code>AssessorTecnico</code>.
     */
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

    /**
     * Calcula a multa a ser paga por um atraso na devolução de um <code>Emprestimo</code>.
     * Considera a taxa de um assessor técnico, 5 reais por dia + 15%.
     *
     * @param emp o <code>Emprestimo</code> para o qual a multa está sendo calculada
     * @return o valor da multa a ser paga
     */
    public double multa(Emprestimo<? extends Item> emp) {
        //se a devolução foi feita com atraso
        if (emp.getDataDevolucao().isAfter(emp.getDevolucaoPrevista())) {
            float atrasoDias = emp.getDataDevolucao().compareTo(emp.getDevolucaoPrevista());
            return (atrasoDias * 5) * 1.15; //15% a mais que um aluno
        }
        return 0;
    }

    /**
     * Imprime no console as informações do <code>AssessorTecnico</code>
     */
    @Override
    public void imprimir(){
        super.imprimir();
        System.out.println("Seção: " + getSecao());
    }
}
