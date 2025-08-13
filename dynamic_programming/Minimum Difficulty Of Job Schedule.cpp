// Recursion and Memoization

class Solution {
public:
    int solve(int idx, int d,int n, vector<int>&jd, vector<vector<int>>&dp) {
        if(d == 1) {
            return *max_element(begin(jd)+idx, end(jd));
        }

        if(dp[idx][d] != -1) {
            return dp[idx][d];
        }

        int minDiff = INT_MAX;
        int maxD = jd[idx];
        for(int i = idx;i <= n-d;i++) {
            maxD = max(maxD, jd[i]);
            minDiff = min(minDiff, maxD + solve(i+1, d-1, n, jd, dp));  
        }

        return dp[idx][d] = minDiff;
    }

    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if(d > n) {
            return -1;
        }

        vector<vector<int>>dp(n,vector<int>(d+1,-1));

        return solve(0,d,n,jd,dp);
    }
};

// Bottom Up

class Solution {
public:
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if(d > n) {
            return -1;
        }

        vector<vector<int>>dp(n,vector<int>(d+1,-1));

        for(int i = 0;i < n;i++) {
            dp[i][1] = *max_element(begin(jd)+i, end(jd));
        }

        for(int days = 2;days <= d;days++) {
            for(int i = 0;i <= n-days;i++) {
                int minDiff = INT_MAX;
                int maxD = jd[i];

                for(int j = i;j <= n-days;j++) {
                    maxD = max(maxD, jd[j]);
                    minDiff = min(minDiff, maxD + dp[j+1][days-1]);  
                }

                dp[i][days] = minDiff;
            }
        }

        return dp[0][d];
    }
};