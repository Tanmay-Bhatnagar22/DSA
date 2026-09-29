class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Path length must be even, and endpoints must be valid
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        // dp[i][j] has bit b set if some path to (i, j) has balance b
        vector<vector<bitset<205>>> dp(m, vector<bitset<205>>(n));
        dp[0][0][1] = 1;  // first cell is '(' so balance = 1

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                bitset<205> prev;
                if (i > 0) prev |= dp[i - 1][j];
                if (j > 0) prev |= dp[i][j - 1];

                if (grid[i][j] == '(') dp[i][j] = prev << 1;  // balance + 1
                else                   dp[i][j] = prev >> 1;  // balance - 1 (balance 0 falls off, dropping invalid paths)
            }
        }
        return dp[m - 1][n - 1][0];  // balance 0 at the end means valid
    }
};