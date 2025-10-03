// Using Stack

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>result;
        stack<int>st;

        for(int &asteroid : asteroids) {
            while(!st.empty() && st.top() > 0 && asteroid < 0) {
                int sum = st.top() + asteroid;
                if(sum < 0) {
                    st.pop();
                } else if(sum > 0) {
                    asteroid = 0;
                } else {
                    st.pop();
                    asteroid = 0;
                }
            }

            if(asteroid != 0) {
                st.push(asteroid);  
            }
        }

        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        reverse(begin(result), end(result));
        return result;
    }
};

// Using Vector as stack

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>result;

        for(int &asteroid : asteroids) {
            while(!result.empty() && result.back() > 0 && asteroid < 0) {
                int sum = result.back() + asteroid;
                if(sum < 0) {
                    result.pop_back();
                } else if(sum > 0) {
                    asteroid = 0;
                } else {
                    result.pop_back();
                    asteroid = 0;
                }
            }

            if(asteroid != 0) {
                result.push_back(asteroid);  
            }
        }

        return result;
    }
};