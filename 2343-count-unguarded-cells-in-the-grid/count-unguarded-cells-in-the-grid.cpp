#include <vector>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // 0: unguarded, 1: guarded, 2: wall/guard
        
        // Mark walls and guards on the grid
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2; // Mark walls
        }
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2; // Mark guards
        }

        // Directions for north, east, south, west
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        // Simulate guard vision
        for (const auto& guard : guards) {
            for (const auto& dir : directions) {
                int x = guard[0], y = guard[1];
                while (true) {
                    x += dir.first;
                    y += dir.second;
                    
                    // Stop if out of bounds or encountering a wall/guard
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 2) break;
                    
                    // Mark the cell as guarded if it is not already guarded
                    if (grid[x][y] == 0) {
                        grid[x][y] = 1;
                    }
                }
            }
        }

        // Count unguarded cells
        int unguardedCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unguardedCount++;
                }
            }
        }

        return unguardedCount;
    }
};