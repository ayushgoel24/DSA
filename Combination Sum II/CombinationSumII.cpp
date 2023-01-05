class Solution {
public:
    
    void findCombinationSum(vector<int>& candidates, int target, int idx, vector<vector<int>>& combinations, vector<int>& ds) {
    
        if (target == 0) {
            combinations.emplace_back(ds);
            return;
        }
        
        for (int i=idx; i<candidates.size(); i++) {
            if (i > idx && (candidates[i] == candidates[i-1])) continue;
            if (candidates[i] > target) break;
            ds.emplace_back(candidates[i]);
            findCombinationSum(candidates, target-candidates[i], i+1, combinations, ds);
            ds.pop_back();
        }

        
    } 
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> ds;
        findCombinationSum(candidates, target, 0, combinations, ds);
        return combinations;
    }
};