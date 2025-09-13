// Using DFS

class Solution {
  public:
    bool dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&vis,vector<bool>&inRecursion) {
        vis[u] = true;
        inRecursion[u] = true;
        
        for(int &v : adj[u]) {
            if(!vis[v] && dfs(v,adj,vis,inRecursion)) {
                return true;
            } else if(inRecursion[v]) {
                return true;
            }
        }
        
        inRecursion[u] = false;
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int,vector<int>>adj;
        
        for(vector<int>&edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
            
        
        vector<bool>vis(V,false);
        vector<bool>inRecursion(V,false);
        
        for(int i = 0;i < V;i++) {
            if(!vis[i] && dfs(i,adj,vis,inRecursion)) {
                return true;
            }
        }
        
        return false;
    }
};

// Using BFS

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int>indegree(V);
        unordered_map<int,vector<int>>adj;
        
        for(vector<int>&edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int>que;
        for(int i = 0;i < V;i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }
        
        int count = 0;
        
        while(!que.empty()) {
            int u = que.front();
            count++;
            que.pop();
            
            for(int &v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }
        
        return count != V;
    }
};