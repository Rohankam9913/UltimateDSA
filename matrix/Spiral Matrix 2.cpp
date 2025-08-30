class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int num = 1;

        int top = 0, down = n-1;
        int left = 0, right = n-1;
        int dir = 0;

        while(top <= down && left <= right) {
            
            if(dir == 0) {
                for(int i = left; i <= right;i++) {
                    matrix[top][i] = num++;
                }
                top++;
            }

            else if (dir == 1) {
                for(int i = top;i <= down;i++) {
                    matrix[i][right] = num++;
                }
                right--;
            }

            else if(dir == 2) {
                for(int i = right; i >= left;i--) {
                    matrix[down][i] = num++;
                }
                down--;
            }

            else {
                for(int i = down;i >= top;i--) {
                    matrix[i][left] = num++;
                }
                left++;
            }

            dir = (dir+1)%4;
        }

        return matrix;
    }
};