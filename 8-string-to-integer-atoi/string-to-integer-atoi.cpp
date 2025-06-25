class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int sign = 1; //positive by default 
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

            // checking the min count is negative
            if (result * sign < numeric_limits<int>::min()) {
                return numeric_limits<int>::min();
            }
            // checking the min count is positive
            else if (result * sign > numeric_limits<int>::max()) {
                return numeric_limits<int>::max();
            }
        }

        return static_cast<int>(result * sign);
    }
};