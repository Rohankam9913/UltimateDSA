class Solution {
public:
    int findMin(vector<int>&nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low < high) {
            int mid = low + (high-low)/2;
            if(nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return high;
    }

    int find(vector<int>&nums,int low, int high,int target) {
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivot = findMin(nums,target);

        int targetIdx = find(nums,0,pivot-1,target); 
        if(targetIdx != -1) {
            return targetIdx;
        }

        targetIdx = find(nums,pivot,nums.size()-1,target);
        return targetIdx;
    }
};