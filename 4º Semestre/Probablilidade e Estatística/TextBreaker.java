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
        StringBuilder trecho;
        Path diretorioDestino, fileDestino;
        String fileName;
        int i, tamanhoTexto, projecao; //controla que linha do arquivo de origem está sendo lida e seu tamanho total
        int a; //controla o nome do arquivo txt de cada trecho
        int continuar; //controla se mais arquivos serão processados
        Scanner sc = new Scanner(System.in);

        System.out.println("Quebra um arquivo txt em trechos de 4000 caracteres (sem quebrar palavras ao meio), e salva esse textos em arquivos txt no endereço especificado\n");

        do {
            try {
                texto = lerTexto(sc);

                //transformamos a String texto em uma array de strings, em que cada String é uma única palavra
                palavras = new ArrayList<>(Arrays.asList(texto.split(" ")));
                tamanhoTexto = palavras.size();
            } catch (IOException e) {
                System.out.println("ERRO: falha ao ler o arquivo de origem");
                throw new RuntimeException(e);
            }
            diretorioDestino = lerDestino(sc);

            trecho = new StringBuilder(); //inicializamos o trecho de 4000 caracteres
            a = i = 0; //zera o contador de arquivos e o contador de palavras
            do {
                projecao = trecho.length() + palavras.get(i).length();

                //falta alguma coisa na condição desse if pra fazer salvar também quando projeção ainda não chegou em 4000, mas já acabou o texto
                if (projecao > 4000 || i == tamanhoTexto) { //já chegamos ao tamanho máximo do trecho, então salvamos
                    try {
                        fileName = a + ".txt";
                        fileDestino = Paths.get(diretorioDestino.toString(), fileName);
                        salvar(trecho, fileDestino);
                        a++; //passamos para o próximo arquivo
                        trecho = new StringBuilder(); //começamos a montar um novo trecho
                    } catch (IOException e) {
                        System.out.println("ERRO: falha no salvamento do arquivo");
                        throw new RuntimeException(e);
                    }
                } else {
                    trecho.append(palavras.get(i)).append(" ");
                    i++; //passamos para a próxima palavra
                }
            } while (i < tamanhoTexto);

            System.out.println("Digite 1 para continuar com outro arquivo");
            continuar = sc.nextInt();
        } while (continuar == 1);
        sc.close();
    }

    private static String lerTexto(Scanner sc) throws IOException {
        System.out.print("Endereço do arquivo de origem: ");
        Path origem = Paths.get(validar(sc.nextLine()));
        List<String> lines = Files.readAllLines(origem); //lê todas as linhas do arquivo
        return String.join(System.lineSeparator(), lines);
    }

    public static Path lerDestino(Scanner sc) {
        System.out.print("Diretório de destino: ");
        return Paths.get(validar(sc.nextLine())); //remove as aspas coladas no caminho
    }

    public static void salvar(StringBuilder trecho, Path destino) throws IOException {
        Files.createFile(destino);
        BufferedWriter writer = Files.newBufferedWriter(destino);
        writer.write(trecho.toString());
        writer.close();
    }

    public static String validar(String original) {
        if (original.charAt(0) == '"') //se há aspas, retira as aspas
            return original.substring(original.indexOf('"'), original.lastIndexOf('"'));
        return original;
    }
}
