class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // base case: length of both strings must be same for them to be anagrams
        if ( s.length() != t.length() ) return false;

        // array to hold the occurance count of chars
        int array_occurance[26] = {0};

        // loops through both the strings. 
        // +1 for char in string s
        // -1 for char in string t
        for ( int i = 0; i < s.length(); i++ ) {
            array_occurance[s[i] - 'a']++;
            array_occurance[t[i] - 'a']--;
        }

        // if count of any char is not zero, we return false
        for ( int i = 0; i < 26; i++ )
            if ( array_occurance[i] ) return false;

        return true;
    }
};