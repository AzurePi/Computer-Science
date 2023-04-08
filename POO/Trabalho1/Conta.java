package Trabalho1;

/**
 *
 * @author Azure
 */
public class Conta {
    private int numero;
    private int agencia; //número da agência, e não objeto
    private double saldo;
    private String nome;
    private String endereco;
    private String cpf;
    private String dataNascimento;
    private String senha;

    //setters & getters--------------------------------------------------------
    public int getNumero() { return numero; }

    public void setNumero(int numero) { this.numero = numero; }

    public double getSaldo() { return saldo; }

    public int getAgencia() { return agencia; }

    public void setAgencia(int agencia) { this.agencia = agencia; }

    public void setSaldo(double saldo) { this.saldo = saldo; }

    public String getNome() { return nome; }

    public void setNome(String nome) { this.nome = nome; }

    public String getEndereco() { return endereco; }

    public void setEndereco(String endereco) { this.endereco = endereco; }

    public String getCpf() { return cpf; }

    public void setCpf(String cpf) { this.cpf = cpf; }

    public String getDataNascimento() { return dataNascimento; }

    public void setDataNascimento(String dataNascimento) { this.dataNascimento = dataNascimento; }

    public String getSenha() { return senha; }

    public void setSenha(String senha) { this.senha = senha; }


    //métodos------------------------------------------------------------------
    public void depositar(double valor){

    }

    public void sacar(double valor){

    }

    /**
     * Valida uma senha fornecida
     * @param senhaComparar Senha fornecida
     * @return true, se a senha corresponder à senha cadastrada, false caso contrário
     */
    public boolean validarSenha(String senhaComparar){
        return senhaComparar == senha;
    }

    /**
     * Troca a senha associada à conta, mediante fornecimento da senha atual
     * @param senhaAtual Senha em uso atualmente
     * @param senhaNova Nova senha
     */
    public void setSenha(String senhaAtual, String senhaNova){
        if(validarSenha(senhaAtual)){
            senha = senhaNova;
        }
    }
}
