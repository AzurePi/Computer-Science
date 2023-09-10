import com.itextpdf.text.pdf.PdfReader;
import com.itextpdf.text.pdf.parser.PdfTextExtractor;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Extrator2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Recebe o endereço de um diretório, dentro do qual há apenas arquivos .pdf, e extrai seus textos para arquivos .txt");

        System.out.print("Diretório pai: ");
        File parent = new File(validar(sc.nextLine()));

        System.out.print("Número inicial: ");
        int d = Integer.parseInt(sc.nextLine());

        File[] artigos = parent.listFiles();

        if (artigos != null) {
            Arrays.sort(artigos); //garante que estará em ordem alfabética
            StringBuilder text;
            int pages;
            for (File artigo : artigos) {
                try {
                    PdfReader reader = new PdfReader(artigo.getAbsolutePath());
                    pages = reader.getNumberOfPages();
                    text = new StringBuilder();

                    for (int i = 1; i<= pages; i++)
                        text.append(PdfTextExtractor.getTextFromPage(reader, i));

                    reader.close();

                    FileWriter wr = new FileWriter(parent.getAbsoluteFile().toString() + d + ".txt");
                    wr.write(text.toString());
                    wr.close();
                } catch (IOException e) {
                    System.out.println("ERRO: falha ao carregar pdf");
                    throw new RuntimeException(e);
                }
                d++;
            }
        }
    }

    public static String validar(String original) {
        if (original.charAt(0) == '"') //se há aspas, retira as aspas
            return original.substring(original.indexOf('"'), original.lastIndexOf('"'));
        return original;
    }
}
