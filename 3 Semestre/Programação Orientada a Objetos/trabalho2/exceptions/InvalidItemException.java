package trabalho2.exceptions;

/**
 * Trata exceções caso a opção selecionada de subclasse de <code>Item</code> não seja válida.
 */
public class InvalidItemException extends Exception {
    public InvalidItemException(String msg) {
        super(msg);
    }
}
