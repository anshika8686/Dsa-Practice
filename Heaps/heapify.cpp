#include <bits/stdc++.h>
using namespace std;
class Heap
{
public:
    void heapify(vector<int> &heap, int n, int i)
    {
        int largest = i;
        int left_child = 2 * largest;
        int right_child = 2 * largest + 1;
        if (left_child <= n && heap[largest] < heap[left_child])
        {
            largest = left_child;
        }
        if (right_child <= n && heap[largest] < heap[right_child])
        {
            largest = right_child;
        }
        if (largest != i)
        {
            swap(heap[largest], heap[i]);
            heapify(heap, n, largest);
        }
    }
    void print(vector<int> &heap, int n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << heap[i] << " ";
        }
    }
};
int main()
{
    Heap h;
   int n;
   cout<<"Enter the size"<<endl;
cin >> n;

vector<int> heap;
heap.push_back(-1); //Adding -1 so that indexing starts from -1

cout<<"Enter the values"<<endl;

for (int i = 0; i < n; i++)
{
    int x;
    cin >> x;
    heap.push_back(x);
}
    h.heapify(heap, n, 1);
    h.print(heap, n);
    return 0;
}