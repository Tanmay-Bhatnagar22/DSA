class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> left, right;

        int i = 0, j = n - 1;

        // Fill the front window
        while (i < candidates && i <= j) {
            left.push(costs[i++]);
        }
        // Fill the back window (without overlapping the front)
        while (j >= n - candidates && j >= i) {
            right.push(costs[j--]);
        }

        long long total = 0;
        while (k--) {
            // Pick from the left heap if the right is empty, or left top <= right top
            // (ties go to the left heap because it holds smaller indices)
            if (right.empty() || (!left.empty() && left.top() <= right.top())) {
                total += left.top();
                left.pop();
                if (i <= j) left.push(costs[i++]);
            } else {
                total += right.top();
                right.pop();
                if (i <= j) right.push(costs[j--]);
            }
        }
        return total;
    }
};