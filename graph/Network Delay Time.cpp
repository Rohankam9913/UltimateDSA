class Solution {
public:
    typedef pair<int,int> P;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<P>>adj;

        for(vector<int>&edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
        }

        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,k});

        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;

        while(!pq.empty()) {
            int u = pq.top().second;
            int timeToReachNodeU = pq.top().first;
            pq.pop();

            for(P &p : adj[u]) {
                int v = p.first;
                int timeToReachNodeV = p.second;

                if(dist[v] > timeToReachNodeU + timeToReachNodeV) {
                    dist[v] = timeToReachNodeU + timeToReachNodeV;
                    pq.push({dist[v],v});
                }
            }
        }

        int minTime = *max_element(begin(dist)+1, end(dist));
        return minTime == INT_MAX ? -1 : minTime;
    }
};