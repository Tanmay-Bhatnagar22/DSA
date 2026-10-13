class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int start, int k, int remain) {
        if (path.size() == k) {
            if (remain == 0) res.push_back(path);
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (i > remain) break;      // pruning: numbers only get larger
            path.push_back(i);
            dfs(i + 1, k, remain - i);  // i + 1 so each number is used once
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return res;
    }
};