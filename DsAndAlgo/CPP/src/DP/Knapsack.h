/* 
 * Given n items, weights of each n items and values of each n items.
 * Given a knapsack of capacity, capacity.
 * Fill the knapsack with items so that total weight of items is less than or equal 
 * to capacity of knapsack, maximizing the overall values.
 * Each items is distinct  
*/
#pragma once

#include <vector>
#include <map>

int FindKnapsack(int capacity, std::vector<int> &weights, std::vector<int> &values, int n) {

    std::map<int, int>weightValueMap;
    for (int idx = 0; idx < weights.size(); idx++) {
        weightValueMap.insert(std::make_pair(weights[idx], values[idx]));
    }

    std::vector<int> maxValues(capacity + 1, 0);
   
    for (std::pair<int, int> items : weightValueMap) {
        maxValues[items.first] = items.second;
    }

    int currMaxValue, currValue;
    for (int cap = 1; cap <= capacity; cap++) {
        currMaxValue = 0;
        for (std::pair<int, int> items : weightValueMap) {
            if (cap >= items.first) {
                currValue =  items.second + maxValues[cap - items.first];
                if (currValue >= currMaxValue) {
                    currMaxValue = currValue; 
                }
            }
        }
        maxValues[cap] = currMaxValue;
    }

    return maxValues[capacity];
}
