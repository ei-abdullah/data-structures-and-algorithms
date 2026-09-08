import java.util.Arrays;

public class ProductsOfArrayExceptSelf {

    public int[] productExceptSelf(int[] nums) {
        int[] left = new int[nums.length];
        int[] right = new int[nums.length];

        left[0] = nums[0];
        right[nums.length-1] = nums[nums.length-1];

        for (int i=1; i<nums.length; i++) {
            left[i] = nums[i] * left[i-1];
        }

        for (int i=nums.length-2; i>=0; i--) {
            right[i] = nums[i] * right[i+1];
        }

        for (int i=0; i<nums.length; i++) {
            if (i==0) {
                nums[i] = right[i+1];
            } else if (i==nums.length-1) {
                nums[i] = left[i-1];
            } else {
                nums[i] = left[i-1] * right[i+1];
            }
        }

        return nums;
    }

    static void main() {
        int[] nums = {1, 2, 3, 4};

        System.out.println(Arrays.toString(new ProductsOfArrayExceptSelf().productExceptSelf(nums)));
    }
}
