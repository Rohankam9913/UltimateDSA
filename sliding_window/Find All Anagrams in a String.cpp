class Solution {
public:
    bool checkIfAllZeros(vector<int>&freq) {
        for(int i = 0;i < 26;i++) {
            if(freq[i] > 0) {
                return false;
            }
        }
        
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int k = p.length();
        vector<int>freq(26,0);
        
        for(char &ch : p) {
            freq[ch-'a']++;
        }
        
        int i = 0, j = 0;
        vector<int>anagramIndexes;

        while(j < n) {
            freq[s[j]-'a']--;
            
            if(j-i+1 == k) {
                if(checkIfAllZeros(freq)) {
                    anagramIndexes.push_back(i);
                }
                
                freq[s[i]-'a']++;
                i++;
            }
            
            j++;
        }
        
        return anagramIndexes;        
    }
};