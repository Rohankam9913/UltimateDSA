// Using DFS

class Solution {
public:
    void dfs(string u, string &dest, unordered_map<string,vector<pair<string,double>>>&adj,double prod,double &result, unordered_set<string>&vis) {

        vis.insert(u);

        if(u == dest) {
            result = prod;
            return;
        }

        for(auto &P : adj[u]) {
            string v = P.first;
            double cost = P.second;

            if(vis.find(v) == vis.end()) {
                prod *= cost;
                dfs(v,dest,adj,prod,result,vis);
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string,vector<pair<string,double>>>adj;

        for(int i = 0;i < n;i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double cost = values[i];

            adj[u].push_back({v,cost});
            adj[v].push_back({u,1.0/cost});
        }

        vector<double>queryResult;

        for(vector<string>&query : queries) {
            string src = query[0];
            string dst = query[1];

            double result = -1.0;

            if(adj.find(src) != adj.end()) {
                unordered_set<string>vis;
                dfs(src,dst,adj,1.0,result,vis);
            }            

            queryResult.push_back(result);
            
        }

        return queryResult;
    }
};

// Using BFS

class Solution {
public:
    void bfs(string &src, string &dst, unordered_map<string,vector<pair<string,double>>>&adj,double &result) {
        unordered_set<string>vis;
        vis.insert(src);

        queue<pair<string,double>>que;
        que.push({src,1.0});

        double prod = 1.0;

        while(!que.empty()){
            string u = que.front().first;
            double costU = que.front().second;
            que.pop();

            if(u == dst) {
                result = costU;
                break;
            }

            for(auto &P : adj[u]) {
                string v = P.first;
                double costV = P.second;

                if(vis.find(v) == vis.end()) {
                    vis.insert(v);
                    que.push({v,costU * costV});
                }
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string,vector<pair<string,double>>>adj;

        for(int i = 0;i < n;i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double cost = values[i];

            adj[u].push_back({v,cost});
            adj[v].push_back({u,1.0/cost});
        }

        vector<double>queryResult;

        for(vector<string>&query : queries) {
            string src = query[0];
            string dst = query[1];

            double result = -1.0;

            if(adj.find(src) != adj.end()) {
                bfs(src,dst,adj,result);
            }            

            queryResult.push_back(result);
            
        }

        return queryResult;
    }
};