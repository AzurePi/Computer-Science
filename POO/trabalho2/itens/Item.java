package trabalho2.itens;

import trabalho2.exceptions.UnavailableItemException;
import trabalho2.exceptions.UncheckedItemException;

import java.util.Scanner;

/**
 * Implementação de <code>Emprestavel</code>. Agregado de informações, identificadas por um título,
 * com quantidade disponível e quantidade já emprestada.
 */
public abstract class Item implements Emprestavel {
    private String titulo, autor;
    private int anoPublicacao, disponivel, emprestada;

    /**
     * Cria, a partir de input no console, um novo <code>Item</code>.
     */
    public Item() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Título: ");
        titulo = sc.nextLine();
        System.out.print("Autor: ");
        autor = sc.nextLine();
        System.out.print("Ano de publicação: ");
        anoPublicacao = sc.nextInt();
        System.out.print("Quantidade disponível: ");
        disponivel = sc.nextInt();
        System.out.print("Quantidade emprestada: ");
        emprestada = sc.nextInt();
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public int getAnoPublicacao() {
        return anoPublicacao;
    }

    public void setAnoPublicacao(int anoPublicacao) {
        this.anoPublicacao = anoPublicacao;
    }

    public int getDisponivel() {
        return disponivel;
    }

    public void setDisponivel(int disponivel) {
        this.disponivel = disponivel;
    }

    public int getEmprestada() {
        return emprestada;
    }

    public void setEmprestada(int emprestada) {
        this.emprestada = emprestada;
    }

    /**
     * Se há disponibilidade do item, atualiza a quantidade disponível e a quantidade emprestada de acordo com um empréstimo.
     *
     * @throws UnavailableItemException caso o <code>Item</code> não esteja disponível
     */
    @Override
    public void emprestimo() throws UnavailableItemException {
        if (getDisponivel() == 0)
            throw new UnavailableItemException("Item sem estoque");

        setDisponivel(getDisponivel() - 1);
        setEmprestada(getEmprestada() + 1);
    }

    /**
     * Se há alguma quantidade emprestada, atualiza a quantidade disponível e a quantidade emprestada de acordo com uma devolução.
     *
     * @throws UncheckedItemException caso o item não tenha sido emprestado.
     */
    @Override
    public void devolucao() throws UncheckedItemException {
        if (getEmprestada() == 0)
            throw new UncheckedItemException("Esse item não está emprestado");

        setDisponivel(getDisponivel() + 1);
        setEmprestada(getEmprestada() - 1);
    }

    /**
     * Imprime no console as informações do <code>Item</code>.
     */
    public void imprimir() {
        System.out.println("Título: " + getTitulo() + " (" + this.getClass().getSimpleName() + ")");
        System.out.println("Autor: " + getAutor());
        System.out.println("Ano de publicação: " + getAnoPublicacao());
    }
}
