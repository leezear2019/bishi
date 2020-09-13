//
// Created by 李哲 on 2020/9/10.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//
vector<vector<int>> A;
//
//bool next_per(vector<int> &B) {
//
//}
int len;

void bc(vector<int> a, int i, int j) {

    if (i == len - 1 & j == len) {
        return;
    }
    for (auto aa:a) {
        cout << aa << " ";
    }
    cout << endl;
    if (j + 1 >= len) {
        i++;
        j = i + 1;
    } else {
        j++;
    }

    std::swap(a[i], a[j]);

    bc(a, i, j);
}

vector<vector<int>> permute2(vector<int> &nums) {
    bc(nums, 0, 1);
}

vector<vector<int>> permute(vector<int> &nums) {

    do {
        A.push_back(nums);
        for (auto a: nums) {
            cout << a << " ";
        }
        cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));

}

int main() {
    vector<int> B = {1, 2, 3};
    len = B.size();
    permute2(B);
    return 0;
}