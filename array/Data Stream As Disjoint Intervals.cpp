// Using Sorting

class SummaryRanges {
public:
    unordered_set<int>st;

    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>intervals;
        vector<int>datas(begin(st),end(st));
    
        sort(begin(datas), end(datas));
        int n = datas.size();

        for(int i = 0;i < n;) {
            int start = datas[i];
            int end = datas[i];
            int j = i+1;

            while(j < n && datas[j] - 1 == datas[j-1]) {
                end = datas[j];
                j++;
            }

            intervals.push_back({start,end});
            i = j;
        }

        return intervals;
    }
};

// Using ordered set for sorting

class SummaryRanges {
public:
    set<int>st;

    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>intervals;
        vector<int>datas(begin(st),end(st));
        int n = datas.size();

        for(int i = 0;i < n;) {
            int start = datas[i];
            int end = datas[i];
            int j = i+1;

            while(j < n && datas[j] - 1 == datas[j-1]) {
                end = datas[j];
                j++;
            }

            intervals.push_back({start,end});
            i = j;
        }

        return intervals;
    }
};

// Using Hashing

class SummaryRanges {
public:
    map<int,int>mp;
    SummaryRanges() {
        mp.clear();
    }
    
    void addNum(int value) {
        int start = value;
        int end = value;

        auto justGreaterThanValue = mp.upper_bound(value);
        if(justGreaterThanValue != mp.begin()) {
            auto justSmallerThanValue = justGreaterThanValue;
            justSmallerThanValue--;

            if(justSmallerThanValue->second >= value) {
                return;
            }

            if(justSmallerThanValue->second + 1 == value) {
                start = justSmallerThanValue->first;
            }
        }

        if(justGreaterThanValue != mp.end()) {
            if(justGreaterThanValue->first - 1 == value) {
                end = justGreaterThanValue->second;
                mp.erase(justGreaterThanValue);
            }
        }

        mp[start] = end;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>intervals;
        for(auto it : mp) {
            intervals.push_back({it.first, it.second});
        }

        return intervals;
    }
};
