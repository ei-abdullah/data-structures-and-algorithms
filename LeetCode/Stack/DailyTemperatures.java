import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class DailyTemperatures {

    public int[] dailyTemperatures(int[] temperatures) {
        int[] result = new int[temperatures.length];
        Deque<int[]> stk = new ArrayDeque<>();

        for (int i=temperatures.length-1; i>=0; i--) {
            while(!stk.isEmpty() && stk.peek()[0] <= temperatures[i]) {
                stk.pop();
            }

            if (stk.isEmpty()) {
                result[i] = 0;
            } else {
                result[i] = stk.peek()[1] - i;
            }

            stk.push(new int[]{temperatures[i], i});
        }

        return result;
    }

    static void main() {
        int[] temperatures = {73,74,75,71,69,72,76,73};
        System.out.println(Arrays.toString(new DailyTemperatures().dailyTemperatures(temperatures)));
    }
}
