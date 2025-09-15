// Using DFS

class Solution {
public:
    void dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&vis) {
        vis[u] = true;

        for(int &v : adj[u]) {
            if(!vis[v]) {
                dfs(v,adj,vis);
            }
        }
    }

    int findNumberOfProvinces(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int,vector<int>>adj;

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(i == j) {
                    continue;
                }

                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool>vis(n,false);
        int count = 0;

        for(int i = 0;i < n;i++) {
            if(!vis[i]) {
                dfs(i,adj,vis);
                count++;
            }
        }

        return count;
    }
};

// Using BFS

class Solution {
public:
    void bfs(int node,unordered_map<int,vector<int>>&adj,vector<bool>&vis) {
        queue<int>que;
        que.push(node);
        vis[node] = true;

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(int &v : adj[u]) {
                if(!vis[v]) {
                    que.push(v);
                    vis[v] = true;
                }
            }
        }
    }

    int findNumberOfProvinces(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int,vector<int>>adj;

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(i == j) {
                    continue;
                }

                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool>vis(n,false);
        int count = 0;

        for(int i = 0;i < n;i++) {
            if(!vis[i]) {
                bfs(i,adj,vis);
                count++;
            }
        }

        return count;
    }
};

// Using DSU

class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int countProvinces;

    int find(int x) {
        if(x == parent[x]) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x,int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y) {
            return;
        }

        if(rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        } else if(rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        } else {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }

        countProvinces--;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        countProvinces = n;

        parent.resize(n);
        rank.resize(n);

        for(int i = 0;i < n;i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(i == j) {
                    continue;
                }

                if(isConnected[i][j] == 1) {
                    Union(i,j);
                }
            }
        }
        
        return countProvinces;
    }
};