class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(const string& src, const string& dst, unordered_set<string>& visited) {
        if (src == dst) return 1.0;
        visited.insert(src);

        for (auto& [next, weight] : graph[src]) {
            if (visited.count(next)) continue;
            double res = dfs(next, dst, visited);
            if (res != -1.0) return res * weight;
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Build the graph
        for (int i = 0; i < equations.size(); i++) {
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            graph[a].push_back({b, values[i]});
            graph[b].push_back({a, 1.0 / values[i]});
        }

        vector<double> ans;
        for (auto& q : queries) {
            const string& c = q[0];
            const string& d = q[1];

            // Unknown variable: answer cannot be determined
            if (!graph.count(c) || !graph.count(d)) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            ans.push_back(dfs(c, d, visited));
        }
        return ans;
    }
};