package Trabalho1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class DisplayBanco {
    private Banco meuBanco;

    public DisplayBanco(String banco, String agencias, String contas){
        Scanner sc = null;
        String linha = null;
        String[] campos = null;

        //leitura de banco.txt ------------------------------------------------
        try {
            sc = new Scanner(new File(banco));
        } catch(FileNotFoundException ex) {
            Logger.getLogger(DisplayBanco.class.getName()).log(Level.SEVERE, null, ex);
        }

        linha = sc.nextLine();
        campos = linha.split("#"); //divide a linha em campos separados por "#"

        meuBanco = new Banco(Integer.parseInt(campos[1]),
                campos[0],
                campos[2],
                campos[3]);

        sc.close();

        //leitura de agencias.txt ---------------------------------------------
        try {
            sc = new Scanner(new File(agencias));
        } catch(FileNotFoundException ex) {
            Logger.getLogger(DisplayBanco.class.getName()).log(Level.SEVERE, null, ex);
        }

        while(sc.hasNextLine()) {
            linha = sc.nextLine();
            campos = linha.split("#"); //divide a linha em campos separados por "#"

            meuBanco.cadastrarAgencia(campos[0], Integer.parseInt(campos[1]), campos[2]);
        }
        sc.close();

        //leitura de contas.txt -----------------------------------------------
        try {
            sc = new Scanner(new File(contas));
        } catch(FileNotFoundException ex) {
            Logger.getLogger(DisplayBanco.class.getName()).log(Level.SEVERE, null, ex);
        }

        Conta contaAux;
        while(sc.hasNextLine()) {
            contaAux = new Conta();

            linha = sc.nextLine();
            campos = linha.split("#"); //divide a linha em campos separados por "#"

            meuBanco.cadastrarConta(Integer.parseInt(campos[5]),
                    Integer.parseInt(campos[6]),
                    campos[0],
                    Double.parseDouble(campos[4]),
                    campos[2],
                    campos[3],
                    campos[1],
                    campos[7]);
        }
        sc.close();

    }

    //métodos------------------------------------------------------------------
    public void login(){
        Scanner sc = new Scanner(System.in);

        System.out.println("-------LOGIN-------");
        System.out.println("Agência: ");
        int a = sc.nextInt();
        System.out.println("Número da Conta: ");
        int n = sc.nextInt();
        System.out.println("Senha: ");
        String senha = sc.nextLine();

        meuBanco.logarCliente(a, n, senha);
        if(meuBanco.getContaLogada() == null) {
            System.out.println("Falha. Tente Novamente\n");
            login();
        }
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
