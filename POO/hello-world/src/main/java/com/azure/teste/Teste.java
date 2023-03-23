package com.mycompany.teste;

import java.util.Scanner;

public class Teste {

    public static void main(String[] args) {
        System.out.println("Olá mundo!");
        Scanner sc = new Scanner(System.in);
        String nome = sc.nextLine();
        System.out.println("Olá "+ nome);
    }
}
