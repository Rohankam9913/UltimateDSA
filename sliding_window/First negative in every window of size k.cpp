// Using Brute Force

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>result(n-k+1,0);
        
        for(int i = 0;i <= n-k;i++) {
            for(int j = i;j < k+i;j++) {
                if(arr[j] < 0) {
                    result[i] = arr[j];
                    break;
                }
            }
        }
        
        return result;
    }
};

// Using Sliding Window

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>result;
        
        deque<int>dq;
        int i = 0, j = 0;
        
        while(j < n) {
            if(arr[j] < 0) {
                dq.push_back(arr[j]);
            }
            
            if(j-i+1 == k) {
                if(!dq.empty()) {
                    result.push_back(dq.front());
                } else {
                    result.push_back(0);
                }
                
                if(arr[i] < 0 && !dq.empty()) {
                    dq.pop_front();
                }
                
                i++;
            }
            
            j++;
        }
        
        return result;
    }
};