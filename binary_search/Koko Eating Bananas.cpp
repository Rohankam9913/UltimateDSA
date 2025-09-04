class Solution {
public:
    bool isPossible(int k,vector<int>&piles,int h) {
        int n = piles.size();
        int totalHours = 0;

        for(int i = 0;i < n;i++) {
            int hour = piles[i]/k;
            if(piles[i]%k != 0) {
                hour++;
            }

            totalHours += hour;
        }

        return totalHours <= h;
    } 

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(begin(piles), end(piles));

        while(low < high) {
            int mid = low + (high-low)/2;
            if(isPossible(mid,piles,h)) {
                high = mid;
            } else {
                low = mid+1;
            }
        }

        return low;
    }
};