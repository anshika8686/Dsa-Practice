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
            int largest=i;
            left_child = 2 * largest;
            right_child = 2 * largest + 1;
            if (left_child <= size && heap[largest] < heap[left_child] )
            {
                largest = left_child;
            }
            if (right_child <= size && heap[largest] < heap[right_child])
            {
                largest = right_child;
            }
            if(largest!=i){ // chances of swapping is possible
                swap(heap[i],heap[largest]);
                i=largest;
            }else{
                return;
            }
        }
    }
    void print()
    {
        int size = heap.size() - 1;
        for (int largest = 1; largest <= size; largest++)
        {
            cout << heap[largest] << " ";
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