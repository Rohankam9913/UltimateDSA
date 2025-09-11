// Using DFS

class Solution {
public:
    bool dfs(int u,int dest,int limit,unordered_map<int,vector<pair<int,int>>>&adj, vector<bool>&vis) {
        vis[u] = true;

        if(u == dest) {
            return true;
        }

        for(auto &P : adj[u]) {
            int v    = P.first;
            int dist = P.second;

            if(!vis[v] && dist < limit && dfs(v,dest,limit,adj,vis)) {
                return true;
            } 
        }

        return false;
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(vector<int>&edge : edges) {
            int u    = edge[0];
            int v    = edge[1];
            int dist = edge[2];

            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }

        vector<bool>result;

        for(vector<int>&query : queries) {
            int p     = query[0];
            int q     = query[1];
            int limit = query[2];

            vector<bool>vis(n,false);

            bool queryResult = dfs(p,q,limit,adj,vis);
            result.push_back(queryResult);
        }

        return result;
    }
};

// Using BFS

class Solution {
public:
    bool bfs(int src,int dest,int limit,unordered_map<int,vector<pair<int,int>>>&adj,vector<bool>&vis) {
        vis[src] = true;
        queue<int>que;
        que.push(src);

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            if(u == dest) {
                return true;
            }

            for(auto &P : adj[u]) {
                int v    = P.first;
                int dist = P.second;

                if(!vis[v] && limit > dist) {
                    que.push(v);
                    vis[v] = true;
                }
            }
        } 

        return false;
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(vector<int>&edge : edges) {
            int u    = edge[0];
            int v    = edge[1];
            int dist = edge[2];

            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }

        vector<bool>result;

        for(vector<int>&query : queries) {
            int p     = query[0];
            int q     = query[1];
            int limit = query[2];

            vector<bool>vis(n,false);

            bool queryResult = bfs(p,q,limit,adj,vis);
            result.push_back(queryResult);
        }

        return result;
    }
};

// Using DSU (Most Optimized Approach)

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

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int qSize = queries.size();
        int eSize = edges.size();

        parent.resize(n);
        rank.resize(n);

        for(int i = 0;i < n;i++) {
            parent[i] = i;
            rank[i] = i;
        }

        for(int i = 0;i < qSize;i++) {
            queries[i].push_back(i);
        }

        auto lambda = [&](vector<int>&a, vector<int>&b) {
            return a[2] < b[2];
        };

        sort(begin(edges), end(edges), lambda); 
        sort(begin(queries), end(queries), lambda);

        vector<bool>result(qSize,false);
        int ptr = 0;

        for(int i = 0;i < qSize;i++) {
            int p     = queries[i][0];
            int q     = queries[i][1];
            int limit = queries[i][2];
            int idx   = queries[i][3];

            while(ptr < eSize && edges[ptr][2] < limit) {
                Union(edges[ptr][0], edges[ptr][1]);
                ptr++;
            }

            if(find(p) == find(q)) {
                result[idx] = true;
            }
        } 

        return result;    
    }
};