class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int totalTime = 0;

        for(int i = 1;i < travel.size();i++) {
            travel[i] += travel[i-1];
        }

        int lastIndexForGlass = -1;
        int lastIndexForPaper = -1;
        int lastIndexForMetal = -1;

        for(int i = 0;i < n;i++) {
            totalTime += garbage[i].length();

            for(char &ch : garbage[i]) {
                if(ch == 'G') {
                    lastIndexForGlass = i; 
                } else if(ch == 'P') {
                    lastIndexForPaper = i;
                } else {
                    lastIndexForMetal = i;
                }
            }
        }

        totalTime += (lastIndexForGlass == -1) ? 0 : travel[lastIndexForGlass-1];
        totalTime += (lastIndexForPaper == -1) ? 0 : travel[lastIndexForPaper-1];
        totalTime += (lastIndexForMetal == -1) ? 0 : travel[lastIndexForMetal-1];            

        return totalTime;
    }
};