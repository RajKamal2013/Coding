//
// Created by rk015348 on 17/05/25.
//

#include "../../include/practice/MaximumProduct.h"

#include <iostream>



std::vector<int> MaximumProduct::SplitNumberInDigits(int n) {
    if (n < 0) {
        throw std::invalid_argument("Negative number is not allowed");
    }
    if (n < 10) {
        return std::vector<int>{n};
    }
    std::vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n = n / 10;
    }
    return digits;
}


std::vector<int> MaximumProduct::RadixSort(std::vector<int> digits) {
    static const int RADIX = 10;
    std::vector<int> arr(RADIX, 0);
    std::vector<int> aux(digits.size(), 0);

    for (int digit : digits) {
        arr[digit]++;
    }
    for (int i = 1; i < RADIX; i++) {
        arr[i] += arr[i - 1];
    }

    for (size_t i = digits.size() - 1; i >= 0; i--) {
        aux[--arr[digits[i]]] = digits[i];
    }

    for (size_t i = 0; i < digits.size(); i++) {
        digits[i] = aux[i];
    }

    return digits;
}


int MaximumProduct::MaxProduct(int n) {
    try {
        std::vector<int> digits = SplitNumberInDigits(n);
        digits = RadixSort(digits);
        if (digits.size() < 2) {
            return 0;
        }
        int product = digits[digits.size() - 1] * digits[digits.size() - 2];
        return product;
    } catch (std::invalid_argument &e) {
        throw e;
    }
}


int MaximumProduct::MaxProductOptimal(int n) {
    int d1, d2, temp;
    d1 = n % 10;
    n /= 10;
    d2 = n % 10;
    n /= 10;
    while (n > 0) {
        temp = n % 10;
        if ((temp > d1) && (d1 < d2)) {
            d1 = temp;
            n = n/10;
            continue;
        }
        if (temp > d2) {
            d2 = temp;
        }
        n = n / 10;
    }
    return d1 * d2;
}
