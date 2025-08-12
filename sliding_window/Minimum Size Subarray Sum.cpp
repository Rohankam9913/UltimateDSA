class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();   
        int sum = 0, minLen = n;
        int i = 0, j = 0;

        while(j < n) {
            sum += nums[j];

            while(sum >= target) {
                minLen = min(minLen, j-i+1);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return minLen == n ? 0 : minLen;
    }
};