package trabalho2.items;

import java.util.Scanner;

public class Livro extends Item {
    private String editora, ISBN;

    public Livro(String titulo, String autor, int anoPublicacao, int disponivel, int emprestada, String editora, String ISBN) {
        super(titulo, autor, anoPublicacao, disponivel, emprestada);
        this.editora = editora;
        this.ISBN = ISBN;
    }

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
}
