class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int best = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            best = max(best, h * w);
            if (height[left] < height[right]) left++;
            else right--;
        }
        return best;
    }
};