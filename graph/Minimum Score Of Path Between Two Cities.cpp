// Using DFS

class Solution {
public:
    void dfs(int u,unordered_map<int,vector<pair<int,int>>>&adj,vector<bool>&vis,int &mnScore) {
        vis[u] = true;

        for(auto &P : adj[u]) {
            int v = P.first;
            int dist = P.second;

            mnScore = min(mnScore,dist);
            if(!vis[v]) {
                dfs(v,adj,vis,mnScore);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(vector<int>&road : roads) {
            int u = road[0];
            int v = road[1];
            int d = road[2];

            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        int mnScore = INT_MAX;
        vector<bool>vis(n+1,false);
        dfs(1,adj,vis,mnScore);

        return mnScore;
    }
};

// Using BFS

class Solution {
public:
    int bfs(unordered_map<int,vector<pair<int,int>>>&adj, int n) {
        queue<int>q;
        q.push(1);
        vector<bool>vis(n+1,false);
        vis[1] = true;

        int result = INT_MAX;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(auto &P : adj[u]) {
                int v = P.first;
                int dist = P.second;
                result = min(result,dist);

                if(!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }

        return result;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(vector<int>&road : roads) {
            int u = road[0];
            int v = road[1];
            int d = road[2];

            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        return bfs(adj, n);
    }
};