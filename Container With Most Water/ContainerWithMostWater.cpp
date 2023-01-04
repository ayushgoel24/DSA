#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int low = 0, high = height.size() - 1;
        int maxWaterContent = 0;

        while( low < high ) {
            int waterContent = ( high - low ) * std::min( height[low], height[high] );
            maxWaterContent = std::max( waterContent, maxWaterContent);
            ( height[low] < height[high] ) ? low++ : high--;
        }

        return maxWaterContent;
    }
};