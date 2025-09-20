class Solution {
    public:

    void findFactorial(int num, vector<int>&product,int &size) {
        int carry = 0;

        for(int i = 0;i < size;i++) {
            int prod = (num * product[i]) + carry;
            product[i] = prod%10;
            carry = prod/10;
        }

        while(carry > 0) {
            product[size++] = carry%10;
            carry /= 10;
        }
    }

    vector<int>factorial(int n) {
        vector<int>product(3000,-1);
        product[0] = 1;
        int size = 1;

        for(int i = 2;i <= n;i++) {
            findFactorial(i,product,size);
        }

        vector<int>result;
        for(int i = size-1;i >= 0;i--) {
            result.push_back(product[i]);
        }

        return result;
    }
};