class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long hours = 0;
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;  // ceil(pile / mid)
            }

            if (hours <= h) {
                ans = mid;
                high = mid - 1;   // try a slower speed
            } else {
                low = mid + 1;    // too slow, speed up
            }
        }
        return ans;
    }
};