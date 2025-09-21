// Using Brute Force

class Solution {
public:
    int n;

    bool isPossible(int &magneticForce, vector<int>&position, int &m) {
        int lastBallPosition = position[0];
        int totalBalls = 1;

        for(int i = 1;i < n;i++) {
            if(position[i] - lastBallPosition >= magneticForce) {
                totalBalls++;
                lastBallPosition = position[i];
            }
        }

        return totalBalls >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        n = position.size();
        sort(begin(position), end(position));
        
        int maxMagneticForce = position[n-1] - position[0];

        for(int magneticForce = maxMagneticForce;magneticForce >= 1;magneticForce--) {
            if(isPossible(magneticForce, position, m)) {
                return magneticForce;
            }
        }

        return -1;
    }
};

// Using Binary Search

class Solution {
public:
    int n;

    bool isPossible(int &magneticForce, vector<int>&position, int &m) {
        int lastBallPosition = position[0];
        int totalBalls = 1;

        for(int i = 1;i < n;i++) {
            if(position[i] - lastBallPosition >= magneticForce) {
                totalBalls++;
                lastBallPosition = position[i];
            }
        }

        return totalBalls >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        n = position.size();
        sort(begin(position), end(position));

        int low = 1, high = position[n-1] - position[0], mid, result;

        while(low <= high) {
            mid = low + (high-low)/2;
            if(isPossible(mid,position,m)) {
                result = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        } 

        return result;
    }
};