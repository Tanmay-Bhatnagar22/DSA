class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });
        
        vector<int> ans(n);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && nums[idx[j+1]] - nums[idx[j]] <= limit) j++;
            
            vector<int> groupIdx(idx.begin() + i, idx.begin() + j + 1);
            sort(groupIdx.begin(), groupIdx.end());
            
            for (int k = 0; k < (int)groupIdx.size(); k++) {
                ans[groupIdx[k]] = nums[idx[i + k]];
            }
            
            i = j + 1;
        }
        
        return ans;
    }
};