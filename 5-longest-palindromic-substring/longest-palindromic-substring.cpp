class Solution {
public:
    // we are expanding the palindrome around the center by left-- and right++
    int expandingPalindrome(int left, int right, string& s) {

        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int left = 0, right = 0;

        for (int i = 0; i < n; i++) {
            int len1 = expandingPalindrome(i, i, s); // for the odd length
            int len2 = expandingPalindrome(i, i + 1, s); // this is for even length
            int len = max(len1, len2);
            if (len > right - left) {
                left = i - (len - 1) / 2;
                right = i + len / 2;
            }
        }

        return s.substr(left, right - left + 1);
    }
};

// \U0001f527 Core Idea:
// A palindrome mirrors around its center. So for each index i in the string:

// Treat it as a center of an odd-length palindrome.
// Also treat i and i+1 as the center of an even-length palindrome.
// Then expand outward from the center while characters match.

// \U0001f504 Step-by-Step for "babad":
// 1️⃣ Center at index i = 0 → 'b'

// Try odd-length: expand "b" → no match → max length = 1 → "b"
// Try even-length: "ba" → not equal → length = 0
// ✅ Longest so far: "b" (len = 1)

// 2️⃣ Center at index i = 1 → 'a'

// Odd: expand "a" → "bab" → match → continue → mismatch at ends → length = 3 → "bab"
// Even: "ab" → not equal → length = 0
// ✅ Longest so far: "bab" (len = 3)

// 3️⃣ Center at index i = 2 → 'b'

// Odd: expand "b" → "aba" → match → length = 3 → "aba"
// Even: "ba" → not equal → length = 0
// \U0001f7f0 Tie with previous → can return either "bab" or "aba"

// 4️⃣ Center at index i = 3 → 'a'

// Odd: expand "a" → no extension → length = 1
// Even: "ad" → not equal → length = 0
// ❌ No update

// 5️⃣ Center at index i = 4 → 'd'

// Odd: only "d" → length = 1
// Even: out of bounds → skip
// ❌ No update

// ✅ Final Answer:
// Longest palindromic substring = "bab" or "aba" (both valid).

// \U0001f4e6 Time Complexity:
// O(n²) — Because for each center, you may expand up to the full string.
// O(1) space — Just using variables for tracking indices.
