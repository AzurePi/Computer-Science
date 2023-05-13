package trabalho2.usuarios;

import trabalho2.Emprestimo;
import trabalho2.items.Item;

import java.util.ArrayList;

public class AssesorTecnico extends Usuario {
    private String secao;

    public AssesorTecnico(String nome, int matricula, ArrayList<Emprestimo<? extends Item>> emprestados, String secao) {
        super(nome, matricula, emprestados);
        this.secao = secao;
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
