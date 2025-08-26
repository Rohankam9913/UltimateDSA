class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<int>>directions = {{-1,0},{0,1},{1,0},{0,-1}};

        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int step_counter = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                vector<int>temp = {i,j};
                if(temp != entrance && (i == 0 || i == m-1 || j == 0 || j == n-1)){
                    return step_counter;
                }

                for(vector<int>&dir : directions){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && maze[new_i][new_j] != '+'){
                        maze[new_i][new_j] = '+';
                        q.push({new_i,new_j});
                    }
                }
            }
            step_counter++;
        }

        return -1;
    }

};