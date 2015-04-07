
/**
 * 最大回文子字符串。哎，算法太鸡巴难了，动态规划，规划你妹啊。最终还是放弃治疗，用O(N²)解决了。
 */
public class Test {
    public static void main(String args[]) {
        System.out.println("Hello IntelliJ IDEA!");
        Test test = new Test();
        String str = "hello world!";
        System.out.println(test.longestPalindrome(str));
    }

    private int mMaxLength = 1;
    private int mMaxIndex = 0;

    public String longestPalindrome(String str) {
        int length = str.length();
        for (int i = 0; i < length; i++) {
            //find longest odd palindrome with center i
            findPalindrome(str, length, i, 0);
            //find longest even palindrome with center i
            findPalindrome(str, length, i, 1);
        }
        return str.substring(mMaxIndex, mMaxIndex + mMaxLength);
    }

    private void findPalindrome(String str, int length, int i, int shift) {
        int left = i;
        int right = i + shift;
        while (left >= 0 && right < length && str.charAt(left) == str.charAt(right)) {
            if ((right - left + 1) > mMaxLength) {
                mMaxLength = right - left + 1;
                mMaxIndex = left;
            }
            left--;
            right++;
        }
    }
}
