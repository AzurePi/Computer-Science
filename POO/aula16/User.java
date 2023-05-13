package aula16;

import java.io.Serializable;
import java.util.Scanner;

public class User implements Serializable {
    String nome, login;
    int senha;

    public User(){
        Scanner sc = new Scanner(System.in);

        System.out.print("Nome: ");
        this.nome = sc.nextLine();
        System.out.print("Login: ");
        this.login = sc.nextLine();
        System.out.print("Senha: ");
        this.senha = sc.nextInt();
    }

    public User(String nome, String login, int senha){
        this.nome = nome;
        this.login = login;
        this.senha = senha;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getLogin() {
        return login;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public int getSenha() {
        return senha;
    }

    public void setSenha(int senha) {
        this.senha = senha;
    }

    public int cryptoSenha(){
        int crypto = senha;
        for(char c : nome.toCharArray())
            senha *= c;
        return crypto;
    }

    public int decryptoSenha(int crypto){
        int senha = crypto;
        for(char c : nome.toCharArray())
            senha /= c;
        return senha;
    }

}
