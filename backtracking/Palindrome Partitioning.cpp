class Solution {
public:
    bool is_palindrome(string &s,int i,int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++, j--;
        }

        return true;
    }

    void solve(int i,string &s,vector<string>&path,vector<vector<string>>&result){
        if(i >= s.length()){
            result.push_back(path);
            return;
        }

        for(int j = i;j < s.length();j++){
            if(is_palindrome(s,i,j)){
                path.push_back(s.substr(i,j-i+1));
                solve(j+1,s,path,result);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>path;

        solve(0,s,path,result);

        return result;
    }
};