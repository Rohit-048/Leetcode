class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        vector<int> freq(26, 0); // to count the freq of each element in current window
        int left = 0, right = 0;

        while (right < n) {
            freq[s[right] - 'A']++;
            int maxi = *max_element(freq.begin(), freq.end());
            int window = right - left + 1;

            while (window - maxi > k) { // shrink the window until k
                freq[s[left] - 'A']--;
                left++;
                window = right - left + 1;
            }
            maxLen = max(maxLen, window);
            right++;
        }
        return maxLen;
    }
};

// freq[s[j] - 'A']++;
// is used to count the frequency of each uppercase English letter in a string,
// and it works like this:

// \U0001f50d Explanation:
// s[j] is a character (e.g., 'A', 'B', 'C', etc.)
// 'A' has ASCII value 65
// Subtracting 'A' shifts the ASCII value to start at index 0
// \U0001f4cc Example:

// s[j] = 'C';
// s[j] - 'A' = 'C' - 'A' = 67 - 65 = 2;
// So 'C' gets counted at freq[2].