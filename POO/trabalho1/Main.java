package trabalho1;

/**
 *
 * @author Azure
 */
public class Main {

    public static void main(String[] args){
        "C:\Users\ppcar\IdeaProjects\Computer-Science\POO\trabalho1\files\agencias.txt"
        final String arquivoBanco = "trabalho1/files/banco.txt";
        final String arquivoAgencias = "trabalho1/files/agencias.txt";
        final String arquivoContas = "trabalho1/files/contas.txt";

        final DisplayBanco display = new DisplayBanco(arquivoBanco, arquivoAgencias, arquivoContas);

        display.telaUsuario();
        

        
    }
}
