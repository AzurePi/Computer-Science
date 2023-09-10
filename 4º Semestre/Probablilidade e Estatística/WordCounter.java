import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.util.*;

public class WordCounter {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        File parent;
        File result;
        FileWriter wr;

        System.out.println("Recebe o endereço de um diretório, dentro do qual há apenas arquivos .txt, e cria um artigo txt com a quantidade de palavras de acada um");

        System.out.print("Diretório pai: ");
        parent = new File(validar(sc.nextLine()));

        System.out.print("Número inicial: ");

        File[] artigos = parent.listFiles();

        if (artigos != null) {
            Arrays.sort(artigos); //garante que estará em ordem alfabética

            result = new File(parent, "result.txt");
            try {
                wr = new FileWriter(result);

                for (File artigo : artigos) {
                    try {
                        ArrayList<String> palavras = lerTexto(artigo);
                        int tamanhoTexto = palavras.size(); //calcula o número total de palavras no texto
                        wr.write(tamanhoTexto + "\n");
                    } catch (IOException e) {
                        System.out.println("ERRO: falha ao ler o arquivo de origem");
                        throw new RuntimeException(e);
                    }
                }
                wr.close();
            } catch (IOException e) {
                System.out.println("ERRO: falha ao criar arquivo de destino");
                throw new RuntimeException(e);
            }
        }
    }

    public static ArrayList<String> lerTexto(File artigo) throws IOException {
        List<String> lines = Files.readAllLines(artigo.toPath());
        String texto = String.join(System.lineSeparator(), lines);

        //transformamos a String texto em uma array de strings, em que cada String é uma única palavra
        ArrayList<String> palavras = new ArrayList<>();
        StringTokenizer tokenizer = new StringTokenizer(texto);

        while (tokenizer.hasMoreTokens())
            palavras.add(tokenizer.nextToken());
        return palavras;
    }

    public static String validar(String original) {
        if (original.charAt(0) == '"') //se há aspas, retira as aspas
            return original.substring(original.indexOf('"'), original.lastIndexOf('"'));
        return original;
    }

}