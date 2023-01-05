class Solution {
public:
    void findCombinationSum(vector<int>& candidates, int idx, vector<vector<int>>& combinations, vector<int>& ds) {
        
        combinations.emplace_back(ds);
        
        for (int i=idx; i<candidates.size(); i++) {
            // This is to avoid duplicacy of combinations (since we wont pick similar nos at same index)
            if (i > idx && (candidates[i] == candidates[i-1])) continue;
            // No point iterating further since the array value (sorted in ascending) has exceeded target
            ds.emplace_back(candidates[i]);
            findCombinationSum(candidates, i+1, combinations, ds);
            ds.pop_back();
        }  
    } 
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> combinations;
        vector<int> ds;
        findCombinationSum(nums, 0, combinations, ds);
        return combinations;
    }
};