#include <iostream>
#include <vector>
#include "TargetSum.h"
using namespace std;
void display(std::vector<int> &arr, int targetSum, int totalExpressionCount, 
    int totalExpressionCountExpected) {
    std::cout << "\n-----------------Input-----------------------" << "\n";
    std::cout << "Array: [";
    for (int data : arr) {
        std::cout << data << " ";
    }
    std::cout << "]" << "\n";
    std::cout <<  "Target Sum: " << targetSum << "\n";


    std::cout << "\n-----------------Output-----------------------" << "\n";
    std::cout << "Total Number of Expressions: " << totalExpressionCount << "\n";
    std::cout << "Total Number of Expressions expected: " << totalExpressionCountExpected << "\n";
}

void test_TargetSum() {
    std::vector<int> arr;
    int targetSum;
    int totalExpressionCountExpected;
    int totalExpressionCount;
    int testCaseCount = 1;
    /*---------------------------- Test Case 1 ------------------------------*/
    std::cout << "-------------------------Test Case: " << testCaseCount << "--------------------------\n";
    arr = {1, 1};
    targetSum = 0;
    totalExpressionCountExpected = 2;
    totalExpressionCount = FindTargetSumWays(arr, targetSum);
    display(arr, targetSum, totalExpressionCount, totalExpressionCountExpected);

    /*---------------------------- Test Case 1 ------------------------------*/
    testCaseCount = testCaseCount + 1;
    std::cout << "-------------------------Test Case: " << testCaseCount << "--------------------------\n";
    arr = {1, 1, 1, 1};
    targetSum = 2;
    totalExpressionCountExpected = 4;
    totalExpressionCount = FindTargetSumWays(arr, targetSum);
    display(arr, targetSum, totalExpressionCount, totalExpressionCountExpected);
}
int main() {
    test_TargetSum();
}