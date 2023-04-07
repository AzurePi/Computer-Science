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


    //setters & getters--------------------------------------------------------
    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public List<Conta> getContas() {
        return contas;
    }


    //métodos------------------------------------------------------------------
    public void cadastrarConta(Conta conta){

    }

    public Conta buscarConta(int numConta, String senha){

        return null;
    }
}
