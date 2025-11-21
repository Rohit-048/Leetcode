#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int result = 0;

        // Iterate over each character from 'a' to 'z'
        for (char c = 'a'; c <= 'z'; ++c) {
            int first = -1, last = -1;

            // Find the first and last occurrence of the character
            for (int i = 0; i < n; ++i) {
                if (s[i] == c) {
                    if (first == -1) {
                        first = i; // Set the first occurrence
                    }
                    last = i; // Update the last occurrence
                }
            }

            // If there are at least two occurrences
            if (first != -1 && last != -1 && first < last) {
                unordered_set<char> uniqueChars;

                // Collect all unique characters between first and last
                for (int i = first + 1; i < last; ++i) {
                    uniqueChars.insert(s[i]);
                }

                // Add the count of unique characters to the result
                result += uniqueChars.size();
            }
        }

        return result;
    }
};