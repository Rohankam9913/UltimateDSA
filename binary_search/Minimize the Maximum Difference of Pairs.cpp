// Using Brute Force

class Solution {
public:
    int n;

    bool isPossible(vector<int>&nums, int &maxDiff, int &p) {
        int countPairs = 0;

        for(int i = 1;i < n;i++) {
            if(nums[i] - nums[i-1] <= maxDiff) {
                countPairs++;
            }
        }

        return countPairs >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        sort(begin(nums), end(nums));
        int diff = nums[n-1] - nums[0];

        for(int maxDiff = 0;maxDiff <= diff;maxDiff++) {
            if(isPossible(nums,maxDiff,p)) {
                return maxDiff;
            }
        }

        return -1;
    }
};

// Using Binary Search

class Solution {
public:
    int n;

    bool isPossible(int &mid, vector<int>&nums, int &p) {
        int countPairs = 0;

        for(int i = 1;i < n;i++) {
            if(nums[i] - nums[i-1] <= mid) {
                countPairs++;
            }
        }

        return countPairs >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        sort(begin(nums), end(nums));

        int low = 0, high = nums[n-1] - nums[0];
        int result = 0;

        while(low <= high) {
            int mid = low + (high-low)/2;
            if(isPossible(mid,nums,p)) {
                result = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }   

        return result;
    }
};