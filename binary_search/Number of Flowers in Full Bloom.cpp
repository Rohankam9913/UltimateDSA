// Using First Brute Force

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = people.size();

        vector<int>result(n,0);

        for(int i = 0;i < n;i++) {
            int totalFlowers = 0;

            for(vector<int>&flower : flowers) {
                int start = flower[0];
                int end = flower[1];

                if(people[i] >= start && people[i] <= end) {
                    totalFlowers++;
                }
            }

            result[i] = totalFlowers;
        }

        return result;
    }
};

// Using Second Brute Force

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();

        vector<int>startTime;
        for(int i = 0;i < m;i++) {
            startTime.push_back(flowers[i][0]);
        }

        vector<int>endTime;
        for(int i = 0;i < m;i++) {
            endTime.push_back(flowers[i][1]);
        }

        vector<int>result;
        for(int &arrivalTime : people) {
            
            int flowerAlreadyBloomed = 0;
            for(int &start : startTime) {
                if(arrivalTime >= start) {
                    flowerAlreadyBloomed++;
                }
            }

            int flowerAlreadyDied = 0;
            for(int &end : endTime) {
                if(arrivalTime > end) {
                    flowerAlreadyDied++;
                }
            }

            result.push_back(flowerAlreadyBloomed - flowerAlreadyDied);
        }

        return result;
    }
};

// Using Binary Search

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = people.size();
        int m = flowers.size();

        vector<int>startTime;
        vector<int>endTime;

        for(vector<int>&flower : flowers) {
            int start = flower[0];
            int end = flower[1];

            startTime.push_back(start);
            endTime.push_back(end);
        }

        sort(begin(startTime), end(startTime));
        sort(begin(endTime), end(endTime));

        vector<int>result;

        for(int &personArrivalTime : people) {
            int flowerAlreadyBloomed = upper_bound(begin(startTime), end(startTime), personArrivalTime) - begin(startTime);
            int flowerAlreadyExpired = lower_bound(begin(endTime), end(endTime), personArrivalTime) - begin(endTime);

            result.push_back(flowerAlreadyBloomed - flowerAlreadyExpired);
        } 

        return result;
    }
};