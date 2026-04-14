#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int rLen = robot.size();
        int fLen = factory.size();

        // Sort robots and factories based on their positions
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // dp array to store minimum distances, initialized to large value
        vector<vector<long long>> dp(fLen + 1, vector<long long>(rLen + 1, LLONG_MAX));
        dp[0][0] = 0;

        // Dynamic Programming loop
        for (int j = 1; j <= fLen; ++j) {
            int factoryPos = factory[j - 1][0];
            int limit = factory[j - 1][1];

            // Use the factory `j-1` to repair robots
            for (int i = 0; i <= rLen; ++i) {
                // Carry over the previous minimum
                dp[j][i] = dp[j - 1][i];

                // Calculate cost if this factory repairs up to its limit
                long long cost = 0;
                for (int k = 1; k <= limit && i - k >= 0; ++k) {
                    cost += abs(robot[i - k] - factoryPos);
                    if (dp[j - 1][i - k] != LLONG_MAX) {
                        dp[j][i] = min(dp[j][i], dp[j - 1][i - k] + cost);
                    }
                }
            }
        }

        return dp[fLen][rLen];
    }
};
