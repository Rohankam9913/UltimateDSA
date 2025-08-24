class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNum = 0;

        for(int k = 0;k < 32;k++) {
            int temp = (1 << k);
            int countOnes = 0;
            
            for(int &num : nums) {
               if(num & temp) {
                countOnes++;
               }
            }

            if(countOnes % 3 == 1) {
                singleNum |= temp;
            }
        }

        return singleNum;
    }
};