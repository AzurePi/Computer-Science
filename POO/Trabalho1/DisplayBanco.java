package Trabalho1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class DisplayBanco {
    private Banco meuBanco = new Banco();

    public DisplayBanco(String banco, String agencias, String contas){
        List<File> arquivos = null;
        arquivos.add(new File(banco));
        arquivos.add(new File(agencias));
        arquivos.add(new File(contas));

        Scanner scanner = null;

        //para cada arquivo
        for(File arquivo : arquivos){
            try {
                scanner = new Scanner(arquivo);
            } catch(FileNotFoundException ex) {
                Logger.getLogger(DisplayBanco.class.getName()).log(Level.SEVERE, null, ex);
            }

            //lê cada linha do arquivo
            while(scanner.hasNextLine()){
                String linha = scanner.nextLine();

                //divide a linha em campos separados por "|"
                String[] campos = linha.split("#");

                //imprime o conteúdo de cada campo, usando "|" como separador
                for (String campo: campos) {
                    System.out.println(campo + " | ");
                }
                System.out.println(); //pula uma linha
            }
        }

        Banco aux = new Banco();

    }

    //métodos------------------------------------------------------------------
    public void login(){

    }

    private void telaUsuario(){

    }

    private void operacaoDeposito(){

    }

    private void operacaoSaque(){

    }

    private void operacaoPix(){

    }

    private void operacaoTransferencia(){

    }

    private void operacaoSaldo(){

    }

    private void operacaoSair(){

    }
}
