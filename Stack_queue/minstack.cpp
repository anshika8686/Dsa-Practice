#include <bits/stdc++.h>
using namespace std;

class MinStackpair {
    stack<pair<int,int>> st;

public:
    MinStackPair() {}

    void pushVal(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            st.push({val, min(st.top().second, val)});
        }
    }

    void popVal() {
        if (st.empty()) return;
        st.pop();
    }

    int topVal() {
        if (st.empty()) return -1;
        return st.top().first;
    }

    int getMinVal() {
        if (st.empty()) return -1;
        return st.top().second;
    }
};
class MinStackEncoded {
    stack<long long> st;
    long long mini;

public:
    MinStackEncoded() {
        mini = LLONG_MAX;
    }

    void pushVal(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                // encode
                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }

    void popVal() {
        if (st.empty()) return;

        if (st.top() < mini) {
            // decode previous min
            mini = 2LL * mini - st.top();
        }
        st.pop();
    }

    int topVal() {
        if (st.empty()) return -1;

        if (st.top() >= mini)
            return st.top();
        else
            return mini;
    }

    int getMinVal() {
        if (st.empty()) return -1;
        return mini;
    }
};
int main() {
    cout << "Testing MinStack using Pair\n";
    MinStackpair s1;
    s1.pushVal(5);
    s1.pushVal(3);
    s1.pushVal(7);

    cout << "Top: " << s1.topVal() << endl;      // 7
    cout << "Min: " << s1.getMinVal() << endl;   // 3
    s1.popVal();
    cout << "Top after pop: " << s1.topVal() << endl; // 3
    cout << "Min after pop: " << s1.getMinVal() << endl; // 3

    cout << "\nTesting MinStack using Encoding\n";
    MinStackEncoded s2;
    s2.pushVal(5);
    s2.pushVal(3);
    s2.pushVal(7);

    cout << "Top: " << s2.topVal() << endl;      // 7
    cout << "Min: " << s2.getMinVal() << endl;   // 3
    s2.popVal();
    cout << "Top after pop: " << s2.topVal() << endl; // 3
    cout << "Min after pop: " << s2.getMinVal() << endl; // 3

    return 0;
}

