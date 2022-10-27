class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxSum = nums[0], currentSum = 0;
        
        for (int& num : nums) {
            currentSum += num;
            
            if ( currentSum > maxSum )
                maxSum = currentSum;
            
            if ( currentSum < 0 )
                currentSum = 0;
        }
        
        return maxSum;
    }
};