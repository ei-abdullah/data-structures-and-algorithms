import java.util.Stack;

public class ValidParentheses {

    public boolean isValid(String s) {
        Stack<Character> stk = new Stack<>();

        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (stk.isEmpty()) {
                    return false;
                }

                char top = stk.pop();
                if (c == ')' && top != '(') {
                    return false;
                } else if (c == ']' && top != '[') {
                    return false;
                } else if (c == '}' && top != '{') {
                    return false;
                } else {
                    continue;
                }
            }
            else {
                return false;
            }
        }

        if(!stk.isEmpty()) {
            return false;
        }

        return true;
    }

    static void main() {
        String s = "[{}";
        System.out.println(new ValidParentheses().isValid(s));
    }
}
