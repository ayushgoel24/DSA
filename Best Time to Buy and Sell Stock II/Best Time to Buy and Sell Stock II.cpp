class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0; // To store the accumulated profit
        
        // Iterate through the price array starting from the second day
        for ( int i = 1; i < prices.size(); i++ ) {
            // If the price of the current day is greater than or equal to the price of the previous day
            // It indicates we can make a profit by selling on the current day after buying on the previous day
            if ( prices[i] >= prices[i - 1] ) {
                maxProfit += prices[i] - prices[i - 1]; // Add the difference to the total profit
            }
        }
        
        // Return the accumulated maximum profit
        return maxProfit; 
    }
};