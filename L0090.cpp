//
// Created by 李哲 on 2020/9/13.
//

#include "leetcode.h"

using namespace std;

void dfs(vector<int> &nums, int start, vector<int> &tmp, vector<vector<int>> &A) {
    A.push_back(tmp);
    for (int i = start; i < nums.size(); ++i) {
        if (i > start && nums[i] == nums[i - 1]) continue;
        tmp.push_back(nums[i]);
        dfs(nums, i + 1, tmp, A);
        tmp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> A;
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    dfs(nums, 0, tmp, A);
    return A;
}

int main() {
    cir(0, 3);
}