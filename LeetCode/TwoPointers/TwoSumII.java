import java.util.Arrays;

public class TwoSumII {
    public int[] twoSum(int[] numbers, int target) {
        int left = 0;
        int right = numbers.length - 1;

        int[] result = new int[2];

        while (left < right) {
            if (numbers[left] + numbers[right] > target) {
                right--;
            } else if (numbers[left] + numbers[right] < target) {
                left++;
            } else if (numbers[left] + numbers[right] == target) {
                result[0] = left + 1;
                result[1] = right + 1;
                break;
            } else {
                result[0] = -1;
                result[1] = -1;
                break;
            }
        }

        return result;
    }

    static void main() {
        int[] nums = {2, 7, 11, 15};

        System.out.println(Arrays.toString(new TwoSumII().twoSum(nums, 9)));
    }
}
