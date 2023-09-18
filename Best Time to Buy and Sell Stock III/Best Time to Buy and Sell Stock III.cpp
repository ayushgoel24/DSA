class Solution {
public:

    int maxProfit(vector<int>& prices) {
        // Variables for two buy-sell transactions
        int buy1 = INT_MAX,        // Minimum price for the 1st buy
            buy2 = INT_MAX,        // Minimum price for the 2nd buy, after considering profit from the 1st transaction
            profit1 = INT_MIN,     // Maximum profit after 1st sell
            profit2 = INT_MIN;     // Maximum profit after 2nd sell
        
        for ( auto& price : prices ) {
            // Find the lowest price for the 1st buy
            buy1 = min( buy1, price );
            
            // Find the maximum profit after the 1st sell
            profit1 = max( profit1, price - buy1 );

            // For the 2nd buy, we consider the profit from the 1st sell 
            // Hence, the effective price becomes (price - profit1)
            // This means we are using the profit from the first transaction to buy again
            buy2 = min( buy2, price - profit1 );
            
            // Find the maximum profit after the 2nd sell
            profit2 = max( profit2, price - buy2 );
        }

        // Return the maximum profit after the second transaction
        return profit2;
    }
};