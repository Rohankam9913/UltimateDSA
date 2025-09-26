// Using Brute Force

class StockSpanner {
public:
    vector<int>stocks;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;

        for(int i = stocks.size()-1;i >= 0;i--) {
            if(stocks[i] > price) {
                break;
            }

            span++;
        }

        stocks.push_back(price);
        return span;
    }
};

// Using Stack

class StockSpanner {
public:
    stack<pair<int,int>>st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;

        if(st.empty() || st.top().first > price) {
            st.push({price,span});
        } else {
            while(!st.empty() && st.top().first <= price) {
                span += st.top().second;
                st.pop();
            }
            
            st.push({price,span});
        }

        return span;
    }
};