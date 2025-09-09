class Solution {
public:
    long long calculateCost(int mid, vector<int>&nums, vector<int>&cost) {
        long long totalCost = 0;
        for(int i = 0;i < nums.size();i++) {
            totalCost += (long long) abs(nums[i] - mid) * cost[i];
        }

        return totalCost;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int low  = *min_element(begin(nums), end(nums));
        int high = *max_element(begin(nums), end(nums));

        long long result = INT_MAX;

        while(low <= high) {
            int mid = low + (high-low)/2;
            long long costToMakeArrayEqualToMid         = calculateCost(mid,nums,cost);
            long long costToMakeArrayEqualToMidPlusOne  = calculateCost(mid+1,nums,cost);

            result = min(costToMakeArrayEqualToMid, costToMakeArrayEqualToMidPlusOne);
            if(costToMakeArrayEqualToMid < costToMakeArrayEqualToMidPlusOne) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return result == INT_MAX ? 0 : result;
    }
};