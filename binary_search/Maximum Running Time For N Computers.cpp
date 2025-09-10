class Solution {
public:
    long long findSum(vector<int>&batteries) {
        long long totalMinutes = 0;

        for(int &min : batteries) {
            totalMinutes += min;
        }

        return totalMinutes;
    }

    bool isPossible(long long mid,int n,vector<int>&batteries) {
        long long totalRunTime = mid * n;
        long long batteriesRunTime = 0;

        for(int i = 0;i < batteries.size();i++) {
            batteriesRunTime += min(mid, (long long) batteries[i]);
            if(batteriesRunTime >= totalRunTime) {
                return true;
            }
        }

        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long low   = *min_element(begin(batteries), end(batteries));
        long long high  = findSum(batteries)/n;

        long long result = 0;

        while(low <= high) {
            long long mid = low + (high-low)/2;
            if(isPossible(mid,n,batteries)) {
                result = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return result;
    }
};