//
// Created by 李哲 on 2020/9/13.
//
#include "leetcode.h"

using namespace std;

void dfs(vector<int> &nums, int start, vector<int> &tmp, vector<vector<int>> &A) {
    A.push_back(tmp);
    for (int i = start; i < nums.size(); ++i) {
        tmp.push_back(nums[i]);
        dfs(nums, i + 1, tmp, A);
        tmp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> A;
    vector<int> tmp;
    dfs(nums, 0, tmp, A);
    return A;
}

int main() {

}