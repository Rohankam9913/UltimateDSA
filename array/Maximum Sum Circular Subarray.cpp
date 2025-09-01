class Solution {
public:
    int kadanesMaxSum(vector<int>&nums, int n) {
        int sum = nums[0], maxSum = nums[0];
        for(int i = 1;i < n;i++) {
            sum = max(sum + nums[i], nums[i]);
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    } 

    int kadanesMinSum(vector<int>&nums, int n) {
        int sum = nums[0], minSum = nums[0];
        for(int i = 1;i < n;i++) {
            sum = min(sum + nums[i], nums[i]);
            minSum = min(minSum, sum);
        }

        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int totalSum = accumulate(begin(nums), end(nums), 0);
        int minSum = kadanesMinSum(nums,n);
        int cirMaxSum = totalSum - minSum;

        int maxSum = kadanesMaxSum(nums,n);
        if(maxSum > 0) {
            return max(maxSum, cirMaxSum);
        }

        return maxSum;
    }
};