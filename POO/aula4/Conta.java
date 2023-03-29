package aula4;

public class Conta {
  private String nome;
  private long cpf;
  private double saldo = 0;
  private int numero;
  private static final int AGENCIA = 1;
  
  public void setNome(String arg){
    nome = arg;
  }
  
  public void setCPF(long arg){
    cpf = arg;
  }
  
  public void setNumero(int arg){
    numero = arg;
  }
  
  /*não faz sentido métodos set para saldo (que é manipulado através de outros métodos)
  ou AGENCIA (que é constante para todos)
  */
  
  public String getNome(){
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

  public void depositar(double arg){
    saldo += arg;
    System.out.print("Saldo em conta: " + getSaldo());
  }

  public void sacar(double arg){
    saldo -= arg;
    System.out.print("Saldo em conta: " + getSaldo());
  }
}
