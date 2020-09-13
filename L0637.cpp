//
// Created by lee on 2020/9/12.
//

#include "leetcode.h"

using namespace std;


vector<double> averageOfLevels2(TreeNode *root) {
    vector<double> scores(1);
    vector<int> num_nodes(1);
    int top = 0;
    scores[top] = 0;
    num_nodes[0] = 0;
    queue<tuple<TreeNode *, int>> q;
    q.push(make_tuple(root, 0));

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        auto a = std::get<0>(p);
        auto b = std::get<1>(p);
        if (b >= scores.size() ) {
            scores.push_back(root->val);
            num_nodes.push_back(1);
        } else {
            num_nodes[b]++;
            scores[b] += a->val;
        }

        if (a->left) { q.push(make_tuple(a->left, b + 1)); }
        if (a->right) { q.push(make_tuple(a->right, b + 1)); }
    }

    for (int i = 0, len = scores.size(); i < len; ++i) {
        scores[i] /= num_nodes[i];
    }

    return scores;
}




void cir(TreeNode *root, vector<double> &scores, vector<int> &num_nodes, int level) {
    if (root)return;
    if (level >= scores.size()) {
        scores.push_back(root->val);
        num_nodes.push_back(1);
    } else {
        num_nodes[level]++;
        scores[level] += root->val;
    }

    cir(root->left,scores,num_nodes,level+1);
    cir(root->right,scores,num_nodes,level+1);
}
vector<double> averageOfLevels(TreeNode *root) {
    vector<double> scores;
    vector<int> num_nodes;
    cir(root,scores,num_nodes,0);

    for (int i = 0, len = scores.size(); i < len; ++i) {
        scores[i] /= num_nodes[i];
    }

    return scores;
}
