class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        bool asc = true, desc = true;
        for (int i = 0; i < n; i++) {
            int nxt = nums[(i + 1) % n];
            if (nxt != (nums[i] + 1) % n) asc = false;
            if (nxt != (nums[i] - 1 + n) % n) desc = false;
        }

        if (!asc && !desc) return -1;

        int ans = INT_MAX;

        if (asc) {
            int k = nums[0];
            if (k == 0) ans = 0;
            else ans = min(n - k, k + 2);
        }

        if (desc) {
            int k = (nums[0] + 1) % n;
            ans = min(ans, 1 + min(k, n - k));
        }

        return ans;
    }
};