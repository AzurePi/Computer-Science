package aula04;

public class Main {
    public static void main(String[] args){
        int n = 0; //número de contas
        
        Conta julia = new Conta();
        julia.setNome("Júlia");
        julia.setCPF(74710674620L);
        julia.setNumero(++n);
        julia.depositar(1397000);
        julia.sacar(10);
    }
}
