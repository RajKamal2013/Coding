#include <iostream>
#include <vector>

#include "SubsetSum.h"

void display(std::vector<int> &arr, int targetSum, bool subsetExist, bool subsetPresent) {
    std::cout << "\n-----------------Input-----------------------" << "\n";
    std::cout << "Array: [";
    for (int data : arr) {
        std::cout << data << " ";
    }
    std::cout << "]" << "\n";
    std::cout <<  "Target Sum: " << targetSum << "\n";


    std::cout << "\n-----------------Output-----------------------" << "\n";
    std::cout << "Subset Exist:  " << subsetExist << "\n";
    std::cout << "Subset Existence Expectation: " << subsetPresent << "\n";
}


void test_SubsetSum() {
    std::vector<int> arr;
    int targetSum;
    bool subsetExist; 
    bool subsetPresent;
    int testCaseCount = 0;

    /*---------------------------- Test Case 1 ------------------------------*/
    testCaseCount = testCaseCount + 1;
    std::cout << "-------------------------Test Case: " << testCaseCount << "--------------------------\n";
    arr = {1, 2, 3, 7};
    targetSum = 6;
    subsetExist = SubsetSum(arr, targetSum);
    subsetPresent = true;
    display(arr, targetSum, subsetExist, subsetPresent);

}

int main() {
    test_SubsetSum();
}