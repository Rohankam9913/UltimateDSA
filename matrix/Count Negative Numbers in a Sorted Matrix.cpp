// Approach 1  Using Nested Loops

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] < 0) {
                    count++;
                }
            }
        }

        return count;
    }
};

// Approach 2 - Using Binary Search

class Solution {
public:
    int binarySearch(vector<int>&nums, int n) {
        int low = 0, high = n-1;
        int negIdx = n;

        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] < 0) {
                negIdx = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return negIdx;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for(int i = 0;i < m;i++) {
            count += (n - binarySearch(grid[i],n));
        }

        return count;
    }
};

// Using Upper Bound

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for(vector<int>vec : grid) {
            int idx = upper_bound(begin(vec),end(vec),0,greater<int>()) - begin(vec);
            count += n - idx;
        }

        return count;
    }
};

// Using Linear Approach

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int row = m-1, col = 0, count = 0;

        while(row >= 00 && col < n) {
            if(grid[row][col] >= 0) {
                col++;
            } else {
                count += (n-col);
                row--;
            }
        }

        return count;
    }
};