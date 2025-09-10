// Using BFS (starting from 1) (Brute Force Approach)

class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    int bfs(int i,int j,vector<vector<int>>&mat) {
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vis[i][j] = true;

        queue<pair<int,int>>que;
        que.push({i,j});

        int distOfNearestZero = 0;

        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();

                if(mat[x][y] == 0) {
                    return distOfNearestZero;
                }

                for(vector<int>&dir : directions) {
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];

                    if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && vis[new_x][new_y] == false) {
                        que.push({new_x,new_y});
                        vis[new_x][new_y] = true;
                    }
                }
            }
            distOfNearestZero++;
        }

        return 0;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(mat[i][j] == 1) {
                    mat[i][j] = bfs(i,j,mat);
                }
            }
        }

        return mat;
    }
};

// Using BFS (starting from 0) (Optimal Approach)

class Solution {
public:
    vector<vector<int>>directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>result(m,vector<int>(n,-1));
        queue<pair<int,int>>que;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(mat[i][j] == 0) {
                    que.push({i,j});
                    result[i][j] = 0;
                }
            }
        }

        while(!que.empty()) {
            int i = que.front().first;
            int j = que.front().second;
            que.pop();

            for(vector<int>&dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && result[new_i][new_j] == -1) {
                    que.push({new_i,new_j});
                    result[new_i][new_j] = 1 + result[i][j];
                }
            }
        }

        return result;
    }
};