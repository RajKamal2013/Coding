#include "DP/MinCoinDenominations.h"
#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> denoms, int target, int count) {
    cout << "Denominations: ";
    for (auto denom: denoms) {
        cout << denom << " ";
    } 
    cout << endl;
    cout << "Target: " << target << endl;
    cout << "Min number of coins needed to make target: " << target << " is : " << count << endl;
}

void test_MinCoinDenominations() {
    vector<int> denoms = {1, 5, 10};
    int target = 7;
    int count;
    
    denoms = {1, 5, 10};
    target = 7;
    count = minNumberOfCoinsForChange(target, denoms);
    display(denoms, target, count);

    denoms = {1, 3, 4};
    target = 10;
    count = minNumberOfCoinsForChange(target, denoms);
    display(denoms, target, count);

}
