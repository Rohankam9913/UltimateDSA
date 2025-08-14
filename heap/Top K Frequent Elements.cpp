// Approach 1 - Using Heap

class Solution {
public:
    typedef pair<int,int> P;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(auto &num : nums) {
            mp[num]++;
        }

        priority_queue<P,vector<P>,greater<P>>pq;
        for(auto it : mp) {
            pq.push({it.second,it.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int>result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};

// Approach 2 - Using Bucket Sort

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mp;
        for(int &num : nums) {
            mp[num]++;
        }

        vector<vector<int>>buckets(n+1);
        for(auto it : mp) {
            buckets[it.second].push_back(it.first);
        }

        vector<int>result;
        for(int freq = n;freq > 0;freq--) {
            while(buckets[freq].size() > 0 && k > 0) {
                result.push_back(buckets[freq].back());
                buckets[freq].pop_back();
                k--;
            }
        }

        return result;
    }
};