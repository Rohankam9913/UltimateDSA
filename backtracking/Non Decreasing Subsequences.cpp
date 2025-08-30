class Solution {
public:
    int n;

    void solve(vector<int>&nums, int idx, vector<int>&cur, vector<vector<int>>&result) {
        if(cur.size() > 1) {
            result.push_back(cur);
        }

        unordered_set<int>seen;
        for(int i = idx;i < n;i++) {
            if((cur.empty() || cur.back() <= nums[i]) && seen.find(nums[i]) == seen.end()) {
                cur.push_back(nums[i]);
                solve(nums,i+1,cur,result);
                cur.pop_back();

                seen.insert(nums[i]);
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();

        vector<vector<int>>result;
        vector<int>cur;
        
        solve(nums,0,cur,result);

        return result;
    }
};