// Using Sliding Window

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int maxLen = 0;

        unordered_map<int,int>mp;

        while(j < n) {
            mp[nums[j]]++;

            while(i <= j && mp[nums[i]] > k) {
                mp[nums[i]]--;
                i++;
            }

            maxLen = max(maxLen, j-i+1);
            j++;
        }

        return maxLen;
    }
};

// Using One Pass Sliding Window

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int maxLen = 0, bad = 0;  

        unordered_map<int,int>mp;

        while(j < n) {
            mp[nums[j]]++;

            if(mp[nums[j]] > k) {
                bad++;
            }

            if(bad > 0) {
                mp[nums[i]]--;
                if(mp[nums[i]] == k) {
                    bad--;
                }

                i++;
            }

            if(bad == 0) {
                maxLen = max(maxLen,j-i+1);
            }

            j++;
        }

        return maxLen;
    }
};