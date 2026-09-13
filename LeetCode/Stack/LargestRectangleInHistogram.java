import java.util.ArrayDeque;
import java.util.Deque;

public class LargestRectangleInHistogram {

    public int largestRectangleArea(int[] heights) {
        Deque<Integer> stk = new ArrayDeque<>();
        int maxArea = 0;
        int n = heights.length;

        int i = 0;

        while (i < heights.length) {
            if (stk.isEmpty() || heights[i] >= heights[stk.peek()]) {
                stk.push(i);
                i++;
            } else {
                int top = stk.pop();
                int right = i - 1;
                int left = stk.isEmpty() ? -1 : stk.peek();
                int area = heights[top] * (right - left);
                maxArea = Math.max(maxArea, area);
            }
        }

        while (!stk.isEmpty()) {
            int top = stk.pop();
            int width = stk.isEmpty() ? i : i - stk.peek() - 1;
            int area = heights[top] * width;
            maxArea = Math.max(maxArea, area);
        }

        return maxArea;
    }

    static void main() {
//        int[] heights = {2,8,5,7};
        int[] heights = {7, 1, 7, 2, 2, 4};
        System.out.println(new LargestRectangleInHistogram().largestRectangleArea(heights));
    }
}
