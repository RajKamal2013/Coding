#include <iostream>
#include <vector>
#include "MaxWaterArea.h"
using namespace std;


void test_waterArea() {
    vector<int> input;
    int area;


    /* ------------------  TestCase1 ------------------- */
    input = {0, 8, 0, 0, 5, 0, 0, 10, 0, 0, 1, 1, 0, 3};
    area = waterArea(input);
    cout << "Input Heights: ";
    for (auto data: input) {
        cout << data << " ";
    }
    cout << endl;
    cout << "Maximum surface area of water that can be trapped: " << area << endl;
    cout << "Expected Answer: 48" << endl;


    /* ----------------- TestCase 2 ---------------------- */
    input = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
    area = waterArea(input);
    cout << "Input Heights: ";
    for (auto data: input) {
        cout << data << " ";
    }
    cout << endl;
    cout << "Maximum surface area of water that can be trapped: " << area << endl;
    cout << "Expected Answer: 0" << endl;

}

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    test_waterArea();
    return 0;
}