//
// Created by rk015348 on 13/09/25.
//

#ifndef CODING_SLIDINGWINDOW_H
#define CODING_SLIDINGWINDOW_H
#include <unordered_set>
#include <algorithm>
#include <cstddef>

using namespace std;

class SlidingWindow {
public:
    static int FindLongestSubstring(string str) {
        if (str.empty()) {
            return -1;
        }

        if (str.length() == 0) {
            return 0;
        }

        size_t firstIdx, secondIdx, len, maxLen;
        firstIdx = 0;
        secondIdx = 1;
        maxLen = 1;

        unordered_set<char> set;
        set.insert(str[0]);

        while (secondIdx < str.length()) {
           while (set.find(str[secondIdx]) != set.end()) {
               maxLen = std::max(maxLen, set.size());
               set.erase(str[firstIdx]);
               firstIdx++;
           }
            set.insert(str[secondIdx]);
            secondIdx = secondIdx + 1;
        }

        maxLen = std::max(maxLen, set.size());
        return static_cast<int>(maxLen);

    }

};


#endif //CODING_SLIDINGWINDOW_H