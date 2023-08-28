import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class TextBreaker {
    public static void main(String[] args) {
        File parent;
        int d; //controla o número do arquivo
        ArrayList<String> palavras;
        StringBuilder trecho;
        File newDir;
        int p, tamanhoTexto, projecao; //controla que linha do arquivo de origem está sendo lida e seu tamanho total
        int a; //controla o nome do arquivo txt de cada trecho, e a quantidade total de arquivos
        Scanner sc = new Scanner(System.in);

        System.out.println("Recebe o endereço de um diretório, dentro do qual há apenas arquivos .txt, e os quebra em trechos com  4000 caracteres (sem quebrar palavras ao meio), e salva esse textos em arquivos txt em um novo sub-diretório");

        System.out.println("Diretório pai: ");
        parent = new File(sc.nextLine());

        System.out.print("Número inicial: ");
        d = Integer.parseInt(sc.nextLine());

        File[] artigos = parent.listFiles();

        if (artigos != null) {
            for (File artigo : artigos) {
                try {
                    palavras = lerTexto(artigo);
                    tamanhoTexto = palavras.size(); //calcula o número total de palavras no texto

                    newDir = new File("result" + d);
                    newDir.mkdir();
                } catch (IOException e) {
                    System.out.println("ERRO: falha ao ler o arquivo de origem");
                    throw new RuntimeException(e);
                }

                a = p = 0; //zera o contador de arquivos e o contador de palavras
                trecho = new StringBuilder();
                while (p < tamanhoTexto) {
                    projecao = trecho.length() + palavras.get(p).length();

                    //se ainda não chegamos ao tamanho máximo
                    if (projecao <= 4000) {
                        trecho.append(palavras.get(p)).append(" ");
                        p++; //passamos para a próxima palavra
                    } else { //já chegamos ao tamanho máximo do trecho
                        salvarTrecho(newDir.toString(), trecho.toString(), a);
                        a++; //passamos para o próximo arquivo
                        trecho = new StringBuilder();
                    }
                }
                //se ainda há informações a salvar no trecho
                if (!trecho.toString().isEmpty())
                    salvarTrecho(newDir.toString(), trecho.toString(), a);

                d++;
            }
        }
        sc.close();
    }

    public static ArrayList<String> lerTexto(File artigo) throws IOException {
        List<String> lines = Files.readAllLines(artigo.toPath());
        String texto = String.join(System.lineSeparator(), lines);

        //transformamos a String texto em uma array de strings, em que cada String é uma única palavra
        ArrayList <String> palavras = new ArrayList<>();
        StringTokenizer tokenizer = new StringTokenizer(texto);

        while (tokenizer.hasMoreTokens())
            palavras.add(tokenizer.nextToken());
        return palavras;
    }

    public static void salvarTrecho(String destino, String trecho, int a) {
        try {
            String fileName = a + ".txt";
            Path fileDestino = Paths.get(destino, fileName);
            salvar(trecho, fileDestino);
        } catch (IOException e) {
            System.out.println("ERRO: falha no salvamento do arquivo");
            throw new RuntimeException(e);
        }
    }

    public static void salvar(String trecho, Path destino) throws IOException {
        Files.createFile(destino);
        BufferedWriter writer = Files.newBufferedWriter(destino);
        writer.write(trecho);
        writer.close();
    }

    public static String validar(String original) {
        if (original.charAt(0) == '"') //se há aspas, retira as aspas
            return original.substring(original.indexOf('"'), original.lastIndexOf('"'));
        return original;
    }
}
