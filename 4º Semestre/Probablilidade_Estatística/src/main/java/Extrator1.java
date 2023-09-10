import org.apache.pdfbox.Loader;
import org.apache.pdfbox.pdmodel.PDDocument;
import org.apache.pdfbox.text.PDFTextStripper;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Extrator1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PDFTextStripper st = new PDFTextStripper();
        FileWriter wr;
        File parent;

        System.out.println("Recebe o endereço de um diretório, dentro do qual há apenas arquivos .pdf, e extrai seus textos para arquivos .txt");

        System.out.print("Diretório pai: ");
        parent = new File(validar(sc.nextLine()));

        System.out.print("Número inicial: ");
        int d = Integer.parseInt(sc.nextLine());

        File[] artigos = parent.listFiles();
        st.setSortByPosition(true);

        if (artigos != null) {
            Arrays.sort(artigos); //garante que estará em ordem alfabética
            String text;
            for (File artigo : artigos) {
                try {
                    PDDocument doc = Loader.loadPDF(artigo);
                    text = st.getText(doc);
                    doc.close();
                    wr = new FileWriter(parent.getAbsoluteFile().toString() + d + ".txt");
                    wr.write(text);
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
