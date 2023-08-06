class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map to store the sorted string to the vector of strings
        std::unordered_map<string, vector<string>> sorted_strings_map;

        // traverses through all strings in `strs`
        // creates a new string and sorts its chars
        // stores the current string against its sorted versions in `sorted_strings_map`
        for ( const auto& str : strs ) {
            string t = str;
            std::sort( t.begin(), t.end() );
            sorted_strings_map[t].push_back(str);
        }

        // vector to store the anagram groups
        vector<vector<string>> grouped_anagrams;
        // reserves the space in vector to avoid reallocating
        grouped_anagrams.reserve( sorted_strings_map.size() );
        
        // loop through the map and add strings
        for ( auto& str : sorted_strings_map ) {
            // move function allows grouped_anagrams to share resources from sorted_strings_map
            grouped_anagrams.push_back( std::move( str.second ) );
        }

        return grouped_anagrams;
    }
};