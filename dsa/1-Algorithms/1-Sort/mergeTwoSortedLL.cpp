/*{
list1[0]+merge(list1[1:],list2)  list1[0]<list2[0]
list2[0]+merge(list1,list2[1:])  otherwise
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

// Recursive
class Solution {
public:
    ListNode *mergeTowSortedLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTowSortedLists(l1->next, l2);
            return l1;
        }
        if (l1->val > l2->val) {
            l2->next = mergeTowSortedLists(l1, l2->next);
            return l2;
        }
    }
};
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *prehead = new ListNode(-1);

        ListNode *prev = prehead;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // At least one of l1 and l2 can still have nodes at this point, so connect
        // the non-NULL list to the end of the merged list.
        prev->next = l1 == NULL ? l2 : l1;

        return prehead->next;
    }
};
