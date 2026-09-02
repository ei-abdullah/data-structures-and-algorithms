import java.util.*;

// array of size 26 with each alphabet in string gets its own index

public class GroupAnagrams {
    private static List<List<String>> myGroupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<>();

        for (String str : strs) {
            char[] sortedCharArray = str.toCharArray();
            Arrays.sort(sortedCharArray);

            String sortedString = new String(sortedCharArray);

            if (map.containsKey(sortedString)) {
                map.get(sortedString).add(str);
            } else {
                List<String> list = new ArrayList<>();
                list.add(str);

                map.put(sortedString, list);
            }
        }

        return map.values().stream().toList();

        /*
        Time: O(m.nlogn)
            where n is the average length of input string
            and m is the length of input strings
         */
    }

    private static List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<>();

        for (String str : strs) {
            int[] count = new int[26];

            // flip the 0 to 1 for the indices for each alphabet
            for (char c : str.toCharArray()) {
                count[c - 'a']++;
            }

            // Create a string with hash between alphabet indices
            StringBuilder sb = new StringBuilder();
            for (int i: count) {
                sb.append("#");
                sb.append(i);
            }
            String key = sb.toString();

            if (map.containsKey(key)) {
                map.get(key).add(str);
            } else {
                map.put(key, new ArrayList<>(List.of(str)));
            }
        }

        return map.values().stream().toList();

        /*
        Time: O(m.n)
         */
    }

    static void main() {
        String[] strs = {"act","pots","tops","cat","stop","hat"};

        System.out.println(groupAnagrams(strs));
    }
}
