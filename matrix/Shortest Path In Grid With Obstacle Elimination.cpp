class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        queue<vector<int>>que;
        que.push({0,0,k});

        vector<vector<vector<bool>>>vis(m,vector<vector<bool>>(n,vector<bool>(k+1, false)));
        vis[0][0][k] = true;

        vector<vector<int>>directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        int steps = 0;

        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                vector<int>front = que.front();
                que.pop();

                int cur_i = front[0];
                int cur_j = front[1];
                int cur_k = front[2];

                if(cur_i == m-1 && cur_j == n-1) {
                    return steps;
                }

                for(vector<int>&dir : directions) {
                    int new_i = cur_i + dir[0];
                    int new_j = cur_j + dir[1];

                    if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n) {
                        continue;
                    }

                    if(grid[new_i][new_j] == 0 && !vis[new_i][new_j][cur_k]) {
                        que.push({new_i, new_j, cur_k});
                        vis[new_i][new_j][cur_k] = true;
                    } else if(grid[new_i][new_j] == 1 && cur_k > 0 && !vis[new_i][new_j][cur_k-1]) {
                        que.push({new_i, new_j, cur_k-1});
                        vis[new_i][new_j][cur_k-1] = true;
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};