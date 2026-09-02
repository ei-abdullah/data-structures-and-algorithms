import java.util.HashMap;

public class TwoSum {
    private static int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i=0; i<nums.length; i++) {
            int diff = target - nums[i];

            if (map.containsKey(diff)) {
                int keyIndex = map.get(diff);
                return new int[] {keyIndex, i};
            } else {
                map.put(nums[i], i);
            }
        }

        return new int[] {-1, -1};
    }

    static void main() {
        int[] nums = {3, 4, 5, 6};
        int target = 9;

        int[] result = twoSum(nums, target);
        System.out.println(result[0] + " " + result[1]);
    }
}
