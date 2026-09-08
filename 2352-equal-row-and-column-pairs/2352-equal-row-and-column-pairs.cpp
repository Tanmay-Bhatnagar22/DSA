class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> rowCount;

        for (int i = 0; i < n; i++) {
            string key;
            for (int val : grid[i]) {
                key += to_string(val) + ",";
            }
            rowCount[key]++;
        }

        int result = 0;
        for (int j = 0; j < n; j++) {
            string key;
            for (int i = 0; i < n; i++) {
                key += to_string(grid[i][j]) + ",";
            }
            if (rowCount.count(key)) {
                result += rowCount[key];
            }
        }

        return result;
    }
};