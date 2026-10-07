class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(') left++;
            else if (c == ')') {
                if (left > 0) left--;
                else right++;
            }
        }

        unordered_set<string> res;
        string path;
        dfs(s, 0, 0, 0, left, right, path, res);
        return vector<string>(res.begin(), res.end());
    }

private:
    void dfs(const string& s, int idx, int open, int close,
             int remL, int remR, string& path, unordered_set<string>& res) {
        if (idx == s.size()) {
            if (remL == 0 && remR == 0) res.insert(path);
            return;
        }

        char c = s[idx];

        if (c == '(' && remL > 0)
            dfs(s, idx + 1, open, close, remL - 1, remR, path, res);
        else if (c == ')' && remR > 0)
            dfs(s, idx + 1, open, close, remL, remR - 1, path, res);

        path.push_back(c);
        if (c != '(' && c != ')')
            dfs(s, idx + 1, open, close, remL, remR, path, res);
        else if (c == '(')
            dfs(s, idx + 1, open + 1, close, remL, remR, path, res);
        else if (close < open)
            dfs(s, idx + 1, open, close + 1, remL, remR, path, res);
        path.pop_back();
    }
};