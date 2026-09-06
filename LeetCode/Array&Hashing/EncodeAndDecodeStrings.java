import java.util.ArrayList;
import java.util.List;

public class EncodeAndDecodeStrings {
    public static String myEncode(List<String> strs) {
        StringBuilder sb = new StringBuilder();

        for (String str : strs) {
            int length = str.length();
            if (length >= 10) {
                double d = length / 10.0;
                sb.append(d).append(str);
            } else {
                sb.append(length).append(str);
            }

        }

        System.out.println();
        return sb.toString();
    }

    public static List<String> myDecode(String str) {
        List<String> strs = new ArrayList<>();
        int length;

        for (int i = 0; i < str.length(); i++) {
            if (Character.isDigit(str.charAt(i))) {
                if (i + 2 < str.length() && str.charAt(i + 1) == '.' && Character.isDigit(str.charAt(i + 2))) {
                    length = Integer.parseInt(String.valueOf(str.charAt(i)) + str.charAt(i + 2));
                    strs.add(str.substring(i + 3, i + 3 + length));
                    i = i + 3 + length - 1;
                } else {
                    length = Integer.parseInt(String.valueOf(str.charAt(i)));
                    strs.add(str.substring(i + 1, i + 1 + length));
                    i = i + 1 + length - 1;
                }
            }
        }

        return strs;
    }

    /* ------------------------------ ------------------------------ ------------------------------ */

    public static String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();

        for (String str : strs) {
            int length = str.length();
            sb.append(length).append("#").append(str);
        }

        return sb.toString();

    }

    public static List<String> decode(String str) {
        List<String> strs = new ArrayList<>();

        for (int i=0; i<str.length(); i++) {
            int hashIndex = str.indexOf("#", i);
            int length = Integer.parseInt(str.substring(i, hashIndex));
            strs.add(str.substring(hashIndex+1, hashIndex+1+length));
            i = hashIndex + length;
        }

        return strs;

    }

    static void main() {

//        List<String> strs = List.of("Hello", "World");
//        List<String> strs = List.of("we","say",":","yes","!@#$%^&*()");
        List<String> strs = List.of("The quick brown fox", "jumps over the", "lazy dog", "1234567890", "abcdefghijklmnopqrstuvwxyz");

        System.out.println(decode(encode(strs)));
    }
}
