class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(26, 0);
        long long total = 0;
        
        for (char ch : s) {
            int c = ch - 'a';
            long long newCount = (total + 1) % MOD;
            total = (total - dp[c] + newCount + MOD) % MOD;
            dp[c] = newCount;
        }
        
        return (int)(total % MOD);
    }
};