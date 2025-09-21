// Using Sorting

class Solution {
public:
    bool solveQuery(int left,int right,vector<int>&nums) {
        if(right-left+1 < 2) {
            return false;
        }

        vector<int>arr;
        for(int i = left;i <= right;i++) {
            arr.push_back(nums[i]);
        }

        sort(begin(arr), end(arr));

        int commonDiff = arr[1] - arr[0];

        for(int i = 2;i < arr.size();i++) {
            if(arr[i] - arr[i-1] != commonDiff) {
                return false;
            } 
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool>result(m,false);

        for(int i = 0;i < m;i++) {
            bool queryResult = solveQuery(l[i],r[i],nums);
            result[i] = queryResult;
        }

        return result;
    }
};

// Without Sorting (Using Maths)

class Solution {
public:
    bool solveQuery(int left,int right,vector<int>&nums) {
        int n = right-left+1;
        if(n < 2) {
            return false;
        }

        unordered_set<int>st;
        int a   = INT_MAX;
        int nth = INT_MIN;

        for(int i = left;i <= right;i++) {
            st.insert(nums[i]);
            a = min(a,nums[i]);
            nth = max(nth,nums[i]);
        }

        int d = (nth - a) / (n -1);
        
        if((nth - a) % (n -1) != 0) {
            return false;
        }

        for(int i = 0;i < n;i++) {
            if(st.find(a + i*d) == st.end()) {
                return false;
            }
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool>result(n,false);

        for(int i = 0;i < n;i++) {
            bool queryResult = solveQuery(l[i],r[i],nums);
            result[i] = queryResult;
        }

        return result;
    }
};