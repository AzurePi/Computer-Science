package Trabalho1;

/**
 *
 * @author Azure
 */
public class Main {
    private final String arquivoBanco = "/files/banco.txt";
    private final String arquivoAgencias = "/files/agencias.txt";
    private final String arquivoContas = "/files/contas.txt";

    private final DisplayBanco display = new DisplayBanco(arquivoBanco, arquivoAgencias, arquivoContas);

    public void main(String[] args){
        display.telaUsuario();
        
        
        
        
    }
}
