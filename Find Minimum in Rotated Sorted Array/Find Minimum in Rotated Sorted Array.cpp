class Solution {
public:
    int findMin(vector<int>& nums) {
        int minValue = nums[0];
        for (std::size_t i = 1; i < nums.size(); i++) {
            if (nums[i] < minValue)
                minValue = nums[i];
        }
        return minValue;
    }
};