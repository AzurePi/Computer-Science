package trabalho2;

import trabalho2.exceptions.UnavailableItemException;
import trabalho2.exceptions.UncheckedItemException;

public interface Emprestavel {
    public void emprestimo() throws UnavailableItemException;
    public void devolucao() throws UncheckedItemException;
}
