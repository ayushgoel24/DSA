// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>
#include <string.h>

int minNumberOfFrogs(char* croakOfFrogs) {
    int charLength = strlen(croakOfFrogs);
    int charOccurance[4];
    int countOfBeginningN = 0, maxNumberOfHorses = 0;
    for (int i=0; i<charLength; i++) {
        switch (croakOfFrogs[i]) {
            case 'c':
                ++charOccurance[0];
                ++countOfBeginningN;
                break;
            case 'r':
                if (!charOccurance[0]--)
                    return -1;
                ++charOccurance[1];
                break;
            case 'o':
                if (!charOccurance[1]--)
                    return -1;
                ++charOccurance[2];
                break;
            case 'a':
                if (!charOccurance[2]--)
                    return -1;
                ++charOccurance[3];
                break;
            case 'k':
                if (!charOccurance[3]--)
                    return -1;
                --countOfBeginningN;
                break;
            default:
                return -1;
        }
        maxNumberOfHorses = std::max(maxNumberOfHorses, countOfBeginningN);
    }
    return charOccurance[0] || charOccurance[1] || charOccurance[2] || charOccurance[3] ? -1 : maxNumberOfHorses;
}

int main() {
    // Write C++ code here
    std::string s = "crcoakrook";
    int a = minNumberOfFrogs(&s[0]);
    std::cout << a;

    return 0;
}