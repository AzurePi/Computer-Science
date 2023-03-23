package aula4;

public class Conta {
    private String[] nome;
    private long cpf;
    private double saldo;
    private int numero;
    private static final int AGENCIA = 1;
    
    public void setNome(String[] arg){
        nome = arg;
    }
    
    public void setCPF(long arg){
        cpf = arg;
    }
    
    public String[] getNome(){
        return nome;
    }
    
    public long getCPF(){
        return cpf;
    }
    
    public double getSaldo(){
        return saldo;
    }
    
    public int getNumero(){
        return numero;
    }
    
    public int getAgencia(){
        return AGENCIA;
    }
    
    //função depósito
    
    //função saque
    
    
}
