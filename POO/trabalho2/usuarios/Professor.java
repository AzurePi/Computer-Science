package trabalho2.usuarios;

import trabalho2.Emprestimo;
import trabalho2.itens.Item;

import java.util.Scanner;

/**
 * Extensão de <code>Usuario</code>.
 */
public class Professor extends Usuario {
    private String departamento, titulacao;

    /**
     * Cria, a partir de input no console, um novo <code>Professor</code>.
     */
    public Professor() {
        super();
        Scanner sc = new Scanner(System.in);
        System.out.print("Departamento: ");
        departamento = sc.nextLine();
        System.out.println("Titulação: ");
        titulacao = sc.nextLine();
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

    /**
     * Calcula a multa a ser paga por um atraso na devolução de um <code>Emprestimo</code>.
     * Considera a taxa de um professor, 5 reais por dia + 25%.
     *
     * @param emp o <code>Emprestimo</code> para o qual a multa está sendo calculada
     * @return o valor da multa a ser paga
     */
    @Override
    public double multa(Emprestimo<? extends Item> emp) {
        //se a devolução foi feita com atraso
        if (emp.getDataDevolucao().isAfter(emp.getDevolucaoPrevista())) {
            float atrasoDias = emp.getDataDevolucao().compareTo(emp.getDevolucaoPrevista());
            return (atrasoDias * 5) * 1.25; //25% a mais que um aluno
        }
        return 0;
    }

    /**
     * Imprime no console as informações do <code>Professor</code>
     */
    @Override
    public void imprimir() {
        super.imprimir();
        System.out.println("Departamento: " + getDepartamento());
        System.out.println("Titulação: " + getTitulacao());
    }
}
