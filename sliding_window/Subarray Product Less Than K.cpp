class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) {
            return 0;
        }

        int n = nums.size();
        int i = 0, j = 0, count = 0;
        int prod = 1;

        while(j < n) {
            prod *= nums[j];

            while(i <= j && prod >= k) {
                prod /= nums[i];
                i++;
            }

            count += (j-i+1);
            j++;
        }

        return count;
    }
};