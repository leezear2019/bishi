//
// Created by lee on 2020/9/12.
//


#include "leetcode.h"

using namespace std;


int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> m;
    int mx = 0, start = -1;
    for (int i = 0; i < s.size(); ++i) {
        auto c = s[i];
        if (m.find(c) != m.end() && m[c] > start)
            start = m[c];
        else
            mx = max(mx, i - start);
        m[c] = i;
    }
    return mx;
}


string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
                case '\"':
                    result.push_back('\"');
                    break;
                case '/' :
                    result.push_back('/');
                    break;
                case '\\':
                    result.push_back('\\');
                    break;
                case 'b' :
                    result.push_back('\b');
                    break;
                case 'f' :
                    result.push_back('\f');
                    break;
                case 'r' :
                    result.push_back('\r');
                    break;
                case 'n' :
                    result.push_back('\n');
                    break;
                case 't' :
                    result.push_back('\t');
                    break;
                default:
                    break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
//    string line;
//    while (getline(cin, line)) {
//        string s = stringToString(line);
//
//        int ret = Solution().lengthOfLongestSubstring(s);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
    cout << lengthOfLongestSubstring("au") << endl;
    return 0;
}
