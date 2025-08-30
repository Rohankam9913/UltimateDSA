class Solution {
public:
    int m,n;
    vector<vector<int>>directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    bool solve(int i, int j, vector<vector<char>>&board, string &word, int idx) {
        if(idx == word.length()) {
            return true;
        }

        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '*' || board[i][j] != word[idx]) {
            return false;
        }

        char ch = board[i][j];
        board[i][j] = '*';

        for(vector<int>&dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(solve(new_i,new_j,board,word,idx+1)) {
                return true;
            }
        }

        board[i][j] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(board[i][j] == word[0]) {
                    if(solve(i,j,board,word,0)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};