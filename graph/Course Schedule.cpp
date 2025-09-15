// Using DFS

class Solution {
public:
    bool dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&vis,vector<bool>&inRecursion) {
        vis[u] = true;
        inRecursion[u] = true;

        for(int &v : adj[u]) {
            if(!vis[v] && dfs(v,adj,vis,inRecursion)) {
                return true;
            } else if(inRecursion[v]) {
                return true;
            }
        }

        inRecursion[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;

        for(vector<int>vec : prerequisites) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
        }

        vector<bool>vis(numCourses,false);
        vector<bool>inRecursion(numCourses,false);

        for(int i = 0;i < numCourses;i++) {
            if(!vis[i] && dfs(i,adj,vis,inRecursion)) {
                return false;
            }
        }

        return true;
    }
};

// Using BFS

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);

        for(vector<int>vec : prerequisites) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int>que;
        for(int i = 0;i < numCourses;i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        int count = 0;
        while(!que.empty()) {
            int u = que.front();
            count++;
            que.pop();

            for(int &v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        return count == numCourses;
    }
};