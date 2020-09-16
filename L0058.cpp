//
// Created by 李哲 on 2020/9/15.
//
#include "leetcode.h"

using namespace std;

//void trim(string &s) {
//    if (s.empty()) {
//        return;
//    }
//    s.erase(0, s.find_first_not_of(" "));
//    s.erase(s.find_last_not_of(" ") + 1);
//}

int lengthOfLastWord(string s) {
    trim(s);
    int len = s.size();
    if (!len) {
        return 0;
    }
    int last = s.find_last_of(' ');
    len = s.substr(last + 1, s.size() - last).size();
    return len;
}