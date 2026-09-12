/*
L - Maximum Left Height
R - Maximum Right Height
Formula - min(L, R) - height[i]
 */

public class TrappingRainWater {
    public int trap(int[] height) {
        int L = 0, R = height.length - 1;
        int maxLeft = height[L];
        int maxRight = height[R];

        int water = 0;
        int i = 0;

        int res = 0;

        while (L < R) {
            res = Math.min(maxLeft, maxRight) - height[i];
            if (res > 0) water += res;

            // Update maxLeft and maxRight
            if (maxLeft < height[L]) maxLeft = height[L];
            if (maxRight < height[R]) maxRight = height[R];

            if (maxLeft <= maxRight) {
                L++;
                i = L;
            } else {
                R--;
                i = R;
            }
        }

        return water;
    }

    static void main() {
        int[] height = {0,1,0,2,1,0,1,3,2,1,2,1};
        System.out.println(new TrappingRainWater().trap(height));
    }
}
