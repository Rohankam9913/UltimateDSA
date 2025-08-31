// Using DFS

class Solution {
public:
    char dfs(char curCh, unordered_map<char,vector<char>>&adj, vector<bool>&vis) {
        vis[curCh-'a'] = true;

        char minChar = curCh;
        for(char &adjCh : adj[curCh]) {
            if(!vis[adjCh-'a']) {
                minChar = min(minChar, dfs(adjCh, adj, vis));
            }
        }

        return minChar; 
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();

        // created the graph
        unordered_map<char,vector<char>>adj;
        for(int i = 0;i < n;i++) {
            char u = s1[i];
            char v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result;
        for(int i = 0;i < m;i++) {
            vector<bool>vis(26,false);
            char minChar = dfs(baseStr[i], adj, vis);
            result.push_back(minChar);
        }

        return result;
    }
};

// Using BFS

class Solution {
public:
    char bfs(char curCh, unordered_map<char,vector<char>>&adj, vector<bool>&vis) {
        vis[curCh-'a'] = true;
        queue<char>que;
        que.push(curCh);

        char minChar = curCh;

        while(!que.empty()) {
            char cur = que.front();
            que.pop();
            minChar = min(minChar, cur);

            for(char &adjCh : adj[cur]) {
                if(!vis[adjCh-'a']) {
                    vis[adjCh-'a'] = true;
                    que.push(adjCh);
                }
            }
        }

        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();

        // created the graph
        unordered_map<char,vector<char>>adj;
        for(int i = 0;i < n;i++) {
            char u = s1[i];
            char v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result;
        for(int i = 0;i < m;i++) {
            vector<bool>vis(26,false);
            char minChar = bfs(baseStr[i], adj, vis);
            result.push_back(minChar);
        }

        return result;
    }
};