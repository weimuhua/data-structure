/**
 *
 * implemantation of atoi in Java.
 */
public class Test {
    public static void main(String args[]) {
        String str = "1";
        System.out.print("atoi(" + str + ") : " + atoi(str));
    }

    private static int atoi(String str) {
        if (str == null || str.length() == 0) {
            return 0;
        }
        int length = str.length();
        int num = 0;
        int index = 0;
        int sign = 1;
        int signCount = 0;
        char ch;
        while (index < length && str.charAt(index) == ' ') {
            index++;
        }
        if (index >= length) {
            return 0;
        }
        if (str.charAt(index) == '+') {
            signCount++;
            index++;
        }
        if (str.charAt(index) == '-') {
            sign = -1;
            signCount++;
            index++;
        }
        if (signCount >= 2) {
            return 0;
        }
        if (index >= length) {
            return 0;
        }
        while (index < length) {
            ch = str.charAt(index);
            if (ch < '0' || ch > '9') {
                break;
            }
            if (Integer.MAX_VALUE / 10 < num || (Integer.MAX_VALUE / 10 == num && Integer.MAX_VALUE % 10 < (ch - '0'))) {
                return sign == -1 ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            num = num * 10 + (ch - '0');
            index++;
        }
        return sign * num;
    }
}
