// Using Topological Sorting

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n,0);
        queue<int>que;
        vector<vector<int>>freq(n,vector<int>(26,0));

        int maxColorValue = 0, count = 0;

        for(vector<int>&edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        for(int i = 0;i < n;i++) {
            if(indegree[i] == 0) {
                que.push(i);
                freq[i][colors[i]-'a'] = 1;
            }
        }

        while(!que.empty()) {
            int u = que.front();
            count++;
            maxColorValue = max(maxColorValue, freq[u][colors[u]-'a']);
            que.pop();

            for(int &v : adj[u]) {
                for(int clr = 0;clr < 26;clr++) {
                    freq[v][clr] = max(freq[v][clr], freq[u][clr] + (colors[v]-'a' == clr));
                }

                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        if(count < n) {
            return -1;
        }

        return maxColorValue;
    }
};