/*
 * Minimum number of Jumps required to reach end of the array. Each index of array represents jumps.
 * if arr[2] = 3 -> then from arr[2], it can reach to arr[3]. arr[4], arr[5] in 1 step. (3 jumps : 1, 2, 3)
 * Example: arr = {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3}
 * Min number of jumps to reach arr[10] from arr[0] => 4 
 * below are the 3 ways. In each way, minimum number of jumps is 4.
 * arr[0] - arr[1] - arr[4] - arr[6] - arr[10]
 * arr[0] - arr[1] - arr[5] - arr[6] - arr[10]
 * arr[0] - arr[2] - arr[4] - arr[6] - arr[10]
 */


#include<iostream>
#include<vector>
using namespace std;

int minNumberOfJumps(vector<int> array) {
  bool debug = true;
  if (array.size() == 0) {
    return -1;
  }
  if (array.size() == 1) {
    return 0;
  }

  // if startting element is 0 then we can't proceed. 
  if (array[0] == 0) {
    return -1;
  }
  vector<int> MinJumps(array.size(), INT_MAX);
  int temp;
  MinJumps[0] = 0;
    if (debug) {
        cout << "After working on array[0]->" << array[0] << endl;
        for (auto data: MinJumps) {
            cout << data << " ";
        }
        cout << endl;
    }
  for (int i = 0; i < array.size(); i++) {
     if (array[i] <= 0) {
        continue;
     } else {
        for (int j = 1; j <= array[i]; j++) {
            temp = MinJumps[i] + 1;
            if ((i + j < array.size()) && (MinJumps[i + j] > temp)) {
                MinJumps[i + j] = temp;
            }
        }
        if (debug) {
            cout << "After working on array[" << i << "]->" << array[i] <<  endl;
            for (auto data: MinJumps) {
                cout << data << " ";
            }
            cout << endl;
        }
    }
  }

  if (MinJumps[array.size() -1] == INT_MAX) {
    return -1;
  } else {
    return MinJumps[array.size() -1];
  }
}


