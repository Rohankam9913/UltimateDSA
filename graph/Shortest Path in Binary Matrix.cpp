// Using BFS

class Solution {
public:
    vector<vector<int>>directions = {{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) {
            return -1;
        }
        int n = grid.size();
        
        queue<pair<int,int>>que;
        que.push({0,0});
        grid[0][0] = 1;

        int path = 0; 

        auto isValid = [&](int &x, int &y) {
            return x >= 0 && x < n && y >= 0 && y < n;
        };

        while(!que.empty()) {
            int size = que.size();
            
            while(size--) {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();

                if(x == n-1 && y == n-1) {
                    return path+1;
                }

                for(vector<int>&dir : directions) {
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];

                    if(isValid(new_x,new_y) && grid[new_x][new_y] == 0) {
                        que.push({new_x,new_y});
                        grid[new_x][new_y] = 1;
                    }
                }
            }

            path++;
        }

        return -1;
    }
};

// Using Djikstra 

class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>>directions = {{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) {
            return -1;
        }

        int n = grid.size();

        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0] = 0;

        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,{0,0,}});

        auto isValid = [&](int &x, int &y) {
            return x >= 0 && x < n && y >= 0 && y < n;
        };

        while(!pq.empty()) {
            int distFromCurCell = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(vector<int>&dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(isValid(new_x,new_y) && grid[new_x][new_y] == 0 && dist[new_x][new_y] > distFromCurCell + 1) {
                    dist[new_x][new_y] = 1 + distFromCurCell;
                    pq.push({dist[new_x][new_y],{new_x,new_y}});
                }
            }
        }
        
        return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1]+1;
    }
};