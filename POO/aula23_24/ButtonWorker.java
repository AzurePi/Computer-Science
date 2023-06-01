package aula23_24;

import javax.swing.*;
import java.util.concurrent.ExecutionException;

public class ButtonWorker extends SwingWorker<Integer, Void> {
    private final int sleepTime;

    public ButtonWorker(int sleepTime) {
        this.sleepTime = sleepTime;
    }

    @Override
    protected Integer doInBackground() {
        try {
            Thread.sleep(sleepTime);
        } catch (InterruptedException ex) {
            ex.printStackTrace();
        }
        return sleepTime;
    }

    @Override
    protected void done() {
        int result;
        try {
            result = get();
            JOptionPane.showMessageDialog(null,
                    "Finished. Sleep time: " + result,
                    "Swing Worker Example",
                    JOptionPane.INFORMATION_MESSAGE);
        } catch (InterruptedException | ExecutionException ex) {
            ex.printStackTrace();
        }
    }
}
