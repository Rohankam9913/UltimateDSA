class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minKPosition = -1;
        int maxKPosition = -1;
        int culpritIdx = -1;
        int n = nums.size();
        long long count = 0;

        for(int i = 0;i < n;i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                culpritIdx = i;
            }

            if(nums[i] == minK) {
                minKPosition = i;
            }

            if(nums[i] == maxK) {
                maxKPosition = i;
            }

            long long minIndex = min(minKPosition, maxKPosition);
            long long tempCount = minIndex - culpritIdx; 
            count += (tempCount > 0) ? tempCount : 0;
        }

        return count;
    }
};