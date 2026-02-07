#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int countB = 0, minDeletions = 0;
        
        for (char c : s) {
            if (c == 'a') {
                // Current 'a' needs all preceding 'b's to be deleted
                minDeletions = min(minDeletions + 1, countB);
            } else {
                // Increment the count of 'b'
                countB++;
            }
        }
        
        return minDeletions;
    }
};
