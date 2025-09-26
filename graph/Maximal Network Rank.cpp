// Using Vector

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<int>>adj;

        for(vector<int>&road : roads) {
            int u = road[0];
            int v = road[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxRank = 0;

        for(int i = 0;i < n;i++) {
            for(int j = i+1;j < n;j++) {
                int iRank = adj[i].size();
                int jRank = adj[j].size();
                int rank = iRank + jRank;

                if(find(adj[i].begin(), adj[i].end(), j) != adj[i].end()) {
                    rank--;
                }

                maxRank = max(maxRank,rank);
            }
        }

        return maxRank;
    }
};

// Using set

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,unordered_set<int>>adj;

        for(vector<int>&road : roads) {
            int u = road[0];
            int v = road[1];

            adj[u].insert(v);
            adj[v].insert(u);
        }

        int maxRank = 0;

        for(int i = 0;i < n;i++) {
            for(int j = i+1;j < n;j++) {
                int iRank = adj[i].size();
                int jRank = adj[j].size();
                int rank = iRank + jRank;

                if(adj[i].find(j) != adj[i].end()) {
                    rank--;
                }

                maxRank = max(maxRank,rank);
            }
        }

        return maxRank;
    }
};

// Without using adjacency list

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>totalConnections(n);
        vector<vector<bool>>isConnected(n,vector<bool>(n,false));

        for(vector<int>&road : roads) {
            int u = road[0];
            int v = road[1];

            totalConnections[u]++;
            totalConnections[v]++;

            isConnected[u][v] = true; 
            isConnected[v][u] = true;
        }

        int maxRank = 0;

        for(int i = 0;i < n;i++) {
            for(int j = i+1;j < n;j++) {
                int iRank = totalConnections[i];
                int jRank = totalConnections[j];
                int rank = iRank + jRank;

                if(isConnected[i][j]) {
                    rank--;
                }

                maxRank = max(maxRank,rank);
            }
        }

        return maxRank;
    }
};