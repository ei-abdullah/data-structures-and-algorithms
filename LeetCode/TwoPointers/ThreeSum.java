import java.util.*;

public class ThreeSum {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = nums.length - 1;

            while (j < k) {
                if (nums[j] + nums[k] < -(nums[i])) {
                    j++;
                } else if (nums[j] + nums[k] > -(nums[i])) {
                    k--;
                } else {
                    result.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    j++;

                    while (nums[j] == nums[j - 1] && j < k) {
                        j++;
                    }
                }
            }
        }

        return result;
    }

    static void main() {
        int[] nums = {-1, 0, 1, 2, -1, -4};


        System.out.println(Arrays.toString(new ThreeSum().threeSum(nums).toArray()));
    }
}