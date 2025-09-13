// Using DFS

class Solution {
  public:
    bool dfs(int u,int par,vector<bool>&vis,unordered_map<int,vector<int>>&adj) {
        vis[u] = true;
        
        for(int &v : adj[u]) {
            if(v == par) {
                continue;
            }
            
            if(vis[v]) {
                return true;
            }
            
            if(!vis[v] && dfs(v,u,vis,adj)) {
                return true;
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        
        for(vector<int>&edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>vis(V,false);
        for(int i = 0;i < V;i++) {
            if(!vis[i] && dfs(i,-1,vis,adj)) {
                return true;
            }
        }
        
        return false;
    }
};

// Using BFS

class Solution {
  public:
    bool bfs(int node,vector<bool>&vis,unordered_map<int,vector<int>>&adj) {
        queue<pair<int,int>>que;
        que.push({node,-1});
        vis[node] = true;
        
        while(!que.empty()){
            int u   = que.front().first;
            int par = que.front().second;
            que.pop();
            
            for(int &v : adj[u]){
                if(v == par) {
                    continue;
                } else if(vis[v]) {
                    return true;
                } else {
                    que.push({v,u});
                    vis[v] = true;
                }
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        
        for(vector<int>&edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>vis(V,false);
        
        for(int i = 0;i < V;i++) {
            if(!vis[i] && bfs(i,vis,adj)) {
                return true;
            } 
        }
        
        return false;
    }
};