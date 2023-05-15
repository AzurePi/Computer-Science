package aula07_08.locadora;

import java.util.Scanner;

public class Carro {
    private String modelo;
    private String placa;
    private float precoDia;

    //constructor
    public Carro(String modelo, String placa, float precoDia){
        this.modelo = modelo;
        this.placa = placa;
        this.precoDia = precoDia;
    }

    public Carro(){
        Scanner sc = new Scanner(System.in);

        System.out.println("Modelo: ");
        modelo = sc.nextLine();
        System.out.println("Placa: ");
        placa = sc.nextLine();
        System.out.println("Preço da diária: ");
        precoDia = sc.nextFloat();
    }

    //getters --------------------------------------
    public String getModelo() {
        return modelo;
    }

    public String getPlaca() {
        return placa;
    }

    public float getPrecoDia() {
        return precoDia;
    }
}
