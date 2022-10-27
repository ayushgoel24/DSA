class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int max_product_till_now = nums[0], min_product_till_now = nums[0], max_product_so_far = nums[0];
        
        for (std::size_t i = 1; i < nums.size(); i++) {
            
            auto tmp_max = std::max({nums[i], nums[i] * max_product_till_now, nums[i] * min_product_till_now});
            
            min_product_till_now = std::min({nums[i], nums[i] * max_product_till_now, nums[i] * min_product_till_now});
            
            max_product_till_now = tmp_max;
            
            max_product_so_far = std::max({max_product_till_now, max_product_so_far});
        }
    
    return max_product_so_far;
    }
};