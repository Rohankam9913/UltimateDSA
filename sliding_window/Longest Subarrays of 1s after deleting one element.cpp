// Brute Force

class Solution {
public:
    int maxSubarray(int skip, vector<int>&nums) {
        int count = 0, mx = 0;
        for(int i = 0;i < nums.size();i++) {
            if(i == skip) {
                continue;
            }

            if(nums[i] == 1) {
                count++;
                mx = max(mx, count);
            } else {
                count = 0;
            }
        }

        return mx;
    }

    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        int countZeros = 0;

        for(int i = 0;i < nums.size();i++) {
            if(nums[i] == 1) {
                continue;
            }

            countZeros++;
            mx = max(mx, maxSubarray(i,nums));
        }

        if(countZeros == 0) {
            return n-1;
        }

        return mx;
    }
};

// Sliding Window

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();    
        int i = 0, j = 0;
        int mx = 0, countZeros = 0;

        while(j < n) {
            if(nums[j] == 0) {
                countZeros++;
            }

            while(countZeros > 1) {
                if(nums[i] == 0) {
                    countZeros--;
                }
                i++;
            }

            mx = max(mx, j-i);
            j++;
        }

        return mx;
    }
};

// Better Sliding Window

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int mx = 0, lastTimeZero = -1;

        while(j < n) {
            if(nums[j] == 0) {
                i = lastTimeZero + 1;
                lastTimeZero = j;
            }

            mx = max(mx, j-i);
            j++;
        }   

        return mx;
    }
};
