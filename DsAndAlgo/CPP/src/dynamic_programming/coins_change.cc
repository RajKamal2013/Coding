#include <iostream>
#include "coins_change.h"

int numberOfWaysToMakeChangeValidations(int n, std::vector<int> denoms) {
    if (n == 0) {
        return 1;
    }    

    if (n < 0) {
        return -1;
    }

    if (denoms.size() <= 0) {
        return -1;
    }

    return INT_MAX;
}

int numberOfWaysToMakeChange(int n, std::vector<int> denoms) {
    int res = numberOfWaysToMakeChangeValidations(n, denoms);
    if (res <= 1) {
        std::cout << "Validations Failed" << std::endl;
        return res;
    }

    int number_of_ways = numberOfWaysToMakeChangeNaive(n, denoms);
    std::cout << "Number of ways to make coin change (Naive way): " << number_of_ways << "\n";

    number_of_ways = numberOfWaysToMakeChangeTopDown(n, denoms);
    std::cout << "Number of ways to make coin change (DP: Top Down Approach): " 
        << number_of_ways << "\n";

    number_of_ways = numberOfWaysToMakeChangeBottomsUp(n, denoms);
    std::cout << "Number of ways to make coin change (DP: Bottoms Up Approach): " 
        << number_of_ways << "\n";

    return number_of_ways;
}

/* Number of ways to make coin change: Naive way */
int numberOfWaysToMakeChangeNaive(int n, std::vector<int> denoms) {

   int res = numberOfWaysToMakeChangeValidations(n, denoms);
    if (res <= 1) {
        std::cout << "Validations Failed" << std::endl;
        return res;
    }

    std::sort(denoms.begin(),denoms.end());
    int number_of_ways = 0;
    int last_index = denoms.size() - 1;
    int maximum = denoms[last_index];
    number_of_ways = numberOfWaysToMakeChangeNaiveInt(n, denoms, maximum); 

    return number_of_ways;

}
int numberOfWaysToMakeChangeNaiveInt(int n, std::vector<int> denoms, int maximum) {
    if (n == 0) {
        return 1;
    }
    
    if (n < 0) {
        return 0;
    }

    int number_of_ways = 0;
    for (int i = 0; i < denoms.size(); i++) {
        if (n >= denoms[i]) {
            number_of_ways = number_of_ways + 
                numberOfWaysToMakeChangeNaiveInt(n - denoms[i], denoms, denoms[i]);
        }
    }

    return number_of_ways;
}

/* Number of ways to make coin change: DP-> Top Down Approach */
int numberOfWaysToMakeChangeTopDown(int n, std::vector<int> denoms) {
    int res = numberOfWaysToMakeChangeValidations(n, denoms);
    if (res <= 1) {
        std::cout << "Validations Failed" << std::endl;
        return res;
    }

    std::vector<int> rows(n + 1, -1);
    std::vector<std::vector<int>> dp(denoms.size(), rows);
    std::sort(denoms.begin(),denoms.end());
    int number_of_ways = 0;
    int max_denoms_idx = denoms.size() - 1;
    number_of_ways = numberOfWaysToMakeChangeTopDownInt(n, denoms, max_denoms_idx, dp);
    return number_of_ways;
}


int numberOfWaysToMakeChangeTopDownInt(int n, std::vector<int> denoms, 
    int max_denoms_idx, std::vector<std::vector<int>> dp) {
    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        return 0;
    }

    if (dp[max_denoms_idx][n] != -1) {
        return dp[max_denoms_idx][n];
    }

    int number_of_ways = 0;
    for (int i = 0; i < denoms.size(); i++) {
        if (denoms[i] <= denoms[max_denoms_idx]) {
            number_of_ways = number_of_ways + 
                numberOfWaysToMakeChangeTopDownInt(n - denoms[i], denoms, i, dp);
        }
    }

    dp[max_denoms_idx][n] = number_of_ways;
    return dp[max_denoms_idx][n];
}

/* Number of ways to make coin change: DP-> Bottoms Up Approach */
int numberOfWaysToMakeChangeBottomsUp(int n, std::vector<int> denoms) {
    int res = numberOfWaysToMakeChangeValidations(n, denoms);
    if (res <= 1) {
        std::cout << "Validations Failed" << std::endl;
        return res;
    }
    std::sort(denoms.begin(),denoms.end());

    std::vector<int> cols(denoms.size(), 0);
    std::vector<std::vector<int>> dp(n + 1, cols);
    for (int i = 0; i < denoms.size(); i++) {
        dp[0][i] = 1;
    }

    int incl, excl;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < denoms.size(); j++) {
            incl = excl = 0;
            if (i >= denoms[j]) {
                incl = dp[i-denoms[j]][j];
            }
            if (j - 1 >= 0) {
                excl = dp[i][j-1];
            }
            dp[i][j] = incl + excl;
        }
    }

    return dp[n][denoms.size() - 1];
}

void DisplayInput(int n, std::vector<int> denoms) {
    std::cout << "-------------------------------------------\n"; 
    std::cout << "Coin Sum: " << n << "\n";
    std::cout << "Coin Denominations: [";
    for (auto coin: denoms) {
        std::cout << coin << " ";
    } 
    std::cout << "]\n";
}

void DisplayOutput(int expected, int computed) {
    std::cout << " Expected: " << expected << " ";
    std::cout << " Computed: " << computed << "\n";
    std::cout << "-------------------------------------------\n"; 
}
int main(int argc, char *argv[]) {
    std::vector<int> denoms = {1 , 5};
    int n = 6;
    int computed = 0;
    int expected = 0;
    
    DisplayInput(n, denoms);
    computed = numberOfWaysToMakeChange(n, denoms);
    expected = 2;
    DisplayOutput(expected, computed);
    
    return 0;
}