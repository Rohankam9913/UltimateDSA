// Using Stack

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int>st;
        vector<string>result;

        int i = 0;

        for(int stream = 1;stream <= n && i < target.size();stream++) {
            st.push(stream);
            result.push_back("Push");

            if(st.top() != target[i]) {
                result.push_back("Pop");
                st.pop();
            } else {
                i++;
            }
        }

        return result;
    }
};

// Without Using Stack

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>result;

        int i = 0;

        for(int stream = 1;stream <= n && i < target.size();stream++) {
            result.push_back("Push");

            if(stream != target[i]) {
                result.push_back("Pop");
            } else {
                i++;
            }
        }

        return result;
    }
};