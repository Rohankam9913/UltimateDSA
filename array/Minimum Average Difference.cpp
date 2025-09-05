// Brute Force

class Solution {
public:
    long long findLeftSum(vector<int>&nums,int i) {
        long long lsum = 0;
        while(i >= 0) {
            lsum += nums[i];
            i--;
        }
        return lsum;
    }

    long long findRightSum(vector<int>&nums,int i, int n) {
        long long rsum = 0;
        if(i == n) {
            return nums[i-1];
        }

        while(i < n) {
            rsum += nums[i];
            i++;
        }
        return rsum;
    }

    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        int minAvg = INT_MAX, ind = -1; 

        for(int i = 0;i < n;i++) {
            long long lsum = findLeftSum(nums,i);
            long long rsum = findRightSum(nums,i+1,n);
            
            long long lavg = lsum/(i+1);
            long long ravg = (i == n-1) ? 0 : rsum/(n-i-1);

            long long avgDiff = abs(lavg - ravg);
            if(avgDiff < minAvg) {
                minAvg = avgDiff;
                ind = i;
            }
        }

        return ind;
    }
};

// Optimized Approach

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = accumulate(begin(nums), end(nums), 0);
        long long lsum = 0;

        int minAvgDiff = INT_MAX, ind = -1;

        for(int i = 0;i < n;i++) {
            lsum += nums[i];  // left sum (i to 0)
            long long rsum = totalSum - lsum; // right sum (i+1 to n-1)

            long long lavg = lsum / (i+1);
            long long ravg = (i == n-1) ? 0 : rsum / (n-i-1);

            long long avgDiff = abs(lavg - ravg);
            if(minAvgDiff > avgDiff) {
                minAvgDiff = avgDiff;
                ind = i;
            }
        }

        return ind;
    }
};