//字符串中最长的无重复的子串
public static int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        if (s.length() == 1) return 1;
        int length = 0;
        String part = "" + s.charAt(0);
        for (int i = 1; i < s.length(); i++)
        {
            // 字符不存在
            if (part.indexOf(s.charAt(i)) == -1)
            {
                part = part + s.charAt(i);
            }
            else
            {
                int index = part.indexOf(s.charAt(i));
                if (part.length() > length)
                {
                    // 获得子串的长度
                    length = part.length();
                }
                part = part.substring(index + 1);
                i--;
            }
        }
        return part.length() > length ? part.length() : length;
    }
