package aula14;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Operação a realizar: ");
        char op = sc.nextLine().charAt(0);
        System.out.println("Números: ");
        double a = sc.nextDouble();
        double b = sc.nextDouble();

        try {
            double result = Calculator.calcular(a, b, (op));
            System.out.println("= " + result);
        } catch (InvalidOperationException | ArithmeticException e) {
            System.out.println("ERRO: " + e.getMessage());
        }

    }
}
