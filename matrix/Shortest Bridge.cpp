// Using DFS + BFS

class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    bool isValid(int i,int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int bfs(vector<vector<int>>&grid,set<pair<int,int>>&vis) {
        queue<pair<int,int>>que(begin(vis),end(vis));
        int flips = 0;

        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                pair<int,int>cell = que.front();
                int i = cell.first;
                int j = cell.second;
                que.pop();

                for(vector<int>&dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(isValid(new_i,new_j) && vis.find({new_i,new_j}) == vis.end()) {
                        if(grid[new_i][new_j] == 1) {
                            return flips;
                        } 

                        que.push({new_i,new_j});
                        vis.insert({new_i,new_j});
                    }
                }
            }

            flips++;
        }

        return 0;
    }

    void dfs(int i,int j,vector<vector<int>>&grid,set<pair<int,int>>&vis) {
        vis.insert({i,j});

        for(vector<int>&dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(isValid(new_i,new_j) && grid[new_i][new_j] == 1 && vis.find({new_i,new_j}) == vis.end()) {
                dfs(new_i,new_j,grid,vis);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        set<pair<int,int>>vis;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 1) {
                    dfs(i,j,grid,vis);
                    return bfs(grid,vis);
                }
            }
        } 

        return -1;
    }
};

// Using BFS + BFS

class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    bool isValid(int i,int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int findLeastFlips(vector<vector<int>>&grid,set<pair<int,int>>&vis) {
        queue<pair<int,int>>que(begin(vis),end(vis));
        int flips = 0;

        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                pair<int,int>cell = que.front();
                int i = cell.first;
                int j = cell.second;
                que.pop();

                for(vector<int>&dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(isValid(new_i,new_j) && vis.find({new_i,new_j}) == vis.end()) {
                        if(grid[new_i][new_j] == 1) {
                            return flips;
                        } 

                        que.push({new_i,new_j});
                        vis.insert({new_i,new_j});
                    }
                }
            }

            flips++;
        }

        return 0;
    }

    void bfs(int i,int j,vector<vector<int>>&grid,set<pair<int,int>>&vis) {
        vis.insert({i,j});
        queue<pair<int,int>>que;
        que.push({i,j});

        while(!que.empty()) {
            pair<int,int>cell = que.front();
            int x = cell.first;
            int y = cell.second;
            que.pop();

            for(vector<int>&dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(isValid(new_x,new_y) && grid[new_x][new_y] == 1 && vis.find({new_x,new_y}) == vis.end()) {
                    que.push({new_x,new_y});
                    vis.insert({new_x,new_y});
                }
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        set<pair<int,int>>vis;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 1) {
                    bfs(i,j,grid,vis);
                    return findLeastFlips(grid,vis);
                }
            }
        } 

        return -1;
    }
};