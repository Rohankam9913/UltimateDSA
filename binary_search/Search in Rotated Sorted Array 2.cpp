class Solution {
public:
    int findPivot(vector<int>&nums){
        int low = 0, high = nums.size()-1;
        while(low < high) {

            // skipping the duplicates from left
            while(low < high && nums[low] == nums[low+1]) {
                low++;
            }

            // skipping the duplicates from right
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

        return high;
    }

    bool find(vector<int>&nums,int low, int high, int target) {
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == target) {
                return true;
            } else if(nums[mid] > target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return false;
    }

    bool search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);

        bool found = find(nums,0,pivot-1,target);
        if(found) {
            return true;
        }

        return find(nums,pivot,nums.size()-1,target);            
    }
};