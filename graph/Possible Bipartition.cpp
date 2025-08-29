// Using BFS

class Solution {
public:
    bool bfs(int node, unordered_map<int,vector<int>>&adj, vector<int>&color) {
        color[node] = 1;
        queue<int>q;
        q.push(node);

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int &v : adj[u]) {
                if(color[u] == color[v]) {
                    return false;
                }

                if(color[v] == -1) {
                    q.push(v);
                    color[v] = 1-color[u];
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adj;

        // constructed a graph
        for(vector<int>&vec : dislikes) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>color(n+1,-1);

        for(int i = 1;i <= n;i++) {
            if(color[i] == -1) {
                if(!bfs(i,adj,color)) {
                    return false;
                }
            }
        }

        return true;
    }
};

// Using DFS

class Solution {
public:
    bool dfs(int u, unordered_map<int,vector<int>>&adj, vector<int>&color) {
        for(int &v : adj[u]) {
            if(color[u] == color[v]) {
                return false;
            }

            if(color[v] == -1) {
                color[v] = 1-color[u];
                if(!dfs(v,adj,color)) {
                    return false;
                }
            }
        }        

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adj;

        // constructed a graph
        for(vector<int>&vec : dislikes) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>color(n+1,-1);

        for(int i = 1;i <= n;i++) {
            if(color[i] == -1) {
                color[i] = 1;
                if(!dfs(i,adj,color)) {
                    return false;
                }
            }
        }

        return true;
    }
};