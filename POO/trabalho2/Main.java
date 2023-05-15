package trabalho2;

import java.util.Scanner;

public class Main {
    private static final Biblioteca bib = new Biblioteca();

    public static void main(String[] args) {
        menu();
    }


    public static void menu() {
        Scanner sc = new Scanner(System.in);
        short op;

        do {
            System.out.println("1 - Consultar item\t\t6 - Listar itens");
            System.out.println("2 - Cadastrar item\t\t7 - Listar usuários");
            System.out.println("3 - Emprestar item");
            System.out.println("4 - Devolver item");
            System.out.println("5 - Cadastrar usuário\t\t0 - Encerrar");

            op = sc.nextShort();
            System.out.println(); //pula uma linha
            switch (op) {
                case 1:
                    bib.consultaItem();
                    break;
                case 2:
                    bib.cadastroItem();
                    break;
                case 3:
                    bib.emprestarItem();
                    break;
                case 4:
                    bib.devolverItem();
                    break;
                case 5:
                    bib.cadastroUsuario();
                    break;
                case 6:
                    System.out.println("Itens ----------------------------------");
                    bib.listarItems();
                    break;
                case 7:
                    System.out.println("Usuários -------------------------------");
                    bib.listarUsuarios();
                    break;
                case 0:
                    break;
            }
        } while (op != 0);
    }
}
