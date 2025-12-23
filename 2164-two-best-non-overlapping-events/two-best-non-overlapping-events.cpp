#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Step 1: Sort events by end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> prefixMax(n, 0);

        // Step 2: Build prefix max array
        prefixMax[0] = events[0][2];
        for (int i = 1; i < n; ++i) {
            prefixMax[i] = max(prefixMax[i - 1], events[i][2]);
        }

        // Step 3: Iterate and calculate the maximum sum
        int result = 0;
        for (int i = 0; i < n; ++i) {
            // Current event's value
            int currentValue = events[i][2];
            
            // Use binary search to find the last non-overlapping event
            int low = 0, high = i - 1, bestIndex = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (events[mid][1] < events[i][0]) {
                    bestIndex = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            // Update result with max sum of current event + best non-overlapping
            if (bestIndex != -1) {
                result = max(result, currentValue + prefixMax[bestIndex]);
            } else {
                result = max(result, currentValue); // Single event case
            }
        }

        return result;
    }
};