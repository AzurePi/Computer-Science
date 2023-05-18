package trabalho2.exceptions;

/**
 * Trata exceções caso o <code>Item</code> não seja parte de um <code>Emprestimo</code>.
 */
public class UncheckedItemException extends Exception {
    public UncheckedItemException(String message) {
        super(message);
    }
}
