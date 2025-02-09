// 2047. Number of Valid Words in a Sentence
// https://leetcode.com/problems/number-of-valid-words-in-a-sentence/description/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isLower(const char letter) {
        return 'a' <= letter && letter <= 'z';
    }
    
    int countValidWords(string sentence) {
        const size_t size = sentence.size();
        
        vector<string> words;
        unsigned int validWordsCount = 0;
        const string puncuations = "!.,";
        
        // 1. Dividing the sentence into words
        unsigned int wordStartPos = 0;
        for (int i = 0; i <= size; ++i) {  // Use `<= size` to correctly handle last word
            if (i == size || sentence[i] == ' ') {
                if (wordStartPos < i) {  // Ensure non-empty words
                    const unsigned int wordCount = i - wordStartPos;
                    const string subString = sentence.substr(wordStartPos, wordCount);
                
                    words.push_back(subString);
                }

                // Skip consecutive spaces
                while (i < size && sentence[i] == ' ') { i++; }

                wordStartPos = i;  // Update start position for the next word
            }
        }
        
        // 2.determining if those words are valid or no
        for (const string& word : words) {
            // if '-' appears more than once
            if (count(word.begin(), word.end(), '-') > 1) { continue; }
            
            bool isValid = true;
            
            for (int i = 0; i < word.size(); ++i) {
                // NO DIGITS
                if ('0' <= word[i] && word[i] <= '9') {
                    isValid = false;
                    break;
                }
                
                if (word[i] == '-') {
                    if (i == 0 || i == word.size() - 1) {
                        isValid = false;
                        break;
                    }
                    
                    if (!(isLower(word[i - 1]) && isLower(word[i + 1]))) {
                        isValid = false;
                        break;
                    }
                }
                
                // when puncuation is not at the end of a word
                if (i < word.size() - 1 &&
                    puncuations.find(word[i]) != string::npos) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                cout << "Current Word: " << word << endl;
                validWordsCount++;
            }
        }
        
        return validWordsCount;
    }
};

/*
int main() {
    vector<string> testCases = {
//        "cat   and  dog",
//        "!this  1-s b8d!",
//        "alice and  bob are playing stone-game10",
        "he bought 2 pencils, 3 erasers, and 1  pencil-sharpener.",
//        "-"
    };
    
    for (string testcase: testCases) {
        cout << Solution().countValidWords(testcase) << endl;
    }

    return 0;
}
*/
