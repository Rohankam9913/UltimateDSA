// Using DFS

class Solution {
public:
    bool dfs(int u,vector<int>&color,vector<vector<int>>&graph,int curColor){
        color[u] = curColor;

        for(int &v : graph[u]) {
            if(color[u] == color[v]) {
                return false;
            }
            
            if(color[v] == -1 && !dfs(v,color,graph,1-curColor)) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);

        for(int i = 0;i < n;i++) {
            if(color[i] == -1 && !dfs(i,color,graph,1)) {
                return false;
            }
        }

        return true;
    }
};

// Using BFS

class Solution {
public:
    bool bfs(int node,vector<int>&color,vector<vector<int>>&graph){
        color[node] = 1;
        queue<int>que;
        que.push(node);

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(int &v : graph[u]) {
                if(color[u] == color[v]) {
                    return false;
                } else if(color[v] == -1) {
                    color[v] = 1-color[u];
                    que.push(v);
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);

        for(int i = 0;i < n;i++) {
            if(color[i] == -1 && !bfs(i,color,graph)) {
                return false;
            }
        }

        return true;
    }
};