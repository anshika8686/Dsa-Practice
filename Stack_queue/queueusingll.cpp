#include <iostream>
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

class myQueue {
    Node* front;
    Node* end;
    int len;

  public:
    myQueue() {
        front = NULL;
        end = NULL;
        len = 0;
    }

    bool isEmpty() {
        return (len == 0);
    }

    void enqueue(int x) {
        Node* newnode = new Node(x);

        if (front == NULL) {
            front = newnode;
            end = newnode;
        } else {
            end->next = newnode;
            end = newnode;
        }
        len++;
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }

        if (len == 1) {
            delete front;
            front = end = NULL;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        len--;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return front->data;
    }

    int size() {
        return len;
    }
};

int main() {
    myQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl; // 10
    cout << "Queue size: " << q.size() << endl;        // 3

    q.dequeue();  // removes 10
    cout << "Front after dequeue: " << q.getFront() << endl; // 20

    q.dequeue();  // removes 20
    q.dequeue();  // removes 30

    cout << "Is queue empty? ";
    if (q.isEmpty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
