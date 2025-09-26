// Using Brute Force

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>result(n,0);

        for(int i = 0;i < n;i++) {
            for(int j = i+1;j < n;j++) {
                if(temperatures[i] < temperatures[j]) {
                    result[i] = j-i;
                    break;
                }
            }
        }   

        return result;
    }
};

// Using Stack

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>result(n,0);

        stack<pair<int,int>>st;

        for(int i = n-1;i >= 0;i--) {
            if(st.empty()) {
                st.push({temperatures[i], i});
            } else if(st.top().first > temperatures[i]) {
                result[i] = st.top().second-i;
                st.push({temperatures[i],i});
            } else {
                while(!st.empty() && st.top().first <= temperatures[i]) {
                    st.pop();
                }

                result[i] = !st.empty() ? st.top().second-i: 0;
                st.push({temperatures[i],i});
            }
        }  

        return result;
    }
};