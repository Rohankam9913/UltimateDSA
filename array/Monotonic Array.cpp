class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool isMonotonicIncreasing = false;
        bool isMonotonicDecreasing = false;

        for(int i = 0;i < n-1;i++) {
            if(nums[i] < nums[i+1]) {
                isMonotonicIncreasing = true;
            } else if(nums[i] > nums[i+1]){
                isMonotonicDecreasing = true;
            }
        }

        if(isMonotonicIncreasing && isMonotonicDecreasing) {
            return false;
        }

        return true;
    }
};