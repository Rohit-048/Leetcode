#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minAbsValue = INT_MAX;
        int negativeCount = 0;

        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = matrix[i][j];
                totalSum += abs(val);
                if (val < 0) negativeCount++;
                minAbsValue = min(minAbsValue, abs(val));
            }
        }

        // If the count of negatives is odd, subtract twice the smallest absolute value
        if (negativeCount % 2 != 0) {
            totalSum -= 2 * minAbsValue;
        }

        return totalSum;
    }
};