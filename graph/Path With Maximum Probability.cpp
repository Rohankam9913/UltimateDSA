// Using Djikstra

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int m = edges.size();
        unordered_map<int,vector<pair<int,double>>>adj;

        for(int i = 0;i < m;i++) {
            int u       = edges[i][0];
            int v       = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }

        priority_queue<pair<double,int>>pq;
        pq.push({1.0, start_node});

        vector<double>probability(n,0);
        probability[start_node] = 1;

        while(!pq.empty()) {
            int u        = pq.top().second;
            double uProb = pq.top().first;
            pq.pop();

            if(u == end_node) {
                return uProb;
            }

            for(auto &P : adj[u]) {
                int v        = P.first;
                double vProb = P.second;

                if(probability[v] < uProb * vProb) {
                    probability[v] = uProb * vProb;
                    pq.push({probability[v], v});
                }
            } 
        }

        return 0;
    }
};