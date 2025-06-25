class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int sign = 1; // positive by default
        int n = s.length();

        // to check for leading whitespaces
        while (i < n && isspace(s[i])) {
            i++;
        }
        // to check for any sign positive or negative
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i++] == '+') ? 1 : -1;
        }

        // finding the actual result in digits
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i++] - '0');

            if (result >
                INT_MAX) { // if it is more then int max so it will also be less
                           // then int min so just return that value first
                return sign == -1 ? INT_MIN : INT_MAX;
            }
        }

        return result * sign;
    }
};