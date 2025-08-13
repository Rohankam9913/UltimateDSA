class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_set<int>seen;

        while(j < n) {
            if(j-i > k) {
                if(seen.find(nums[i]) != seen.end()) {
                    seen.erase(nums[i]);
                }
                i++;
            }

            if(seen.find(nums[j]) != seen.end()) {
                return true;
            }

            seen.insert(nums[j]);
            j++;
        }

        return false;
    }
};