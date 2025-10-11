// Using Recursion

class Solution {
public:
    int n;

    int findMaxConsecutives(string &answerKey) {
        int mx = 0, count = 0;

        for(int i = 0;i < n;) {
            if(answerKey[i] == 'T') {
                count = 1;
                i++;

                while(i < n && answerKey[i] == 'T') {
                    count++;
                    i++;
                }

                mx = max(mx,count);
            } else {
                count = 1;
                i++;

                while(i < n && answerKey[i] == 'F') {
                    count++;
                    i++;
                }

                mx = max(mx,count);
            }
        }

        return mx;
    }

    void solve(int idx,int &result,int k,string &answerKey) {
        if(idx >= n || k == 0) {
            return;
        }

        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T';
        result = max(result,findMaxConsecutives(answerKey));
        solve(idx+1,result,k-1,answerKey);
        
        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T';
        solve(idx+1,result,k,answerKey);
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        n = answerKey.length();
        int result = 0;

        solve(0,result,k,answerKey);

        return result;
    }
};

// Using Two Pass Sliding Window

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int i = 0,j = 0;
        int count = 0;
        int result = 0;

        while(j < n) {
            count += (answerKey[j] == 'F');

            while(i < j && count > k) {
                count -= (answerKey[i] == 'F');
                i++;
            }

            result = max(result,j-i+1);
            j++;
        }

        i = 0,j = 0,count = 0;

        while(j < n) {
            count += (answerKey[j] == 'T');

            while(i < j && count > k) {
                count -= (answerKey[i] == 'T');
                i++;
            }

            result = max(result,j-i+1);
            j++;
        }

        return result;
    }
};

// Using One Pass Sliding Window

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int i = 0, j = 0;
        int result = 0;
        unordered_map<char,int>mp;

        while(j < n) {
            mp[answerKey[j]]++;

            while(min(mp['T'], mp['F']) > k) {
                mp[answerKey[i]]--;
                i++;
            }

            result = max(result,j-i+1);
            j++;
        }

        return result;
    }
};