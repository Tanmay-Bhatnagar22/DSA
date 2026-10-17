class Solution {
public:
    int digitSum(int x) {
        int s = 0;
        while (x > 0) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<array<int, 3>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {digitSum(nums[i]), nums[i], i};
        }

        sort(v.begin(), v.end());

        // v[i][2] is the original index of the element that belongs at position i
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || v[i][2] == i) continue;

            int cycleLen = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = v[j][2];
                cycleLen++;
            }
            swaps += cycleLen - 1;
        }

        return swaps;
    }
};