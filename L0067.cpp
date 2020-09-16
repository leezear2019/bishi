//
// Created by 李哲 on 2020/9/15.
//
#include "leetcode.h"
#include <bitset>

using namespace std;

string addBinary(string a, string b) {
//    bitset<10000> aa(a);
//    bitset<10000> bb(b);
//    return aa + bb;
    if (a.size() < b.size()) {
        swap(a, b);
    }
    int j = b.size() - 1;
    int i = a.size() - 1;
    int cc = 0;
    while (j >= 0) {
        int aa = a[i] - '0';
        int bb = b[j] - '0';
        switch (aa + bb + cc) {
            case 0:
                cc = 0;
                break;
            case 1:
                a[i] = '1';
                cc = 0;
                break;
            case 2:
                a[i] = '0';
                cc = 1;
                break;
            case 3:
                a[i] = '1';
                cc = 1;
                break;
            default:
                break;

        }
        --i;
        --j;
    }
//    int i = a.size() - b.size();
    while (i >= 0) {
        if (cc == 0) { return a; }
        if (a[i] == '1') {
            cc = 1;
            a[i] = '0';
        } else {
            cc = 0;
            a[i] = '1';
        }
        --i;
    }

    if (cc == 1) {
        a = '1' + a;
    }
    return a;
}

int main() {
    string a = "0";
    string b = "0";
    cout << addBinary(a, b) << endl;
    return 0;
}