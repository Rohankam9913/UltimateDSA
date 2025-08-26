// Approach 1 - Using DFS

class Solution {
public:
    int n;

    void dfs(int u, vector<bool>&vis, vector<vector<int>>&stones) {
        vis[u] = true;
        for(int v = 0;v < n;v++) {
            if(!vis[v] && ((stones[u][0] == stones[v][0]) || (stones[u][1] == stones[v][1]))) {
                dfs(v,vis,stones);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();

        vector<bool>vis(n,false);
        int groups = 0;

        for(int i = 0;i < n;i++) {
            if(!vis[i]) {
                dfs(i,vis,stones);
                groups++;
            }
        }

        return n - groups;
    }
};

// Approach 2 - Using DSU

class Solution {
public:
    int n;
    vector<int>parent;
    vector<int>rank;

    int find(int i) {
        if(parent[i] != i) {
            parent[i] = find(parent[i]);
        }

        return parent[i];
    }

    void Union(int i,int j) {
        int parent_i = find(i);
        int parent_j = find(j);

        if(parent_i == parent_j) {
            return;
        }

        if(rank[parent_i] > rank[parent_j]) {
            parent[parent_j] = parent_i;
        } else if(rank[parent_j] > rank[parent_i]) {
            parent[parent_i] = parent_j;
        } else {
            parent[parent_i] = parent_j;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        parent.resize(n,0);
        rank.resize(n,0);

        for(int i = 0;i < n;i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for(int i = 0;i < n;i++) {
            for(int j = i+1;j < n;j++) {
                if((stones[i][0] == stones[j][0]) || (stones[i][1] == stones[j][1])) {
                    Union(i,j);
                }
            }          
        }

        int groups = 0;
        for(int i = 0;i < n;i++) {
            if(i == parent[i]) {
                groups++;
            }
        }

        return n - groups;
    }
};