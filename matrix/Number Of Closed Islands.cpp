// Using DFS

class Solution {
public:
    int m,n;

    bool dfs(int i,int j,vector<vector<int>>&grid) {
        if(i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }

        if(grid[i][j] == 1) {
            return true;
        }

        grid[i][j] = 1;

        bool top    = dfs(i-1,j,grid);
        bool right  = dfs(i,j+1,grid);
        bool down   = dfs(i+1,j,grid);
        bool left   = dfs(i,j-1,grid);

        return top && right && down && left;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int countOfClosedIslands = 0;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 0 && dfs(i,j,grid)) {
                   countOfClosedIslands++;
                }
            }
        }

        return countOfClosedIslands;
    }
};

// Using BFS

class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    bool bfs(int i,int j,vector<vector<int>>&grid) {
        queue<pair<int,int>>que;
        que.push({i,j});
        grid[i][j] = 1;
        bool isClosedIsland = true;

        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();

            if (x == 0 || x == m - 1 || y == 0 || y == n - 1) {
                isClosedIsland = false;
            }

            for (auto& dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == 0) {
                    grid[new_x][new_y] = 1;
                    que.push({new_x, new_y});
                }
            }
        }   

        return isClosedIsland;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int countOfClosedIslands = 0; 

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 0 && bfs(i,j,grid)) {
                    countOfClosedIslands++;
                }   
            }
        }

        return countOfClosedIslands;
    }
};