class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        int result = 0;
        int sign = 1;
        stack<int>st;

        for(char &ch : s) {
            if(isdigit(ch)) {
                num = (num*10) + ch-'0';
            } else if(ch == '+') {
                result = result + (num*sign);
                num = 0;
                sign = 1;
            } else if(ch == '-') {
                result = result + (num*sign);
                num = 0;
                sign = -1;
            } else if(ch == '(') {
                st.push(result);
                st.push(sign);
                num = 0;
                result = 0;
            } else if(ch == ')') {
                result = result + (num*sign);
                num = 0;

                int prevSign = st.top(); st.pop();
                result *= prevSign;

                int prevResult = st.top(); st.pop();
                result += prevResult;
            }
        }
        
        result = result + (num*sign);
        return result;
    }
};