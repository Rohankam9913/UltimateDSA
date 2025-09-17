// Using DFS

class Solution {
public:
    void dfs(int u,vector<int>&edges,vector<bool>&vis,vector<bool>&inRecursion,vector<int>&count,int &result) {
        vis[u] = true;
        inRecursion[u] = true;
        
        int v = edges[u];

        if(v != -1) {
            if(!vis[v]) {
                count[v] += count[u];
                dfs(v,edges,vis,inRecursion,count,result);
            } else if(inRecursion[v]) {
                result = max(result,count[u]-count[v]+1);
            }
        }

        inRecursion[u] = false;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        vector<bool>vis(n,false);
        vector<bool>inRecursion(n,false);
        vector<int>count(n,1);

        int result = -1;
        for(int i = 0;i < n;i++) {
            if(!vis[i]) {
                dfs(i,edges,vis,inRecursion,count,result);
            }
        }

        return result;
    }
};