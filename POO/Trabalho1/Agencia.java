package Trabalho1;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Azure
 */
public class Agencia {
    private int codigo;
    private String nome;
    private String endereco;
    private final List<Conta> contas = new ArrayList<>();

    public Agencia(String nome, int codigo, String endereco) {
        this.nome = nome;
        this.codigo = codigo;
        this.endereco = endereco;
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

    /**
     * Adiciona um objeto Conta à lista de contas da Agencia
     *
     * @param conta Objeto Conta com que será adicionado à agência
     */
    public void cadastrarConta(Conta conta) {
        contas.add(conta);
    }

    /**
     * Busca uma conta dentre as listadas na agência com base em seu número. Só fornece acesso se a senha fornecida
     * equivales à senha cadastrada na conta.
     *
     * @param numConta número (int) da conta sendo buscada
     * @param senha    String com a senha da conta sendo buscada
     * @return Objeto Conta, se o número e senha informados estiverem corretos, ou null caso contrário
     */
    public Conta buscarConta(int numConta, String senha) {

        for (Conta conta : contas) {
            if (conta.getNumero() == numConta && conta.validarSenha(senha))
                return conta;
        }

        return null;
    }

    /**
     * Busca uma conta dentre as listadas na agência com base em seu número.
     * @param numConta número (int) da conta sendo buscada
     * @return Objeto Conta, se o número e senha informados estiverem corretos, ou null caso contrário
     */
    public Conta buscarConta(int numConta) {

        for (Conta conta : contas) {
            if (conta.getNumero() == numConta)
                return conta;
        }

        return null;
    }
}
