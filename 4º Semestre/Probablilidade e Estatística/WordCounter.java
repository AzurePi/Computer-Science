import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Scanner;

public class WordCounter {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Recebe um arquivo, e conta a quantidade de palavras");

        do {
            System.out.println();
            try {
                String texto = lerTexto(sc);
                System.out.println(texto.length());
            } catch (IOException e) {
                System.out.println("ERRO: falha ao ler o arquivo");
                throw new RuntimeException(e);
            }

            System.out.print("Digite OK para continuar com outro arquivo ");
        } while (sc.nextLine().equalsIgnoreCase("OK"));
    }

    private static String lerTexto(Scanner sc) throws IOException {
        System.out.print("Endereço do arquivo de origem: ");
        Path origem = Paths.get(validar(sc.nextLine()));
        List<String> lines = Files.readAllLines(origem); //lê todas as linhas do arquivo
        return String.join(System.lineSeparator(), lines);
    }

    public static String validar(String original) {
        if (original.charAt(0) == '"') //se há aspas, retira as aspas
            return original.substring(original.indexOf('"'), original.lastIndexOf('"'));
        return original;
    }
}
