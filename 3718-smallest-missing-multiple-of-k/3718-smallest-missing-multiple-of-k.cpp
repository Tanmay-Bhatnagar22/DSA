class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> present(nums.begin(), nums.end());
        
        long multiple = k;
        while (present.count(multiple)) {
            multiple += k;
        }
        
        return (int)multiple;
    }
};