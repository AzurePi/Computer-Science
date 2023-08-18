package trabalho2.itens;

import java.util.Scanner;

/**
 * Extensão de <code>Item</code>.
 */
public class Livro extends Item {
    private String editora, ISBN;

    /**
     * Cria, a partir de input no console, um novo <code>Livro</code>.
     */
    public Livro() {
        super();
        Scanner sc = new Scanner(System.in);
        System.out.print("Editora: ");
        editora = sc.nextLine();
        System.out.print("ISBN: ");
        ISBN = sc.nextLine();
    }

    public String getEditora() {
        return editora;
    }

    public void setEditora(String editora) {
        this.editora = editora;
    }

    public String getISBN() {
        return ISBN;
    }

    public void setISBN(String ISBN) {
        this.ISBN = ISBN;
    }

    /**
     * Imprime no console as informações do <code>Livro</code>.
     */
    @Override
    public void imprimir() {
        super.imprimir();
        System.out.println("Editora: " + getEditora());
        System.out.println("ISBN: " + getISBN());
    }
}
