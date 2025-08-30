class Solution {
public:
    int dfs(int u,int parent,unordered_map<int,vector<int>>&adj, vector<bool>&hasApple) {
        int time = 0;

        for(int &v : adj[u]) {
            if(v == parent) {
                continue;
            }

            int timeTakenToCollectApplesFromChild = dfs(v,u,adj,hasApple);
            if(timeTakenToCollectApplesFromChild > 0 || hasApple[v]) {
                time += timeTakenToCollectApplesFromChild + 2;
            }
        }

        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>adj;
       
        for(vector<int>&edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(0,-1,adj,hasApple);
    }
};