class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // Return if size of nums < 3
        if (nums.size() < 3)
            return {};
        
        // Sorting the array
        sort(nums.begin(), nums.end());
        
        // If the first no in the sorted array is +ve, then the following nos are also +ve. Hence the sum would never go to 0.
        if (nums[0] > 0) 
            return {};
        
        vector<vector<int>> result;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            
            // If the number at ith index is +ve, the sum would never go to zero. Hence, break the loop.
            if (nums[i] > 0)
                break;
            
            // To avoid duplicate triplets, we want the last instance of the fixed no
            if (i>0 && nums[i] == nums[i-1])
                continue;
            
            // Searching using two pointer approach
            int low = i + 1, high = nums.size() - 1, sum = 0;
            
            while (low < high) {
                sum = nums[i] + nums[low] + nums[high];
                
                if (sum > 0) {
                    high--;
                } else if (sum < 0) {
                    low++;
                } else {
                    result.push_back({nums[i], nums[low], nums[high]});
                    // The below code is to avoid similar triplets. 
                    int current_low = low;
                    int current_high = high;
                    while (low < high && nums[low] == nums[current_low])
                        low++;
                    while (low < high && nums[high] == nums[current_high])
                        high--;
                }
            }
        }
        
        return result;
        
    }
};