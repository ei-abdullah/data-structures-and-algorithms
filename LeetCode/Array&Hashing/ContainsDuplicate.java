import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;

public class ContainsDuplicate {
    public ContainsDuplicate() {
    }

    public static Boolean containsDuplicateBrute(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;

        /*
            Time: O(n^2)
            Space: -
         */
    }

    public static Boolean containsDuplicateSort(int[] nums) {
        int[] sortedNums = Arrays
                .stream(nums)
                .sorted()
                .toArray();

        for (int i = 0; i < sortedNums.length - 1; i++) {
            if (sortedNums[i] == sortedNums[i + 1]) {
                return true;
            }
        }

        return false;

        /*
            Time: O(nlogn)
            Space: O(1)
         */
    }

    public static Boolean containsDuplicateHash(int[] nums) {
        HashSet<Integer> set = new HashSet<>();

        for (int num : nums) {
            if (set.contains(num)) {
                return true;
            } else {
                set.add(num);
            }
        }

        return false;

        /*
            Time: O(n)
            Space: O(n)
         */
    }

    static void main() {
        int[] nums = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

        System.out.println(containsDuplicateBrute(nums));
        System.out.println(containsDuplicateSort(nums));
        System.out.println(containsDuplicateHash(nums));
    }
}
