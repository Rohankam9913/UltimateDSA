// Using Floyd Warshall

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        
        vector<vector<long long>>adjMatrix(26,vector<long long>(26,INT_MAX));

        for(int i = 0;i < n;i++) {
            int u = original[i]-'a';
            int v = changed[i]-'a';
            adjMatrix[u][v] = min(adjMatrix[u][v], (long long) cost[i]);
        }

        for(int k = 0;k < 26;k++) {
            for(int i = 0;i < 26;i++) {
                for(int j = 0;j < 26;j++) {
                    if(i == j) {
                        adjMatrix[i][j] = 0;
                        continue;
                    }

                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }

        long long minCost = 0;

        for(int i = 0;i < source.length();i++) {
            if(source[i] == target[i]) {
                continue;
            }

            int src = source[i]-'a';
            int tar = target[i]-'a';

            if(adjMatrix[src][tar] == INT_MAX) {
                return -1;
            }

            minCost += adjMatrix[src][tar];
        }

        return minCost;
    }
};

// Using Djikstra 

class Solution {
public:
    typedef pair<int,char> P;

    void djikstra(char &src, unordered_map<char,vector<pair<char,int>>> &adj, vector<vector<long long>>&dist){
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0, src});

        while(!pq.empty()){
            int d = pq.top().first;
            char u = pq.top().second;
            pq.pop();

            for(auto &node : adj[u]){
                char v = node.first;
                int w = node.second;

                if(dist[src-'a'][v-'a'] > (d + w)){
                    dist[src-'a'][v-'a'] = d + w;
                    pq.push({d+w, v});
                }
            }
        }

        
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char,vector<pair<char,int>>> adj;

        for(int i = 0;i < original.size();i++){
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        long long total_cost = 0;
        vector<vector<long long>>dist(26,vector<long long>(26,INT_MAX));
            
        for(int i = 0;i < source.length();i++){
            char src = source[i];
            djikstra(src,adj,dist);
        }

        for(int i = 0;i < source.length();i++){
            if(source[i] == target[i]){
                continue;
            }

            long long val = dist[source[i]-'a'][target[i]-'a'];
            if(val == INT_MAX){
                return -1;
            }

            total_cost += val;
        }

        return total_cost;
    }
};