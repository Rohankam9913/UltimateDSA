// Using Brute Force

class Solution {
public:
    long long findLeftSum(int num,int index) {
        long long sum = 0;

        for(int i = index-1;i >= 0;i--) {
            sum += (num-1) == 0 ? 1 : (num-1);
            num--;
        }

        return sum;
    }   

    long long findRightSum(int num,int index,int n) {
        long long sum = 0;

        for(int i = index+1;i < n;i++) {
            sum += (num-1) == 0 ? 1 : (num-1);
            num--;
        }

        return sum;
    }

    int maxValue(int n, int index, int maxSum) {
        for(int i = maxSum;i >= 1;i--) {
            long long leftSum  = findLeftSum(i,index);
            long long rightSum = findRightSum(i,index,n);

            if(leftSum + i + rightSum <= maxSum) {
                return i;
            }
        }

        return -1;
    }
};

// Using Binary Search 

class Solution {
public:
    long long findLeftSum(int num,int index) {
        long long sum = 0;

        for(int i = index-1;i >= 0;i--) {
            sum += (num-1) == 0 ? 1 : (num-1);
            num--;
        }

        return sum;
    }   

    long long findRightSum(int num,int index,int n) {
        long long sum = 0;

        for(int i = index+1;i < n;i++) {
            sum += (num-1) == 0 ? 1 : (num-1);
            num--;
        }

        return sum;
    }

    int maxValue(int n, int index, int maxSum) {
        long long low = 1, high = maxSum, mid;
        int result = 0;

        while(low <= high) {
            mid = low + (high-low)/2;

            long long leftSum  = findLeftSum(mid,index);
            long long rightSum = findRightSum(mid,index,n);

            if(leftSum + mid + rightSum <= maxSum) {
                result = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return result;
    }
};

// Using Binary Search With Cumulative Sum

class Solution {
public:
    long long findSum(long long num, long long n) {
        return (num*n) - (n*(n+1))/2;
    }

    int maxValue(int n, int index, int maxSum) {
        long long low = 1, high = maxSum, mid;
        int result = 0;

        while(low <= high) {
            mid = low + (high-low)/2;

            long long totalElementsToLeft = min((long long)index, mid-1);
            long long extraSumAddedToLeft = max(0LL, index - (mid-1));
            long long leftSum = findSum(mid,totalElementsToLeft) + extraSumAddedToLeft;

            long long totalElementsToRight = min((long long)n-index-1, mid-1);
            long long extraSumAddedToRight = max(0LL, (n-index-1) - (mid-1));
            long long rightSum = findSum(mid,totalElementsToRight) + extraSumAddedToRight;

            if(leftSum + mid + rightSum <= maxSum) {
                result = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return result;
    }
};
