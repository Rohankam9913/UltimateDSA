// Using Stack 

class Solution {
public:
    string removeStars(string s) {
        stack<char>st;

        for(char &ch : s) {
            if(ch == '*' && !st.empty()) {
                st.pop();
            } else {
                st.push(ch);
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

// Using String as Stack

class Solution {
public:
    string removeStars(string s) {
        string result = "";

        for(char &ch : s) {
            if(ch == '*') {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }

        return result;
    }
};

// Using Two Pointer

class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        vector<char>temp(n);

        int j = 0;
        for(int i = 0;i < n;i++) {
            if(s[i] != '*') {
                temp[j] = s[i];
                j++;
            } else {
                j--;
            }
        }

        string result = "";

        for(int i = 0;i < j;i++) {
            result += temp[i];
        }

        return result;
    }
};