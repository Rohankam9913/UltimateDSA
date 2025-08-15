class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>>vec(n);

        for(int i = 0;i < n;i++) {
            vec[i] = {nums1[i], nums2[i]};
        }

        auto lambda = [&](auto &P, auto &Q) {
            return P.second > Q.second;
        };

        sort(begin(vec), end(vec), lambda);
        long long kElementsSum = 0;
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i = 0;i < k;i++) {
            kElementsSum += vec[i].first;
            pq.push(vec[i].first);
        }

        long long result = kElementsSum * vec[k-1].second;

        for(int i = k;i < n;i++) {
            kElementsSum -= pq.top() + vec[i].first;
            pq.pop();

            pq.push(vec[i].first);
            result = max(result, kElementsSum * vec[i].second);
        }

        return result;  
    }
};