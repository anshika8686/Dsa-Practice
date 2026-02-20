class LRUCache {
public:
class Node{
    public:
    int key;
    int data;
    Node* prev;
    Node* next;

Node(int k,int v){
    key=k;
    data=v;
    prev=NULL;
    next=NULL;
}
};
unordered_map<int,Node*>mpp;
int cap;
Node* head;
Node* tail;
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;  
    }

    void deletee(Node* temp)
    {
        Node* prevNode=temp->prev;
        Node* nextNode=temp->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    void insertAfterHead(Node* temp)
    {
        Node* nextNode=head->next;

        head->next=temp;
        temp->prev=head;

        temp->next=nextNode;
        nextNode->prev=temp;
    }

    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
           Node* node =mpp[key];
           deletee(node);
           insertAfterHead(node);
           return node->data;
        }
        return -1;
      }
    
    void put(int key, int value) {
      
        if(mpp.find(key)!=mpp.end()){
            Node*node=mpp[key];
            deletee(node);
            node->data=value;
            
            insertAfterHead(node);
        }
        else
        {
            if(mpp.size()==cap){
                Node* node=tail->prev;
                mpp.erase(node->key);
                deletee(node);
                    delete(node);
            }
            Node* newNode=new Node(key,value);
            mpp[key]=newNode;
            insertAfterHead(newNode);
        }
       }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */