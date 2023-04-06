package aula7_8.locadora;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Cliente {
    private String nome;
    private String cpf;
    private List<Locacao> locacoes;

    public Cliente(String nome, String cpf) {
        this.nome = nome;
        this.cpf = cpf;
        this.locacoes = new ArrayList<>();
        novaLocacao();
    }

    //getters --------------------------------------
    public String getNome() {
        return nome;
    }

    public String getCpf() {
        return cpf;
    }


    //métodos --------------------------------------
    public void novaLocacao(){
        System.out.println("-------Nova Locação-------");
        int n = locacoes.size();

        Scanner sc = new Scanner(System.in);

        System.out.println("Motorista: ");
        String motorista = sc.nextLine();
        System.out.println("Carro: ");

        Carro carro = new Carro();

        locacoes.add(new Locacao(n, motorista, carro));
    }
}
