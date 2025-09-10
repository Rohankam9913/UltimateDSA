class Solution {
public:
    bool isPossible(int& mid, vector<int>&dist, double& hour) {
        int n = dist.size();
        double totalTime = 0;

        for(int i = 0;i < n-1;i++) {
            totalTime += ceil((double)dist[i]/(double)mid);
        }

        totalTime += (double)dist[n-1]/(double)mid;
        return totalTime <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e7;    
        int minSpeed = -1;

        while(low <= high) {
            int mid = low + (high-low)/2;
            if(isPossible(mid,dist,hour)) {
                minSpeed = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return minSpeed;
    }
};