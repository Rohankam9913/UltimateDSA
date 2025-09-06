// Using DFS

class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    bool isValid(int i,int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void dfs(int i,int j,vector<vector<char>>&grid) {
        grid[i][j] = '0';

        for(vector<int>&dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(isValid(new_i,new_j) && grid[new_i][new_j] == '1') {
                dfs(new_i,new_j,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int numberOfIslands = 0;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == '1') {
                    dfs(i,j,grid);
                    numberOfIslands++;
                }
            }
        }

        return numberOfIslands;
    }
};

// Using BFS

class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    bool isValid(int i,int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void bfs(int x,int y,vector<vector<char>>&grid) {
        grid[x][y] = '0';
        queue<pair<int,int>>que;
        que.push({x,y});

        while(!que.empty()) {
            int i = que.front().first;
            int j = que.front().second;
            que.pop();

            for(vector<int>&dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(isValid(new_i,new_j) && grid[new_i][new_j] == '1') {
                    que.push({new_i,new_j});
                    grid[new_i][new_j] = '0';
                }
            }   
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int numberOfIslands = 0;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == '1') {
                    bfs(i,j,grid);
                    numberOfIslands++;
                }
            }
        }

        return numberOfIslands;
    }
};