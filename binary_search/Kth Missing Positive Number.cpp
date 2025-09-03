// Using Linear Search

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int num = 1, i = 0;

        while(i < n && k > 0) {
            if(arr[i] == num) {
                i++;
            } else {
                k--;
            }

            num++;
        }

        while(k > 0) {
            num++;
            k--;
        }

        return num-1;
    }
};

// Using Binary Search

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;

        while(low <= high) {
            int mid = low + (high-low)/2;
            int total_missing_elements_till_i = arr[mid] - (mid+1);

            if(total_missing_elements_till_i > k) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return low + k;
    }
};