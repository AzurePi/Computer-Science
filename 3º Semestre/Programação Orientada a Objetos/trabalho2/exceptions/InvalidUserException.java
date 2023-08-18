package trabalho2.exceptions;

/**
 * Trata exceções caso a opção selecionada de subclasse de <code>Usuario</code> não seja válida.
 */
public class InvalidUserException extends Exception {
    public InvalidUserException(String message) {
        super(message);
    }
}
