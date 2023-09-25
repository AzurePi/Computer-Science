package trabalho2;

import trabalho2.exceptions.*;
import trabalho2.itens.CD;
import trabalho2.itens.Item;
import trabalho2.itens.Livro;
import trabalho2.itens.Revista;
import trabalho2.usuarios.Aluno;
import trabalho2.usuarios.AssessorTecnico;
import trabalho2.usuarios.Professor;
import trabalho2.usuarios.Usuario;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * Classe que gerencia um inventário de itens e uma lista de usuários cadastrados com seus respectivos empréstimos.
 */
public class Biblioteca {
    ArrayList<Item> inventario = new ArrayList<>();
    ArrayList<Usuario> usuarios = new ArrayList<>();

    /**
     * Cadastra um novo item.
     * Recebe input do console para determinar a qual subclasse de <code>Item</code> pertence,
     * e então cria um novo objeto dessa subclasse para o <code>inventario</code>
     */
    public void cadastroItem() {
        Scanner sc = new Scanner(System.in);
        short op;

        System.out.println("Cadastro de Item ------------------------------");
        System.out.println("1 - CD\t2 - Livro\t3 - Revista");
        op = sc.nextShort();
        try {
            switch (op) {
                case 1:
                    inventario.add(new CD());
                    break;
                case 2:
                    inventario.add(new Livro());
                    break;
                case 3:
                    inventario.add(new Revista());
                    break;
                default:
                    throw new InvalidItemException("Tipo de item não reconhecido");
            }
        } catch (InvalidItemException e) {
            System.out.println("\tERRO: " + e.getMessage());
        } finally {
            System.out.println();//pula uma linha
        }
    }

    /**
     * Recebe do console um título de <code>Item</code>,
     * e com base nisso procura um correspondente no <code>inventario</code>.
     * Se encontrar, imprime as informações do item na tela.
     */
    public void consultaItem() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Consulta de Item ------------------------------");
        System.out.print("Nome do item: ");
        String nome = sc.nextLine();
        System.out.println(); //pula uma linha

        try {
            Item aux = busca(nome); //pode causar ItemNotFoundException

            //imprime informações genéricas
            System.out.println("Título: " + aux.getTitulo());
            System.out.println("Autor: " + aux.getAutor());
            System.out.println("Ano de Publicação: " + aux.getAnoPublicacao());
            System.out.println("Quantidade disponível: " + aux.getDisponivel());
            System.out.println("Quantidade emprestada: " + aux.getEmprestada());

            //imprime informações específicas
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
            System.out.println("\tERRO: " + e.getMessage());
        } finally {
            System.out.println();//pula uma linha
        }
    }

    /**
     * Recebe do console um título de <code>Item</code> e uma matrícula de <code>Usuario</code>,
     * e com base nisso procura um <code>Item</code> no <code>inventario</code> e um <code>Usuario</code>
     * dentre os cadastrados. Depois disso, cria um novo <code>Emprestimo</code> para o <code>Usuario</code>,
     * com o tipo de <code>Item</code> especificado.
     */
    public void emprestarItem() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Empréstimo de Item ----------------------------");
        System.out.print("Nome do item: ");
        String nome = sc.nextLine();
        System.out.print("Matrícula de a quem se empresta: ");
        int matricula = sc.nextInt();
        System.out.println(); //pula uma linha

        try {
            Item auxI = busca(nome); //pode gerar ItemNotFountException
            Usuario auxU = login(matricula); //pode gerar UserNotFoundException

            // tenta criar um Emprestimo do item requisitado para o usuário especificado
            // pode gerar UnavailableItemException
            if (auxI instanceof CD)
                auxU.getEmprestados().add(new Emprestimo<>((CD) auxI));
            else if (auxI instanceof Livro)
                auxU.getEmprestados().add(new Emprestimo<>((Livro) auxI));
            else if (auxI instanceof Revista)
                auxU.getEmprestados().add(new Emprestimo<>((Revista) auxI));

            System.out.println(nome + " emprestado com sucesso");
        } catch (ItemNotFoundException | UserNotFoundException | UnavailableItemException e) {
            System.out.println("\tERRO: " + e.getMessage());
        } finally {
            System.out.println();//pula uma linha
        }
    }

    /**
     * Recebe do console um título de <code>Item</code> e uma matrícula de <code>Usuario</code>,
     * e com base nisso procura um <code>Item</code> no <code>inventario</code> e um <code>Usuario</code>
     * dentre os cadastrados. Depois disso, procura na lista de empréstimos do <code>Usuario</code> pelo <code>Item</code>.
     * Se houver, realiza a devolução e apresenta o valor da multa.
     */
    public void devolverItem() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Devolução de Item -----------------------------");
        System.out.print("Nome do item: ");
        String nome = sc.nextLine();
        System.out.print("Matrícula de quem emprestou: ");
        int matricula = sc.nextInt();
        System.out.println(); //pula uma linha

        try {
            busca(nome); //pode gerar ItemNotFountException
            Usuario auxU = login(matricula); //pode gerar UserNotFoundException

            //procuramos pelo item na lista de empréstimos do usuário
            ArrayList<Emprestimo<? extends Item>> emps = auxU.getEmprestados();
            double multa = 0;
            short flag = 0;
            for (Emprestimo<? extends Item> emp : emps) {
                String titulo = emp.getEmprestado().getTitulo();
                if (titulo.equals(nome)) {
                    emp.devolver(auxU); //pode gerar UncheckedItemException
                    multa = emp.calcularMulta(auxU);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                throw new UncheckedItemException("Esse item não foi emprestado por esse usuário");

            System.out.println(nome + " devolvido com sucesso");
            if (multa != 0)
                System.out.printf("Multa de R$%.2f%n\n", multa);
        } catch (ItemNotFoundException | UserNotFoundException | UncheckedItemException e) {
            System.out.println("\tERRO: " + e.getMessage());
        } finally {
            System.out.println();//pula uma linha
        }
    }

    /**
     * Cadastra um novo usuário.
     * Recebe input do console para determinar a qual subclasse de <code>Usuario</code> pertence,
     * e então cria um novo objeto dessa subclasse para a lista de usuários.
     */
    public void cadastroUsuario() {
        Scanner sc = new Scanner(System.in);
        short op;

        System.out.println("Cadastro de Usuário ---------------------------");
        System.out.println("1 - Aluno\t2 - Assessor Técnico\t3 - Professor");
        op = sc.nextShort();

        try {
            switch (op) {
                case 1:
                    usuarios.add(new Aluno());
                    break;
                case 2:
                    usuarios.add(new AssessorTecnico());
                    break;
                case 3:
                    usuarios.add(new Professor());
                    break;
                default:
                    throw new InvalidUserException("Tipo de usuário não reconhecido");
            }
        } catch (InvalidUserException e) {
            System.out.println("\tERRO: " + e.getMessage());
        } finally {
            System.out.println();//pula uma linha
        }
    }

    /**
     * Busca, dentre os itens no <code>inventario</code>, aquele que tem o título correspondente ao fornecido.
     *
     * @param titulo o título do <code>Item</code> sendo buscado
     * @return um <code>Item</code> com o título correspondente
     * @throws ItemNotFoundException caso o <code>Item</code> não seja encontrado
     */
    private Item busca(String titulo) throws ItemNotFoundException {
        Item aux = null;
        for (Item i : inventario) {
            if (i.getTitulo().equals(titulo)) {
                aux = i;
                break;
            }
        }
        if (aux == null)
            throw new ItemNotFoundException("Item não encontrado");
        return aux;
    }

    /**
     * Busca, dentre os usuários cadastrados, aquele que tem o número de matrícula correspondente ao fornecido.
     *
     * @param matricula o número de matrícula do <code>Usuario</code> sendo buscado
     * @return um <code>Usuario</code> com o número de matrícula correspondente
     * @throws UserNotFoundException caso o <code>Usuario</code> não seja encontrado
     */
    private Usuario login(int matricula) throws UserNotFoundException {
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

    /**
     * Imprime no console informações sobre todos os itens no <code>inventario</code>
     */
    public void listarItems() {
        if (!inventario.isEmpty()) {
            for (Item i : inventario) {
                i.imprimir();
                System.out.println();//pula uma linha
            }
        } else
            System.out.println("Não há itens cadastrados");

        System.out.println();//pula uma linha
    }

    /**
     * Imprime no console o nome e número de matrícula de todos os usuários cadastrados
     */
    public void listarUsuarios() {
        if (!usuarios.isEmpty()) {
            for (Usuario u : usuarios) {
                u.imprimir();
                System.out.println();
            }
        } else
            System.out.println("Não há usuários cadastrados");

        System.out.println();//pula uma linha
    }

    /**
     * Recebe do console um número de matrícula, procura por um <code>Usuario</code> cadastrado
     * com a matrícula correspondente, e então lista todos os seus empréstimos pendentes.
     */
    public void emprestimosUsuario() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Matrícula: ");
        int mat = sc.nextInt();

        try {
            Usuario u = login(mat);
            ArrayList<Emprestimo<? extends Item>> emps = u.getEmprestados();

            if (!emps.isEmpty()) {
                System.out.println("Empréstimos -----------------------------------");
                for (Emprestimo<? extends Item> e : emps) {
                    e.getEmprestado().imprimir();
                    System.out.println();//pula uma linha
                }
            } else
                System.out.println("Esse usuário não tem items emprestados");
        } catch (UserNotFoundException e) {
            System.out.println("\tERRO: " + e.getMessage());
        } finally {
            System.out.println();//pula uma linha
        }
    }
}
