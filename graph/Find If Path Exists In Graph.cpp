// Using DFS

class Solution {
public:
    bool dfs(int u,int destination,unordered_map<int,vector<int>>&adj, vector<bool>&vis) {
        if(u == destination) {
            return true;
        }

        vis[u] = true;

        for(int &v : adj[u]) {
            if(!vis[v]) {
               if(dfs(v,destination,adj,vis)) {
                return true;
               }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adj;

        for(vector<int>&edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n,false);
        vis[source] = true;

        return dfs(source,destination,adj,vis);
    }
};

// Using BFS

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adj;

        for(vector<int>&edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int>que;
        que.push(source);

        vector<bool>vis(n,false);
        vis[source] = true;

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            if(u == destination) {
                return true;
            }

            for(int &v : adj[u]) {
                if(!vis[v]) {
                    que.push(v);
                    vis[v] = true;
                }
            }
        }

        return false;
    }
};

// Using DSU

class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int components;

    int find(int i) {
        if(i == parent[i]) {
            return i;
        }

        return parent[i] = find(parent[i]);
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


        components--;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adj;

        for(vector<int>&edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        parent.resize(n);
        rank.resize(n);

        for(int i = 0;i < n;i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        components = n;
        for(int u = 0;u < n;u++) {
            for(int &v : adj[u]) {
                Union(u,v);
            }
        }
        
        return components == 1;      
    }
};