#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next, *random;
    Node(int x) {
        val = x;
        next = random = NULL;
    }
};

void print(Node *start) {
    Node *ptr = start;
    while (ptr) {
        cout << "val = " << ptr->val << ", Random  = " << ptr->random->val << endl;
        ptr = ptr->next;
    }
}

Node *clone(Node *head) {
    unordered_map<Node *, Node *> hm;
    for (Node *curr = head; curr != NULL; curr = curr->next)
        hm[curr] = new Node(curr->val);

    for (Node *curr = head; curr != NULL; curr = curr->next) {
        Node *cloneCurr = hm[curr];
        cloneCurr->next = hm[curr->next];
        cloneCurr->random = hm[curr->random];
    }
    Node *head2 = hm[head];

    return head2;
}

class Solution {
public:
    map<Node *, Node *> mp;

    Node *copyRandomList(Node *head) {

        if (head == NULL)
            return NULL;
        Node *current = new Node(head->val);
        Node *newHead = current;
        Node *oldHead = head;

        mp[head] = current;
        while (head != NULL) {
            Node *newNext = NULL;
            if (head->next != NULL) {
                newNext = new Node(head->next->val);
                mp[head->next] = newNext;
            }

            current->next = newNext;
            current = current->next;
            head = head->next;
        }

        Node *newNewHead = newHead;

        while (oldHead != NULL) {
            newHead->random = oldHead->random == NULL ? NULL : mp[oldHead->random];
            oldHead = oldHead->next;
            newHead = newHead->next;
        }

        return newNewHead;
    }
};

int main() {
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(20);

    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next->next->next;

    cout << "Original list : \n";
    print(head);

    cout << "\nCloned list : \n";
    Node *cloned_list = clone(head);
    print(cloned_list);

    return 0;
}
