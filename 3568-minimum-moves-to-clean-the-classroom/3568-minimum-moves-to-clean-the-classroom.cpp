class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));
        int sx = 0, sy = 0, cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = classroom[i][j];
                if (c == 'S') { sx = i; sy = j; }
                else if (c == 'L') { litterIdx[i][j] = cnt++; }
            }
        }

        if (cnt == 0) return 0;

        int fullMask = (1 << cnt) - 1;
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << cnt, false))));

        queue<tuple<int,int,int,int>> q;
        q.push({sx, sy, energy, fullMask});
        visited[sx][sy][energy][fullMask] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                if (mask == 0) return moves;
                if (e <= 0) continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dx[d], nc = c + dy[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;

                    int ne = (classroom[nr][nc] == 'R') ? energy : e - 1;
                    int nmask = mask;
                    if (classroom[nr][nc] == 'L' && litterIdx[nr][nc] != -1) {
                        nmask = mask & ~(1 << litterIdx[nr][nc]);
                    }

                    if (!visited[nr][nc][ne][nmask]) {
                        visited[nr][nc][ne][nmask] = true;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};