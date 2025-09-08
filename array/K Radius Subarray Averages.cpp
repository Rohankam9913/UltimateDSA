// Using Prefix Sum

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int m = 2*k+1;

        vector<long long>prefixSum(n,0);
        prefixSum[0] = nums[0];

        for(int i = 1;i < n;i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        vector<int>result(n,-1);
        for(int i = k;i < n-k;i++) {
            long long sum = prefixSum[i+k];
            if(i-k > 0) {
                sum -= prefixSum[i-k];
            }

            result[i] = sum/m;
        }

        return result;
    }
};