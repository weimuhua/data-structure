//求一个无序数组中最小的数字
public class Solution {
    public int findMin(int[] num) {
        int i,min;
        min = num[0];
        for(i = 0;i < num.length;i++)
        {
            if (num[i] < min)
            {
                min = num[i];
            }
        }
        return min;
    }
}
