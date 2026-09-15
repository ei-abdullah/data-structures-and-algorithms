import java.util.Arrays;

public class BinarySearch {
    public int search(int[] nums, int target) {
        int low=0, high = nums.length - 1;

        while (low <= high) {
            // Better than mid = (high + low) / 2;
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }

    static void main() {
        int[] nums = {-1,0,2,4,6,8};
        System.out.println(new BinarySearch().search(nums, 4));
    }
}
