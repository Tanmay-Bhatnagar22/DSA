class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxcandies = *max_element(candies.begin(), candies.end());
        
        vector<bool> result(candies.size());

        for (int i = 0; i<candies.size(); i++){
            result[i] = (candies[i] + extraCandies >= maxcandies);
        }
        return result;
    }
};