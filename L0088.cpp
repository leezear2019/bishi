//
// Created by lee on 2020/9/12.
//

#include "leetcode.h"

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int top = m + n - 1, i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0)
        if (nums1[i] >= nums2[j])
            nums1[top--] = nums1[i--];
        else
            nums1[top--] = nums2[i--];
    while (j >= 0)
        nums1[top--] = nums2[j--];
}

int main() {
    vector<int> a = {4, 5, 6, 0, 0, 0};
    vector<int> b = {1, 2, 3};

    merge(a, 3, b, 3);
    return 0;
}