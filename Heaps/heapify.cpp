void heapify(vector<int>&heap,int n,int i){
    int largest=i;
    while(largest<n){
         int left_child=2*largest;
    int right_child=2*largest+1;
        if( left_child<n && heap[largest]<heap[left_child] ){
            largest=left_child;
        }
        if(right_child<n && heap[largest]<heap[right_child] ){
            largest=right_child;
        }
    if(largest!=i){
        swap(heap[largest],heap[i]);
        heapify(heap,largest);
    }

}