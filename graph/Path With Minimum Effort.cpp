// Using Djikstra

class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>>directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,{0,0}});

        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        result[0][0] = 0;

        auto isValid = [&](int &x, int &y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        while(!pq.empty()) {
            int pathMaxEffort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(vector<int>&dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(isValid(new_x,new_y)) {
                    int newEffort = abs(heights[new_x][new_y] - heights[x][y]);
                    int maxEffort = max(pathMaxEffort,newEffort);

                    if(result[new_x][new_y] > maxEffort) {
                        result[new_x][new_y] = maxEffort;
                        pq.push({result[new_x][new_y], {new_x,new_y}});
                    }
                }
            }
        }

        return result[m-1][n-1];
    }
};