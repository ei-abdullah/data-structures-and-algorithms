
public class ArrayConcatenation {

    public int[] getConcatenation(int[] nums) {
        int[] ans = new int[2 * nums.length];
        int idx = 0;
        for (int i = 0; i < 2; i++) {
            for (int num : nums) {
                ans[idx] = num;
                idx++;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3};

        ArrayConcatenation obj = new ArrayConcatenation();
        int[] result = obj.getConcatenation(nums);

        for (int num : result) {
            System.out.print(num + " ");
        }
    }
}
