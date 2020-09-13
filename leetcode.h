//
// Created by lee on 2020/9/11.
//

#ifndef BISHI_LEETCODE_H
#define BISHI_LEETCODE_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <stack>
#include <algorithm>
#include <sstream>
#include <queue>
#include <cassert>
#include <unordered_set>


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //BISHI_LEETCODE_H
