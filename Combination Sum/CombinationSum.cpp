#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void combinationSumInternal(vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& comb, int idx) {
        if ( target <= 0 || idx == candidates.size() ) {
            if ( target == 0 ) {
                comb.emplace_back( ds );
            }
            return;
        }

        if ( candidates[idx] <= target ) {
            ds.emplace_back(candidates[idx]);
            combinationSumInternal(candidates, target - candidates[idx], ds, comb, idx);
            ds.pop_back();
        }
        combinationSumInternal(candidates, target, ds, comb, idx+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> comb;
        vector<int> ds;
        combinationSumInternal(candidates, target, ds, comb, 0);
        return comb;
    }
};