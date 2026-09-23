class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int n : nums) total += n;
        
        int target = total - x;
        if (target < 0) return -1;
        if (target == 0) return nums.size();
        
        int n = nums.size();
        int left = 0, sum = 0, maxLen = -1;
        
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            
            while (sum > target && left <= right) {
                sum -= nums[left];
                left++;
            }
            
            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen == -1 ? -1 : n - maxLen;
    }
};