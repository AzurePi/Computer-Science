import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class TextBreaker {
    public static void main(String[] args) {
        String texto;
        ArrayList<String> palavras;
        StringBuilder trecho = new StringBuilder();
        Path diretorioDestino;
        File destino;
        int n; //controla o nome do arquivo txt de cada trecho
        int inicio, fim; //índices da palavra no trecho

        System.out.println("Quebra um arquivo txt em trechos de 4000 caracteres (sem quebrar palavras ao meio), e salva esse textos em arquivos txt no endereço especificado");

        try {
            texto = lerTexto();
        } catch (IOException e) {
            System.out.println("ERRO: falha ao ler o arquivo de origem");
            throw new RuntimeException(e);
        }
        diretorioDestino = lerDestino();


        //transformamos a String texto em uma array de strings, em que cada String é uma única palavra
        palavras = new ArrayList<>(Arrays.asList(texto.split(" ")));

        n = 0;

        while (!palavras.isEmpty()) {
            trecho.append(palavras.get(0));

            //se extrapolamos 4000 caracteres
            if (trecho.length() > 4000) {
                //determina os índices inicial e final da última palavra inserida
                inicio = trecho.indexOf(palavras.get(0));
                fim = inicio + palavras.get(0).length();

                trecho.delete(inicio, fim); //remove a última palavra inserida

                try {
                    destino = new File(diretorioDestino.toFile(), n + ".txt");
                    salvar(trecho, destino);
                    n++;
                } catch (IOException e) {
                    System.out.println("ERRO: falha no salvamento do arquivo");
                    throw new RuntimeException(e);
                }
            } else //se não extrapolamos 4000 caracteres
                palavras.remove(0); //removemos a palavra inserida da lista de palavras

            trecho.append(" "); //colocamos um espaço após a palavra
        }
    }

    private static void salvar(StringBuilder trecho, File destino) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(destino));
        writer.write(trecho.toString());
        writer.close();
        System.out.println("salvar() ok");
    }

    public static Path lerDestino() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Diretório de destino: ");
        Path destino = Paths.get(sc.nextLine());
        sc.close();
        System.out.println("lerDestino() ok");
        return destino;
    }

    private static String lerTexto() throws IOException {
        Scanner sc = new Scanner(System.in);
        System.out.print("Endereço do arquivo de origem: ");
        Path path = Paths.get(sc.nextLine());
        sc.close();

        BufferedReader reader = Files.newBufferedReader(path);
        String lines = reader.lines().toString();
        reader.close();

        System.out.println("lerTexto() ok");
        return lines;
    }
}
