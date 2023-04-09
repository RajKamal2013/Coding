#include "DP/MinNumberOfJumps.h"
#include <iostream>
#include <vector>
using namespace std;



void test_MinNumberOfJumps() {
    vector<int> arr;
    int jumps;

   
    cout << "-------------------------- TestCase 1------------------------------------" << endl;
    arr = {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3};
    cout << "Input Array: ";
    for (auto data: arr) {
        cout << data << " ";
    }
    cout << endl;
    jumps = minNumberOfJumps(arr);
    cout << "Minimum of Jumps Required to reach end of Array from Start: " << jumps << endl;
    cout << endl;

}

