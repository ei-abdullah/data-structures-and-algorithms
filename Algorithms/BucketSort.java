import java.util.*;
import java.util.LinkedList;

public class BucketSort {

    public static int[] sort(int[] array, int bucketSize) {
        if (array == null || array.length == 0 || bucketSize <= 0) {
            return new int[]{};
        }

        // find the min and max values in array
        int minValue = array[0];
        int maxValue = array[0];

        for (int value: array) {
            if (value < minValue) {
                minValue = value;
            } else if (value > maxValue) {
                maxValue = value;
            }
        }

        // get range to ensure value goes into correct bucket
        double range = Math.ceil((double) (maxValue - minValue) + 1) / bucketSize;

        // create bucket
        List<Integer>[] buckets = new LinkedList[bucketSize];

        for (int i=0; i<bucketSize; i++) {
            buckets[i] = new LinkedList<>();
        }

        // Insert the value into each bucket
        for (int value: array) {
            int bucketIndex = (int) ((value - minValue) / range);
            buckets[bucketIndex].add(value);
        }

        // sort each bucket
        for (List<Integer> bucket: buckets) {
            Collections.sort(bucket);
        }

        // add bucket value back into original array
        int index = 0;
        for (List<Integer> bucket: buckets) {
            for (int value: bucket) {
                array[index++] = value;
            }
        }

        return array;
    }

    static void main() {
        List<Integer> list = Arrays.asList(3, 7, 21, 5);

        System.out.println(Arrays.toString(sort(list.stream().mapToInt(Integer::intValue).toArray(), 2)));
    }
}
