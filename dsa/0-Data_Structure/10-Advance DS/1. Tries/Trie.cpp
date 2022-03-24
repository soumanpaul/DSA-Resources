#include<bits/stdc++.h>
using namespace std;

const int AlPHA_SIZE = 26;

struct TrieNode {
    TrieNode *TrieChild[AlPHA_SIZE];
    bool isEndOfWord;

    // TrieNode() {
    //     isEndOfWord = false;
    //     for(int i=0; i< AlPHA_SIZE;i++)
    //         TrieChild[i] = NULL;
    // }   

}

struct TrieNode *getNode(void){\
    struct TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false
    for(int i = 0; i< AlPHA_SIZE; i++)
        pNode->TrieChild[i] = NULL; 
    return pNode;    
}


int main () {
    TrieNode *root;

    for(int i = 0; )
    return 0;
}