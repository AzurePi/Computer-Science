package Trabalho1;

import java.util.List;

/**
 *
 * @author Azure
 */
public class Agencia {
    private int codigo;
    private String nome;
    private String endereco;
    private final List<Conta> contas = null;

    public Agencia(int cod, String nom, String end){
        this.codigo = cod;
        this.nome = nom;
        this.endereco = end;
    }


    //métodos------------------------------------------------------------------
    public void cadastrarConta(Conta conta){

    }

    public Conta buscarConta(int numConta, String senha){

        return null;
    }
}
