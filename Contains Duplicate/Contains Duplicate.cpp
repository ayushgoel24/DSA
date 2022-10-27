class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, std::size_t> container;
        
        for ( std::size_t i = 0; i < nums.size(); i++ ) {
            if ( container.find( nums[i] ) != container.end() ) {
                return true;
            }
            container[ nums[i] ] =  i;
        }
        return false;
    }
};