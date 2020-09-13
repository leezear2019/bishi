//
// Created by 李哲 on 2020/9/13.
//

#include "leetcode.h"

using namespace std;


string minWindow(string s, string t) {
    unordered_map<char, int> M;
    unordered_map<char, int> MMAX;
    string min_str;
    int num_matches = 0;
    int num_t = t.size();
    int min_matches = INT_MAX;
    // 先建索引字典
    for (auto c:t) {
        MMAX[c]++;
        M[c] = 0;
    }

    for (int i = 0, j = 0; i < s.size(); ++i) {
        auto ss = s[i];
        if (M.find(ss) != M.end()) {
            if (++M[ss] <= MMAX[ss]) {
                num_matches++;
            }
            if (num_matches == num_t) {
                while (true) {
                    ss = s[j];
                    if (M.find(ss) != M.end() && --M[ss] == (MMAX[ss] - 1)) {
                        int k = i - j + 1;
                        if (min_matches > k) {
                            min_matches = k;
                            min_str = s.substr(j, k);
                        }
                        num_matches--;
                        j++;
                        break;
                    }
                    j++;
                }
            }
        }
    }
    return min_str;
}


int main() {
//    string s = "ADOBECODEBANC";
//    string t = "ABC";
    string s = "AA";
    string t = "AA";
    cout << minWindow(s, t) << endl;
    return 0;
}
