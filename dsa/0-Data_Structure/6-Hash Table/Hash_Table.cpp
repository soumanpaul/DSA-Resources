#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
    vector<pair<int, int>> *hashTable;

public:
    MyHashMap() {
        hashTable = new vector<pair<int, int>>[10000];
    }

    void put(int key, int value) {
        int index = key % 1000;
        int i = 0;
        auto it = hashTable[index].begin();
        for (auto it = hashTable[index].begin(); it != hashTable[index].end(); it++) {
            if (hashTable[index][i].first == key) {
                hashTable[index][i].second = value;
                break;
            }
            i++;
        }
        if (it == hashTable[index].end())
            hashTable[index].push_back({key, value});
    }

    int get(int key) {
        int index = key % 1000;
        int i = 0;
        while (i < hashTable[index].size()) {

            if (hashTable[index][i].first == key) {
                return hashTable[index][i].second;
            }
            i++;
        }
        return -1;
    }

    void remove(int key) {
        int index = key % 1000;
        int i = 0;
        while (i < hashTable[index].size()) {
            if (hashTable[index][i].first == key) {
                hashTable[index].erase(hashTable[index].begin() + i);
                // break;
            }
            i++;
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