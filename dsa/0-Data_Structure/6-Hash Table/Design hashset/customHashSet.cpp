// There are two key questions that one should address, in order to implement the HashSet 
// data structure, namely hash function and collision handling.

/*
hash function: 

The goal of the hash function is to assign an address to store a given value. Ideally, each unique value should have a unique hash value.
collision handling: since the nature of a hash function is to map a value from a space A
into a corresponding value in a smaller space B, it could happen that multiple values from 
space A might be mapped to the same value in space B. This is what we call collision. 
Therefore, it is indispensable for us to have a strategy to handle the collision.

Overall, there are several strategies to resolve the collisions:

Separate Chaining: for values with the same hash key, we keep them in a bucket, and each bucket is independent of each other.

Open Addressing: whenever there is a collision, we keep on probing on the main space with certain strategy until a free slot is found.

2-Choice Hashing: we use two hash functions rather than one, and we pick the generated address with fewer collision.

we focus on the strategy of separate chaining. Here is how it works overall.

Essentially, the primary storage underneath a HashSet is a continuous memory as Array. Each element in this array corresponds to a bucket that stores the actual values.
Given a value, first we generate a key for the value via the hash function. The generated key serves as the index to locate the bucket.
Once the bucket is located, we then perform the desired operations on the bucket, such as add, remove and contains.


*/

// Approach 1: LinkedList as Bucket:



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

//  Approach 2: Binary Search Tree (BST) as Bucket

/*
In the above approach, one of the drawbacks is that we have to scan the entire linkedlist in order to verify if a value already exists in the bucket (i.e. the lookup operation).
To optimize the above process, one of the strategies could be that we maintain a sorted list as the bucket. With the sorted list, we could obtain the \mathcal{O}(\log{N})O(logN) time complexity for the lookup operation, with the binary search algorithm, rather than a linear \mathcal{O}({N})O(N) complexity as in the above approach.
On the other hand, if we implement the sorted list in a continuous space such as Array, it would incur a linear time complexity for the update operations (e.g. insert and delete), since we would need to shift the elements.
So the question is can we have a data structure that have \mathcal{O}(\log{N})O(logN) time complexity, for the operations of search, insert and delete ?
*/

// Well. The answer is yes, with Binary Search Tree (BST). Thanks to the properties of BST, we could optimize the time
// complexity of our first approach with LinkedList.
// https://leetcode.com/problems/design-hashset/Figures/705/705_BST.png

