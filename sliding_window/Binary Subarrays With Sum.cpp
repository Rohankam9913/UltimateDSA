// Using Cumulative Sum and map

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        
        unordered_map<int,int>mp;
        mp[0] = 1;

        int sum = 0, count = 0;

        for(int i = 0;i < n;i++) {
            sum += nums[i];
            int remaining = sum - goal;

            if(mp.find(remaining) != mp.end()) {
                count += mp[remaining];
            }

            mp[sum]++;
        }

        return count;
    }
};

// Using Sliding Window

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int i = 0, j = 0;

        int sum = 0, count = 0;
        int countZeros = 0;
        
        while(j < n) {
            sum += nums[j];

            while(i < j && (sum > goal || nums[i] == 0)) {
                if(nums[i] == 0) {
                    countZeros++;
                } else {
                    countZeros = 0;
                }

                sum -= nums[i];
                i++;
            }

            if(sum == goal) {
                count += countZeros + 1;
            }
            j++;
        }

        return count;
    }
};