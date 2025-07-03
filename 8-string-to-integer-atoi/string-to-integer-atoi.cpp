class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        long long result = 0;
        int sign = 1;

        while (i < n && isspace(s[i])) {
            i++;
        }
        if ( i<n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i++] - '0');

            if (result > INT_MAX) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
        }
        return result * sign;
    }
};