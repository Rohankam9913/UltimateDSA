class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();

        if(n > m){
            return "";
        }

        int i = 0, j = 0;
        unordered_map<char,int> mp;
        
        for(auto &ch: t){
            mp[ch]++;
        }

        int count = t.length();
        int minWindowLength = INT_MAX;
        int startInd = 0;

        while(j < m){
            char ch = s[j];

            if(mp[ch] > 0){
                count--;
            }

            while(count == 0){
                int curWindowLength = j - i + 1;
                if(curWindowLength < minWindowLength){
                    minWindowLength = curWindowLength;
                    startInd = i;
                }

                mp[s[i]]++;
                if(mp[s[i]] > 0){
                    count++;
                }

                i++;
            }

            mp[ch]--;
            j++;
        }

        return (minWindowLength == INT_MAX) ? "" : s.substr(startInd, minWindowLength);
    }
};