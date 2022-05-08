#include <bits/stdc++.h>
using namespace std;

struct DoublyListNode {
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int x) : val(x), next(NULL), prev(NULL) {}
};

class MyLinkedList {
    DoublyListNode *head;

public:
    MyLinkedList() {
        head = NULL;
    }
    DoublyListNode *getNode(int index) {
        DoublyListNode *cur = head;
        for (int i = 0; i < index && cur; ++i)
            cur = cur->next;
        return cur;
    }
    DoublyListNode *getTail() {
        DoublyListNode *cur = head;
        while (cur && cur->next)
            cur = cur->next;
        return cur;
    }
    int get(int index) {
        DoublyListNode *cur = getNode(index);
        return cur == NULL ? -1 : cur->val;
    }
    void addAtHead(int val) {
        DoublyListNode *cur = new DoublyListNode(val);
        cur->next = head;
        if (head) {
            head->prev = cur;
        }
        head = cur;
        return;
    }
    void addAtTail(int val) {
        if (head == NULL) {
            addAtHead(val);
            return;
        }
        DoublyListNode *prev = getTail();
        DoublyListNode *cur = new DoublyListNode(val);
        prev->next = cur;
        cur->prev = prev;
    }
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        DoublyListNode *prev = getNode(index - 1);
        if (prev == NULL) {
            return;
        }
        DoublyListNode *cur = new DoublyListNode(val);
        DoublyListNode *next = prev->next;
        cur->prev = prev;
        cur->next = next;
        prev->next = cur;
        if (next) {
            next->prev = cur;
        }
    }
    void deleteAtIndex(int index) {
        DoublyListNode *cur = getNode(index);
        if (cur == NULL)
            return;
        DoublyListNode *prev = cur->prev;
        DoublyListNode *next = cur->next;
        if (prev)
            prev->next = next;
        else
            head = next;

        if (next)
            next->prev = prev;
    }
};
