// Using DFS

class Solution {
public:
    bool dfs(int u, vector<vector<int>>&adj, vector<bool>&vis, vector<bool>&inRecursion) {
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

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool>vis(n,false);
        vector<bool>inRecursion(n,false);

        for(int i = 0;i < n;i++) {
            if(!vis[i]) {
                dfs(i,graph,vis,inRecursion);
            }
        }

        vector<int>result;

        for(int i = 0;i < n;i++) {
            if(!inRecursion[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};

// Using BFS

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int>indegree(n,0);
        unordered_map<int,vector<int>>adj;

        for(int i = 0;i < n;i++) {
            for(int &node : graph[i]) {
                adj[node].push_back(i);
                indegree[i]++;
            }
        }

        queue<int>que;
        vector<int>result;

        for(int i = 0;i < n;i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        while(!que.empty()){
            int u = que.front();
            result.push_back(u);
            que.pop();

            for(int &v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        sort(begin(result), end(result));
        return result;
    }
};