class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& current, int open, int close, int n) {
        // Base case: the string has all n pairs
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        // We can add '(' as long as we haven't used all n
        if (open < n) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, n);
            current.pop_back();
        }

        // We can add ')' only if it won't exceed the number of '('
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, n);
            current.pop_back();
        }
    }
};