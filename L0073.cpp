//
// Created by lee on 2020/9/12.
//
#include "leetcode.h"

using namespace std;

void setZeroes(vector<vector<int>> &matrix) {
    auto m = matrix.size();
    auto n = matrix[0].size();

    bool h0 = false, v0 = false;
    for (int i = 0; i < m; ++i) {
        if (matrix[i][0]) {
            h0 = true;
            break;
        }
    }

    for (int i = 0; i < m; ++i) {
        if (matrix[0][i]) {
            v0 = true;
            break;
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!matrix[i][j]) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        if (!matrix[i][0]) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        if (!matrix[i][0]) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    if (h0) {
        for (int i = 0; i < m; ++i) {
            matrix[i][0] = 0;
        }
    }
    if (v0) {
        for (int i = 0; i < m; ++i) {
            matrix[0][i] = 0;
        }
    }

    if (!h0 && !v0) {
        matrix[0][0] = 1;
    }

}
