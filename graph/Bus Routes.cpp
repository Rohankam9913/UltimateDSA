// Using BFS

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) {
            return 0;
        }

        unordered_map<int,vector<int>>stopToRoute;

        for(int i = 0;i < routes.size();i++) {
            for(int &stop : routes[i]) {
                stopToRoute[stop].push_back(i);
            }
        }

        queue<int>que;
        int bus = 1;
        unordered_set<int>vis;

        for(int &route : stopToRoute[source]) {
            que.push(route);
            vis.insert(route);
        }

        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                int route = que.front();
                que.pop();

                for(int &stop : routes[route]) {
                    if(stop == target) {
                        return bus;
                    }

                    for(int &busRoute : stopToRoute[stop]) {
                        if(vis.find(busRoute) == vis.end()) {
                            vis.insert(busRoute);
                            que.push(busRoute);
                        }
                    }
                }
            }
            bus++;
        }

        return -1;
    }
};