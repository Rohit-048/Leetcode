class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n = s.length();
        int i = 0;

        while (i < n) {
            string group = "";

            for (int j = 0; j < k; ++j) {
                if (i < n)
                    group += s[i++];
                else
                    group += fill;
            }

            res.push_back(group);
        }

        return res;
    }
};
