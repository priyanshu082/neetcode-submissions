class Node {
    public :
    int key,value;
    Node* next;

    Node(int k, int v){
        key = k;
        value = v;
        next = nullptr;
    }
};

class MyHashMap {
public:
    int SIZE = 1000;
    Node* Bucket[1000];
    MyHashMap() {
        for(int i=0;i<SIZE;i++) Bucket[i]=nullptr;
    }
    
    void put(int key, int value) {
        int idx= key % SIZE;
        if(Bucket[idx]==nullptr){
            Node* node = new Node(key,value);
            Bucket[idx]=node;
        }else{
            Node* node = Bucket[idx];
            while(true){
                if(node->key == key) {
                    node->value=value;
                    break;
                }
                if(node->next) node= node->next;
                else {
                    Node* newNode = new Node(key,value);
                    node->next= newNode;
                    break;
                }
            }
        }
    }
    
    int get(int key) {
        int idx=key % SIZE;
        Node* node = Bucket[idx];
        int ans=-1;
        if(!node) return ans;
        else{
            while(node){
                if(node->key==key) {
                    ans=node->value;
                    break;
                }
                else node = node->next;
            }
        }
        return ans;
    }
    
    void remove(int key) {
        int idx = key % SIZE;
        Node* node = Bucket[idx];
        Node* prev = nullptr;

        while(node){
            if(node->key == key){
                if(prev == nullptr) Bucket[idx] = node->next;
                else prev->next = node->next;
                delete node;
                return;    
            }else{
                prev = node;
                node = node->next;
            } 
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */