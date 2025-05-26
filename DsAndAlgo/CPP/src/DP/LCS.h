
/* 
 * Find longest common subsequence of two strings. 
 *  str1 = "clement";
 *  str2 = "antoine"; 
 *  Answer = n, t
 * issues: Duplicate issue (needs to track)
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2) {
  if ((str1.length() == 0) || (str2.length() == 0)) {
    return {};
  }
  
  size_t n = str1.length() + 1;
  size_t m = str2.length() + 1;
  vector<vector<int>> L(n, vector<int>(m, 0));
  vector<vector<char>> C(n, vector<char>(m, 'N'));
  bool debug = false;
  
  for (size_t i = 1; i < n; i++) {
    for (size_t j = 1; j < m; j++) {
        if (str1[i-1] == str2[j-1]) {
            bool alreadyFound = false;
            if (i == j){
                L[i][j]  = L[i-1][j-1] + 1;
                C[i][j] = 'D';
            } else if (i < j) {
                for (int z = static_cast<int>(i)-2; z >= 0; z--) {
                    if (str1[z] == str2[j-1]) {
                        alreadyFound = true;
                        break;
                    }
                }
                if (alreadyFound) {
                    L[i][j] = L[i-1][j];
                    C[i][j] = 'U';
                } else {
                    L[i][j] = L[i-1][j] + 1;
                    C[i][j] = 'U';
                }
                
            } else {
                for (int z = static_cast<int>(j)-2; z >= 0; z--) {
                    if (str1[i-1] == str2[z]) {
                        alreadyFound = true;
                        break;
                    }
                }
                if (alreadyFound) {
                    L[i][j] = L[i][j-1];
                    C[i][j] = 'L';
                } else {
                    L[i][j] = L[i][j-1] + 1;
                    C[i][j] = 'L';
                }
            }
        } else {
            L[i][j] = L[i-1][j-1];
            C[i][j] = 'D';
            if (L[i][j] < L[i-1][j]) {
                L[i][j] = L[i-1][j];
                C[i][j] = 'U'; 
            } 
            if (L[i][j] < L[i][j-1]) {
                L[i][j] = L[i][j-1];
                C[i][j] = 'L';
            }
        }
        if (debug) {
            cout << " L[" << i << "][" << j << "]" << ":" << L[i][j];
            cout << " C[" << i << "][" << j << "]" << ":" << C[i][j];

        }
    }
    if (debug) {
        cout << endl;
    }
  }
  size_t i, j;
  i = n - 1;
  j = m - 1;
  vector<char> res;
  char ch = C[i][j];

  while (ch != 'N') {
        if (debug) {
                cout << "Ch: " << ch << " Str1: " << i << " " << str1[i-1];
                cout << " Str2: " << j << " " << str2[j-1] << endl;

        }
        if (str1[i-1] == str2[j-1]) {
            res.push_back(str1[i-1]);
        }

        if (C[i][j] == 'D') {
            i = i-1;
            j = j-1;
        } else if (C[i][j] == 'L') {
            j = j-1;
            continue;
        } else if (C[i][j] == 'U') {
            i = i-1;
            continue;
        } else {

        }
        ch = C[i][j];
  }

  if (debug) {
                cout << "Ch: " << ch << " Str1: " << i << " " << str1[i-1];
                cout << " Str2: " << j << " " << str2[j-1] << endl;

   }
   if ((i > 0) && (j > 0) && (str1[i-1] == str2[j-1])) {
    res.push_back(str1[i-1]);
  }
  reverse(res.begin(), res.end());

  if (debug) {
    cout << "LCS Size: " << L[n-1][m-1] << endl;
    cout << "[";
    for (auto ch: res) {
        cout << ch << " ";
    }
    cout << "]" << endl;
  }
  return res;
}