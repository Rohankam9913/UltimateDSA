// Using DFS

class Solution {
public:
    bool isSimilar(string &s1, string &s2) {
        int n = s1.length(), diffCount = 0;
        for(int i = 0;i < n;i++) {
            if(s1[i] != s2[i]) {
                diffCount++;
            }
        }

        return diffCount == 0 || diffCount == 2;
    }

    void dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&vis) {
        vis[u] = true;

        for(int &v : adj[u]) {
            if(!vis[v]) {
                dfs(v,adj,vis);
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        unordered_map<int,vector<int>>adj;

        for(int i = 0;i < n;i++) {
            for(int j = i+1;j < n;j++) {
                if(isSimilar(strs[i], strs[j]))  {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int groups = 0;
        vector<bool>vis(n,false);

        for(int i = 0;i < n;i++) {
            if(!vis[i]) {
                dfs(i,adj,vis);
                groups++;
            }
        }

        return groups;
    }
};

// Using BFS

class Solution {
public:
    bool isSimilar(string &s1, string &s2) {
        int n = s1.length(), diffCount = 0;
        for(int i = 0;i < n;i++) {
            if(s1[i] != s2[i]) {
                diffCount++;
            }
        }

        return diffCount == 0 || diffCount == 2;
    }

    void bfs(int node,unordered_map<int,vector<int>>&adj,vector<bool>&vis) {
        vis[node] = true;
        queue<int>que;
        que.push(node);

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(int &v : adj[u]) {
                if(!vis[v]) {
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        unordered_map<int,vector<int>>adj;

        for(int i = 0;i < n;i++) {
            for(int j = i+1;j < n;j++) {
                if(isSimilar(strs[i], strs[j]))  {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int groups = 0;
        vector<bool>vis(n,false);

        for(int i = 0;i < n;i++) {
            if(!vis[i]) {
                bfs(i,adj,vis);
                groups++;
            }
        }

        return groups;
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

    bool isSimilar(string &s1, string &s2) {
        int n = s1.length(), diffCount = 0;
        for(int i = 0;i < n;i++) {
            if(s1[i] != s2[i]) {
                diffCount++;
            }
        }

        return diffCount == 0 || diffCount == 2;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        parent.resize(n);
        rank.resize(n);

        for(int i = 0;i < n;i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        int groups = n;

        for(int i = 0;i < n;i++) {
            for(int j = i+1;j < n;j++) {
                if(isSimilar(strs[i],strs[j]) && find(i) != find(j)) {
                    Union(i,j);
                    groups--;
                }
            }
        }      

        return groups;
    }
};