package aula14;

public class Calculator {
    public static double calcular(double a, double b, char operacao) throws InvalidOperationException, ArithmeticException {
        switch (operacao) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                if (b == 0)
                    throw new ArithmeticException("Divisão por 0");
                return a / b;
            default:
                throw new InvalidOperationException("Operação inválida: " + operacao);
        }
    }
}
