// Using Smart Linear Approach

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0, col = n-1;
        while(row < m && col >= 0) {
            if(matrix[row][col] > target) {
                col--;
            } else if(matrix[row][col] < target) {
                row++;
            } else {
                return true;
            }
        }

        return false;
    }
};

// Using Binary Search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0, high = m*n-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target) {
                return true;
            } else if(matrix[row][col] > target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return false;
    }
};