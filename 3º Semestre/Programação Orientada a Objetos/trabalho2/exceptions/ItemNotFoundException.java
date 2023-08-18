package trabalho2.exceptions;

/**
 * Trata exceções caso o <code>Item</code> não esteja no <code>inventario</code> da <code>Biblioteca</code>.
 */
public class ItemNotFoundException extends Exception {
    public ItemNotFoundException(String msg) {
        super(msg);
    }
}
