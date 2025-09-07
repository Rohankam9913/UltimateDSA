// First Approach

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals));

        vector<vector<int>>result;
        result.push_back(intervals[0]);
        int i = 1;

        while(i < n) {
            vector<int>&prevInterval = result.back();

            if(prevInterval[1] < intervals[i][0]) {
                result.push_back(intervals[i]);
            } else {
                prevInterval[0] = min(prevInterval[0], intervals[i][0]);
                prevInterval[1] = max(prevInterval[1], intervals[i][1]);
            }
            i++;
        }

        return result;
    }
};

// Second Approach

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals));
        vector<vector<int>>result;
        
        int i = 1;
        vector<int>prevInterval = intervals[0];

        while(i < n) {
            if(intervals[i][0] > prevInterval[1]) {
                result.push_back(prevInterval);
                prevInterval = intervals[i];
            } else {
                prevInterval[0] = min(prevInterval[0], intervals[i][0]);
                prevInterval[1] = max(prevInterval[1], intervals[i][1]);
            }
            i++;
        }

        result.push_back(prevInterval);
        return result;
    }
};