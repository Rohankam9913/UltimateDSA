// Using Topological sorting

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n,0);
        vector<int>timeTaken(n,INT_MIN);
        queue<int>que;

        for(vector<int>&relation : relations) {
            int u = relation[0]-1;
            int v = relation[1]-1;

            adj[u].push_back(v);
            indegree[v]++;
        }

        for(int i = 0;i < n;i++) {
            if(indegree[i] == 0) {
                que.push(i);
                timeTaken[i] = time[i];
            }
        }

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(int &v : adj[u]) {
                timeTaken[v] = max(timeTaken[v], timeTaken[u] + time[v]);    
                indegree[v]--;

                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        return *max_element(begin(timeTaken), end(timeTaken));
    }
};