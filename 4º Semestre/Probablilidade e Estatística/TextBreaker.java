import java.io.BufferedWriter;
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
        ArrayList<String> palavras;
        StringBuilder trecho;
        StringTokenizer tokenizer;
        Path diretorioDestino;
        int i, tamanhoTexto, projecao; //controla que linha do arquivo de origem está sendo lida e seu tamanho total
        int a, totalArquivos; //controla o nome do arquivo txt de cada trecho, e a quantidade total de arquivos
        Scanner sc = new Scanner(System.in);

        System.out.println("Quebra um arquivo txt em trechos de 4000 caracteres (sem quebrar palavras ao meio), e salva esse textos em arquivos txt no endereço especificado");

        do {
            System.out.println(); //pula uma linha
            try {
                String texto = lerTexto(sc);

                //transformamos a String texto em uma array de strings, em que cada String é uma única palavra
                palavras = new ArrayList<>();
                tokenizer = new StringTokenizer(texto);
                int nChars = 0;
                String aux;
                totalArquivos = 0;
                while (tokenizer.hasMoreTokens()) {
                    aux = tokenizer.nextToken();
                    /*
                    nChars += aux.length();
                    if (nChars >= 4000) {
                        totalArquivos++;
                        nChars %= 4000;
                    }
                    */
                    palavras.add(aux);
                }
                tamanhoTexto = palavras.size(); //calcula o número total de palavras no texto
            } catch (IOException e) {
                System.out.println("ERRO: falha ao ler o arquivo de origem");
                throw new RuntimeException(e);
            }
            diretorioDestino = lerDestino(sc);

            a = i = 0; //zera o contador de arquivos e o contador de palavras
            //trecho = new StringBuilder("[" + a + "/" + totalArquivos + "]\n"); //inicializamos o trecho de 4000 caracteres
            trecho = new StringBuilder();
            while (i < tamanhoTexto) {
                projecao = trecho.length() + palavras.get(i).length();

                //se ainda não chegamos ao tamanho máximo
                if (projecao <= 4000) {
                    trecho.append(palavras.get(i)).append(" ");
                    i++; //passamos para a próxima palavra
                } else { //já chegamos ao tamanho máximo do trecho
                    salvarTrecho(diretorioDestino, trecho.toString(), a);
                    a++; //passamos para o próximo arquivo
                    //trecho = new StringBuilder("[" + a + "/" + totalArquivos + "]\n"); //começamos a montar um novo trecho
                    trecho = new StringBuilder();
                }
            }
            //se ainda há informações a salvar no trecho
            if (!trecho.isEmpty())
                salvarTrecho(diretorioDestino, trecho.toString(), a);

            System.out.print("Digite OK para continuar com outro arquivo ");
        } while (sc.nextLine().equalsIgnoreCase("OK"));
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
        return Paths.get(validar(sc.nextLine()));
    }

    public static void salvarTrecho(Path diretorioDestino, String trecho, int a) {
        try {
            String fileName = a + ".txt";
            Path fileDestino = Paths.get(diretorioDestino.toString(), fileName);
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
