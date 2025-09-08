class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0) {
            return nums;
        }

        int n = nums.size();
        vector<int>result(n,-1);
        
        if(n < k) {
            return result;
        }

        int ind = k, count = 2*k+1;
        int i = 0, j = ind + k;
        
        long long sum = 0;
        for(int i = 0;i <= ind+k;i++) {
            sum += nums[i];
        }

        result[ind] = sum/count;
        ind++;
        j++;

        while(j < n) {
            sum = sum + nums[j] - nums[i];

            result[ind] = sum / count;
            ind++;
            i++;
            j++;
        }

        return result;
    }
};