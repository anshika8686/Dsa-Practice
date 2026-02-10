#include <bits/stdc++.h>
using namespace std;

class myStack {
    int *arr;
    int top, size;

public:
    myStack(int n) {
        size = n;
        arr = new int[n];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;   // cleaner than top=top+1
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[top];
    }
};

int main() {
    myStack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.peek() << endl; // 30

    st.pop();

    cout << "Top after pop: " << st.peek() << endl; // 20

    st.push(40);
    st.push(50);
    st.push(60); // overflow

    cout << "Final top: " << st.peek() << endl;

    return 0;
}
