// Using BFS (Kahns Algo)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);

        for(vector<int>&vec : prerequisites) {
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int>que;
        for(int i = 0;i < numCourses;i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<int>courseOrder;
        while(!que.empty()) {
            int u = que.front();
            courseOrder.push_back(u);
            que.pop();

            for(int &v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        if(courseOrder.size() == numCourses) {
            return courseOrder;
        }

        return {};
    }
};

// Using DFS

class Solution {
public:
    void dfs(int u,vector<bool>&vis,unordered_map<int,vector<int>>&adj,stack<int>&st) {
        vis[u] = true;

        for(int &v : adj[u]) {
            if(!vis[v]) {
                dfs(v,vis,adj,st);
            }
        }

        st.push(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;

        for(vector<int>&vec : prerequisites) {
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u);
        }

        vector<bool>vis(numCourses,false);
        stack<int>st;

        for(int i = 0;i < numCourses;i++) {
            if(!vis[i]) {
                dfs(i,vis,adj,st);
            }
        }

        vector<int>courseOrder;
        if(st.size() == numCourses) {
            while(!st.empty()) {
                courseOrder.push_back(st.top());
                st.pop();
            }
        }

        return courseOrder;
    }
};