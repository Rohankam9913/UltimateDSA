class Solution {
public:
    int dfs(int cur,int par,unordered_map<int,vector<int>>&adj,string &s,int &maxPathLength) {
        int max1 = 0,max2 = 0;
        for(int &child : adj[cur]) {
            if(child == par) {
                continue;
            }

            int pathLength = dfs(child,cur,adj,s,maxPathLength);
            if(s[cur] == s[child]) {
                continue;
            }

            if(pathLength > max2) {
                max2 = pathLength;
            }

            if(max2 > max1) {
                swap(max1, max2);
            }
        }

        int case_1 = 1 + max1 + max2;
        int case_2 = 1 + max(max1,max2);
        int case_3 = 1;

        maxPathLength = max({maxPathLength,case_1,case_2,case_3});
        return max(case_2,case_3);
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        unordered_map<int,vector<int>>adj;

        for(int i = 1;i < n;i++) {
            int u = i;
            int v = parent[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxPathLength = 0;
        dfs(0,-1,adj,s,maxPathLength);
        return maxPathLength;
    }
};