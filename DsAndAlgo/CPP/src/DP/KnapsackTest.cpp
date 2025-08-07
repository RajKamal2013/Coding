/* 
 * Given n items, weights of each n items and values of each n items.
 * Given a knapsack of capacity, capacity.
 * Fill the knapsack with items so that total weight of items is less than or equal 
 * to capacity of knapsack, maximizing the overall values.
 * Each items is distinct  
*/

#include <iostream>
#include <vector>
#include <map>
//#include "Knapsack.h"

int FindKnapsack(int capacity, std::vector<int> &weights, std::vector<int> &values, int n) {
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(capacity + 1, 0));
    for (std::size_t idx = 0; idx < dp.size(); idx++) {
        for (std::size_t weight = 0; weight < dp[0].size(); weight++) {
            if ((idx == 0) || (weight == 0)) {
                dp[idx][weight] = 0;
            } else if (weights[idx - 1] <= static_cast<int>(weight)) {
                dp[idx][weight] = std::max(values[idx-1] + dp[idx -1][weight - weights[idx-1]], dp[idx-1][weight]);
            } else {
                dp[idx][weight] = dp[idx-1][weight];
            }
        }
    }
    return dp[n][capacity];
}

void display(int capacity, std::vector<int> weights, std::vector<int> values, int items, 
                    int maxValue, int expectedValue= 0) {
    std::cout << "\n-----------------Input-----------------------" << "\n";
    std::cout << "Total Items :" << items << "\n"; 
    std::cout << "Weights: {";
    for (int weight: weights) {
        std::cout << weight <<  " ";
    }
    std::cout << "}" << "\n";

    std::cout << "Values: {";
    for (int value: values) {
        std::cout << value << " ";
    }
    std::cout << "}" << "\n";

    std::cout << "Knapsack Capacity: " << capacity << "\n";
    std::cout << "\n------------------Output -------------------------\n";
    std::cout << "FindKnasack Computed Output: " << maxValue << "\n";
    std::cout << "FindKnasack Expected Output: " << expectedValue << "\n";
}
void test_Knapsack() {
    int capacity;
    int items;


    std::vector<int> weights;
    std::vector<int> values;
    int maxValue;
    int expectedValue;

    //---------------------------- Test Case 1 ------------------------------//
    capacity = 6;
    weights = {1, 2, 3, 5};
    values = {1, 5, 4, 8};
    items = 4;
    maxValue = FindKnapsack(capacity, weights, values, items);
    expectedValue = 10;
    display(capacity, weights, values, items, maxValue, expectedValue);
}

int main() {
    std::cout << " --------------------------------------------------------------\n";
    std::cout << "                    Testing Knapsack 01                        \n";
    std::cout << " --------------------------------------------------------------\n";
    test_Knapsack();
    std::cout << "\n-------------------------------------------------------------------\n";
}