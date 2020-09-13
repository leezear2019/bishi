#include <iostream>
#include <vector>

using namespace std;

bool next(vector<int> &A, const int len, int n) {
    int i = len - 1;
    int k = 0;
    while (i >= 0) {
        if (A[i] < n) {
            ++A[i];
            break;
        } else {
            ++k;
            n = A[i] - 1;
        }
        --i;
    }
    if (k == A.size())
        return false;

    for (; k > 0; k--) {
        A[++i] = A[i] + 1;
    }
    return true;
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> B;
    vector<int> A(k);

    for (int i = 0; i < k; ++i) {
        A[i] = i + 1;
    }

    do {
        for (auto a:A) {
            cout << a << " ";
        }
        cout << endl;
        B.push_back(A);
    } while (next(A, k, n));

    return B;
}

int main() {
    combine(4, 2);
    return 0;
}
