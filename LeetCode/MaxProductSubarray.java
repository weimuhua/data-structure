/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/
public class Solution {
    public int maxProduct(int[] A) {
        int maxHerePre = A[0];
        int minHerePre = A[0];
        int maxHere = 0,minHere = 0,maxSoFar = A[0];
        for(int i = 1;i < A.length;i++)
        {
            maxHere = Math.max(Math.max(maxHerePre*A[i],minHerePre*A[i]),A[i]);
            minHere = Math.min(Math.min(maxHerePre*A[i],minHerePre*A[i]),A[i]);
            maxSoFar = Math.max(maxHere,maxSoFar);
            maxHerePre = maxHere;
            minHerePre = minHere;
        }
        return maxSoFar;
    }
}
