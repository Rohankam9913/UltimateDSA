// Approach 1 - Reccursion and Memoization

class Solution {
public:
    bool solve(int idx, int n, vector<int>&nums, vector<int>&dp) {
        if(idx == n-1) {
            return true;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        for(int jump = 1;jump <= nums[idx];jump++) {
            if(solve(idx+jump, n, nums, dp)) {
                return dp[idx] = true;
            }
        }  

        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);

        return solve(0,n,nums,dp);
    }
};

// Approach 2 - Bottom Up

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,false);
        dp[0] = true;

        for(int i = 1;i < n;i++) {
            for(int j = i-1;j >= 0;j--) {
                if(dp[j] && j + nums[j] >= i) {
                    dp[i] = true;
                }
            }
        }

        return dp[n-1];
    }
};

// Approach 3 - Smart Approach

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;

        for(int i = 0;i < n;i++) {
            if(i > maxReach) {
                return false;
            }

            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};