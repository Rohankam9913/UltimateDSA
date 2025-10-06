// Using BFS

class Solution {
public:
    vector<int> bfs(int src,int n,unordered_map<int,vector<int>>&adj) {
        queue<int>que;
        que.push(src);

        vector<int>dist(n+1,INT_MAX);
        dist[src] = 0;

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(int &v : adj[u]) {
                if(dist[v] > dist[u] + 1) {
                    dist[v] = dist[u]+1;
                    que.push(v);
                }
            }
        }

        return dist;
    }

    vector<int> countOfPairs(int n, int x, int y) {
        unordered_map<int,vector<int>>adj;

        for(int i = 1;i < n;i++) {
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }

        adj[x].push_back(y);
        adj[y].push_back(x);

        vector<int>result(n);

        for(int src = 1;src <= n;src++) {
            vector<int>dist = bfs(src,n,adj);

            for(int i = 1;i <= n;i++) {
                int val = dist[i]-1;
                if (val >= 0) {
                    result[val]++;
                }
            }
        }

        return result;
    }
};

// Using Djikstra
class Solution {
public:
    vector<int> djikstra(int src,int n,unordered_map<int,vector<int>>&adj) {
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0,src});

       vector<int>dist(n+1,INT_MAX);
       dist[src] = 0;

       while(!pq.empty()) {
        int distU = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for(int &v : adj[u]) {
            if(dist[v] > distU + 1) {
                dist[v] = distU + 1;
                pq.push({dist[v], v});
            }
        }
       }

       return dist;
    }

    vector<int> countOfPairs(int n, int x, int y) {
        unordered_map<int,vector<int>>adj;

        for(int i = 1;i < n;i++) {
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }

        adj[x].push_back(y);
        adj[y].push_back(x);

        vector<int>result(n);

        for(int src = 1;src <= n;src++) {
            vector<int>dist = djikstra(src,n,adj);

            for(int i = 1;i <= n;i++) {
                int val = dist[i]-1;
                if (val >= 0) {
                    result[val]++;
                }
            }
        }

        return result;
    }
};

// Using Floyd Warshall

class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>>adjMatrix(n+1,vector<int>(n+1,1e6));

        for(int i = 1;i < n;i++) {
            adjMatrix[i][i+1] = 1;
            adjMatrix[i+1][i] = 1;
        }

        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;

        for(int via = 1;via <= n;via++) {
            for(int i = 1;i <= n;i++) {
                for(int j = 1;j <= n;j++) {
                    if(i == j) {
                        adjMatrix[i][j] = 0;
                    } else {
                        adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][via] + adjMatrix[via][j]);
                    }
                }
            }
        }

        vector<int>result(n,0);

        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(i == j) {
                    continue;
                }

                result[adjMatrix[i][j]-1]++;
            }
        }

        return result;
    }
};
