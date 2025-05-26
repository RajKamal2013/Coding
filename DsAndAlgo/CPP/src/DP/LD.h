#pragma once 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

using namespace std;


/* 
 * PseudoCode 
 * I need to convert str1 to str2 and need to find the number of changes. 
 *  int a, b, c;
 *  for (auto s1: str1) {
 *      for (auto s2: str2) {
 *          a = LD[s1 - 1][s2]
 *          if (s1 == s2) {
 *               
 *          } else {
 *              
 *          }      
 * }
 * }
 */

int LevenshteinDistance(string str1, string str2) {
    int m = str2.length();
    int n = str1.length();

    if (str1.empty() && str2.empty()) {
      return 0;
    }

    if (str1.empty()) {
      return str2.length();
    }

    if (str2.empty()) {
      return str1.length();
    }
    
    vector<vector<int>> LD(m+1, vector<int>(n+1));

    for (int i = 0; i <= m; i++) {
      LD[i][0] = i;
    }   

    for (int j = 0; j <= n; j++) {
      LD[0][j] = j;
    }  


    for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
        LD[i][j] = j;
    }
    LD[i][0] = i;
  }

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (str2[i - 1] == str1[j-1]) {
          LD[i][j] = LD[i-1][j-1];
        } else {
            LD[i][j] = 1 + min(LD[i-1][j-1], min(LD[i-1][j], LD[i][j-1]));
        }
      }
    }

    return LD[m][n];
}

int LevenshteinDistance2(string str1, string str2) {
int m = str1.length();
  int n = str2.length();
  bool debug = false;

  if (str1.empty() && str2.empty()) {
    return 0;
  }

  if (str1.empty()) {
    return str2.length();
  }

  if (str2.empty()) {
    return str1.length();
  }

  vector<vector<int>> LD(m, vector<int>(n));
  vector<int> subset(m);
  int a, b, c, l;

  for (int i = 0; i < m; i++) {
    subset[i] = -1;
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        LD[i][j] = 0;
    }
  }

  if (str1[0] == str2[0]) {
    LD[0][0] = 0;
  } else {
    LD[0][0] = 1;
  }

  for (int i = 1; i < m; i++) {
    if (str1[i] == str2[0]) {
        LD[i][0] = LD[i-1][0];
    } else {
        LD[i][0] = LD[i-1][0] + 1;
    }
    if (debug) {
        cout << "Str1:" << str1[i] << " Str2:" << str2[0] << endl;
        cout << "LD["   << i << "][0]: " << LD[i][0] << endl;
    }
  }
  

  for (int i = 0; i < m; i++) {
    for (int j = 1; j < n; j++) {
        if ((i - 1) >= 0) {
            a = LD[i-1][j];
        } else {
            a = INT_MAX;
        }
        if ((j - 1) >= 0) {
            b = LD[i][j-1];
        }else {
            b = INT_MAX;
        }
        if (((i - 1) >= 0) && ((j - 1) >= 0)) {
            c = LD[i-1][j-1];
        } else {
            c = INT_MAX;
        }
        LD[i][j] = min(a, b);
        LD[i][j] = min(c, LD[i][j]);
        
        if (str1[i] != str2[j]) {
            LD[i][j] = LD[i][j] + 1;
        } else {
            if (i == 0) {
              subset[i] = j;
            }
            if (subset[i] == -1){
              l = subset[i-1];
              if ((l >= j) || (l == -1)){
                LD[i][j] = LD[i-1][j-1];
              } else  {
                subset[i] = j;
              }
            } else { //already subset 
               LD[i][j] = LD[i][j] + 1;
            }
        }
        if (debug) {
            cout << "Str1:" << str1[i] << " Str2:" << str2[j] << endl;
            cout << "LD["<<i<<"][" << j << "]: " << LD[i][j] << endl;
        }
    }
  }
  
  return LD[m-1][n-1];
  // Write your code here.
}