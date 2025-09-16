// Using Brute Force

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int maxPerimeter = 0;

        for(int i = 0;i < n-2;i++) {
            for(int j = i+1;j < n-1;j++) {
                for(int k = j+1;k < n;k++) {
                    int a = nums[i];
                    int b = nums[j];
                    int c = nums[k];

                    if(a + b > c && b + c > a && a + c > b) {
                        maxPerimeter = max(maxPerimeter, a+b+c);
                    }
                }
            }
        }

        return maxPerimeter;
    }
};

// Using Sorting

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        
        for(int i = n-3;i >= 0;i--) {
            if(nums[i] + nums[i+1] > nums[i+2]) {
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }

        return 0;
    }
};