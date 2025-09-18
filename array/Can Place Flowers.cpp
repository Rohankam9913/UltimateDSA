class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) {
            return true;
        }

        int m = flowerbed.size(), i = 0;
        while(i < m) {
            if(flowerbed[i] == 0) {
                bool left = (i == 0) || (flowerbed[i-1] == 0);
                bool right = (i == m-1) || (flowerbed[i+1] == 0);

                if(left && right) {
                    n--;
                    if(n == 0){
                        return true;
                    }
                }
            }
            i++;
        }

        return false;
    }
};