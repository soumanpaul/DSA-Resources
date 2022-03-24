#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = NULL;
    }
}

void
printHead(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->data;
    }
}

// Insert at front
void push(struct Node **head, int new_data) {
    struct Node *temp = new Node;
    temp->data = new_data;
    temp->new_data = *head;
    *head = temp;
}

// Insert After
void insertAfter(struct Node *prev_node, int new_data) {
    if (prev_node == NULL)
        return;
    Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node
}

// insert last
void append(struct Node **head, int new_data) {
    Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return
    }

    struct Node *last = *head_ref;

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

// delete first occurance
void deleteNode(struct Node **head_ref, int key) {
    struct Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

int search(Node *head, int x) {
    if (head == NULL)
        return -1;
    if (head->data == x)
        return 1;
    else {
        int res = search(head->next, x);
        if (res == -1)
            return -1;
        else
            return res + 1;
    }
}

/* Given a reference (pointer to pointer) to the head of a list
   and a position, delete the node at the given position */
void deleteNodeAtGivenPosition(struct Node **heade_ref, int position) {
    if (*head_ref == NULL)
        return;
    struct Node *temp = *head_ref;
    int count = 0;

    while (temp != NULL && count < position) {
        count++;
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
        return;
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void deleteNodeWhithPointerGiven() {
}

void printMiddle(Node *head) {
    if (head == NULL)
        return;
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
}

void printNthFromEnd(Node *head, int n) {
    if (head == NULL)
        return;
    Node *first = head;
    for (int i = 0; i < n; i++) {
        if (first == NULL)
            return;
        first = first->next;
    }
    Node *second = head;
    while (first != NULL) {
        second = second->next;
        first = first->next;
    }
    cout << (second->data);
}

Node *reverseIterative(Nide *head) {
    Node *curr = head;
    Node *prev = NULL, *next = NULL

                       while (curr != NULL) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    head = prev;
}

Node *ReverseRecursive(Node *head) {
    if (head == NULL || head->nex == NULL)
        return head;
    Node *rest_head = ReverseRecursive(head->next);
    Node *rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;
    return rest_head;
}
//   Tail recursive
Node *recRevL(Node *curr, Node *prev) {
    if (curr == NULL)
        return prev;
    Node *next = curr->next;
    curr->next = prev;
    return recRevL(next, curr);
}

void RemoveDuplicate(Node *head) {
    Node *curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete (temp);
        } else
            curr = curr->next;
    }
}

Node reverseK(Node *head, int k) {
    Node curr = head, next = NULL, prev = NULL;
    int count = 0;
    while (curr != NULL && count < k) {
        next = curr.next;
        curr->next = prev;
        prev = curr;
        curr = new;
        count++;
    }
    if (next != NULL) {
        Node rest_head = reverseK(next, k);
        head.next = rest_head;
    }
    return prev;
}
Node *reverseKIterative(Node *head, int k) {
    Node *curr = head, *prevFirst = NULL;
    bool isFirstPass = true;
    while (curr != NULL) {
        Node *first = curr, *prev = NULL;
        int count = 0;
        while (curr != NULL && count < k) {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (isFirstPass) {
            head = prev;
            isFirstPass = false;
        } else {
            prevFirst->next = prev;
        }
        prevFirst = first;
    }
    return head;
}

bool isLoopModifyStruc(Node *head) {
    Node *temp = new Node(0);
    Node *curr = head;
    while (curr != NULL) {
        if (curr->next == NULL)
            return false;
        if (curr->next == temp)
            return true;
        Node *curr_next = curr->next;
        curr->next = temp;
        curr = curr_next;
    }
    return false;
}

bool isLoop(Node *head) {
    unordered_set<Node *> s;
    for (Node *curr = head; curr != NULL; curr = curr->next) {
        if (s.find(curr) != s.end())
            return true;
        s.insert(curr);
    }
    return false;
}

bool isLoopUsingFloydCycle(Node *head) {
    Node *slow_p = head, *fast_p = head;

    while (fast_p != NULL && fast_p->next != NULL) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return true;
        }
    }
    return false;
}

void detectRemoveLoop(Node *head) {
    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (slow != fast)
        return;
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

void deleteNodeWithPointerGiven(Node *ptr) {
    Node *temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    delete (temp);
}

void deleteNodeWithOnePtr(Node *ptr) {
    Node *temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    delete (temp);
}

Node *segregate(Node *head) {
    Node *eS = NULL, *eE = NULL, *oS = NULL, *oE = NULL;
    for (Node *curr = head; curr != NULL; curr = curr->next) {
        int x = curr->data;
        if (x % 2 == 0) {
            if (eS == NULL) {
                eS = curr;
                eE = eS;
            } else {
                eE->next = curr;
                eE = eE->next;
            }
        } else {
            if (oS == NULL) {
                oS = curr;
                oE = oS;
            } else {
                oE->next = curr;
                oE = oE->next;
            }
        }
    }
    if (oS == NULL || eS == NULL)
        return head;
    eE->next = oS;
    oE->next = NULL;
    return eS;
}

int main() {

    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = new Node;
    second = new Node;
    third = new Node;

    head->data = 3;
    head->next = second;
    second->data = 4;
    second->next = third;
    third->data = 5;
    third->next = NULL;

    printHead(head);
}