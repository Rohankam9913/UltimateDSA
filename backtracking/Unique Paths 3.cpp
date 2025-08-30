class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    void solve(vector<vector<int>>&grid,int i,int j, int count, int &nonObstaclesCount, int &result) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) {
            return;
        }

        if(grid[i][j] == 2) {
            if(count == nonObstaclesCount) {
                result++;
            }
            return;
        }

        grid[i][j] = -1;

        for(vector<int>&dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            solve(grid,new_i,new_j,count+1,nonObstaclesCount,result);
        }

        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int nonObstaclesCount = 0;
        int start_x = 0, start_y = 0;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 0) {
                    nonObstaclesCount++;
                }
                
                if(grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;
                    nonObstaclesCount++;
                }
            }
        }

        int result = 0;
        solve(grid,start_x,start_y,0,nonObstaclesCount,result);
        return result;
    }
};