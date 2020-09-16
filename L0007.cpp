//
// Created by 李哲 on 2020/9/17.
//

#include "leetcode.h"

using namespace std;

int reverse(int x) {
    int a = 0;

    while (x != 0) {
        auto b = x % 10;
        a *= 10;
        a += b;
        x /= 10;
    }

    if(a>INT_MAX||a<INT_MIN){
        a=0;
    }

    return a;

}

int main() {
    cout << reverse(1534236469) << endl;
    return 0;
}