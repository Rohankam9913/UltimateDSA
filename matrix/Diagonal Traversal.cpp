class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int>result;
        map<int,vector<int>>mp;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                mp[i+j].push_back(mat[i][j]);
            }
        }

        bool flip = true;
        for(auto it : mp) {
            if(flip) {
                reverse(begin(it.second), end(it.second));
            }

            for(int &val : it.second) {
                result.push_back(val);
            }

            flip = !flip;
        }

        return result;
    }
};