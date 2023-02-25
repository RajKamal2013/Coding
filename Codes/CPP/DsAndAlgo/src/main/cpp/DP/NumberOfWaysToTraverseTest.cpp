
#include<iostream>
#include<vector>
#include "DP/NumberOfWaysToTraverse.h"

using namespace std;

void test_NumberOfWaysToTraverse() {
    int height, width, ways;

    height = 3;
    width = 4;
    ways = numberOfWaysToTraverseGraph(width, height);
    cout << "Number of Ways To traverse Grid <" << width << " * " << height << ">  is:" << ways << endl;

    height = 3;
    width = 2;
    ways = numberOfWaysToTraverseGraph(width, height);
    cout << "Number of Ways To traverse Grid <" << width << " * " << height << ">  is:" << ways << endl;

}
