// Using Brute Force

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size(); 
        vector<int>pairs(n);

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                int spell = spells[i];
                int potion = potions[j];

                long long successPair = spell * potion;
                if(successPair >= success) {
                    pairs[i]++;
                }
            }
        }

        return pairs;
    }
};

// Using Binary Search (finding lower bound using custom lower bound)

class Solution {
public:
    int lowerBound(vector<int>&potions, int potionVal) {
        int m = potions.size();
        int low = 0, high = m-1;
        int result = -1;

        while(low <= high) {
            int mid = low + (high-low)/2;
            if(potions[mid] >= potionVal) {
                result = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return result;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        sort(begin(potions), end(potions));
        vector<int>pairs(n);

        for(int i = 0;i < n;i++) {
            int spell = spells[i];
            long long potionVal = ceil((success * 1.0)/spell);
            if(potionVal > potions[m-1]) {
                continue;
            }

            int idx = lowerBound(potions,potionVal);
            pairs[i] = m-idx;
        }        

        return pairs;
    }
};

// Using Binary Search (finding lower bound using c++ stl)

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        sort(begin(potions), end(potions));
        vector<int>pairs;

        for(int i = 0;i < n;i++) {
            int spell = spells[i];
            long long potionVal = ceil((success * 1.0)/spell);

            int idx = lower_bound(begin(potions), end(potions), potionVal) - begin(potions);
            pairs.push_back(m-idx);
        }        

        return pairs;
    }
};