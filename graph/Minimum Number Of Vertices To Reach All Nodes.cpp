class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>result;

        vector<bool>indegree(n,false);
        for(vector<int>&edge : edges) {
            int u = edge[0];
            int v = edge[1];

            indegree[v] = true;
        }

        for(int i = 0;i < n;i++) {
            if(!indegree[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};