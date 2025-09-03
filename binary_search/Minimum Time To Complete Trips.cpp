class Solution {
public:
    bool isPossible(long long midTime, vector<int>&time, int totalTrips) {
        long long trips = 0;
        for(int &t : time) {
            trips += midTime/t;
        }

        return trips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = (long long)*min_element(begin(time), end(time)) * totalTrips;

        long long result = 0;
        while(low <= high) {
            long long midTime = low + (high-low)/2;

            if(isPossible(midTime,time,totalTrips)) {
                result = midTime;
                high = midTime-1;
            } else {
                low = midTime+1;
            }
        }

        return result;
    }
};