package trabalho2.itens;

import trabalho2.exceptions.UnavailableItemException;
import trabalho2.exceptions.UncheckedItemException;

/**
 * Define métodos de uma classe que pode realizar empréstimos e devoluções
 */
public interface Emprestavel {
    void emprestimo() throws UnavailableItemException;

    void devolucao() throws UncheckedItemException;
}
