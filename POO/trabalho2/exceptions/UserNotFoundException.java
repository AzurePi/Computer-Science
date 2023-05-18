package trabalho2.exceptions;

/**
 * Trata exceções caso o <code>Usuario</code> não esteja cadastrado na <code>Biblioteca</code>
 */
public class UserNotFoundException extends Exception {
    public UserNotFoundException(String msg) {
        super(msg);
    }
}
