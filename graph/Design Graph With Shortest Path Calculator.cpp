// Using Djikstra Algorithm

class Graph {
public:
    typedef pair<int,int> P;

    unordered_map<int,vector<P>>adj;
    int N;

    Graph(int n, vector<vector<int>>& edges) : N(n){
        for(vector<int>&edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            adj[u].push_back({v,cost});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        adj[u].push_back({v,cost});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<P,vector<P>,greater<P>>pq;     
        pq.push({0,node1});

        vector<int>dist(N,INT_MAX);
        dist[node1] = 0;

        while(!pq.empty()) {
            int u     = pq.top().second;
            int costU = pq.top().first;
            pq.pop();

            for(P &p : adj[u]) {
                int v = p.first;
                int costV = p.second;

                if(dist[v] > costU + costV) {
                    dist[v] = costU + costV;
                    pq.push({dist[v], v});
                }
            }
        } 

        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};

// Using Floyd Warshall Algoritihm

class Graph {
public:
    vector<vector<int>>dist;
    int N;

    Graph(int n, vector<vector<int>>& edges) : N(n) {
        dist = vector<vector<int>>(n,vector<int>(n,1e9));

        for(int i = 0;i < n;i++) {
            dist[i][i] = 0;
        }

        for(vector<int>&edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            dist[u][v] = cost;
        }

        for(int via = 0;via < n;via++) {
            for(int u = 0;u < n;u++) {
                for(int v = 0;v < n;v++) {
                    if(dist[u][via] < 1e9 && dist[via][v] < 1e9) {
                        dist[u][v] = min(dist[u][v], dist[u][via] + dist[via][v]);
                    }
                }
            }
        }        
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        for(int i = 0;i < N;i++) {
            for(int j = 0;j < N;j++) {
                dist[i][j] = min(dist[i][j], dist[i][u] + cost + dist[v][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return dist[node1][node2] == 1e9 ? -1 : dist[node1][node2];
    }
};