import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class TopKFrequentElements {
    public static int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> countMap = new HashMap<>();
        HashMap<Integer, List<Integer>> countArray = new HashMap<>();
        List<Integer> topK = new ArrayList<>(k);

        for (int num : nums) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }

        countMap.forEach((key, value) -> {
            countArray.computeIfAbsent(value, v -> new ArrayList<>()).add(key);
        });

        for (int i = nums.length; i >= 0; i--) {
            List<Integer> bucket = countArray.get(i);
            if (bucket != null && topK.size() < k) {
                topK.addAll(bucket);
            }
        }

        return topK.stream().mapToInt(Integer::intValue).toArray();
    }

    static void main() {
        int[] nums = {1,2};
        int k = 2;

        System.out.println(Arrays.toString(topKFrequent(nums, k)));
    }
}
