package Trabalho1;

import java.util.List;
import java.util.Objects;

/**
 * @author Azure
 */
public class Banco {
    private int numero;
    private String nome;
    private String cnpj;
    private String endereco;
    private Conta contaLogada;
    private List<Agencia> agencias = null;

    public Banco(int numero, String nome, String cnpj, String endereco) {
        this.numero = numero;
        this.nome = nome;
        this.cnpj = cnpj;
        this.endereco = endereco;
    }

    //setters & getters--------------------------------------------------------
    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCnpj() {
        return cnpj;
    }

    public void setCnpj(String cnpj) {
        this.cnpj = cnpj;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public Conta getContaLogada() {
        return contaLogada;
    }

    public void setContaLogada(Conta contaLogada) {
        this.contaLogada = contaLogada;
    }

    public List<Agencia> getAgencias() {
        return agencias;
    }

    public void setAgencias(List<Agencia> agencias) {
        this.agencias = agencias;
    }


    //métodos------------------------------------------------------------------
    public void logarCliente(int numAgencia, int numConta, String senha) {
        Agencia auxAgencia = buscarAgencia(numAgencia);

        if (auxAgencia != null) {
            contaLogada = auxAgencia.buscarConta(numConta, senha);
            if (contaLogada == null)
                System.out.println("Conta não encontrada ou senha incorreta");
        } else
            System.out.println("Agência não encontrada");
    }

    /**
     * Realiza um saque para a conta logada
     *
     * @param valor Valor a ser sacado
     * @return true, se o saque for possível, falso caso contrário
     */
    public boolean realizarSaque(double valor) {
        if (valor > contaLogada.getSaldo())
            return false;

        contaLogada.sacar(valor);
        contaLogada.novaOperacao("Saque", -valor);
        return true;
    }

    /**
     * Realiza um depósito na conta logada
     *
     * @param valor Valor a ser depositado
     */
    public void realizarDeposito(double valor) {
        contaLogada.depositar(valor);
        contaLogada.novaOperacao("Depósito", valor);
    }

    /**
     * @return valor do saldo da conta logada
     */
    public double saldo() {
        return contaLogada.getSaldo();
    }

    public List<String> extrato(){
        return contaLogada.getExtrato();
    }

    /**
     * Cadastra uma agência no banco a partir de informações da agência
     * * @param nome Nome da nova agência
     *
     * @param codigo   Código da nova agência
     * @param endereco endereço da nova agência
     */
    public void cadastrarAgencia(String nome, int codigo, String endereco) {
        agencias.add(new Agencia(nome, codigo, endereco));
    }

    /**
     * Cadastra uma agência no banco a partir de uma agência pré-existente
     *
     * @param agencia Objeto Agencia sendo cadastrado
     */
    public void cadastrarAgencia(Agencia agencia) {
        agencias.add(agencia);
    }

    /**
     * Cadastra uma nova conta no banco
     *
     * @param numAgencia     Número da agência
     * @param numero         Número da conta
     * @param nome           Nome do dono da conta
     * @param saldo          Saldo na conta
     * @param endereco       Endereço do dono da conta
     * @param cpf            CPF do dono da conta
     * @param dataNascimento Data de nascimento do dono da conta
     * @param senha          Senha da conta
     */
    public void cadastrarConta(int numAgencia,
                               int numero,
                               String nome,
                               double saldo,
                               String endereco,
                               String cpf,
                               String dataNascimento,
                               String senha) {
        Agencia auxAgencia = buscarAgencia(numAgencia);
        Conta auxConta = new Conta(numero, auxAgencia.getCodigo(), saldo, nome, endereco, cpf, dataNascimento, senha);
        auxAgencia.cadastrarConta(auxConta);
    }

    /**
     * Busca, dentre as agências do banco, aquela que possui o código informado
     *
     * @param codigo Numero da agência sendo procurada
     * @return Um objeto Agencia com o código informado, ou null caso não exista
     */
    public Agencia buscarAgencia(int codigo) {

        for (Agencia agencia : agencias) {
            if (agencia.getCodigo() == codigo)
                return agencia;
        }
        return null;
    }

    public boolean transferencia(int numAgencia, int numConta, float valor) {
        Agencia auxAgencia = buscarAgencia(numAgencia);
        if(auxAgencia == null)
            return false;

        Conta auxConta = auxAgencia.buscarConta(numConta);
        if(auxConta == null)
            return false;

        if(valor > contaLogada.getSaldo())
            return false;

        contaLogada.sacar(valor);
        auxConta.depositar(valor);
        contaLogada.novaOperacao("Transferência", -valor, auxConta.getNome());
        auxConta.novaOperacao("Trasferência", valor, contaLogada.getNome());
        return true;
    }

    public boolean pix(String chaveCPF, float valor) {
        Conta auxConta = null;

        primeiroFor: for(Agencia agencia : agencias){
            for(Conta conta : agencia.getContas()) {
                if (Objects.equals(chaveCPF, conta.getCpf())) {
                    auxConta = conta;
                    break primeiroFor;
                }
            }
        }

        if (auxConta == null)
            return false;

        if(valor > contaLogada.getSaldo())
            return false;

        contaLogada.sacar(valor);
        auxConta.depositar(valor);
        contaLogada.novaOperacao("PIX", -valor, auxConta.getNome());
        auxConta.novaOperacao("PIX", valor, contaLogada.getNome());
        return true;
    }

    /**
     * Faz com que a conta logada seja nula
     */
    public void deslogarConta() {
        contaLogada = null;
    }
}
