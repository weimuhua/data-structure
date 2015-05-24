/**
 * Created by Wayne on 15/5/23.
 * LeetCode 回文数。
 */
public class Palindrome {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x >= 0 && x <= 9) {
            return true;
        }

        String str = String.valueOf(x);
        int len = str.length();
        int j = len / 2 - 1;
        if (j == 0) {
            j++;
        }
        boolean result = true;
        for (int i = 0; i < j; i++) {
            if (str.charAt(i) != str.charAt(len - 1 - i)) {
                result = false;
                break;
            }
        }
        return result;
    }
}
