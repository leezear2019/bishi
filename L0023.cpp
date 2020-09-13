////
//// Created by lee on 2020/9/11.
////
//
//
////Definition for singly-linked list.\
//
////
//
//
//#include <vector>
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode *next;
//
//    ListNode() : val(0), next(nullptr) {}
//
//    ListNode(int x) : val(x), next(nullptr) {}
//
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//
//    ListNode *mergeTwoLists(ListNode *a, ListNode *b) {
//        if ((!a && b)) {
//            return a ? a : b;
//        }
//        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
//        while (aPtr && bPtr) {
//            if (aPtr->val < bPtr->val) {
//                tail->next = aPtr;
//                aPtr = aPtr->next;
//            } else {
//                tail->next = bPtr;
//                bPtr = bPtr->next;
//            }
//            tail = tail->next;
//        }
//        tail->next = aPtr ? aPtr : bPtr;
//        return tail;
//    }
//
//    ListNode *merge(vector<ListNode *> &lists, int l, int r) {
//        if (l == r) return lists[l];
//        if (l < r) return nullptr;
//        int mid = (l + r) >> 1;
//        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
//    }
//
//    ListNode *mergeKLists(vector<ListNode *> &lists, ListNode *pNode) {
//        return merge(lists, 0, lists.size());
//    }
////
////    ListNode *mergeTwoList(ListNode *a, ListNode *b) {
////        if (!a || !b) {
////            return a ? a : b;
////        }
////
////        ListNode *head;
////        while (a && b) {
////            if (a->val <= b->val) {
////                head->next = a;
////                a = a->next;
////            } else {
////                head->next = b;
////                b = b->next;
////            }
////            head = head->next;
////        }
////        head->next = a ? a : b;
////        return head;
////    }
////
////    ListNode *mergeKLists(vector<ListNode *> &lists) {
//////        return merge(lists, 0, lists.size() - 1);
////    }
//
//};
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr;
                aPtr = aPtr->next;
            } else {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    ListNode *merge(vector<ListNode *> &lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};


ListNode *merge2Lists(ListNode *a, ListNode *b) {
    if (!a || !b) return a ? a : b;
    ListNode head, *tail = &head;
    while (a && b) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return head.next;
}

ListNode *merge(vector<ListNode *>& lists, int l, int r) {
    if (l == r) return lists[l];
    if (l > r) return nullptr;
    int mid = (l + r) >> 1;
    return merge2Lists(merge(lists, l, mid), merge(lists, mid + 1, r));
}

int main() {
    return 0;
}