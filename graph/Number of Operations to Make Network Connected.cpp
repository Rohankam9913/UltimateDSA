// Using DSU

class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int componentCount = 0;

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
        } else if(rank[parent_y] > rank[parent_x]) {
            parent[parent_x] = parent_y;
        } else {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }

        componentCount--;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(n-1 > m) {
            return -1;
        }

        parent.resize(n);
        rank.resize(n);
        componentCount = n;

        for(int i = 0;i < n;i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for(vector<int>&edge : connections) {
            int u = edge[0];
            int v = edge[1];

            Union(u,v);
        }

        return m - componentCount;
    }
};

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

    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(n-1 > m) {
            return -1;
        }

        unordered_map<int,vector<int>>adj;
        for(vector<int>&edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n,false);
        int componentCount = 0;

        for(int i = 0;i < n;i++) {
            if(!vis[i]) {
                dfs(i,adj,vis);
                componentCount++;
            }
        }

        return m-componentCount;
    }
};

// Using BFS

/class Solution {
public:
    void bfs(int node,unordered_map<int,vector<int>>&adj,vector<bool>&vis) {
        vis[node] = true;
        queue<int>que;
        que.push(node);

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

    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(n-1 > m) {
            return -1;
        }

        unordered_map<int,vector<int>>adj;
        for(vector<int>&edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n,false);
        int componentCount = 0;

        for(int i = 0;i < n;i++) {
            if(!vis[i]) {
                bfs(i,adj,vis);
                componentCount++;
            }
        }

        return m-componentCount;
    }
};