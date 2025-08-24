// Approach 1 - Finding mask using 2s complement

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Finding the xor of all elmenents of nums
        long long xorArr = 0;
        for(int &num : nums) {
            xorArr ^= num;
        }

        // Finding the mask
        int mask = (xorArr) & (-xorArr);

        // Creating two groups
        int num1 = 0, num2 = 0;
        for(int &num : nums) {
            if(mask & num) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }

        return {num1,num2};
    }
};

// Approach 2 - Finding mask by shifting bits

class Solution {
  public:
    int getMask(int xorArr) {
        int shift = 0;
        
        for(int bit = 0;bit < 32;bit++) {
            if((xorArr & (1 << bit)) == 0) {
                shift++;
            } else {
                break;
            }
        }
        
        return (1 << shift);
    }
  
    vector<int> singleNumber(vector<int>& arr) {
        long long xorArr = 0;
        for(int &num : arr) {
            xorArr ^= num;
        }
        
        int mask = getMask(xorArr);
        
        int num1 = 0, num2 = 0;
        
        for(int &num : arr) {
            if(mask & num) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        
        if(num1 > num2) {
            return {num2,num1};
        }
        
        return {num1,num2};
    }
};