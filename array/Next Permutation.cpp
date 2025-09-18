class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int idx = -1;

        for(int i = n-1;i > 0;i--) {
            if(nums[i] > nums[i-1]) {
                idx = i-1;
                break;
            }
        }

        if(idx != -1) {
            int justGreaterIdx = -1;

            for(int i = n-1;i > idx;i++) {
                if(nums[i] > nums[idx]) {
                    justGreaterIdx = i;
                    break;
                }
            }

            swap(nums[idx], nums[justGreaterIdx]);
        }

        reverse(begin(nums)+idx+1, end(nums));
    }
};