// Using Stack

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;

        for(char &ch : s) {
            if(st.empty() || st.top() != ch) {
                st.push(ch);
            } else {
                st.pop();
            }
        }

        string result = "";
        while(!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};

// Without Using Stack

class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";

        for(int i = 0;i < s.length();i++) {
            if(result == "" || result.back() != s[i]) {
                result += s[i];
            } else {
                result.pop_back();
            }
        }   

        return result;
    }
};