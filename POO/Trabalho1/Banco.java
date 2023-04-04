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
