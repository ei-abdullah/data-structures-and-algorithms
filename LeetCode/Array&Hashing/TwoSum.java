
import java.util.HashMap;

public class TwoSum {

    public static int[] twoSum(int[] nums, int target) {

        int diff;

        HashMap<Integer, Integer> valHashMap = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            diff = target - nums[i];

            if (valHashMap.containsKey(diff)) {
                return new int[]{valHashMap.get(diff), i};
            }

            valHashMap.put(nums[i], i);
        }

        return new int[]{};
    }

    public static void main(String[] args) {
        int[] nums = {2, 1, 5, 3};
        int[] funcValues = twoSum(nums, 4);

        for (int elem : funcValues) {
            System.out.println(elem);
        }

    }
}
