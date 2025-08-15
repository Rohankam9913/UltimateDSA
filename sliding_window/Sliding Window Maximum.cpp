class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;
        vector<int>result;

        for(int i=0;i<n;i++) {

            // Step 1: Remove all those indexes from the deque which are not present in the window
            while(!dq.empty() && dq.front() <= i-k) {
                dq.pop_front();
            }

            // Step 2: Remove all those indexes from the deque which are smaller than the current element
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Step 3: Push the current element index in the deque
            dq.push_back(i);

            // Step 4: Calculate the result from the front of the deque
            if(i >= k-1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};