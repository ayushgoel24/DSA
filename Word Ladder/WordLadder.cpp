class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Queue to hold pairs of word and the number of transformations to reach that word
        queue<pair<string, int>> wordsToTransform;
        // Initialize the queue with the beginWord and a transformation count of 1
        wordsToTransform.push({beginWord, 1});

        // Convert the wordList to a set for efficient lookup and deletion
        unordered_set<string> remainingWords(wordList.begin(), wordList.end());
        // If the endWord is not in the wordList, no ladder exists
        if (remainingWords.find(endWord) == remainingWords.end()) return 0;
        // Remove the beginWord from the set, as it is already being considered
        remainingWords.erase(beginWord);

        while (!wordsToTransform.empty()) {
            string currentWord = wordsToTransform.front().first;
            int transformationSteps = wordsToTransform.front().second;
            wordsToTransform.pop();

            // If the currentWord is the endWord, return the number of transformation steps
            if (currentWord == endWord) return transformationSteps;

            // Try transforming each character of the currentWord
            for (int i = 0; i < currentWord.size(); i++) {
                char originalChar = currentWord[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    currentWord[i] = c;
                    // Check if the new word is in the remainingWords set
                    if (remainingWords.find(currentWord) != remainingWords.end()) {
                        // If so, add it to the queue with an incremented step count
                        wordsToTransform.push({currentWord, transformationSteps + 1});
                        // Remove the new word from the set to prevent revisiting
                        remainingWords.erase(currentWord);
                    }
                }
                // Revert the change to try a new transformation in the next iteration
                currentWord[i] = originalChar;
            }
        }
        // If no ladder was found to transform beginWord to endWord, return 0
        return 0;
    }
};
