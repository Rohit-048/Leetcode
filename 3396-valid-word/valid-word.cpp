class Solution {
public:
    bool isValid(string word) {
        int len = word.size();
        if (len < 3)
            return false;

        int digit = 0, vowel = 0, consonant = 0;
        string vowelsList = "aeiouAEIOU";
        for (char c : word) {
            if (isalpha(c)) {
                if (vowelsList.find(c) != string::npos) {
                    vowel++;
                } else {
                    consonant++;
                }
            } else if (!isdigit(c)) {
                return false;
            }
        }
        return vowel >= 1 && consonant >= 1;
    }
};