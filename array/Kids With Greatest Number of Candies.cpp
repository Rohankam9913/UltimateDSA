class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxCandyVal = *max_element(begin(candies), end(candies));

        vector<bool>result(n,false);
        for(int i = 0;i < n;i++) {
            if(candies[i] + extraCandies >= maxCandyVal) {
                result[i] = true;
            }
        }

        return result;
    }
};