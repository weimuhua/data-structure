import java.util.HashMap;
import java.util.Map;

/**
 * Created by Wayne on 15/5/23.
 * LeetCode ZigZag Conversion
 */
public class Convert {
    public String convert(String s, int numRows) {
        if (numRows <= 1) {
            return s;
        }

        Map<Integer, StringBuilder> map = new HashMap<Integer, StringBuilder>();
        for (int i = 0; i < numRows; i++) {
            map.put(i, new StringBuilder());
        }

        int flag = 1;
        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            map.put(index, map.get(index).append(s.charAt(i)));
            if (index == 0) {
                flag = 1;
            }
            if (index == numRows - 1) {
                flag = -1;
            }
            index += flag;
        }

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < numRows; i++) {
            result.append(map.get(i).toString());
        }
        return result.toString();
    }
}
