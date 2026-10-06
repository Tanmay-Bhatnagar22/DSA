class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {nums2[i], nums1[i]};
        }

        // sort by nums2 descending
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });

        priority_queue<int, vector<int>, greater<int>> pq; // min-heap of nums1 values
        long long sum = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            sum += v[i].second;
            pq.push(v[i].second);

            if ((int)pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if ((int)pq.size() == k) {
                ans = max(ans, sum * v[i].first);
            }
        }
        return ans;
    }
};