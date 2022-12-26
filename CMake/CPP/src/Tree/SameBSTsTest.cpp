#include <iostream>
#include "BST.h"
#include "SameBSTs.h"
using namespace std;

void test_SameBSTs() {
    cout << "Testing SAME BSTS" << endl;
    vector<int> arr1 = {10, 15, 8, 12, 94, 81, 5, 2, 11};
    vector<int> arr2 = {10, 8, 5, 15, 2, 12, 11, 94, 81};
    bool isSameBST = sameBsts(arr1, arr2);
    cout << "Input:" << endl;
    for (auto data: arr1) {
        cout << data << " ";
    }
    cout << endl;

    for (auto data: arr2) {
        cout << data << " ";
    }
    cout << endl;

    cout << "Above arrays represent Same BST: " << isSameBST << endl;

}


int main() {
    test_SameBSTs();
}
/* 
 * Command 
 * clang++ -std=c++11 src/Tree/BST.cpp src/Tree/SameBSTsTest.cpp -o bin/testTree && ./bin/testTree 
 */