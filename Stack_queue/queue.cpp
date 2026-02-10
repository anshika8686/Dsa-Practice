#include <bits/stdc++.h>
using namespace std;

class myQueue {
    int *arr;
    int start, end, size;

public:
    myQueue(int n) {
        size = n;
        arr = new int[n];
        start = -1;
        end = -1;
    }

    bool isEmpty() {
        return start == -1;
    }

    bool isFull() {
        return end == size;   // end points to next free index
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }

        if (isEmpty()) {
            start = 0;
            end = 0;
        }

        arr[end] = x;
        end++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        start++;

        // if queue becomes empty again
        if (start == end) {
            start = end = -1;
        }
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[start];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[end - 1];   // last element
    }
};

int main() {
    myQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.getFront() << endl; // 10
    cout << "Rear: " << q.getRear() << endl;   // 30

    q.dequeue();

    cout << "Front after dequeue: " << q.getFront() << endl; // 20

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // should show "Queue is Full"

    cout << "Rear now: " << q.getRear() << endl;

    return 0;
}
