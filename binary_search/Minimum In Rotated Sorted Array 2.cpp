class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;

        while(low < high) {
            // Skip duplicates from left
            while(low < high && nums[low] == nums[low+1]) {
                low++;
            }

            // Skip duplicates from right
            while(low < high && nums[high] == nums[high-1]) {
                high--;
            }

            int mid = low + (high-low)/2;
            if(nums[mid] > nums[high]) {
                low = mid+1;
            } else {
                high = mid;
            }
        }

        return nums[high];
    }
};