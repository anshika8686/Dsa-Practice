#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> st;  // {price, index}
    int index;

    StockSpanner() {
        index = -1;
    }

    int next(int price) {
        index++;   // move to next day
        
        // Remove all smaller or equal prices
        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }

        int pge = st.empty() ? -1 : st.top().second;
        int span = index - pge;

        st.push({price, index});
        
        return span;
    }
};

int main() {
    StockSpanner obj;

    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(prices[0]);

    for(int i = 0; i < n; i++) {
        cout << obj.next(prices[i]) << " ";
    }

    return 0;
}
