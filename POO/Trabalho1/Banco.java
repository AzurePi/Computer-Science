package Trabalho1;

import java.util.List;

/**
 *
 * @author Azure
 */
public class Banco {
    private int numero;
    private String nome;
    private String cnpj;
    private String endereco;
    private Conta contaLogada = new Conta();
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
    public void logarCliente(int numAgencia, int numConta, String senha){
        Agencia auxAgencia = buscarAgencia(numAgencia);

        if(auxAgencia != null)
            contaLogada = auxAgencia.buscarConta(numConta, senha);
    }

    public double realizarSaque(double valor){
        return 0;
    }

    public void realizarDeposito(double valor){

    }

    public double saldo(){
        return contaLogada.getSaldo();
    }

    /**
     * Cadastra uma agência no banco a partir de informações da agência
     * * @param nome Nome da nova agência
     * @param codigo Código da nova agência
     * @param endereco endereço da nova agência
     */
    public void cadastrarAgencia(String nome, int codigo, String endereco){
        agencias.add(new Agencia(nome, codigo, endereco));
    }

    /**
     * Cadastra uma agência no banco a partir de uma agência pré-existente
     * @param agencia Objeto Agencia sendo cadastrado
     */
    public void cadastrarAgencia(Agencia agencia){
        agencias.add(agencia);
    }

    /**
     * Cadastra uma nova conta no banco
     * @param numAgencia Número da agência
     * @param numero Número da conta
     * @param nome Nome do dono da conta
     * @param saldo Saldo na conta
     * @param endereco Endereço do dono da conta
     * @param cpf CPF do dono da conta
     * @param dataNascimento Data de nascimento do dono da conta
     * @param senha Senha da conta
     */
    public void cadastrarConta(int numAgencia, int numero, String nome, double saldo, String endereco, String cpf, String dataNascimento, String senha){
        Agencia auxAgencia = buscarAgencia(numAgencia);

        Conta auxConta = new Conta();
        auxConta.setNumero(numero);
        auxConta.setNome(nome);
        auxConta.setSaldo(saldo);
        auxConta.setEndereco(endereco);
        auxConta.setCpf(cpf);
        auxConta.setDataNascimento(dataNascimento);
        auxConta.setSenha(senha);

        auxAgencia.cadastrarConta(auxConta);
    }

    /**
     * Busca, dentre as agências do banco, aquela que possui o código informado
     * @param codigo Numero da agência sendo procurada
     * @return Um objeto Agencia com o código informado, ou null caso não exista
     */
    public Agencia buscarAgencia(int codigo){

        for(Agencia agencia : agencias){
            if(agencia.getCodigo() == codigo)
                return agencia;
        }
        return null;
    }

    public void tranferencia(int numAgencia, int numConta){

    }
    
    public void pix(String chaveCPF){

    }

    public void deslogarConta(){

    }
}
