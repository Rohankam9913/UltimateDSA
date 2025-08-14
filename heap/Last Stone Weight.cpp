// Approach 1 - Using Heap

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>pq;

        for(int &stone : stones){
            pq.push(stone);
        }   

        while(pq.size() > 1) {
            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            pq.push(abs(first-second));
        }

        return pq.top();
    }
};

// Approach 2 - Using Sorting

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        while(stones.size() > 1) {
            sort(begin(stones), end(stones));

            int first = stones.back();
            stones.pop_back();

            int second = stones.back();
            stones.pop_back();

            stones.push_back(abs(first-second));
        }

        return stones[0];
    }
};