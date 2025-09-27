class Solution {
public:
    vector<int>nextSmallerToLeft(vector<int>&arr, int n) {
        vector<int>result(n,0);
        stack<pair<int,int>>st;

        for(int i = 0;i < n;i++) {
            if(st.empty()) {
                result[i] = -1;
            } else if(st.top().first < arr[i]) {
                result[i] = st.top().second;
            } else {
                while(!st.empty() && st.top().first >= arr[i]) {
                    st.pop();
                }

                result[i] = st.empty() ? -1 : st.top().second;
            }
            
            st.push({arr[i], i});
        }

        return result;
    }

    vector<int>nextSmallerToRight(vector<int>&arr, int n) {
        vector<int>result(n,0);
        stack<pair<int,int>>st;

        for(int i = n-1;i >= 0;i--) {
            if(st.empty()) {
                result[i] = n;
            } else if(st.top().first < arr[i]) {
                result[i] = st.top().second;
            } else {
                while(!st.empty() && st.top().first > arr[i]) {
                    st.pop();
                }

                result[i] = st.empty() ? n : st.top().second;
            }

            st.push({arr[i],i});
        }

        return result;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9+7;
        long long sum = 0;

        vector<int>nsl = nextSmallerToLeft(arr,n);
        vector<int>nsr = nextSmallerToRight(arr,n);

        for(int i = 0;i < n;i++) {
            long long leftCount   = i - nsl[i];
            long long rightCount  = nsr[i] - i;

            long long totalCount = (leftCount * rightCount) * arr[i];
            sum += totalCount;
        }

        return sum % mod;
    }
};