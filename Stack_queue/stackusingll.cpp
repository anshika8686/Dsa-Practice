#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = NULL;
    }
};

class myStack {
    Node* top;
    int len;

  public:
    myStack() {
        top = NULL;
        len = 0;
    }

    bool isEmpty() {
        return (len == 0);
    }

    void push(int x) {
        Node* newnode = new Node(x);
        newnode->next = top;
        top = newnode;
        len++;
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        len--;
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return top->data;
    }

    int size() {
        return len;
    }
};

int main() {
    myStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.peek() << endl; // 30
    cout << "Stack size: " << st.size() << endl;  // 3

    st.pop();   // removes 30
    cout << "Top after pop: " << st.peek() << endl; // 20

    st.pop();   // removes 20
    st.pop();   // removes 10

    cout << "Is stack empty? ";
    if (st.isEmpty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
      cin.get();

    return 0;
}
