class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& c : connections) {
            adj[c[0]].push_back({c[1], 1}); // original direction a -> b, must flip if traversed from a
            adj[c[1]].push_back({c[0], 0}); // reverse view, already points toward the parent
        }

        int changes = 0;
        vector<bool> visited(n, false);
        stack<int> st;
        st.push(0);
        visited[0] = true;

        while (!st.empty()) {
            int u = st.top();
            st.pop();
            for (auto& [v, needFlip] : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    changes += needFlip;
                    st.push(v);
                }
            }
        }
        return changes;
    }
};