// Using DFS

class Solution {
public:
    int m,n;

    void dfs(int i,int j,vector<vector<int>>&grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;
        dfs(i-1,j,grid); // top
        dfs(i,j+1,grid); // right
        dfs(i+1,j,grid); // down
        dfs(i,j-1,grid); // left
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int col = 0;col < n;col++) {
            if(grid[0][col] == 1) {
                dfs(0,col,grid);
            }

            if(grid[m-1][col] == 1) {
                dfs(m-1,col,grid);
            }
        }

        for(int row = 0;row < m;row++) {
            if(grid[row][0] == 1) {
                dfs(row,0,grid);
            }

            if(grid[row][n-1] == 1) {
                dfs(row,n-1,grid);
            }
        }

        int countOfEnclaves = 0;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 1) {
                    countOfEnclaves++;
                }
            }
        }

        return countOfEnclaves;
    }
};

// Using BFS

class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    void bfs(int i,int j,vector<vector<int>>&grid) {
        grid[i][j] = 0;
        queue<pair<int,int>>que;
        que.push({i,j});

        while(!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            for(vector<int>&dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == 1) {
                    grid[new_x][new_y] = 0;
                    que.push({new_x,new_y});
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int col = 0;col < n;col++) {
            if(grid[0][col] == 1) {
                bfs(0,col,grid);
            }

            if(grid[m-1][col] == 1) {
                bfs(m-1,col,grid);
            }
        }

        for(int row = 0;row < m;row++) {
            if(grid[row][0] == 1) {
                bfs(row,0,grid);
            }

            if(grid[row][n-1] == 1) {
                bfs(row,n-1,grid);
            }
        }

        int countOfEnclaves = 0;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 1) {
                    countOfEnclaves++;
                }
            }
        }

        return countOfEnclaves;
    }
};