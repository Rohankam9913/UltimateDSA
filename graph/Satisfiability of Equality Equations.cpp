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

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);

        for(int i = 0;i < 26;i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for(string &equation : equations) {
            int var1 = equation[0]-'a';
            int var2 = equation[3]-'a';

            if(equation[1] == '=') {
                Union(var1,var2);
            } 
        }

        for(string &equation : equations) {
            int var1 = equation[0]-'a';
            int var2 = equation[3]-'a';

            if(equation[1] == '!' && find(var1) == find(var2)) {
                return false;
            }
        }

        return true;
    }
};

// Using DFS

class Solution {
public:
    bool dfs(int u,int dest,unordered_map<int,vector<int>>&adj,vector<bool>&vis) {
        if(u == dest) {
            return true;
        }

        vis[u] = true;
        for(int &v : adj[u]) {
            if(!vis[v] && dfs(v,dest,adj,vis)) {
                return true;
            }
        }

        return false;
    }

    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();

        unordered_map<int,vector<int>>adj;
        for(string &equation : equations) {
            int u = equation[0]-'a';
            int v = equation[3]-'a';

            if(equation[1] == '=') {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        for(string &equation : equations) {
            int u = equation[0]-'a';
            int v = equation[3]-'a';

            if(equation[1] == '!') {
                vector<bool>vis(26,false);
                if(dfs(u,v,adj,vis)) {
                    return false;
                }
            }
        }

        return true;
    }
};

// Using BFS

class Solution {
public:
    bool bfs(int src,int dest,unordered_map<int,vector<int>>&adj) {
        vector<bool>vis(26,false);
        vis[src] = true;

        queue<int>que;
        que.push(src);

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            if(u == dest) {
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

    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();

        unordered_map<int,vector<int>>adj;
        for(string &equation : equations) {
            int u = equation[0]-'a';
            int v = equation[3]-'a';

            if(equation[1] == '=') {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        for(string &equation : equations) {
            int u = equation[0]-'a';
            int v = equation[3]-'a';

            if(equation[1] == '!') {
                if(bfs(u,v,adj)) {
                    return false;
                }
            }
        }

        return true;
    }
};