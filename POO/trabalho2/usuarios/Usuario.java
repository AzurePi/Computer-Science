package trabalho2.usuarios;

import trabalho2.Emprestimo;
import trabalho2.itens.Item;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * Classe abstrata de um usuário da biblioteca, identificado por um número de matrícula, que contém uma lista de
 * <code>Emprestimo</code> de <code>Item</code>.
 */
public abstract class Usuario {
    private String nome;
    private int matricula;
    private ArrayList<Emprestimo<? extends Item>> emprestados = new ArrayList<>();

    /**
     * Cria, a partir de input no console, um novo <code>Usuario</code>.
     */
    public Usuario() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Nome: ");
        nome = sc.nextLine();
        System.out.print("Matrícula: ");
        matricula = sc.nextInt();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getMatricula() {
        return matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    public ArrayList<Emprestimo<? extends Item>> getEmprestados() {
        return emprestados;
    }

    public void setEmprestados(ArrayList<Emprestimo<? extends Item>> emprestados) {
        this.emprestados = emprestados;
    }

    /**
     * Calcula a multa a ser paga por um atraso na devolução de um <code>Emprestimo</code>
     *
     * @param emp o <code>Emprestimo</code> para o qual a multa está sendo calculada
     * @return o valor da multa a ser paga
     */
    public abstract double multa(Emprestimo<? extends Item> emp);

    /**
     * Imprime no console as informações do <code>Usuario</code>
     */
    public void imprimir() {
        System.out.println("Nome: " + getNome() + " (" + this.getClass().getSimpleName() + ")");
        System.out.println("Matrícula: " + getMatricula());
    }
}
