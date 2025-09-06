class Solution {
public:
    bool isPossible(int mid, vector<int>&nums) {
        vector<long long>temp(begin(nums), end(nums));

        int n = nums.size();
        for(int i = 0;i < n-1;i++) {
            if(temp[i] > mid) {
                return false;
            }

            long long incr = mid - temp[i];
            temp[i+1] -= incr;
        }

        return temp[n-1] <= mid;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int low = 0, high = *max_element(begin(nums),end(nums));
        int minimizedValue = high;

        while(low <= high) {
            int mid = low + (high-low)/2;
            if(isPossible(mid,nums)) {
                minimizedValue = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return minimizedValue;
    }
};