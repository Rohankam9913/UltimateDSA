// Using BFS

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>>mp;

        for(int i = 0;i < n;i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int>que;
        que.push(0);

        vector<bool>vis(n,false);
        vis[0] = true;

        int jumps = 0;

        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                int ind = que.front();
                que.pop();

                if(ind == n-1) {
                    return jumps;
                }

                if(ind + 1 < n && !vis[ind+1]) {
                    que.push(ind+1);
                    vis[ind+1] = true;
                }

                if(ind - 1 >= 0 && !vis[ind-1]){
                    que.push(ind-1);
                    vis[ind-1] = true;
                }

                for(auto indices : mp[arr[ind]]) {
                    que.push(indices);
                    vis[indices] = true;
                }
                mp.erase(arr[ind]);
            }

            jumps++;
        }

        return -1;
    }
};