public class ContainerWithMostWater {
    // Area = (right - left) * min(height[i], height[j])

    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxArea = 0;

        while (left < right) {
            maxArea = Math.max(maxArea, (right - left) * Math.min(height[left], height[right]));

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }

    static void main() {
        int[] height = {1,7,2,5,4,7,3,6};
        System.out.println(new ContainerWithMostWater().maxArea(height));
    }
}
