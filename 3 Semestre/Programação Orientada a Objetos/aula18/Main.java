package aula18;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        HashMap<String, Integer> dicionario = new HashMap<>();

        Scanner sc = new Scanner(System.in);

        System.out.println("Escreva um texto para a contagem de palavras");


        String line = sc.nextLine().toLowerCase(Locale.ROOT);
        String[] words = line.split(" ");

        for(String word : words){
            if (dicionario.containsKey(word))
                dicionario.put(word, dicionario.get(word) + 1);
            else
                dicionario.put(word, 1);
        }

        ArrayList<String> alfabetica = new ArrayList<>();
        for (String s : dicionario.keySet())
            alfabetica.add(s);
        alfabetica.sort(null);

        /*
        Collection<Integer> values = dicionario.values();
        ArrayList<Integer> ordered = new ArrayList<>()
        for(Integer i : values)
            ordered.add(i);
        ordered.sort(null);
        */

        System.out.println(); //pula linha

        System.out.println("Frequência das palavras");
        for (String s : alfabetica)
            System.out.println(s + " " + dicionario.get(s));
    }
}
