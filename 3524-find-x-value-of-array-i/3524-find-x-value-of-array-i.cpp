class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);
        vector<long long> cnt(k, 0);   // cnt[r] = number of active subarrays with current product % k == r

        for (int j = 0; j < n; j++) {
            int a = nums[j] % k;
            vector<long long> newCnt(k, 0);

            // extend every existing active subarray by multiplying by nums[j]
            for (int r = 0; r < k; r++) {
                if (cnt[r]) {
                    newCnt[(int)((long long)r * a % k)] += cnt[r];
                }
            }

            // start a brand-new subarray beginning at j
            newCnt[a] += 1;

            // every active subarray (start <= j) now contributes to its residue's count for ending index j
            for (int r = 0; r < k; r++) {
                result[r] += newCnt[r];
            }

            cnt = newCnt;
        }

        return result;
    }
};