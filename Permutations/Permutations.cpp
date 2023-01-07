#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void permuteInternal( vector<int>& nums, vector<int>& ds, vector<vector<int>>& comb, vector<bool>& freq ) {
        if ( ds.size() == nums.size() ) {
            comb.emplace_back( ds );
            return;
        }

        for ( int i = 0; i < nums.size(); i++ ) {
            if ( !freq[i] ) {
                ds.emplace_back( nums[i] );
                freq[i] = true;
                permuteInternal( nums, ds, comb, freq );
                ds.pop_back();
                freq[i] = false;
            }
        }
    }

    void permuteInternal2( vector<int>& nums, int idx, vector<vector<int>>& comb ) {
        if ( idx == nums.size() - 1 ) {
            comb.emplace_back( nums );
            return;
        }

        for ( int i = idx; i < nums.size(); i++ ) {
            swap( nums[i], nums[idx] );
            permuteInternal2( nums, idx + 1, comb );
            swap( nums[i], nums[idx] );
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> comb;
        vector<bool> freq( nums.size(), false );
        permuteInternal( nums, ds, comb, freq );
        permuteInternal2( nums, comb);
        return comb;
    }
};