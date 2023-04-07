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

    }

    public double realizarSaque(double valor){
        return 0;
    }

    public void realizarDeposito(double valor){

    }

    public double saldo(){
        return 0;
    }

    public void cadastrarAgencia(int codigo, String nome, String endereco){

    }

    public void cadastrarAgencia(Agencia agencia){

    }

    public void cadastrarConta(int numAgencia, int numero, String nome){

    }

    public Agencia buscarAgencia(int codigo){
        return null;
    }

    public void tranferencia(int numAgencia, int numConta){

    }
    
    public void pix(String chaveCPF){

    }

    public void deslogarConta(){

    }
}
