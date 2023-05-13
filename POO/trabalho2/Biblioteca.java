package trabalho2;

import trabalho2.exceptions.ItemNotFoundException;
import trabalho2.exceptions.UnavailableItemException;
import trabalho2.exceptions.UserNotFoundException;
import trabalho2.items.CD;
import trabalho2.items.Item;
import trabalho2.items.Livro;
import trabalho2.items.Revista;
import trabalho2.usuarios.Usuario;

import java.util.ArrayList;
import java.util.Scanner;

public class Biblioteca {
    ArrayList<? extends Item> inventario = new ArrayList<>();
    ArrayList<? extends Usuario> usuarios = new ArrayList<>();

    public void consultaItem() {
        System.out.println("Consulta de item -----------------------");

        Scanner sc = new Scanner(System.in);
        System.out.println("Nome do item: ");
        String nome = sc.nextLine();
        System.out.println(); //pula uma linha

        try {
            Item aux = busca(nome); //pode causar ItemNotFoundException

            //informações genéricas
            System.out.println("Título: " + aux.getTitulo());
            System.out.println("Autor: " + aux.getAutor());
            System.out.println("Ano de Publicação: " + aux.getAnoPublicacao());
            System.out.println("Quantidade disponível: " + aux.getDisponivel());
            System.out.println("Quantidade emprestada: " + aux.getEmprestada());

            //informações específicas
            if (aux instanceof CD) {
                System.out.println("Volume: " + ((CD) aux).getVolume());
                System.out.println("Gravadora: " + ((CD) aux).getGravadora());
            } else if (aux instanceof Livro) {
                System.out.println("Editora: " + ((Livro) aux).getEditora());
                System.out.println("ISBN: " + ((Livro) aux).getISBN());
            } else if (aux instanceof Revista) {
                System.out.println("Volume: " + ((Revista) aux).getVolume());
                System.out.println("Número: " + ((Revista) aux).getNumero());
            }
        } catch (ItemNotFoundException e) {
            System.out.println("ERRO: " + e.getMessage());
        }


    }

    public void emprestarItem() {
        System.out.println("Empréstimo de item ------------------");

        Scanner sc = new Scanner(System.in);
        System.out.print("Nome do item: ");
        String nome = sc.nextLine();
        System.out.print("Matrícula de a quem se empresta: ");
        int matricula = sc.nextInt();
        System.out.println(); //pula uma linha

        try {
            Item auxI = busca(nome); //pode gerar ItemNotFountException
            Usuario auxU = login(matricula); //pode gerar UserNotFoundException

            // tentar criar um Emprestimo do item requisitado para o usuário especificado
            try {
                if (auxI instanceof CD)
                    auxU.getEmprestados().add(new Emprestimo<>((CD) auxI));
                else if (auxI instanceof Livro)
                    auxU.getEmprestados().add(new Emprestimo<>((Livro) auxI));
                else if (auxI instanceof Revista)
                    auxU.getEmprestados().add(new Emprestimo<>((Revista) auxI));
            } catch (UnavailableItemException e) {
                System.out.println("ERRO: " + e.getMessage());
            }

        } catch (ItemNotFoundException | UserNotFoundException e) {
            System.out.println("ERRO: " + e.getMessage());
        }
    }

    public Item busca(String nome) throws ItemNotFoundException {
        Item aux = null;
        for (Item i : inventario) {
            if (i.getTitulo().equals(nome)) {
                aux = i;
                break;
            }
        }
        if (aux == null)
            throw new ItemNotFoundException("Item não encontrado");
        return aux;
    }

    public Usuario login(int matricula) throws UserNotFoundException {
        Usuario aux = null;
        for (Usuario u : usuarios) {
            if (u.getMatricula() == matricula) {
                aux = u;
                break;
            }
        }
        if (aux == null)
            throw new UserNotFoundException("Usuário não encontrado");
        return aux;
    }
}
