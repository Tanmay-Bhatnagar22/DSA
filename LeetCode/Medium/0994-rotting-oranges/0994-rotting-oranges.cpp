class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int minutes = 0;

        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            minutes++;                       // one level = one minute
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();
                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                    if (grid[nr][nc] != 1) continue;
                    grid[nr][nc] = 2;        // rot it
                    fresh--;
                    q.push({nr, nc});
                }
            }
        }
        return fresh == 0 ? minutes : -1;
    }
};