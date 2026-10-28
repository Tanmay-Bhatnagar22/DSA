class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int mx = 0;
        for (auto& row : grid)
            for (int v : row) mx = max(mx, v);

        int K = 1;
        while (K <= mx) K <<= 1;   // all XOR results are < K

        vector<vector<char>> prev(n, vector<char>(K, 0));
        vector<vector<char>> cur(n, vector<char>(K, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fill(cur[j].begin(), cur[j].end(), 0);
                int v = grid[i][j];

                if (i == 0 && j == 0) {
                    cur[0][v] = 1;
                    continue;
                }
                if (i > 0) {                       // from top
                    for (int x = 0; x < K; x++)
                        if (prev[j][x]) cur[j][x ^ v] = 1;
                }
                if (j > 0) {                       // from left
                    for (int x = 0; x < K; x++)
                        if (cur[j - 1][x]) cur[j][x ^ v] = 1;
                }
            }
            swap(prev, cur);
        }

        for (int x = 0; x < K; x++)
            if (prev[n - 1][x]) return x;
        return -1;
    }
};