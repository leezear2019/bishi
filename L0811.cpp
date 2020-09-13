//
// Created by 李哲 on 2020/9/10.
//
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, int> M;


    vector<string> subdomainVisits(vector<string> &cpdomains) {

        for (auto &s: cpdomains) {
            find_first_of();
        }
    }
};