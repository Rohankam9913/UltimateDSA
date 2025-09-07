class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>result(n);

        for(int ball = 0;ball < n;ball++) {
            int row = 0;
            int col = ball;

            bool isNotStuck = true;
            while(row < m && col < n) {
                if(grid[row][col] == 1) {
                    if(col == n-1 || grid[row][col+1] == -1) {
                        isNotStuck = false;
                        break;
                    }
                    col++;
                } else {
                    if(col == 0 || grid[row][col-1] == 1) {
                        isNotStuck = false;
                        break;
                    }
                    col--;
                }
                row++;
            }

            if(isNotStuck) {
                result[ball] = col;
            } else {
                result[ball] = -1;
            }
        }

        return result;
    }
};