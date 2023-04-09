#include <iostream>
#include <vector>
#include "MaxIncreasingSubsequence.h"
using namespace std;

void test_MaximumIncreasingSubsequence() {
    vector<vector<int>> res;
    vector<int> arr;

    
    cout << "----------------------- Testcase 1 ------------------------" << endl;

    arr = {10, 70, 20, 30, 50, 11, 30};
    res = maxSumIncreasingSubsequence(arr);

    cout << "Input" << endl;
    cout << "[";
    for (auto data: arr) {
        cout << data << " ";
    }
    cout << "]" << endl;

    cout << "Output" << endl;
    for (auto arrList: res) {
        cout << "[ ";
        for (auto data: arrList) {
            cout << data << " ";
        }
        cout << "]";
    }
    cout << endl;
    cout << "Expected Answer : [110, [10, 20, 30, 50]]" << endl;

    cout << "----------------------- Testcase 2 ------------------------" << endl;
    arr = {-5, -4, -3, -2, -1};
    res = maxSumIncreasingSubsequence(arr);

    cout << "Input" << endl;
    cout << "[";
    for (auto data: arr) {
        cout << data << " ";
    }
    cout << "]" << endl;

    cout << "Output" << endl;
    for (auto arrList: res) {
        cout << "[ ";
        for (auto data: arrList) {
            cout << data << " ";
        }
        cout << "]";
    }
    cout << endl;
    cout << "Expected Answer: [-1, [-1]]" << endl;

 
    cout << "----------------------- Testcase 3 ------------------------" << endl;
    arr = {8, 12, 2, 3, 15, 5, 7};
    res = maxSumIncreasingSubsequence(arr);

   cout << "Input" << endl;
    cout << "[";
    for (auto data: arr) {
        cout << data << " ";
    }
    cout << "]" << endl;

    cout << "Output" << endl;
    for (auto arrList: res) {
        cout << "[ ";
        for (auto data: arrList) {
            cout << data << " ";
        }
        cout << "]";
    }
    cout << endl;
    cout << "Expected Answer: [35, [8, 12, 15]]" << endl;

    
    cout << "----------------------- Testcase 4 ------------------------" << endl;
    arr = {10, 15, 4, 5, 11, 14, 31, 25, 31, 23, 25, 31, 50};
    res = maxSumIncreasingSubsequence(arr);

    cout << "Input" << endl;
    cout << "[";
    for (auto data: arr) {
        cout << data << " ";
    }
    cout << "]" << endl;

    cout << "Output" << endl;
    for (auto arrList: res) {
        cout << "[ ";
        for (auto data: arrList) {
            cout << data << " ";
        }
        cout << "]";
    }
    cout << endl;
    cout << "Expected Answer: [164, [10, 11, 14, 23, 25, 31, 50]] " << endl;


}

int main() {
    test_MaximumIncreasingSubsequence();
}