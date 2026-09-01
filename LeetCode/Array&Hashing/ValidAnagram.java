import java.util.Arrays;
import java.util.HashMap;

public class ValidAnagram {
    public static Boolean isAnagram(String s, String p) {
        if (s.length() != p.length()) {
            return false;
        }

        // Add the new characters to hashmap, and count its frequency for corresponding words
        HashMap<Character, Integer> sMap = new HashMap<>();
        HashMap<Character, Integer> pMap = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            sMap.put(s.charAt(i), sMap.getOrDefault(s.charAt(i), 0) + 1);
            pMap.put(p.charAt(i), pMap.getOrDefault(p.charAt(i), 0) + 1);
        }

        return sMap.equals(pMap);

        /*
            Time: O(n) or O(s + p)
            Space: O(n) or O(s + p)
         */
    }

    public static Boolean isAnagramSort(String s, String p) {
        if (s.length() != p.length()) {
            return false;
        }

        char[] sChars = s.toCharArray();
        char[] pChars = p.toCharArray();

        Arrays.sort(sChars);
        Arrays.sort(pChars);

        return Arrays.equals(sChars, pChars);

        /*
        Time: O(n.logn)
        Space: O(n)
         */
    }



    static void main() {
        String s = "anagram";
        String p = "nagaram";

        String t = "cat";
        String l = "rat";

        System.out.println(isAnagram(s, p));
        System.out.println(isAnagramSort(s, p));

        System.out.println(isAnagram(t, l));
        System.out.println(isAnagramSort(t, l));
    }
}
