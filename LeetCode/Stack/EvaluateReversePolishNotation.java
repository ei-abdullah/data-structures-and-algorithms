public class EvaluateReversePolishNotation {
    public int evalRPN(String[] tokens) {
        int[] stack = new int[tokens.length];
        int top = -1;

        for (String token: tokens) {
            char c = token.charAt(0);
            if (token.length() == 1 && (c == '+' || c == '-' || c == '*' || c == '/')) {
                int b = stack[top--];
                int a = stack[top--];
                int result = switch (c) {
                    case '+' -> a + b;
                    case '-' -> a - b;
                    case '*' -> a * b;
                    case '/' -> a / b;
                    default -> 0;
                };
                stack[++top] = result;
            } else {
                stack[++top] = Integer.parseInt(token);
            }
        }

        return stack[top];
    }

    static void main() {
        String[] tokens = {"1", "2", "+", "3", "*", "4", "-"};
        System.out.println(new EvaluateReversePolishNotation().evalRPN(tokens));
    }
}
