#include <bits/stdc++.h>
using namespace std;

struct SLLNode {
    int val;
    SLLNode *next;
    SLLNode(int x) : val(x), next(NULL) {}
};

class MYSLL {
    SLLNode *head;

public:
    MYSLL() {
        head = NULL;
    }

    void addAtHead(int val) {
        SLLNode *cur = new SLLNode(val);
        cur->next = head;
        head = cur;
    }

    SLLNode *getNode(int index) {
        SLLNode *cur = head;
        for (int i = 0; i < index && cur; ++i)
            cur = cur->next;
        return cur;
    }

    int getIndexValue(int index) {
        SLLNode *cur = getNode(index);
        return cur == NULL ? -1 : cur->val;
    }

    void addAtTail(int val) {
        if (head == NULL) {
            addAtHead(val);
            return;
        }
        SLLNode *prev = getTail();
        SLLNode *cur = new SLLNode(val);
        prev->next = cur;
    }

    SLLNode *getTail() {
        SLLNode *cur = head;
        while (cur && cur->next) {
            cur = cur->next;
        }
        return cur;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        SLLNode *prev = getNode(index - 1);
        if (prev == NULL) {
            return;
        }
        SLLNode *cur = new SLLNode(val);
        SLLNode *next = prev->next;
        cur->next = next;
        prev->next = cur;
    }

    void deleteAtIndex(int index) {
        SLLNode *cur = getNode(index);
        if (cur == NULL) {
            return;
        }
        SLLNode *next = cur->next;
        if (index == 0) {
            head = next;
        } else {
            SLLNode *prev = getNode(index - 1);
            prev->next = next;
        }
    }
};

int main() {
    MYSLL sll;

    sll.addAtHead(5);
    sll.addAtHead(6);
    sll.addAtHead(7);

    sll.addAtTail(11);

    sll.addAtIndex(4, 16);

    sll.deleteAtIndex(3);

    SLLNode *lastNode = sll.getTail();

    SLLNode *indexNode = sll.getNode(0);

    cout << "val : " << indexNode->val << endl;
    cout << "Last Node : " << lastNode->val << endl;

    return 0;
}