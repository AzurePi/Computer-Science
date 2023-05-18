package trabalho2.exceptions;

/**
 * Trata exceções caso o <code>Item</code> não esteja disponível para empréstimo.
 */
public class UnavailableItemException extends Exception {
    public UnavailableItemException(String message) {
        super(message);
    }
}
