class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (n < k) return 0;
        
        // isPal[i][j] = true if s[i..j] is palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) isPal[i][i] = true;
        for (int i = 0; i + 1 < n; i++) isPal[i][i+1] = (s[i] == s[i+1]);
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                isPal[i][j] = (s[i] == s[j]) && isPal[i+1][j-1];
            }
        }
        
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i+1];
            for (int len = k; len <= n - i; len++) {
                if (len != k && len != k + 1) continue; // only need to check k and k+1
                int j = i + len - 1;
                if (isPal[i][j]) {
                    dp[i] = max(dp[i], 1 + dp[j+1]);
                    break; // once we find one starting at i, no need to check longer
                }
            }
        }
        
        return dp[0];
    }
};