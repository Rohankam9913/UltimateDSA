class Solution {
public:
    vector<int> getOrder(unordered_map<int,vector<int>>&adj, vector<int>&indegree) {
        vector<int>order;
        queue<int>que;

        for(int i = 0;i < indegree.size();i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        while(!que.empty()) {
            int u = que.front();
            order.push_back(u);
            que.pop();

            for(int &v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        return order;
    }
    
    vector<int> getItemOrder(vector<vector<int>>&beforeItems, int n) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n,0);

        for(int v = 0;v < beforeItems.size();v++) {
            for(int &u : beforeItems[v]) {
                adj[u].push_back(v);
                indegree[v]++;
            }
        }

        return getOrder(adj,indegree);
    }

    vector<int> getGroupOrder(vector<vector<int>>&beforeItems, vector<int>&group, int m) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(m,0);

        for(int v = 0;v < beforeItems.size();v++) {
            for(int &u : beforeItems[v]) {
                
                int group_of_u = group[u];
                int group_of_v = group[v];

                if(group_of_u != group_of_v) {
                    adj[group_of_u].push_back(group_of_v);
                    indegree[group_of_v]++;
                }
            }
        }

        return getOrder(adj,indegree);
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i = 0;i < n;i++) {
            if(group[i] == -1) {
                group[i] = m;
                m++;
            }
        }   

        vector<int>itemOrder = getItemOrder(beforeItems,n);
        if(itemOrder.size() != n) {
            return {};
        }

        vector<int>groupOrder = getGroupOrder(beforeItems,group,m);
        if(groupOrder.size() != m){
            return {};
        }

        unordered_map<int,vector<int>>groupToItemMapping;

        for(int &item : itemOrder) {
            groupToItemMapping[group[item]].push_back(item);
        }

        vector<int>result;
        
        for(int &grp : groupOrder) {
            for(int &member : groupToItemMapping[grp]) {
                result.push_back(member);
            }
        }

        return result;
    }
};