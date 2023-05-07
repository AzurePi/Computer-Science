package trabalho2;

import java.util.ArrayList;

public abstract class Usuario {
    private String nome;
    private int matricula;
    private ArrayList<Emprestimo> emprestados = new ArrayList<>();

    public abstract float multa();
}
