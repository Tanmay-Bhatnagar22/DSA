class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, zeroCount = 0, best = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) zeroCount++;
            while (zeroCount > 1) {
                if (nums[left] == 0) zeroCount--;
                left++;
            }

            best = max(best, right - left + 1 - 1);
        }
        return best;
    }
};