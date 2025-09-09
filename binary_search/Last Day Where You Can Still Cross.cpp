// Using DFS

class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    bool dfs(int i,int j,vector<vector<int>>&grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) {
            return false;
        } 

        if(i == m-1) {
            return true;
        }

        grid[i][j] = 1;

        for(vector<int>&dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(dfs(new_i,new_j,grid)) {
                return true;
            }
        }

        return false;
    }

    bool isPossible(int mid, vector<vector<int>>&cells) {
        vector<vector<int>>grid(m,vector<int>(n,0));

        for(int i = 0;i <= mid;i++) {
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;

            grid[x][y] = 1;
        }

        for(int col = 0;col < n;col++) {
            if(grid[0][col] == 0 && dfs(0,col,grid)) {
                return true;
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        m = row, n = col;

        int lastDay = 0;

        int low = 0, high = cells.size()-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(isPossible(mid, cells)) {
                lastDay = mid+1;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return lastDay;
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

        while(!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            if(x == m-1) {
                return true;
            }

            for(vector<int>&dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == 0) {
                    que.push({new_x,new_y});
                    grid[new_x][new_y] = 1;
                }
            }
        }

        return false;
    }

    bool isPossible(int mid, vector<vector<int>>&cells) {
        vector<vector<int>>grid(m,vector<int>(n,0));

        for(int i = 0;i <= mid;i++) {
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;

            grid[x][y] = 1;
        }

        for(int col = 0;col < n;col++) {
            if(grid[0][col] == 0 && bfs(0,col,grid)) {
                return true;
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        m = row, n = col;

        int lastDay = 0;

        int low = 0, high = cells.size()-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(isPossible(mid, cells)) {
                lastDay = mid+1;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return lastDay;
    }
};