class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;
            long long prevMax = LLONG_MIN;

            for (int s = 0; s < n && ok; s += k) {
                int mn = nums[s], mx = nums[s];
                int descents = 0;

                for (int i = s; i < s + k; i++) {
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                    int nxt = (i + 1 < s + k) ? nums[i + 1] : nums[s]; // cyclic wrap
                    if (nums[i] > nxt) descents++;
                }

                // block must be a rotation of a sorted array
                if (descents > 1) { ok = false; break; }
                // blocks must chain in sorted order
                if (mn < prevMax) { ok = false; break; }
                prevMax = mx;
            }

            if (ok) ans += k;
        }

        return (int)ans;
    }
};