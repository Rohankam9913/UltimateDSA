class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n % 2 != 0) {
            return {};
        }

        vector<int>result;
        sort(begin(changed), end(changed));

        unordered_map<int,int>mp;
        for(int &num : changed) {
            mp[num]++;
        }

        for(int i = 0;i < n;i++) {
            if(mp[changed[i]] == 0) {
                continue;
            }

            int twice = changed[i] * 2;

            if(mp.find(twice) == mp.end() || mp[twice] == 0) {
                return {};
            }

            result.push_back(changed[i]);
            mp[changed[i]]--;
            mp[twice]--;
        }

        return result;
    }
};