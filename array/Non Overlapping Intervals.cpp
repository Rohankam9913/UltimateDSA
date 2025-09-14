// Using Two Pointers

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals));

        int i = 0, j = 1, count = 0;

        while(j < n) {
            if(intervals[i][1] <= intervals[j][0]) {
                i = j;
                j++;
            } else if(intervals[i][1] <= intervals[j][1]) {
                count++;
                j++;
            } else if(intervals[i][1] > intervals[j][1]) {
                count++;
                i = j;
                j++;
            }
        }

        return count;
    }
};

// Using Previous Interval

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals));

        vector<int>prevInterval = intervals[0];
        int i = 1, count = 0;
        
        while(i < n) {
            if(prevInterval[1] <= intervals[i][0]) {
                prevInterval = intervals[i];
            } else if(prevInterval[1] <= intervals[i][1]) {
                count++;
            } else if(prevInterval[1] > intervals[i][1]) {
                count++;
                prevInterval = intervals[i];
            }

            i++;
        }

        return count;
    }
};