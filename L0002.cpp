//
// Created by lee on 2020/9/11.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "leetcode.h"

using namespace std;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int a = 0, b = 0, c = 0;
        ListNode *head = l1, *pre, *pre2 = l2;
        while (l1 && l2) {
            pre = l1;
            a = l1->val + l2->val + b;
            b = a / 10;
            c = a % 10;
            l1->val = c;
            l1 = l1->next;
            l2 = l2->next;
        }

        pre->next = l1 ? l1 : l2;

        while (pre->next) {
            pre = pre->next;
            a = pre->val + b;
            b = a / 10;
            c = a % 10;
            pre->val = c;
        }

        if (b) {
            pre->next = pre2;
            pre = pre->next;
            pre->val = b;
        }
        pre->next = nullptr;

        return head;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode *stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode *node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
//    string line= "[2,4,3]";
//    while (getline(cin, line)) {

    ListNode *l1 = stringToListNode("[5]");
//        getline(cin, line);
    ListNode *l2 = stringToListNode("[5]");

    ListNode *ret = Solution().addTwoNumbers(l1, l2);

    string out = listNodeToString(ret);
    cout << out << endl;
//    }
    return 0;
}