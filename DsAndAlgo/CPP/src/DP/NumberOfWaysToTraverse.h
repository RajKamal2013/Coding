

/* 
 * Number of ways to traverse
 * Given height and width of matrix and you are allowed to move either right or down.
 * Starting from top left, find number of ways to reach bottom right. 
 */


#include <iostream>
#include <vector>

using namespace std; 

int numberOfWaysToTraverseGraph(int width, int height) {
  if ((width == 0) && (height == 0)) {
    return -1;
  }

  if ((height == 0) || (width == 0)){
    return -1;
  }

  if ((height == 1) && (width ==1)) {
    return 0;
  }

  if ((height == 1) || (width == 1)) {
    return 1;
  }
  
  vector<vector<int>> traverse (height, vector<int>(width, 1)); 

  for (int i = 1; i < height; i++) {
    for (int j = 1; j < width; j++) {
        traverse[i][j] = traverse[i-1][j] + traverse[i][j-1];
    }
  }
  return (traverse[height-1][width-1]);
}
