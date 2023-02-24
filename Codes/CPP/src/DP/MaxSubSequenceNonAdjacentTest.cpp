#include "MaxSubSequenceNonAdjacent.h"
#include <iostream>
#include <vector>
using namespace std; 

void test_MaxSubSequenceNonAdjacent() {
    cout << "Testing Maximum Sub Sequence Sum Non Adjacent" << endl;
    vector<int> arr = {75, 105, 120, 75, 90, 135};
    cout << "Input Array:" << endl;
    for (auto data:arr) {
        cout << data << " ";
    }
    cout << endl;
    
    int sum = maxSubsetSumNoAdjacent(arr);
    cout << "Maximum Sub Sequence Sum Non Adjacent is : " << sum << endl;

}

int main() {
    test_MaxSubSequenceNonAdjacent();
    return 0;
}

/* 
 * Command to run 
 * clang++ -g -std=c++11 src/DP/MaxSubSequenceNonAdjacentTest.cpp  -o bin/testDP && ./bin/testDP
 */