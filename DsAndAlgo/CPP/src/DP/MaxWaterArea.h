/* 
 * Maximum Water Area
 * You are given array of non-negative number where each interger represents height of pillar of width 1.
 * Imagine water being poured over the pillars, write a function to calculater the surface area of water
 * trapped between the pillars. Spilled water should be ignored.
 * Example: 
 *  Input: {0, 8, 0, 0, 5, 0, 0, 10, 0, 0, 1, 1, 0, 3}
 *  Output: 48 
 *  
 * 
 */


#include <iostream>
#include <vector>
using namespace std;

/* 
 * Algorithm:
 * Calculate array of maximum height at index to its left.
 * Calculate array of maximum height at index to its right.
 * At each index, area of water trapped = (min(LeftMaxHeight, RighMaxHeight) - CurrHeight) * 1
 * Calculate height at each index and return the sum, 
 */

int waterAreaInt(vector<int> heights) {
    bool debugPrint = false;
    vector<int>leftMaxHeight(heights.size(), -1);
    vector<int>rightMaxHeight(heights.size(), -1);
    int area = 0;

    // calculate left maximum height
    leftMaxHeight[0] = 0;
    int currMax=heights[0];
    for (std::size_t i = 1; i < heights.size(); i++) {
        if (heights[i-1] >= currMax) {
            leftMaxHeight[i] = heights[i-1];
            currMax = heights[i-1];
        } else {
            leftMaxHeight[i] = leftMaxHeight[i-1];
        }
    }

    //calculate right maximum height
    rightMaxHeight[heights.size()-1] = 0;
    currMax = heights[heights.size()-1];
    // Using int for reverse loop to avoid unsigned underflow when reaching 0
    for (int i = static_cast<int>(heights.size())-2; i >= 0; i--) {
        if (heights[i+1] >= currMax) {
            rightMaxHeight[i] = heights[i+1];
            currMax = heights[i+1];
        } else {
            rightMaxHeight[i] = rightMaxHeight[i+1];
        }
    }

    if (debugPrint) {
        cout<< "Left Max and Right max for element at each idx" << endl;
        for (std::size_t i = 0; i < heights.size(); i++) {
            cout <<  " Data:" << heights[i] << " Left Max: " << leftMaxHeight[i] << " Right Max:" << rightMaxHeight[i] << endl;
        }
    }
    
    // calculate area
    int currHeight=0;
    area = 0;
    for (std::size_t i = 0; i < heights.size(); i++) {
        currHeight = min(leftMaxHeight[i], rightMaxHeight[i]) - heights[i];
        if (currHeight > 0) {
            area = area + currHeight * 1;
        }
    } 

    if (debugPrint) {
        cout << "Area Calculated: " << area << endl;
    }

    return area;
}


int waterArea(vector<int> heights) {
  if (heights.size() == 0) {
    return 0;
  }
  if (heights.size() == 1) {
    return 0;
  }
  
  return waterAreaInt(heights);
}
