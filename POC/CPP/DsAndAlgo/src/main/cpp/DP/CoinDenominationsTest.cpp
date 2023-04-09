#include <iostream>
#include <vector>
#include "DP/CoinDenominations.h"

using namespace std;

void test_numberOfWaysToMakeChange() {
    vector<int> denoms = {1, 5};
    int target = 6;
    int count = -1;
    cout << "Denominations: ";
    for (auto data:denoms) {
        cout << data << " ";
        
    }
    cout << endl;
    cout << "Target: " << target << endl; 
    count = numberOfWaysToMakeChange(target, denoms);
    cout << "Number of ways to make Target: " << target << "is: " << count << endl;


    denoms = {1, 2, 4, 6};
    target = 6;
    cout << "Denominations: ";
    for (auto data:denoms) {
        cout << data << " ";
       
    }
    cout << endl;
    cout << "Target: " << target << endl;
    count = numberOfWaysToMakeChange(target, denoms);
    cout << "Number of ways to make Target: " << target << "is: " << count << endl;

}


/* 
 * Command 
 *  clang++ -g -std=c++11 src/DP/CoinDenominationsTest.cpp  -o bin/testDP && ./bin/testDP
 */