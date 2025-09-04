// Using BFS

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(vector<int>&flight : flights) {
            int u    = flight[0];
            int v    = flight[1];
            int cost = flight[2];

            adj[u].push_back({v,cost});
        }

        vector<int>dist(n,INT_MAX);
        dist[src] = 0;

        queue<pair<int,int>>que;
        que.push({src,0});

        int stops = 0;
        while(!que.empty() && stops <= k) {
            int size = que.size();
            while(size--) {
                pair<int,int>curP = que.front();
                que.pop();

                int u = curP.first;
                int costToReachU = curP.second;

                for(pair<int,int>&adjP : adj[u]) {
                    int v = adjP.first;
                    int costToReachV = adjP.second;

                    if(dist[v] > costToReachU + costToReachV) {
                        dist[v] = costToReachU + costToReachV;
                        que.push({v,costToReachU + costToReachV});
                    }
                }
            }
            stops++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};