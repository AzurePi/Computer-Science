package aula16;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        List<User> users = new ArrayList<>();
        User logado = null;

        try {
            FileInputStream fileInput = new FileInputStream("users.dat");
            FileOutputStream fileOutput = new FileOutputStream("users.dat");
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }

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
                    cadastro(users);
                    //imprimirArquivoObj(users);
                    imprimirArquivoTxt(users);
                    break;
                case 2:
                    String login;
                    int senha;

                    System.out.print("Login: ");
                    login = sc.nextLine();
                    System.out.print("Senha: ");
                    senha = sc.nextInt();

                    System.out.println();//pula uma linha
                    System.out.println("1 - Procurar em arquivo de texto");
                    System.out.println("2 - Procurar em arquivo de objetos");
                    int op2 = sc.nextInt();

                    switch (op2) {
                        case 1:
                            //logado = loginObj(login, senha);
                            break;
                        case 2:
                            //logado = loginTxt(login, senha);
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        } while (op < 0);
    }

    public static void lerArquivoObj(List<User> users, FileInputStream file) {
        ObjectInputStream in = null;

        try {
            in = new ObjectInputStream(file);

            users.add((User) in.readObject());

        } catch (IOException | ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public static void imprimirArquivoObj(List<User> users, FileOutputStream file) {
        ObjectOutputStream out = null;

        try {
            out = new ObjectOutputStream(file);

            for (User user : users)
                out.writeObject(user);

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void imprimirArquivoTxt(List<User> users) {
        OutputStreamWriter out = null;

        try {
            out = new OutputStreamWriter(new FileOutputStream("users.txt"));

            for (User user : users)
                out.write(user.nome + "|" + user.login + "|" + user.cryptoSenha());

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void cadastro(List<User> users) {
        users.add(new User());
    }

    public static User login(List<User> users, String login, int senha) {
        for (User user : users) {
            if (user.login.equals(login) && user.senha == senha)
                return user;
        }
        return null;
    }
}
