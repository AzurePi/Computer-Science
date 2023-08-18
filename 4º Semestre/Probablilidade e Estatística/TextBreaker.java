import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class TextBreaker {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String texto = "";
        ArrayList<String> trechos;
        String trecho = "";
        String path = "";
        int charCount;

        System.out.println("Quebra um dado texto em trechos de 4000 caracteres (sem quebrar palavras ao meio), e salva esse textos em arquivos txt no endereço especificado");

        path = lerEndereco(sc);
        texto = lerTexto(sc);

        trechos = new ArrayList<>(Arrays.asList(texto.split(" ")));

        charCount = 0;
        while (!trechos.isEmpty()){
            if()
        }


    }

    public static String lerEndereco(Scanner sc) {
        System.out.print("Endereço de destino: ");
        return sc.nextLine();
    }

    private static String lerTexto(Scanner sc) {
        System.out.println("Cole o texto a ser quebrado");
        return sc.nextLine();
    }

}
