class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n+1,0);

        for (int i=n-1; i>=0; i--){
            int onest =(i+1 <n) ? dp[i+1] : 0;
            int twost =(i+2 <n) ? dp[i+2] : 0;
            dp[i] = cost[i] + min(onest,twost);
        }
        return min(dp[0], dp[1]);
    }
};