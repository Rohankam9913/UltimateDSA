// Using Stack

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string dir;

        stack<string>st;

        while(getline(ss,dir,'/')) {
            if(dir == "." || dir == "") {
                continue;
            } else if(dir == "..") {
                if(st.empty()) {
                    continue;
                }
                
                st.pop();
            } else {
                st.push(dir);
            }
        }

        if(st.empty()) {
            return "/";
        }

        string resolvedPath = "";

        while(!st.empty()) {
            resolvedPath = "/" + st.top() + resolvedPath;
            st.pop();
        }

        return resolvedPath;
        
    }
};

// Using vector as stack

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string dir;

        vector<string>vec;

        while(getline(ss,dir,'/')) {
            if(dir == "." || dir == "") {
                continue;
            } 
            
            else if(dir == "..") {
                if(vec.empty()) {
                    continue;
                }

                vec.pop_back();
            }

            else {
                vec.push_back(dir);
            }
        }

        if(vec.empty()) {
            return "/";
        }

        string resolvedPath;

        for(auto &dir : vec) {
            resolvedPath += "/" + dir;
        }

        return resolvedPath;
    }
};