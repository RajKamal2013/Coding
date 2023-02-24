#include <iostream>
#include <string>
#include <vector>
#include "LCS.h"
using namespace std;

void test_LCS() {
    string str1, str2;
    vector<char> res;

/*
    cout << "-------------------------- TestCase 1 --------------------------" << endl;
    str1 = "AAABC";
    str2 = "AACAB";

    cout << "Input: " << endl;
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;

    res = longestCommonSubsequence(str1, str2);
    cout << "Output: " << endl;
    cout << "[";
    for (auto ch: res) {
        cout << ch << " ";
    }
    cout << "]" << endl;

    cout << "-------------------------- TestCase 2 --------------------------" << endl;
    str1 = "AACAB";
    str2 = "AAABC";
    cout << "Input: " << endl;
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;

    res = longestCommonSubsequence(str1, str2);
    cout << "Output: " << endl;
    cout << "[";
    for (auto ch: res) {
        cout << ch << " ";
    }
    cout << "]" << endl;

    cout << "-------------------------- TestCase 3 --------------------------" << endl;
    str1 = "ZXVVYZW";
    str2 = "XKYKZPW";

    cout << "Input: " << endl;
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;

    res = longestCommonSubsequence(str1, str2);
    cout << "Output: " << endl;
    cout << "[";
    for (auto ch: res) {
        cout << ch << " ";
    }
    cout << "]" << endl;

    cout << "-------------------------- TestCase 4 --------------------------" << endl;
    str1 = "XKYKZPW";
    str2 = "ZXVVYZW";
    
    cout << "Input: " << endl;
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;

    res = longestCommonSubsequence(str1, str2);
    cout << "Output: " << endl;
    cout << "[";
    for (auto ch: res) {
        cout << ch << " ";
    }
    cout << "]" << endl;

    cout << "-------------------------- TestCase 5 --------------------------" << endl;
    str1 = "ABCDEFG";
    str2 = "ABCDEFG";
    
    cout << "Input: " << endl;
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;

    res = longestCommonSubsequence(str1, str2);
    cout << "Output: " << endl;
    cout << "[";
    for (auto ch: res) {
        cout << ch << " ";
    }
    cout << "]" << endl;
    */

    cout << "-------------------------- TestCase 6 --------------------------" << endl;
    str2 = "clement";
    str1 = "antoine";

    cout << "Input: " << endl;
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;

    res = longestCommonSubsequence(str1, str2);
    cout << "Output: " << endl;
    cout << "[";
    for (auto ch: res) {
        cout << ch << " ";
    }
    cout << "]" << endl;
    cout << "Expected: [n, t]" << endl;

    cout << "-------------------------- TestCase 7 --------------------------" << endl;
    str1 = "clement";
    str2 = "antoine";

    cout << "Input: " << endl;
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;

    res = longestCommonSubsequence(str1, str2);
    cout << "Output: " << endl;
    cout << "[";
    for (auto ch: res) {
        cout << ch << " ";
    }
    cout << "]" << endl;
    cout << "Expected: [n, t]" << endl;

    cout << "-------------------------- TestCase 7 --------------------------" << endl;

    str1 =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    str2 = "CCCDDEGDHAGKGLWAJWKJAWGKGWJAKLGGWAFWLFFWAGJWKAG";
      cout << "Input: " << endl;
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;

    res = longestCommonSubsequence(str1, str2);
    cout << "Output: " << endl;
    cout << "[";
    for (auto ch: res) {
        cout << ch << " ";
    }
    cout << "]" << endl;

    cout << "Expected Answer: [C, D, E, G, H, J, K, L, W] " << endl;



}


int main() {
    test_LCS();
}