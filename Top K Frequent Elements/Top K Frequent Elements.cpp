class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create a map to store the frequency of each number
        map<size_t, size_t> numberFrequencyMap;
        
        // Iterate through the nums vector and populate the frequency map
        for( auto& num : nums ) {
            numberFrequencyMap[num]++;
        }

        // Create a max-heap (priority queue) that can store pairs of frequency and number
        priority_queue<pair<int, int>> maxFrequencyContainer;
        
        // Populate the max-heap with the frequency and number
        for ( auto& it : numberFrequencyMap ) {
            maxFrequencyContainer.emplace( make_pair( it.second, it.first ) );
        }

        // Create a container to store the top k frequent elements
        vector<int> maxFrequencyElementsContainer;
        
        // Extract the top k frequent elements from the max-heap and populate the container
        for ( int i = 0; i < k; i++ ) {
            maxFrequencyElementsContainer.emplace_back( maxFrequencyContainer.top().second );
            maxFrequencyContainer.pop();
        }

        // Return the container with top k frequent elements
        return maxFrequencyElementsContainer;
    }
};