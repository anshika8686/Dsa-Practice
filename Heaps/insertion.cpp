#include <bits/stdc++.h>
using namespace std;
class Heap
{
public:
    vector<int> heap;

    Heap()
    {
        heap.push_back(-1);
    }

    void insert(int val)
    {
        heap.push_back(val);
        int size = heap.size() - 1;
        int index = size;
        while (index > 1 && heap[index / 2] < heap[index])
        // a[parent]<a[child](implementing max heap)
        {
            swap(heap[index / 2], heap[index]);
            index = index / 2;
        }
    }
    void deletion()
    {
        int left_child, right_child;
        int size = heap.size() - 1;
        if(size==0){
            cout<<"Nothing to delete"<<endl;
        }
        heap[1] = heap[size];
        heap.pop_back();
        size--;



        //heapify down

        int i = 1;
        while (true)
        {
            left_child = 2 * i;
            right_child = 2 * i + 1;
            if (left_child < size && heap[i] < heap[left_child] && heap[left_child]>heap[right_child])
            {
                swap(heap[i], heap[left_child]);
                i = left_child;
            }
            else if (right_child < size && heap[i] < heap[right_child] && heap[left_child]<heap[right_child])
            {
                swap(heap[i], heap[right_child]);
                i = right_child;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        int size = heap.size() - 1;
        for (int i = 1; i <= size; i++)
        {
            cout << heap[i] << " ";
        }
    }
};
int main()
{
    Heap h;
    cin.clear();
    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(20);
    h.insert(60);
    cout<<"Insertion"<<endl;
    h.print();
    h.deletion();
    h.deletion();
    h.deletion();
    cout<<"After Deletion"<<endl;
    h.print();
    return 0;
}