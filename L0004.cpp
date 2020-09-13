//
// Created by lee on 2020/9/12.
//
#include "leetcode.h"

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // 交换
    if (nums1 > nums2) {
        swap(nums1, nums2);
    }

    int s1 = 0, e1 = nums1.size() - 1, s2 = 0, e2 = nums2 - 1;

    auto mid1 = (s1 + e1 + 1) / 2;
}

tuple<bool, int, int, int> midian(vector<int> &A, i, j){
    (i+j+1 )/2
}