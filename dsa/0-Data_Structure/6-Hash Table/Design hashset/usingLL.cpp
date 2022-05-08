struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
}


class SLL {

    public: 

};



class MyHashSet {
  list<int> *hashTable;
    
public:
    MyHashSet() {
       hashTable = new  list<int>[10000]; 
    }
    
    void add(int key) {
        int y = key % 1000;
        hashTable[y].push_back(key);
    }
    
    void remove(int key) {
        int y = key % 1000;
        hashTable[y].remove(key);
    }
    
    bool contains(int key) {
         int i = key % 1000;
        for (auto x : hashTable[i])
            if (x == key)
                return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */