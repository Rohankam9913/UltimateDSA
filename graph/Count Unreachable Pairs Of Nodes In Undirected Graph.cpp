// Using DFS

class Solution {
public:
    void dfs(int u, unordered_map<int,vector<int>>&adj, vector<bool>&vis, int &countOfNodes) {
        vis[u] = true;
        countOfNodes++;

        for(int &v : adj[u]) {
            if(!vis[v]) {
                dfs(v,adj,vis,countOfNodes);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        
        for(vector<int>&edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n,false);
        long long totalPairs = 0;
        int totalNodes = n;

        for(int i = 0;i < n;i++) {
            if(!vis[i]) {
                int countOfNodes = 0;
                dfs(i,adj,vis,countOfNodes);

                totalPairs += countOfNodes * (totalNodes - countOfNodes);
                totalNodes -= countOfNodes;
            }
        }

        return totalPairs;
    }
};

// Using BFS

class Solution {
public:
    void bfs(int node, unordered_map<int,vector<int>>&adj, vector<bool>&vis, int &countOfNodes) {
        vis[node] = true;
        queue<int>que;
        que.push(node);

        while(!que.empty()) {
            int u = que.front();
            countOfNodes++;
            que.pop();

            for(int &v : adj[u]) {
                if(!vis[v]) {
                    que.push(v);
                    vis[v] = true;
                }
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        
        for(vector<int>&edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n,false);
        long long totalPairs = 0;
        int totalNodes = n;

        for(int i = 0;i < n;i++) {
            if(!vis[i]) {
                int countOfNodes = 0;
                bfs(i,adj,vis,countOfNodes);

                totalPairs += countOfNodes * (totalNodes - countOfNodes);
                totalNodes -= countOfNodes;
            }
        }

        return totalPairs;
    }
};

// Using DSU

class Solution {
public:
    vector<int>parent;
    vector<int>rank;

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
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);

        for(int i = 0;i < n;i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        unordered_map<int,vector<int>>adj;
        for(vector<int>&edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>parentToNodeCount(n,0);

        for(int u = 0;u < n;u++) {
            for(int &v : adj[u]) {
                Union(u,v);
            }
        }

        for(int i = 0;i < n;i++) {
            parentToNodeCount[find(i)]++;
        }

        long long totalPairs = 0;
        int totalNodes = n;

        for(int i = 0;i < n;i++) {
            if(parentToNodeCount[i] == 0) {
                continue;
            }

            totalPairs += (long long) parentToNodeCount[i] * (totalNodes - parentToNodeCount[i]);
            totalNodes -= parentToNodeCount[i];
        }

        return totalPairs;
    }
};