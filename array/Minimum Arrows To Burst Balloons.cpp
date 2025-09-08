class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points));

        vector<int>prev = points[0];
        int arrowCount = 1;

        for(int i = 1;i < n;i++) {
            if(points[i][0] > prev[1]) {
                arrowCount++;
                prev = points[i];
            } else {
                prev[0] = max(prev[0], points[i][0]);
                prev[1] = min(prev[1], points[i][1]);
            }
        }

        return arrowCount;
    }
};