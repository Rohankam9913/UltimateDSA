class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        int totalStones = 0;
        priority_queue<int>pq;

        for(int &stones : piles) {
            pq.push(stones);
            totalStones += stones;
        }

        for(int i = 1; i <= k;i++) {
            int top = pq.top();
            pq.pop();

            int remove = top/2;
            totalStones -= remove;

            pq.push(top - remove);
        }
    }
};