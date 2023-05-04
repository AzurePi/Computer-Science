package aula16;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        List<User> users = new ArrayList<>();

        int op;
        Scanner sc = new Scanner(System.in);

        System.out.println("1 - Cadastro de novo usuário");
        System.out.println("2 - Login");
        System.out.println("0 - Encerrar");
        do {
            op = sc.nextInt();
            System.out.println(); //pula uma linha
            switch (op) {
                case 1:
                    users.add(new User());
                    break;
                case 2:




                    String login;
                    int senha;

                    System.out.print("Login: ");
                    login = sc.nextLine();
                    System.out.print("Senha: ");
                    senha = sc.nextInt();






                    break;
                default:
                    break;
            }
        } while (op < 0);


    }
}
