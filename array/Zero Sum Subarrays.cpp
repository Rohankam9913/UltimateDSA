// Using Cumulative Sum and map

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        int n = arr.size();
        
        unordered_map<int,int>mp;
        mp[0] = 1;
        
        int count = 0;
        long sum = 0;
        
        for(int i = 0;i < n;i++) {
            sum += arr[i];
            
            if(mp.find(sum) != mp.end()) {
                count += mp[sum];
            }
            
            mp[sum]++;
        }
        
        return count;
    }
};