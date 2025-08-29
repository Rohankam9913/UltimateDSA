// Using DFS

class Solution {
public:
    void dfs(int u,int target,vector<vector<int>>&graph, vector<int>&path, vector<vector<int>>&result) {
        path.push_back(u);

        if(u == target) {
            result.push_back(path);
        }

        for(int &v : graph[u]) {
            dfs(v,target,graph,path,result);
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>result;
        vector<int>path;

        dfs(0,n-1,graph,path,result);

        return result;
    }
};
