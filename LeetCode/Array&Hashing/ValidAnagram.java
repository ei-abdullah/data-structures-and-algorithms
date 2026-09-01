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
            Time:
            Space:
         */
    }

    static void main() {
        String s = "anagram";
        String p = "nagaram";

        String t = "cat";
        String l = "rat";

        System.out.println(isAnagram(s, p));
        System.out.println(isAnagram(t, l));
    }
}
