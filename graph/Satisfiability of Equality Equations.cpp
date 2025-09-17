// Using DSU

class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int x) {
        if(x == parent[x]) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x,int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y) {
            return;
        }

        if(rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        } else if(rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        } else {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);

        for(int i = 0;i < 26;i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for(string &equation : equations) {
            int var1 = equation[0]-'a';
            int var2 = equation[3]-'a';

            if(equation[1] == '=') {
                Union(var1,var2);
            } 
        }

        for(string &equation : equations) {
            int var1 = equation[0]-'a';
            int var2 = equation[3]-'a';

            if(equation[1] == '!' && find(var1) == find(var2)) {
                return false;
            }
        }

        return true;
    }
};