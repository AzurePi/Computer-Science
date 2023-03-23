import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner();
        System.out.println("Dimensões da matriz 1: ");

        int i1 = sc.nextInt();
        int j1 = sc.nextInt();
        double[][] m1 = new double[i1][j1]; //declaração da matriz

        System.out.println("Valores na matriz 1: ");
        for(int i = 0; i < i1; i++){
            for(int j = 0; j<j1; j++){
                m1[i][j] = sc.nextDouble();
            }
        }

        System.out.println("Dimensões da matriz 2: ");

        int i2 = sc.nextInt();
        int j2 = sc.nextInt();
        double[][] m2 = new double[i2][j2]; //declaração da matriz

        System.out.println("Valores na matriz 2: ");
        for(int i = 0; i < i2; i++){
            for(int j = 0; j<j2; j++){
                m2[i][j] = sc.nextDouble();
            }
        }

        if(j1 == i2){
            double[][] res = new double[i1][j2];
            for(int i=0; i<i1; i++){
                for(int j =0; j<j2; j++){

                }
            }
        }
        else System.out.println("Essas matrizes não podme ser multiplicadas");

        sc.close();
    }
}