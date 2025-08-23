//
// Created by raj on 19/8/25.
//

#ifndef TWOPOINTERS_H
#define TWOPOINTERS_H

#include <vector>

class TwoPointers
{
public:
    static std::vector<int> SortColors(std::vector<int> colors) {
        auto FindPivot = [&](int pivot, int startIdx) -> int {
            int lastIdx = colors.size() - 1;
            while (startIdx < lastIdx) {
                if (startIdx < colors.size() && colors[startIdx] == pivot) {
                    startIdx = startIdx + 1;
                }
                if (lastIdx > 0 && colors[lastIdx] != pivot) {
                    lastIdx = lastIdx - 1;
                }
                if (lastIdx > startIdx) {
                    std::swap(colors[startIdx], colors[lastIdx]);
                }
            }
            return startIdx;
        };

        int startIdx = 0;
        int pivot = 0;

        startIdx = FindPivot(pivot, startIdx);
        if (startIdx == colors.size()) {
            return colors;
        }

        pivot = 1;
        startIdx = FindPivot(pivot, startIdx);
        return colors;
    }

    static int FindPivot(std::vector<int> &colors, int pivot, int startIdx) {
        int lastIdx = colors.size() - 1;
        while (startIdx < lastIdx) {
            if (startIdx < colors.size() && colors[startIdx] == pivot) {
                startIdx = startIdx + 1;
            }

            if (lastIdx > 0 && colors[lastIdx] != pivot) {
                lastIdx = lastIdx - 1;
            }

            if (lastIdx > startIdx) {
                std::swap(colors[startIdx], colors[lastIdx]);
            }
        }
        return startIdx;
    }
};

#endif //TWOPOINTERS_H
