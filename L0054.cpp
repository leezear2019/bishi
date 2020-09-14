//
// Created by lee on 2020/9/14.
//

#include "leetcode.h"

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> A;
    if(!matrix.size()){return A;}
    int m = matrix[0].size();
    int n = matrix.size();
    int len = m * n;
    int h0 = 0, h1 = m - 1, v0 = 0, v1 = n - 1;
    int i, j = 0;
    while (true) {
        for (i = h0, j = v0; i <= h1; ++i) {
            A.push_back(matrix[j][i]);
        }
        if (A.size() == len) {
            return A;
        }
        for (j = ++v0, i = h1; j <= v1; ++j) {
            A.push_back(matrix[j][i]);
        }
        if (A.size() == len) {
            return A;
        }
        for (i = --h1, j = v1; i >= h0; --i) {
            A.push_back(matrix[j][i]);
        }
        if (A.size() == len) {
            return A;
        }
        for (j = --v1, i = h0; j >= v0; --j) {
            A.push_back(matrix[j][i]);
        }
        h0++;
        if (A.size() == len) {
            return A;
        }
    }

    return A;

}

int main() {
//    vector<vector<int>> M = {{1, 2, 3},
//                             {4, 5, 6},
//                             {7, 8, 9}};
    vector<vector<int>> M = {{1, 2,  3,  4},
                             {5, 6,  7,  8},
                             {9, 10, 11, 12}};
    auto A = spiralOrder(M);
    cout << A << endl;
    return 0;
}