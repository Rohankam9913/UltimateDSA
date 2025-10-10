// Using DFS with sorting

class Solution {
public:
    int n;

    void dfs(string &u, unordered_map<string,vector<string>>&adj,vector<string>&path,vector<string>&result) {
        path.push_back(u);

        if(path.size()-1 == n) {
            result = path;
            return;
        }

        vector<string>&neighbours = adj[u];

        for(int i = 0;i < neighbours.size();i++) {
            string v = neighbours[i];
            neighbours.erase(begin(neighbours) + i);

            dfs(v,adj,path,result);

            neighbours.insert(begin(neighbours) + i, v);
        }     
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();
        unordered_map<string,vector<string>>adj;

        for(vector<string>&ticket : tickets) {
            string from = ticket[0];
            string to   = ticket[1];

            adj[from].push_back(to);
        }

        for(auto &it : adj) {
            sort(begin(it.second), end(it.second));
        }

        vector<string>result;
        vector<string>path;
        string start = "JFK";

        dfs(start,adj,path,result);

        return result;
    }
};

// Using DFS with Heap

class Solution {
public:
    int n;
    typedef priority_queue<string,vector<string>,greater<string>> P;

    void dfs(string &u, unordered_map<string,P>&adj, vector<string>&path, vector<string>&result) {
        path.push_back(u);

        if(path.size()-1 == n) {
            result = path;
            return;
        }

        string v = adj[u].top();
        adj[u].pop();

        dfs(v,adj,path,result);

        adj[u].push(v);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();
        unordered_map<string,P>adj;

        for(vector<string>&ticket : tickets) {
            string u = ticket[0];
            string v = ticket[1];
            adj[u].push(v);   
        }

        vector<string>result;
        vector<string>path;
        string source = "JFK";

        dfs(source,adj,path,result);

        return result;
    }
};