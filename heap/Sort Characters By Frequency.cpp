// First Way

class Solution {
public:
    typedef pair<int,char>P;

    string frequencySort(string s) {
        priority_queue<P> pq;   
        unordered_map<char,int>mp;

        for(char &ch : s) {
            mp[ch]++;
        }

        for(auto i : mp) {
            pq.push({i.second, i.first});
        }

        string ans;
        while(!pq.empty()) {
            P top = pq.top();
            pq.pop();

            ans += string(top.first, top.second);
        }

        return ans;
    }
};

// Second Way

class Solution {
public:
    typedef pair<char,int> P;

    struct lambda {
        bool operator()(P &a, P &b) {
            return a.second < b.second;
        }
    };

    string frequencySort(string s) {
        priority_queue <P, vector<P>, lambda> pq;

        unordered_map<char,int> mp;
        for(char &ch : s) {
            mp[ch]++;
        }

        for(auto i : mp) {
            pq.push({i.first, i.second});
        }

        string ans;
        while(!pq.empty()){
            P top = pq.top();
            pq.pop();

            ans += string(top.second, top.first);
        }

        return ans;
    }
};