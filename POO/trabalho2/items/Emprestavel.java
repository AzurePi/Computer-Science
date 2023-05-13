package trabalho2.items;

import trabalho2.exceptions.UnavailableItemException;
import trabalho2.exceptions.UncheckedItemException;

public interface Emprestavel {
    void emprestimo() throws UnavailableItemException;

    void devolucao() throws UncheckedItemException;
}
