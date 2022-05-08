#include <bits/stdc++.h>
using namespace std;

static const auto ___ = []() {
    // fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return 0;
}();

// Runtime - 152 ms, Memory - 42.3 MB
class LRUCache {
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> dict; // hash table to store key and iterator to node in list with that key
    list<pair<int, int>> cache;                              // doubly linked list to store key-value pair starting from most freq used to least freq

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        // return -1 if key not present in hash-table
        if (dict.find(key) == dict.end())
            return -1;

        auto itr = dict[key];         // get iterator to pair with required key
        int val = (*itr).second;      // store value at required key
        cache.erase(itr);             // delete pair
        cache.push_front({key, val}); // insert that pair again but at the front of cache
        dict[key] = cache.begin();    // store updated position of iterator for key
        return val;
    }

    void put(int key, int value) {
        // if key already present in hash-table (also means, already in cache)
        if (dict.find(key) != dict.end()) {
            // remove pair from cache and insert pair with the same key but different value to front of cache and update iterator value in hash-table
            auto itr = dict[key];
            cache.erase(itr);
        } else {
            // if key not present already first check capacity of cache
            if (cache.size() == capacity) {
                // if capacity is full already pop out least recently used (last element from cache) key-value pair and corresponding entry from hash-table
                pair<int, int> lru = cache.back();
                cache.pop_back();
                dict.erase(lru.first);
            }
        }

        // insert new pair in cache and its entry in hash-table
        cache.push_front({key, value});
        dict[key] = cache.begin();
    }
};