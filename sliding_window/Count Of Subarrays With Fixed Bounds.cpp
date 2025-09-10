class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long count = 0;

        int corruptIdx = -1;
        int minPosition = -1;
        int maxPosition = -1;

        for(int i = 0;i < n;i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                corruptIdx = i;
            }

            if(nums[i] == minK) {
                minPosition = i;
            }

            if(nums[i] == maxK) {
                maxPosition = i;
            }

            long long temp = min(minPosition,maxPosition) - corruptIdx;
            count += (temp > 0) ? temp : 0; 
        }

        return count;
    }
};