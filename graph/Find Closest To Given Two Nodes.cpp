// Using DFS

class Solution {
public:
    void dfs(int u, unordered_map<int,vector<int>>&adj, vector<bool>&vis, vector<int>&dist) {
        vis[u] = true;

        for(int &v : adj[u]) {
            if(!vis[v]) {
                dist[v] = 1 + dist[u];
                dfs(v,adj,vis,dist);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        unordered_map<int,vector<int>>adj;

        for(int i = 0;i < n;i++) {
           int u = i;
           int v = edges[i];

            if(v == -1) {
                continue;
            }

            adj[u].push_back(v);
        }

        vector<bool>vis1(n,false);
        vector<int>dist1(n,INT_MAX);
        dist1[node1] = 0;
        dfs(node1,adj,vis1,dist1);

        vector<bool>vis2(n,false);
        vector<int>dist2(n,INT_MAX);
        dist2[node2] = 0;
        dfs(node2,adj,vis2,dist2);

        int minDist = INT_MAX, node = -1;
        for(int i = 0;i < n;i++) {
            int maxD = max(dist1[i], dist2[i]);
            if(maxD < minDist) {
                minDist = maxD;
                node = i;
            }
        }      

        return node;
    }
};

// Using BFS

class Solution {
public:
    int n;

    void bfs(int node, unordered_map<int,vector<int>>&adj, vector<int>&dist) {
        vector<bool>vis(n,false);
        vis[node] = true;

        queue<int>que;
        que.push(node);
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(int &v : adj[u]) {
                if(!vis[v]) {
                    dist[v] = 1 + dist[u];
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        unordered_map<int,vector<int>>adj;

        for(int i = 0;i < n;i++) {
           int u = i;
           int v = edges[i];

            if(v == -1) {
                continue;
            }

            adj[u].push_back(v);
        }

        vector<int>dist1(n,INT_MAX);
        dist1[node1] = 0;
        bfs(node1,adj,dist1);

        vector<int>dist2(n,INT_MAX);
        dist2[node2] = 0;
        bfs(node2,adj,dist2);

        int minDist = INT_MAX, node = -1;
        for(int i = 0;i < n;i++) {
            int maxD = max(dist1[i], dist2[i]);
            if(maxD < minDist) {
                minDist = maxD;
                node = i;
            }
        }      

        return node;
    }
};