// Using Brute Force 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(i == j) {
                    continue;
                }

                if(nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }

        return 0;
    }
};

// Using Sorting

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        
        for(int i = 0;i < n-1;i++) {
            if(nums[i] == nums[i+1]) {
                return nums[i];
            }
        }

        return 0;
    }
};

// Using Hashing 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,bool>seen;

        for(int i = 0;i < n;i++) {
            if(seen[nums[i]]) {
                return nums[i];
            }

            seen[nums[i]] = true;
        }

        return 0;
    }
};

// Using Elements as index

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0;i < n;i++) {
            int ind = abs(nums[i]);
            if(nums[ind] < 0) {
                return ind;
            }

            nums[ind] *= -1;
        }

        return 0;
    }
};

// using Hare Tortoise Method for Cycle detection

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};