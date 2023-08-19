import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class TextBreaker {
    public static void main(String[] args) {
        String texto;
        ArrayList<String> palavras;
        StringBuilder trecho = new StringBuilder();
        Path diretorioDestino;
        String fileName;
        Path file;
        int i, tamanhoTexto, projecao; //controla que linha do arquivo de origem está sendo lida e seu tamanho total
        int n; //controla o nome do arquivo txt de cada trecho
        Scanner sc = new Scanner(System.in);

        System.out.println("Quebra um arquivo txt em trechos de 4000 caracteres (sem quebrar palavras ao meio), e salva esse textos em arquivos txt no endereço especificado");

        try {
            texto = lerTexto(sc);
        } catch (IOException e) {
            System.out.println("ERRO: falha ao ler o arquivo de origem");
            throw new RuntimeException(e);
        }
        diretorioDestino = lerDestino(sc);

        //transformamos a String texto em uma array de strings, em que cada String é uma única palavra
        palavras = new ArrayList<>(Arrays.asList(texto.split(" ")));

        n = i = 0;
        tamanhoTexto = palavras.size();
        while (i < tamanhoTexto) {
            projecao = trecho.length() + palavras.get(i).length();

            //não salva o último trecho! descobrir porque, alguma coisa com os ifs

            if (projecao <= 4000) {
                trecho.append(palavras.get(i));
                trecho.append(" ");
                i++;
            } else { //já chegamos ao tamanho máximo
                try {
                    fileName = n + ".txt";
                    file = Paths.get(diretorioDestino.toString(), fileName);
                    salvar(trecho, file);
                    n++;
                    trecho = new StringBuilder(); //começamos a montar um novo trecho
                } catch (IOException e) {
                    System.out.println("ERRO: falha no salvamento do arquivo");
                    throw new RuntimeException(e);
                }
            }
        }

        sc.close();
    }

    private static String lerTexto(Scanner sc) throws IOException {
        System.out.print("Endereço do arquivo de origem: ");
        String aux = sc.nextLine();
        Path origem = Paths.get(aux.substring(1, aux.length() - 1)); //remove as aspas coladas no caminho

        List<String> lines = Files.readAllLines(origem);
        return String.join(System.lineSeparator(), lines);
    }

    public static Path lerDestino(Scanner sc) {
        System.out.print("Diretório de destino: ");
        String aux = sc.nextLine();
        return Paths.get(aux.substring(1, aux.length() - 1)); //remove as aspas coladas no caminho
    }

    private static void salvar(StringBuilder trecho, Path destino) throws IOException {
        Files.createFile(destino);
        BufferedWriter writer = Files.newBufferedWriter(destino);
        writer.write(trecho.toString());
        writer.close();
    }
}
