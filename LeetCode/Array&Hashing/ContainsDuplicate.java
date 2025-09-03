
import java.util.HashSet;
import java.util.Set;

public class ContainsDuplicate {

    private static Boolean containsDuplicate(int[] arr) {
        Set<Integer> seen = new HashSet<>();

        for (int arrElems : arr) {
            if (seen.contains(arrElems)) {
                return true;
            } else {
                seen.add(arrElems);
            }
        }

        return false;
    }

    public static void main(String[] args) {
        int[] array = {1, 2, 3};

        System.err.println(containsDuplicate(array));
    }
}
