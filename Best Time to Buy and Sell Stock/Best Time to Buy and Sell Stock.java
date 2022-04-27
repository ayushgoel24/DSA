class Solution {
    public int maxProfit(int[] prices) {
        int min = prices[0], max = 0;
        for (int i = 1; i < prices.length; i++) {
            if (min > prices[i]) {
                min = prices[i];
            } else if (prices[i] - min > max) {
                max = prices[i] - min;
            } 
        }
        return max;
    }
}