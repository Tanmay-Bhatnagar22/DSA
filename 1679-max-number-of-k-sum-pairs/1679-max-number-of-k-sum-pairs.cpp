class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) count[num]++;
        
        int operations = 0;
        for (int num : nums) {
            int complement = k - num;
            
            if (count[num] <= 0) continue;
            
            if (complement == num) {
                if (count[num] >= 2) {
                    operations++;
                    count[num] -= 2;
                }
            } else if (count.count(complement) && count[complement] > 0) {
                operations++;
                count[num]--;
                count[complement]--;
            }
        }
        
        return operations;
    }
};