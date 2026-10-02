class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';  // mark visited

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            steps++;
            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (maze[nr][nc] == '+') continue;

                    // Empty border cell reached (entrance is already marked '+')
                    if (nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1)
                        return steps;

                    maze[nr][nc] = '+';  // mark visited
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
};