class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0;

        for(int i = 0;i < n;i++) {
            if(nums[i] % 2 == 0){
                sum += nums[i];
            }
        }

        vector<int>result;

        for(vector<int>&query : queries) {
            int val = query[0];
            int idx = query[1];

            if(nums[idx] % 2 == 0) {
                sum -= nums[idx];
            }

            nums[idx] += val;

            if(nums[idx] % 2 == 0) {
                sum += nums[idx];
            }

            result.push_back(sum);
        }

        return result;
    }
};