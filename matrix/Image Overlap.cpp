class Solution {
public:
    int overlapping(int rowOffset, int colOffset, vector<vector<int>>&img1, vector<vector<int>>&img2, int n) {
        int countOfOnes = 0;

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                int img2_ith = i + rowOffset;
                int img2_jth = j + colOffset;

                if(img2_ith < 0 || img2_ith >= n || img2_jth < 0 || img2_jth >= n) {
                    continue;
                }

                if(img1[i][j] == 1 && img2[img2_ith][img2_jth] == 1) {
                    countOfOnes++;
                }
            }
        }

        return countOfOnes;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        int maxCountOfOnes = 0;
        for(int rowOffset = 1-n; rowOffset < n; rowOffset++) {
            for(int colOffset = 1-n; colOffset < n; colOffset++) {
                maxCountOfOnes = max(maxCountOfOnes, overlapping(rowOffset, colOffset, img1, img2, n));
            }
        }

        return maxCountOfOnes;
    }
};