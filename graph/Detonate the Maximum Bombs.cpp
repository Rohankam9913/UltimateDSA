// Using DFS

class Solution {
public:
    typedef long long ll;

    void dfs(int u,int &count,unordered_map<int,vector<int>>&adj,vector<bool>&vis) {
        vis[u] = true;
        count++;

        for(int &v : adj[u]) {
            if(!vis[v]) {
                dfs(v,count,adj,vis);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        unordered_map<int,vector<int>>adj;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(i == j) {
                    continue;
                }

                ll x1 = bombs[i][0];
                ll y1 = bombs[i][1];
                ll R  = bombs[i][2];

                ll x2 = bombs[j][0];
                ll y2 = bombs[j][1];

                ll dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
                if((ll) R*R >= dist) {
                    adj[i].push_back(j);
                }
            }
        }

        int result = 0;

        for(int bomb = 0;bomb < n;bomb++) {
            vector<bool>vis(n,false);
            int count = 0;
            dfs(bomb,count,adj,vis);

            result = max(result,count);
        }  

        return result;    
    }
};

// Using BFS

class Solution {
public:
    typedef long long ll;

    int bfs(int node,unordered_map<int,vector<int>>&adj,vector<bool>&vis) {
        vis[node] = true;

        queue<int>que;
        que.push(node);

        int count = 0;

        while(!que.empty()) {
            int u = que.front();
            count++;
            que.pop();

            for(int &v : adj[u]) {
                if(!vis[v]) {
                    que.push(v);
                    vis[v] = true;
                }
            }
        }   

        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        unordered_map<int,vector<int>>adj;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(i == j) {
                    continue;
                }

                ll x1 = bombs[i][0];
                ll y1 = bombs[i][1];
                ll R  = bombs[i][2];

                ll x2 = bombs[j][0];
                ll y2 = bombs[j][1];

                ll dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
                if((ll) R*R >= dist) {
                    adj[i].push_back(j);
                }
            }
        }

        int result = 0;

        for(int bomb = 0;bomb < n;bomb++) {
            vector<bool>vis(n,false);

            int count = bfs(bomb,adj,vis);
            result = max(result,count);
        }  

        return result;    
    }
};