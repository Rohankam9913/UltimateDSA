class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degree(n);

        for(vector<int>&road : roads) {
            int u = road[0];
            int v = road[1];

           degree[u]++;
           degree[v]++;
        }

        sort(begin(degree), end(degree));
        long long value = 1;
        long long result = 0;

        for(int i = 0;i < n;i++) {
            result += degree[i] * value;
            value++;
        }

        return result;
    }
};