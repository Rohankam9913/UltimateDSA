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
  
    int CountOccurencesOfAnagrams(string &pat, string &txt) {
        int n = txt.length();
        int k = pat.length();
        vector<int>freq(26,0);
        
        for(char &ch : pat) {
            freq[ch-'a']++;
        }
        
        int i = 0, j = 0, count = 0;
        while(j < n) {
            freq[txt[j]-'a']--;
            
            if(j-i+1 == k) {
                if(checkIfAllZeros(freq)) {
                    count++;
                }
                
                freq[txt[i]-'a']++;
                i++;
            }
            
            j++;
        }
        
        return count;
    }
};