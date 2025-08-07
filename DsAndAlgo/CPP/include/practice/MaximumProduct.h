//
// Created by rk015348 on 17/05/25.
//

#ifndef MAXIMUM_PRODUCT_H
#define MAXIMUM_PRODUCT_H
#include <vector>
#include <stdexcept>

/**
 * Given an integer, return the maximum product of any two digits in n.
 * example:
 *  31 -> 3
 *  124 -> 8 Max(1*2, 1*4, 2*4)
 */

class MaximumProduct {

public:
    static std::vector<int> SplitNumberInDigits(int n);
    static std::vector<int> RadixSort(std::vector<int> digits);
    static int MaxProduct(int n);
    static int MaxProductOptimal(int n);
};



#endif //MAXIMUM_PRODUCT_H