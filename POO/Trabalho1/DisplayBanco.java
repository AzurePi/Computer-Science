package Trabalho1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class DisplayBanco {
    private Banco meuBanco;

    public DisplayBanco(String banco, String agencias, String contas){
        Scanner sc = null;
        String linha = null;
        String[] campos = null;

        //leitura de banco.txt -------------------------------------------
        try {
            sc = new Scanner(new File(banco));
        } catch(FileNotFoundException ex) {
            Logger.getLogger(DisplayBanco.class.getName()).log(Level.SEVERE, null, ex);
        }

        linha = sc.nextLine();

        //divide a linha em campos separados por "#"
        campos = linha.split("#");

        meuBanco.setNome(campos[0]);
        meuBanco.setNumero(Integer.parseInt(campos[1]));
        meuBanco.setCnpj(campos[2]);
        meuBanco.setEndereco(campos[3]);
        sc.close();

        //leitura de agencias.txt e contas.txt ---------------------------
        try {
            sc = new Scanner(new File(agencias));
        } catch(FileNotFoundException ex) {
            Logger.getLogger(DisplayBanco.class.getName()).log(Level.SEVERE, null, ex);
        }

        Agencia agenciaAux = null;
        int i = 0;
        while(sc.hasNextLine()) {
            agenciaAux = meuBanco.getAgencias().get(i);

            linha = sc.nextLine();

            //divide a linha em campos separados por "#"
            campos = linha.split("#");

            agenciaAux.setNome(campos[0]);
            agenciaAux.setCodigo(Integer.parseInt(campos[1]));
            agenciaAux.setEndereco(campos[2]);

            i++;
        }
        sc.close();

        //leitura de contas.txt ------------------------------------------
        try {
            sc = new Scanner(new File(contas));
        } catch(FileNotFoundException ex) {
            Logger.getLogger(DisplayBanco.class.getName()).log(Level.SEVERE, null, ex);
        }

        Conta contaAux = null;
        i = 0;
        while(sc.hasNextLine()) {
            contaAux = new Conta();

            linha = sc.nextLine();

            //divide a linha em campos separados por "#"
            campos = linha.split("#");

            i++;
        }
        sc.close();

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
