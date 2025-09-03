
public class PrefixSum {

    public static int[] calcPrefixSum(int[] arr) {

        for (int i = 1; i < arr.length; i++) {
            arr[i] += arr[i - 1];
        }

        return arr;
    }

    public static void main(String[] args) {
        int[] array = {3, 7, 5, 21};

        array = calcPrefixSum(array);
        for (int arrElem : array) {
            System.err.println(arrElem);
        }
    }
}
