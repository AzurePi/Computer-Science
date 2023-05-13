package trabalho2.usuarios;

import trabalho2.Emprestimo;
import trabalho2.items.Item;

import java.util.ArrayList;

public abstract class Usuario {
    private String nome;
    private int matricula;
    private ArrayList<Emprestimo<? extends Item>> emprestados = new ArrayList<>();

    public Usuario(String nome, int matricula, ArrayList<Emprestimo<? extends Item>> emprestados) {
        this.nome = nome;
        this.matricula = matricula;
        this.emprestados = emprestados;
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

    public abstract double multa(Emprestimo<? extends Item> emp);
}
