// Using Brute Force

class Solution {
public:
    int n;

    bool isPossible(int &day, vector<int>&bloomDay, int &m,int &k) {
        int countBouquets = 0;
        int count = 0;

        for(int i = 0;i < n;i++) {
            if(bloomDay[i] <= day) {
                count++;
            } else {
                count = 0;
            }

            if(count == k) {
                countBouquets++;
                count = 0;
            }
        }

        return countBouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        n = bloomDay.size();
        if(n < m * k) {
            return -1;
        }   

        int minDay = *min_element(begin(bloomDay), end(bloomDay));
        int maxDay = *max_element(begin(bloomDay), end(bloomDay)); 

        for(int day = minDay;day <= maxDay;day++) {
            if(isPossible(day,bloomDay,m,k)) {
                return day;
            }
        }

        return -1;
    }
};

// Using Binary Search

class Solution {
public:
    int n;

    bool isPossible(int &day, vector<int>&bloomDay, int &m,int &k) {
        int countBouquets = 0;
        int count = 0;

        for(int i = 0;i < n;i++) {
            if(bloomDay[i] <= day) {
                count++;
            } else {
                count = 0;
            }

            if(count == k) {
                countBouquets++;
                count = 0;
            }
        }

        return countBouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        n = bloomDay.size();
        if(n < m * k) {
            return -1;
        }   

        int low = *min_element(begin(bloomDay), end(bloomDay));
        int high = *max_element(begin(bloomDay), end(bloomDay)); 
        int result = -1;

        while(low <= high) {
            int mid = low + (high-low)/2;
            if(isPossible(mid,bloomDay,m,k)) {
                result = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }   

        return result;
    }
};