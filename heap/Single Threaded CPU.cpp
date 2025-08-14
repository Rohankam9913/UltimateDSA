class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>>Tasks;

        for(int i = 0;i < n;i++) {
            int startTime = tasks[i][0];
            int processTime = tasks[i][1];
            Tasks.push_back({startTime, processTime, i});
        }

        vector<int>tasksOrder;
        sort(begin(Tasks), end(Tasks));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        int startTime = 0;
        int i = 0;

        while(!pq.empty() || i < n) {
            if(pq.empty() && Tasks[i][0] > startTime) {
                startTime = Tasks[i][0];
            }

            while(i < n && startTime >= Tasks[i][0]) {
                pq.push({Tasks[i][1], Tasks[i][2]});
                i++;
            }

            pair<int,int>top = pq.top();
            pq.pop();

            startTime += top.first;
            tasksOrder.push_back(top.second);
        }

        return tasksOrder;
    }
};