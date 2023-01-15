#include <iostream>
#include <vector>
using namespace std;


void maxIncreasingSubsequenceSumInt(vector<int> arr, int& globalMax, int& globalMaxSum, vector<int> &res) {
    int sum, max, currId;
    bool debug = false;
    vector<int> maxE(arr.size(), 0);
    vector<int> sumE(arr.size(), 0);
    vector<int> sumI(arr.size(), 0);
    vector<int> maxI(arr.size(), 0);
    vector<int> traceE(arr.size(), -1);
    vector<int> traceI(arr.size(), -1);

    globalMaxSum  = arr[0];
    globalMax = arr[0];

    if (arr[0] > 0) {
        maxE[0] = 0;
        sumE[0] = 0;
    } else {
        maxE[0] = arr[0] - 1;
        sumE[0] = arr[0] - 1;
    }
    traceE[0] = -1;
    currId = 0;
    

    maxI[0] = arr[0];
    sumI[0] = arr[0];
    traceI[0] = -1;

    if (debug) {
        cout << "Working on Arr: " << arr[0] << endl;
        cout << "Sum Including: " << arr[0] << " is: " << sumI[0] << " Max Element: " << maxI[0] << " Prev: " << traceI[0] << endl;
        cout << "Sum Excluding: " << arr[0] << " is: " << sumE[0] << " Max Element: " << maxE[0] << " Prev: " << traceE[0] << endl;
    }
    for (int i = 1; i < arr.size(); i++) {
        if (debug) {
            cout << "Working on Arr: " << arr[i] << endl;
        }
        // sum including i 
        if (maxI[i-1] < arr[i]) {
            maxI[i] = arr[i];
            sumI[i] = sumI[i-1] + arr[i];
            if (sumI[i] < arr[i]) {
                sumI[i] = arr[i];
                traceI[i] = -1;
            } else {
                traceI[i] = i - 1;
            }
            if (maxE[i-1] < maxI[i]) {
                if (sumI[i] < sumE[i-1] + arr[i]) {
                    sumI[i] = sumE[i-1] + arr[i];
                    traceI[i] = traceE[i-1];
                }   
            } else {
                int j = i - 1;
                while ((j >= 0) && (maxE[j] >= arr[i])) {
                    j = j - 1;
                }
                if (sumI[i] < sumE[j] + arr[i]) {
                    sumI[i] = sumE[j] + arr[i];
                    traceI[i] = traceE[j];
                }
            }
        } else {
            int j = i - 2;
            while ((j >= 0) && (maxI[j] > arr[i])) {
                j = j - 1;
            }
            if (maxI[j] < arr[i]) {
                sumI[i] = sumI[j] + arr[i];
                traceI[i] = j;
            } else {
                sumI[i] = arr[i];
                traceI[i] = -1;
            }
            j = i - 1;
            while ((j >= 0) && (maxE[j] > arr[i])) {
                j = j - 1;
            }
            if (maxE[j] < arr[i]) {
                if (sumI[i] < sumE[j] + arr[i]) {
                    sumI[i] = sumE[j] + arr[i];
                    traceI[i] = traceE[j];
                }
            }

            maxI[i] = arr[i];
        }
        if (debug) {
            cout << "Sum Including: " << arr[i] << " is: " << sumI[i] << " Max Element: " << maxI[i] << " Prev: " << traceI[i]<< endl;
        
        }

        //sum  exclude 
        if (sumI[i-1] > sumE[i-1]) {
            sumE[i] = sumI[i-1];
            traceE[i] = traceI[i-1];
            maxE[i] = maxI[i-1];
            if (arr[traceE[i]] != maxE[i]) {
                traceE[i] = i - 1;
            }
        } else {
            sumE[i] = sumE[i-1];
            traceE[i] = traceE[i-1];
            maxE[i] = maxE[i-1];
        }
        
        if (sumI[i] > sumE[i]) {
            sum = sumI[i];
            max = maxI[i];
        } else {
            sum = sumE[i];
            max = maxE[i];
        }
        
        if (globalMaxSum < sum) {
                globalMaxSum = sum;
                globalMax = max;
                currId = i;
        } 

        if (debug) {
            cout << "Sum Excluding: " << arr[i] << " is: " << sumE[i] << " Max Element: " << maxE[i] << " Prev:" << traceE[i] << endl;

        }
    }

    if (sumI[currId] == globalMaxSum) {
            int id = currId;
            res.push_back(arr[id]);
            while (traceI[id] != -1) {
                res.push_back(arr[traceI[id]]);
                id = traceI[id];
            }
    } else {
        int id = currId;
        res.push_back(arr[id]);
        while (traceE[id] != -1) {
            res.push_back(arr[traceE[id]]);
            id = traceE[id];
        }
    }
    reverse(res.begin(), res.end());

    if (debug) {
        cout << "Max Including Sum" << endl;
        for (auto data: maxI) {
            cout << data << " ";
        }
        cout << endl;
        cout << "Max Excluding Sum" << endl;
        for (auto data: maxE) {
            cout << data << " ";
        }
        cout << endl;

    }
    if (debug ) {
        cout << "Maximum Increasing Subsequence Sum: " << globalMaxSum << endl;
        cout << "Maximum Increasing Subsequence Element: " << globalMax << endl;

        cout << "Maximum Increasing Subsequence" << endl;
        for (auto data:res) {
            cout << data << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
  vector<int> res;
  int max, sum;
  max = sum = 0;
  bool debug = false;
  maxIncreasingSubsequenceSumInt(array, max, sum, res);
  vector<vector<int>> val;
  vector<int> valSum;
  valSum.push_back(sum);
  val.push_back(valSum);
  val.push_back(res);
  if (debug ) {
        cout << "Maximum Increasing Subsequence Sum: " << sum << endl;
        cout << "Maximum Increasing Subsequence Element: " << max << endl;

        cout << "Maximum Increasing Subsequence" << endl;
        for (auto data:res) {
            cout << data << " ";
        }
        cout << endl;
    }
  return val;
}


vector<vector<int>> maxSumIncreasingSubsequence2(vector<int> array) {

    if (array.size() == 0) {
        return {
            {0}, // Sum of sequence.
            {},  // Elements of the sequence.
        };
     }
    if (array.size() == 1) {
        return { {array[0]}, {array[0]},};
    }

    vector<int> trace(array.size(), -1);
    vector<int> sums(array);
    vector<vector<int>> res;
    int maxSumIdx = 0;

    for (int i = 0; i < array.size(); i++) {
        for (int j = 0; j < i ; j++) {
             if (array[i] > array[j]){
                if (sums[i] < sums[j] + array[i]) {
                    sums[i] = sums[j] + array[i];
                    trace[i] = j;
                }
             }
        }
        if (sums[maxSumIdx] < sums[i]) {
            maxSumIdx = i;
        }
    }

    vector<int> arr;
    arr.push_back(maxSumIdx);
    idx = maxSumIdx;
    while (trace[idx] != -1) {
        arr.push_back(array[trace[idx]]);
        idx = trace[idx];
    }
    sort(arr.begin(), arr.end());

    res.push_back({sums[maxSumIdx]});
    res.push_back(arr);


    return res;

}