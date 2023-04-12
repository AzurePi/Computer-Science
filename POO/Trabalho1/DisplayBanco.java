package Trabalho1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class DisplayBanco {
    private Banco meuBanco;

    public DisplayBanco(String banco, String agencias, String contas) {
        Scanner sc = null;
        String linha = null;
        String[] campos = null;

        //leitura de banco.txt ------------------------------------------------
        try {
            sc = new Scanner(new File(banco));
        } catch (FileNotFoundException ex) {
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
        } catch (FileNotFoundException ex) {
            Logger.getLogger(DisplayBanco.class.getName()).log(Level.SEVERE, null, ex);
        }

        while (sc.hasNextLine()) {
            linha = sc.nextLine();
            campos = linha.split("#"); //divide a linha em campos separados por "#"

            meuBanco.cadastrarAgencia(campos[0], Integer.parseInt(campos[1]), campos[2]);
        }
        sc.close();

        //leitura de contas.txt -----------------------------------------------
        try {
            sc = new Scanner(new File(contas));
        } catch (FileNotFoundException ex) {
            Logger.getLogger(DisplayBanco.class.getName()).log(Level.SEVERE, null, ex);
        }

        Conta contaAux;
        while (sc.hasNextLine()) {

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

    /**
     * Cria uma estrutura no console para fazer o login de uma conta
     */
    public void login() {
        Scanner sc = new Scanner(System.in);

        do {
            System.out.println("-------LOGIN-------");
            System.out.println("Agência: ");
            int a = sc.nextInt();
            System.out.println("Número da Conta: ");
            int n = sc.nextInt();
            System.out.println("Senha: ");
            sc.nextLine(); //para lidar com problemas de buffer
            String senha = sc.nextLine();
            meuBanco.logarCliente(a, n, senha);

            if (meuBanco.getContaLogada() == null)
                System.out.println("Falha. Tente Novamente\n");

        } while (meuBanco.getContaLogada() == null);
    }

    /**
     * Cria uma estrutura de controle para determinar a operação a ser realizada pelo usuário
     */
    private void telaUsuario() {
        int op; //variável para controlar a operação
        Scanner sc = new Scanner(System.in);

        do {
            System.out.println("-------- OPERAÇÕES --------");
            System.out.println("1 - Depósito");
            System.out.println("2 - Saque");
            System.out.println("3 - PIX");
            System.out.println("4 - Transferência");
            System.out.println("5 - Saldo");
            System.out.println("6 - Alterar senha");
            System.out.println("\n0 - Sair\n");

            op = sc.nextInt();

            switch (op) {
                case 1 -> operacaoDeposito();
                case 2 -> operacaoSaque();
                case 3 -> operacaoPix();
                case 4 -> operacaoTransferencia();
                case 5 -> operacaoSaldo();
                case 6 -> alterarSenha();
            }
        } while (op != 0);
        operacaoSair();
    }

    /**
     * Realiza um depósito para a conta logada. Prde, no console, o valor a ser depositado
     */
    private void operacaoDeposito() {
        Scanner sc = new Scanner(System.in);

        System.out.println("------ DEPÓSITO ------");
        System.out.println("Valor a depositar: ");
        meuBanco.realizarDeposito(Math.abs(sc.nextDouble()));
    }

    /**
     * Realiza um saque da conta logada. Pede, no console, pelo valor a ser sacado
     */
    private void operacaoSaque() {
        Scanner sc = new Scanner(System.in);
        boolean funcionou;

        System.out.println("------ SAQUE ------");
        System.out.println("Valor a sacar: ");
        funcionou = meuBanco.realizarSaque(Math.abs(sc.nextDouble()));

        if (!funcionou)
            System.out.println("ERRO: Valor excede o saldo em conta");
    }

    private void operacaoPix() {
        Scanner sc = new Scanner(System.in);


    }

    /**
     * Realiza uma transferência à partir da conta logada. Pede, no console, os dados da conta de destino e o valor a ser transferido
     */
    private void operacaoTransferencia() {
        Scanner sc = new Scanner(System.in);
        int agencia, conta;
        float valor;

        System.out.println("------ TRASFERÊNCIA ------");
        System.out.println("Agência à qual transferir: ");
        agencia = sc.nextInt();
        System.out.println("Conta à qual transferir: ");
        conta = sc.nextInt();
        System.out.println("Valor a transferir: ");
        valor = sc.nextFloat();

        boolean b = meuBanco.transferencia(agencia, conta, valor);
        if (!b)
            System.out.println("Falha na transferência. Verifique os dados e tente novamente.");
    }

    /**
     * Imprime na tela o saldo em conta da conta logada de meuBanco
     */
    private void operacaoSaldo() {
        System.out.println("Saldo em conta: " + meuBanco.getContaLogada().getSaldo());
    }

    private void alterarSenha(){
        Scanner sc = new Scanner(System.in);
        String nova, atual;
        boolean funcionou;

        System.out.println("------ ALTERAÇÃO DE SENHA ------");
        System.out.println("Senha nova: ");
        nova = sc.nextLine();
        System.out.println("Senha atual: ");
        atual = sc.nextLine();

        funcionou = meuBanco.getContaLogada().setSenha(atual, nova);
        if(!funcionou)
            System.out.println("Senha atual incorreta. Alteração cancelada");
    }

    /**
     * Desloga a conta logada do meuBanco
     */
    private void operacaoSair() {
        meuBanco.deslogarConta();
        System.out.println("Conta deslogada");
    }
}
