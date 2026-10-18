class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<vector<long long>> C;

    long long dfs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long l = dfs(left);
        long long r = dfs(right);

        long long ways = C[n - 1][left.size()] % MOD;
        ways = ways * l % MOD;
        ways = ways * r % MOD;
        return ways;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Pascal's triangle for nCr mod p
        C.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        return (dfs(nums) - 1 + MOD) % MOD;
    }
};