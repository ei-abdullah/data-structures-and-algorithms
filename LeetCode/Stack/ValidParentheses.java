import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Stack;

public class ValidParentheses {

    public boolean isValidOld(String s) {
        if (s.length() % 2 != 0) {
            return false;
        }

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

    public boolean isValid(String s) {
        if (s.length() % 2 != 0) return false;

        Deque<Character> stk = new ArrayDeque<>();

        for (char c: s.toCharArray()) {
            if (c == '(') stk.push(')');
            else if (c == '[') stk.push(']');
            else if (c == '{') stk.push('}');
            else if (stk.isEmpty() || stk.pop() != c) return false;
        }

        return stk.isEmpty();
    }

    static void main() {
        String s = "[]{}";
        System.out.println(new ValidParentheses().isValid(s));
    }
}
