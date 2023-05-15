package aula07_08.locadora;

import java.util.Scanner;

public class Locacao {
    private int numero;
    private Data dataInicio;
    private Data dataFinal;
    private String motorista;
    private Carro carro;

    public Locacao(int numero, String motorista, Carro carro) {
        this.numero = numero;
        this.motorista = motorista;
        this.carro = carro;

        Scanner sc = new Scanner(System.in);

        System.out.println("Início da Locação (dd/mm/aaaa): ");
        dataInicio = new Data(sc.nextInt(), sc.nextInt(), sc.nextInt());
    }

    public float valor(){
        float preco = carro.getPrecoDia();

        Scanner sc = new Scanner(System.in);

        System.out.println("Final da Locação (dd/mm/aaaa): ");
        dataFinal = new Data(sc.nextInt(), sc.nextInt(), sc.nextInt());

        preco *= dataInicio.periodo(dataFinal);

        return preco;
    }

}
