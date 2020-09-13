//
// Created by 李哲 on 2020/9/11.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>


using namespace std;

bool pr(vector<int> &postorder, int i, int j) {
    if (i >= j)
        return false;
    int m = i;
    while (postorder[m] < postorder[j]) {
        m++;
    }
    int n = m;
    while (postorder[m] > postorder[j]) {
        m++;
    }
    return m == j && pr(postorder, i, n - 1) && pr(postorder, n, j);
}

bool recur(vector<int>& postorder, int i, int j) {
    if(i >= j) return true;
    int p = i;
    while(postorder[p] < postorder[j]) p++;
    int m = p;
    while(postorder[p] > postorder[j]) p++;
    return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);
}


//bool verifyPostorder(vector<int> &postorder) {
//    return pr(postorder, 0, postorder.size() - 1);
//}


bool verifyPostorder(vector<int> &postorder) {
    stack<int> s;
    int root = INT_MAX;
    for (int i = postorder.size() - 1; i >= 0; i--) {
        if (postorder[i] > root) {
            return false;
        }
        while (!s.empty() && s.top() > postorder[i]) {
            root = s.top();
            s.pop();
        }
        s.push(postorder[i]);
    }
    return true;
}

int main() {

}