#include <iostream>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, std::size_t> num_to_index;
        vector<int> result;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (num_to_index.find(target - nums[i]) != num_to_index.end()) {
                result.push_back(num_to_index[target - nums[i]]);
                result.push_back(i);
                return result;
            }
            num_to_index[nums[i]] = i;
        }
        return {};
    }
};