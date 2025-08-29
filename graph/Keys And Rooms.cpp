// Using DFS

class Solution {
public:
    void dfs(int u, vector<vector<int>>&rooms, vector<bool>&vis) {
        vis[u] = true;
        for(int &v : rooms[u]) {
            if(!vis[v]) {
                dfs(v,rooms,vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n,false);

        dfs(0,rooms,vis);

        for(bool room : vis) {
            if(!room) {
                return false;
            }
        }

        return true;
    }
};

// Using BFS

class Solution {
public:
    void bfs(int node, vector<vector<int>>&rooms, vector<bool>&vis) {
        queue<int>q;
        q.push(node);
        vis[node] = true;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int &v : rooms[u]) {
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n,false);

        bfs(0,rooms,vis);

        for(bool room : vis) {
            if(!room) {
                return false;
            }
        }

        return true;
    }
};