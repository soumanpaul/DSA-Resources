#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
   vector<int>heap;
   
   void MinHeapify(int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i; 
    if (l < heap.size() && heap[l] < heap[i]) smallest = l;
    if (r < heap.size() && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        MinHeapify(smallest);
    }
  }
    
    void insertKey(int key) {
        heap.push_back(key);
        int i = heap.size() -1;
        while(i !=0 && heap[i/2] > heap[i]){
            swap(heap[i], heap[i/2]);
            i = i/2;
        }
    }
    void insertAtTop(int key) {
        heap[0] = heap[heap.size()-1];
        heap[heap.size()-1] = key;
        MinHeapify(0);
    }
    int getMin(){
        return heap[0];
    }
    
    int constructHeapAndReturnMin(vector<int>& nums, int k){
        for(int i =0; i <k; i++){
            insertKey(nums[i]);
        }
        for(int i =k; i <nums.size(); i++){
            if(nums[i] > getMin())
                insertAtTop(nums[i]);
        }
        return getMin();
    }
    
    int findKthLargest(vector<int>& nums, int k) {
       int minMum;
       minMum = constructHeapAndReturnMin(nums,k);    
       return minMum;
    }
};