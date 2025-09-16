class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mp;
        mp[0] = 1;

        int count = 0, sum = 0;

        for(int i = 0;i < n;i++) {
            sum += nums[i];
            int remaining = sum - k;

            if(mp.find(remaining) != mp.end()) {
                count += mp[remaining];
            }

            mp[sum]++;
        }

        return count;
    }
};