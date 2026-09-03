class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX, minEven = INT_MAX;
        for (int x : nums1) {
            if (x % 2 == 0) minEven = min(minEven, x);
            else            minOdd  = min(minOdd, x);
        }
        
        if (minEven == INT_MAX || minOdd == INT_MAX) return true;
        return minOdd < minEven;
    }
};