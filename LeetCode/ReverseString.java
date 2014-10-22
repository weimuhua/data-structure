/*
Given an input string, reverse the string word by word.
For example,
Given s = "the sky is blue",
return "blue is sky the".
*/
public class Solution {
    public String reverseWords(String s) {
        if (s == null)
            return "";
        int i = 0;
        String newStr = "";
        String word = "";
        while (i < s.length()) {
            char c = s.charAt(i);
            if (c == ' ') {
                if (newStr != "" && word != "")
                    newStr = word + " " + newStr;
                if (newStr == "" && word != "")
                    newStr = word;
                word = "";
            } else {
                word += c;
            }
            i++;
        }
        if (newStr != "" && word != "")
            newStr = word + " " + newStr;
        if (newStr == "" && word != "")
            newStr = word;
        return newStr;
    }
}
